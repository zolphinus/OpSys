#include "ChopSystem.h"
#include <iostream>

#ifdef _WIN32
    #include "direct.h"
    #define GetCurrentDir _getcwd
#endif // _WIN32

ChopSystem::ChopSystem(){
    initializeData();
}

void ChopSystem::runOS(){

    while(this->isRunning() == true){
            commandManager.enterCommand(system_data);
    }
}

bool ChopSystem::isRunning(){
    return system_data.isRunning;
}


void ChopSystem::initializeData(){
    system_data.isRunning = true;
    system_data.versionInfo = "Chopsticks Version 0.1";
    system_data.currentDirectory = getWorkingDirectory();
}

std::string ChopSystem::getWorkingDirectory(){
    // declare variables
     char filePath[256];

     // get current directory
     if(!GetCurrentDir(filePath, sizeof(filePath)))
     {
          std::cout<<"** ERROR - Unable to locate current file directory." << std::endl;;
     }

     std::string workingDirectory(filePath);
    return workingDirectory;
}
