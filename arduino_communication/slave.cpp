//
//  slave.cpp
//  arduino_communication
//
//  Created by Filip Peterek on 02/02/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#include "slave.hpp"

void Slave::receiveData(const char * data) {
    
    strcpy(rawData, data);
    parseData();
    
}

const fun<void (Slave::*)()> Slave::functions[3] = {
    
    fun<void (Slave::*)()>("time", &Slave::parseTime),
    fun<void (Slave::*)()>("date", &Slave::parseDate),
    fun<void (Slave::*)()>("temp", &Slave::parseTemp)
    
};

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
    for (auto & i : Slave::functions) {
        
        if (strcmp(type, i.string)) {
            ((*this).*(i.function))();
            break;
        }
        
    }
    
}
