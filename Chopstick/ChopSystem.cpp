#include "ChopSystem.h"
#include <iostream>
#include <time.h>
#include <stdio.h>

#include "GeneralFunctions.h"

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
    getCurrentDate();
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


void ChopSystem::getCurrentDate(){
    time_t* tempTime;
    //std::stringstream ss;

    tm* timeGetter;
    time(tempTime);

    timeGetter = localtime(tempTime);
//    out << timeGetter->tm_mon;
    //sprintf(strConvert, "%c", timeGetter->tm_mday);
    //system_data.day = strConvert;

    //sprintf(strConvert, "%c", timeGetter->tm_mon + 1);
    //system_data.month = strConvert;

    //sprintf(strConvert, "%c", timeGetter->tm_year - 100);
    //system_data.year = strConvert;
    //system_data.year = timeGetter->tm_year;

    //std::cout << system_data.day << "/" << system_data.month<< "/" << system_data.year << std::endl;

}
