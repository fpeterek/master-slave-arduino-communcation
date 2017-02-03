//
//  main.cpp
//  arduino_communication
//
//  Created by Filip Peterek on 02/02/2017.
//  Copyright © 2017 Filip Peterek. All rights reserved.
//

#include <iostream>

#include "slave.hpp"

int main(int argc, const char * argv[]) {
    
    Slave slave;
    const char * time = "{time;23:05:12}";
    slave.receiveData(time);
    std::cout << "Time: " << (int)slave.getInfo().hour << ":" << (int)slave.getInfo().minute
              << ":" << (int)slave.getInfo().second << std::endl;
    
    const char * date = "{date;24.9.2017}";
    slave.receiveData(date);
    std::cout << "Date: " << (int)slave.getInfo().day << "." << (int)slave.getInfo().month << "."
              << slave.getInfo().year << std::endl;

    const char * temp = "{temp;24}";
    slave.receiveData(temp);
    std::cout << "Temperature: " << (int)slave.getInfo().temperature << "°C" << std::endl;
    
}
