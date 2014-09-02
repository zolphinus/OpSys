#include "ChopSystem.h"
#include <iostream>
#include <time.h>
#include <string>
#include <sstream>
#include "GeneralFunctions.h"

#define OSname "Chopsticks "
#define VERSION "0.2.1"

#ifdef _WIN32
    #include "direct.h"
    #define GetCurrentDir _getcwd
#endif // _WIN32

ChopSystem::ChopSystem(){
    initializeData();
}

ChopSystem::~ChopSystem()
{
    for(int i = 0; i < TOTAL_COMMANDS; i++){
        delete system_data.commandList[i];
    }
    system_data.commandList.resize(0);
    system_data.keywordList.resize(0);
    system_data.keywordHelpList.resize(0);
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
    time(&tempTime);
    getCurrentDate();
    commandManager.initCommandList(system_data);
}

std::string ChopSystem::getWorkingDirectory(){
    // declare variables
     char filePath[256];

     // get current directory
     if(!GetCurrentDir(filePath, sizeof(filePath)))
     {
          std::cout<< "Unable to locate current file directory." << std::endl;;
     }

     std::string workingDirectory(filePath);
    return workingDirectory;
}


void ChopSystem::getCurrentDate(){
    std::ostringstream strout;

    tm* timeGetter = localtime(&tempTime);

    int temp = timeGetter->tm_year - 100; //year from 2000
    strout << temp;
    system_data.year = strout.str();
    strout.str(""); //clears buffer

    temp = timeGetter->tm_mon + 1; //months are 1 -12
    strout << temp;
    system_data.month = strout.str();
    strout.str(""); //clears buffer

    temp = timeGetter->tm_mday; //months are 1 -12
    strout << temp;
    system_data.day = strout.str();
    strout.str(""); //clears buffer
    formatDate(system_data);
}
