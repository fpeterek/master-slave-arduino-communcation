//
//  slave.cpp
//  arduino_communication
//
//  Created by Filip Peterek on 02/02/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#include "slave.hpp"

info::info() {
    
    day   = 0;
    month = 0;
    year  = 0;
    
    hour   = 0;
    minute = 0;
    second = 0;
    
    temperature = 0;
    
}


void Slave::receiveData(const char * data) {
    
    strcpy(rawData, data);
    parseData();
    
}

const fun<void (Slave::*)()> Slave::functions[3] = {
    
    fun<void (Slave::*)()>("time", &Slave::parseTime),
    fun<void (Slave::*)()>("date", &Slave::parseDate),
    fun<void (Slave::*)()>("temp", &Slave::parseTemp)
    
};

const info & Slave::getInfo() const {
    return information;
}

void Slave::parseTime() {
    
    const char * substr;
    substr = strstr(rawData, ";") + 1;
    
    unsigned char newHour;
    unsigned char newMinute;
    unsigned char newSecond;
    
    char * str;
    
    unsigned char * const pointers[3] = {
        &newHour,
        &newMinute,
        &newSecond
    };
    const unsigned char delimiters[3] = { ':', ':', '}' };
    
    for (unsigned char i = 0; i < 3; ++i) {
        char number[20];
        strcpy(number, substr);
        for (str = number; *str != delimiters[i]; ++str);
        *str = '\0';
        substr += str - number + 1;
        *(pointers[i]) = atoi(number);
    }
    
    if (newHour > 24 or newMinute > 60 or newSecond > 60) {
        return;
    }
    
    information.hour   = newHour;
    information.minute = newMinute;
    information.second = newSecond;
    
}

void Slave::parseDate() {
    
    const char * substr;
    substr = strstr(rawData, ";") + 1;
    
    unsigned short newDay;
    unsigned short newYear;
    unsigned short newMonth;
    
    char * str;
    
    unsigned short * const pointers[3] = {
        &newDay,
        &newMonth,
        &newYear
    };
    
    const unsigned char delimiters[3] = { '.', '.', '}' };
    
    for (unsigned char i = 0; i < 3; ++i) {
        char number[20];
        strcpy(number, substr);
        for (str = number; *str != delimiters[i]; ++str);
        *str = '\0';
        substr += str - number + 1;
        *(pointers[i]) = atoi(number);
    }
    
    if (newDay > 31 or newMonth > 12 or not newMonth) {
        return;
    }
    
    information.day   = newDay;
    information.month = newMonth;
    information.year  = newYear;

    
}

void Slave::parseTemp() {
    
    const char * substr;
    substr = strstr(rawData, ";") + 1;
    
    char newTemp;
    
    char * str;
    
    char number[20];
    strcpy(number, substr);
    for (str = number; *str != '}'; ++str);
    *str = '\0';
    substr += str - number + 1;
    newTemp = atoi(number);
    
    
    information.temperature = newTemp;
    
}

void Slave::parseData() {
    
    /* Invalid data */
    if (rawData[0] != '{' or strlen(rawData) < 6) {
        return;
    }
    
    const char * substr;
    substr = strstr(rawData, ";");
    /* Max 4 characters for type info */
    if (substr - rawData - 1 > 4) {
        return;
    }
    
    /* Copy first four characters */
    char type[5];
    char i = 0;
    for (char * c = rawData + 1; c < substr; ++c) {
        type[i++] = *c;
    }
    type[4] = 0;
    
    /* Iterate over function pointers and call matching function */
    for (auto & iter : Slave::functions) {
        
        /* strcmp returns 0 if strings are equal */
        if (not strcmp(type, iter.string)) {
            ((*this).*(iter.function))();
            break;
        }
        
    }
    
}
