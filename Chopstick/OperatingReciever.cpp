#include "OperatingReciever.h"
#include <iostream>
#include "DirectoryCommands.h"

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
          for (std::vector<std::string>::iterator iter = system_data.directoryList.begin();
                iter != system_data.directoryList.end(); ++iter)
            {
                std::cout << *iter << std::endl;
            }
    }

}
