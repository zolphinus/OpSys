#ifndef FUNCTIONS
#define FUNCTIONS

#include <sstream>
#include <iostream>


std::string intToString(int intValue){
    std::string stringValue;
    std::stringstream out;
    out << intValue;
    stringValue = out.str();

    std::cout << "TEST" << std::endl;

    return stringValue;
};

#endif // FUNCTIONS
