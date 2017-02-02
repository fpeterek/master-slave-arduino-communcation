//
//  slave.hpp
//  arduino_communication
//
//  Created by Filip Peterek on 02/02/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#ifndef slave_hpp
#define slave_hpp

#include <stdio.h>
#include <cstdlib>
#include <cstring>

#include "fun.hpp"

struct info {
    
    unsigned char day;
    unsigned char month;
    unsigned char year;
    
    unsigned char hour;
    unsigned char minute;
    unsigned char second;
    
    char temperature;
    
};

class Slave {
    
    char rawData[30];
    
    info information;
    
    void parseData();
    
    void parseTime();
    void parseDate();
    void parseTemp();
    
    static const fun<void (Slave::*)()> functions[3];
    
public:
    void receiveData(const char * data);
    
};

#endif /* slave_hpp */
