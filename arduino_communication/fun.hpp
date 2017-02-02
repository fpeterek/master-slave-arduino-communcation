//
//  fun.hpp
//  arduino_communication
//
//  Created by Filip Peterek on 02/02/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#ifndef fun_hpp
#define fun_hpp

#include <stdio.h>
#include <cstring>

template <typename funPtr>
struct fun {
    
    char string[5];
    funPtr function;
    
    fun(const char * str, funPtr f) {
        
        strcpy(string, str);
        function = f;
        
    }
    
};

#endif /* fun_hpp */
