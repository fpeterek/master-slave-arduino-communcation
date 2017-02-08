//
//  master.cpp
//  arduino_communication
//
//  Created by Filip Peterek on 02/02/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#include "master.hpp"

void sendData(const char * data) {
    
    /* Sends data using Arduino pins */
    
}

void Master::setTemp(const char temp) {
    temperature = temp;
}

void Master::sendDate() {
    
    /* Get date from system time */
    time_t t = time(nullptr);
    struct tm timeInfo = *localtime(&t);
    
    /* Convert time to string */
    char data[50];
    sprintf(data, "{date;%d.%d.%d}", timeInfo.tm_mday, timeInfo.tm_mon, timeInfo.tm_year);
    
    sendData(data);
    
}

void Master::sendTime() {
    
    /* Get time from system time */
    time_t t = time(nullptr);
    struct tm timeInfo = *localtime(&t);
    
    /* Convert time to string */
    char data[50];
    sprintf(data, "{time;%d:%d:%d}", timeInfo.tm_hour, timeInfo.tm_min, timeInfo.tm_sec);
    
    sendData(data);
    
}

void Master::sendTemperature() {
    
    /* Convert time to string */
    char data[30];
    sprintf(data, "{temp;%d}", (int)temperature);
    
    sendData(data);
    
}
