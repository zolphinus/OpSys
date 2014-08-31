#include "ChopSystem.h"
#include <iostream>

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
}

