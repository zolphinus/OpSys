#ifndef FUNCTIONS
#define FUNCTIONS


#include <iostream>
#include <string>

void formatDate(Global_Data& system_data){
    system_data.date = system_data.day + "/" + system_data.month + "/" + system_data.year;
}

#endif // FUNCTIONS
