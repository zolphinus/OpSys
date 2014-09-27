#include "ProcessControlBlock.h"
#include "ProcessControlEnums.h"
#include <iostream>

ProcessControlBlock::ProcessControlBlock(){
    memory = 0;
    timeRemaining = 0;
    timeOfArrival = 0;
    percentOfCPU = 0;
    turnAround = 0;
}

std::string ProcessControlBlock::getProcessName(){
    return processName;
}

ProcessClass ProcessControlBlock::getProcessClass(){
    return processClass;
}

RunState ProcessControlBlock::getRunState(){
    return runState;
}

int ProcessControlBlock::getPriority(){
    return priority;
}

int ProcessControlBlock::getMemory(){
    return memory;
}

int ProcessControlBlock::getTurnAround(){
    return turnAround;
}

//Parameter validation occurs in the controller
void ProcessControlBlock::setupPCB(std::string newProcessName, int newPriority, ProcessClass newProcessClass){
    processName = newProcessName;
    priority = newPriority;
    processClass = newProcessClass;
}


void ProcessControlBlock::setRunState(RunState newRunState){
    runState = newRunState;
}

void ProcessControlBlock::setPriority(int newPriority){
    priority = newPriority;
}

void ProcessControlBlock::calculateTurnAround(int completionTime){
    turnAround = completionTime - timeOfArrival;
}

void ProcessControlBlock::printControlInfo(PrintMode printMode){

    if(printMode == FULL_PRINT){
        std::cout << "Name : " << processName << std::endl;
        std::cout << "Process Class : ";
        switch(processClass)
        {
        case APPLICATION :
            std::cout << "Application" << std::endl;
            break;
        case SYSTEM :
            std::cout << "System" << std::endl;
            break;
        default :
            std::cout << "Error" << std::endl;
        }

        std::cout << "Run State : ";

        switch(runState)
        {
        case READY :
            std::cout << "Ready" << std::endl;
            break;
        case SUSPENDED_READY :
            std::cout << "Suspended Ready" << std::endl;
            break;
        case BLOCKED :
            std::cout << "Blocked" << std::endl;
            break;
        case SUSPENDED_BLOCKED :
            std::cout << "Suspended Blocked" << std::endl;
            break;
        case RUNNING :
            std::cout << "Running" << std::endl;
            break;
        default :
            std::cout << "Error" << std::endl;
        }

        std::cout << "Priority : " << priority << std::endl;
        std::cout << "Memory : " << memory << std::endl << std::endl;
    }
    else if(printMode == PARTIAL_PRINT){
        std::cout << processName << " ";

        switch(runState)
        {
        case READY :
            std::cout << "Ready ";
            break;
        case SUSPENDED_READY :
            std::cout << "Suspended Ready ";
            break;
        case BLOCKED :
            std::cout << "Blocked ";
            break;
        case SUSPENDED_BLOCKED :
            std::cout << "Suspended Blocked ";
            break;
        case RUNNING :
            std::cout << "Running ";
            break;
        default :
            std::cout << "Error ";
        }

        std::cout << priority << std::endl;
    } else if (printMode == TIME_REMAINING){
        std::cout << processName << "   Time Remaining: ";
        std::cout << timeRemaining << std::endl;
    }

}

void ProcessControlBlock::testControlBlock(){

    processName = "TEST PROCESS NAME";
    priority = -37;
    memory = 1337;
    std::cout << "TESTING THE PCB CLASS " << std::endl;
    std::cout << processName << std::endl;
    processClass = APPLICATION;
    if(processClass == APPLICATION)
    {
        std::cout << "TEST APPLICATION STATE" << std::endl;
    }
    else{
        std::cout << "ERROR IN APPLICATION STATE" << std::endl;
    }

    processClass = SYSTEM;
    if(processClass == SYSTEM)
    {
        std::cout << "TEST SYSTEM STATE" << std::endl;
    }
    else{
        std::cout << "ERROR IN SYSTEM STATE" << std::endl;
    }

    runState = READY;
    if(runState == READY)
    {
        std::cout << "TEST READY STATE" << std::endl;
    }
    else{
        std::cout << "ERROR IN READY STATE" << std::endl;
    }

    runState = SUSPENDED_READY;
    if(runState == SUSPENDED_READY)
    {
        std::cout << "TEST SUSPENDED_READY STATE" << std::endl;
    }
    else{
        std::cout << "ERROR IN SUSPENDED_READY STATE" << std::endl;
    }

    runState = BLOCKED;
    if(runState == BLOCKED)
    {
        std::cout << "TEST BLOCKED STATE" << std::endl;
    }
    else{
        std::cout << "ERROR IN BLOCKED STATE" << std::endl;
    }

    runState = SUSPENDED_BLOCKED;
    if(runState == SUSPENDED_BLOCKED)
    {
        std::cout << "TEST SUSPENDED_BLOCKED STATE" << std::endl;
    }
    else{
        std::cout << "ERROR IN SUSPENDED_BLOCKED STATE" << std::endl;
    }

    runState = RUNNING;
    if(runState == RUNNING)
    {
        std::cout << "TEST RUNNING STATE" << std::endl;
    }
    else{
        std::cout << "ERROR IN RUNNING STATE" << std::endl;
    }


    printControlInfo(FULL_PRINT);
}

void ProcessControlBlock::setMemory(int newMemory){
    memory = newMemory;
}

void ProcessControlBlock::setTimeRemaining(int newTimeRemaining){
    timeRemaining = newTimeRemaining;
}

void ProcessControlBlock::setTimeOfArrival(int newTimeOfArrival){
    timeOfArrival = newTimeOfArrival;
}

void ProcessControlBlock::setPercentOfCPU(int newPercent){
    percentOfCPU = newPercent;
}

int ProcessControlBlock::getTimeRemaining(){
    return timeRemaining;
}

int ProcessControlBlock::getTimeOfArrival(){
    return timeOfArrival;
}

int ProcessControlBlock::getPercentOfCPU(){
    return percentOfCPU;
}

void ProcessControlBlock::run(){
    if(timeRemaining > 0){
        timeRemaining--;
    }
}

void ProcessControlBlock::lowerPriority(){
    if(priority > 0){
        priority--;
    }
}
