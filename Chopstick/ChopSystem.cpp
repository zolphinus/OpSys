#include "ChopSystem.h"
#include <iostream>

ChopSystem::ChopSystem(){
    initializeData();
}

void ChopSystem::runOS(){

    while(this->isRunning() == true){
            std::cout << "L" << std::endl;
    }
}

bool ChopSystem::isRunning(){
    return system_data.isRunning;
}


void ChopSystem::initializeData(){
    system_data.isRunning = true;
}

