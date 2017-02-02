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

class Master {
    
public:
    
    void sendTime();
    void sendTemperature();
    void sendDate();
    
};

#endif /* master_hpp */
