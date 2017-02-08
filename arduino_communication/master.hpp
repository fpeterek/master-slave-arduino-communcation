//
//  master.hpp
//  arduino_communication
//
//  Created by Filip Peterek on 02/02/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#ifndef master_hpp
#define master_hpp

#include <stdio.h>
#include <ctime>
#include <cstdlib>
#include <cmath>
#include <cstdlib>

void sendData(const char * data);

class Master {
    
    char temperature;
    
public:
    
    void setTemp(const char temp);
    
    void sendTime();
    void sendTemperature();
    void sendDate();
    
};

#endif /* master_hpp */
