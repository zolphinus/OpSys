#include "OperatingReciever.h"
#include <iostream>
#include "DirectoryCommands.h"
#include "GeneralFunctions.h"
#include <time.h>
#include <stdio.h>

#define SCREEN_PRINT_LIMIT 22

void OperatingReciever::setAction(ACTION_LIST newAction){
    currentAction = newAction;
}

void OperatingReciever::performAction(Global_Data& system_data)
{
    char tempChar;
    if(currentAction == EXIT)
    {
        std::cout << std::endl << "Do you wish to exit? (Y/N) : ";
        std::cin >> tempChar;
        tempChar = toupper(tempChar);
        std::cin.ignore();
        if(tempChar == 'Y')
        {
            std::cout << "Now exiting..." << std::endl << std::endl;
            system_data.isRunning = false;
        }
    }else if(currentAction == DISPLAY_VERSION){

        std::cout << std::endl << system_data.versionInfo << std::endl << std::endl;
    }else if(currentAction == LIST_DIR_CONTENTS){

        getAllFilesInFolder(system_data);
        printInformation(system_data.directoryList);
    }else if(currentAction == GET_DATE){
        formatDate(system_data);
        std::cout << std::endl << system_data.date << std::endl << std::endl;
    }else if(currentAction == SET_DATE){
        setDate(system_data);
    }else if(currentAction == HELP)
    {
        printInformation(system_data.keywordList);
    }

}


void OperatingReciever::printInformation(std::vector <std::string>& currentData){
    int lineCounter = 0;
    for (std::vector<std::string>::iterator iter = currentData.begin();
                iter != currentData.end(); ++iter)
            {
                std::cout << *iter << std::endl;
                lineCounter++;
                if((lineCounter % SCREEN_PRINT_LIMIT == 0))
                {
                    std::cout << std::endl;
                    std::cout << "Press Enter to continue...";
                    std::cin.ignore();
                    std::cin.get();
                    std::cout << std::endl;
                    lineCounter += 3;
                }
            }
            std::cout << std::endl;
}

void OperatingReciever::setDate(Global_Data& system_data){

    int dateIsValid = false;

    std::string tempDay;
    std::string tempMonth;
    std::string tempYear;

    std::cout << "Please enter the date." << std::endl;
    std::cout << "Day (integer): ";
    std::cin >> tempDay;
    std::cin.ignore();

    std::cout << "Month (integer): ";
    std::cin >> tempMonth;
    std::cin.ignore();

    std::cout << "Year (integer, last two digits): ";
    std::cin >> tempYear;
    std::cin.ignore();

    dateIsValid = validateDate(atoi(tempDay.c_str()),
                               atoi(tempMonth.c_str()),
                               atoi(tempYear.c_str()));





    if(dateIsValid == FALSE)
    {
        std::cout << "Not a valid date. Date unchanged. " << std::endl;
    }
    else{
        std::cout << "Changing date to ";
        system_data.day = tempDay;
        system_data.month = tempMonth;
        system_data.year = tempYear;
        formatDate(system_data);
        std::cout << system_data.date << std::endl << std::endl;

    }

}
