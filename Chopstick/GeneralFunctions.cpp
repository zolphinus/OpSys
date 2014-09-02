#include "GeneralFunctions.h"
#include <algorithm>

void formatDate(Global_Data& system_data){
    system_data.date = system_data.day + "/" + system_data.month + "/" + system_data.year;
}


bool validateDate(int day, int month, int year)
{
    bool isLeapYear = checkLeapYear(year); //check leap year
    if(month < 1 || month > 12)
    {
        return false;
    }

    if(day < 1)
    {
        return false;
    }

    if(year < 1 || year > 99){
        return false;
    }

    switch(month){
    case 2:
        if(isLeapYear == true){
            if(day > 29){
                return false;
            }
        }else{
            if(day > 28){
                return false;
            }
        }
        break;
    case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12:
        if(day > 31)
        {
            return false;
        }
        break;

    case 4 :
        case 6 : case 9 : case 11:
        if(day > 30)
        {
            return false;
        }
        break;
    default :
        return false;
    }

    return true;
}


bool checkLeapYear(int year){
    bool leapYear = false;
    if ((year % 4) ==0)  {
         if ((year % 100) == 0) {
              leapYear = ((year % 400) == 0);
         } else {
              leapYear = true;
         }
         // leap year
    }
    return leapYear;
}


std::string stringToUpper(std::string strToConvert)
{
    std::transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);

    return strToConvert;
}
