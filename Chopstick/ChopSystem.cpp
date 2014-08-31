#include "ChopSystem.h"
#include <iostream>

#define OSname "Chopsticks "
#define VERSION "0.2"

#ifdef _WIN32
    #include "direct.h"
    #define GetCurrentDir _getcwd
#endif // _WIN32

ChopSystem::ChopSystem(){
    initializeData();
}

void ChopSystem::runOS(){
    welcomeScreen();
    while(this->isRunning() == true){
            commandManager.enterCommand(system_data);
    }
}

void ChopSystem::welcomeScreen(){
    std::cout << "Welcome to " << system_data.versionInfo << " !" << std::endl << std::endl;
}

bool ChopSystem::isRunning(){
    return system_data.isRunning;
}


void ChopSystem::initializeData(){
    system_data.isRunning = true;
    std::string tempName = OSname;
    std::string tempVersion = VERSION;
    system_data.versionInfo = tempName + tempVersion;
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
