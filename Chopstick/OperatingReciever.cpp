#include "OperatingReciever.h"
#include <iostream>

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
    }

}
