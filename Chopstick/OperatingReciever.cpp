#include "OperatingReciever.h"
#include <iostream>
#include "DirectoryCommands.h"

#define SCREEN_PRINT_LIMIT 22

void OperatingReciever::setAction(ACTION_LIST newAction){
    currentAction = newAction;
}

void OperatingReciever::performAction(Global_Data& system_data)
{
    if(currentAction == EXIT)
    {
        system_data.isRunning = false;
    }else if(currentAction == DISPLAY_VERSION){

        std::cout << std::endl << system_data.versionInfo << std::endl << std::endl;
    }else if(currentAction == LIST_DIR_CONTENTS){

        getAllFilesInFolder(system_data);
        printInformation(system_data.directoryList);
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
                    std::cin.get();
                }
            }
}
