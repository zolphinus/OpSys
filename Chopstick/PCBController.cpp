#include "PCBController.h"
#include "ProcessControlBlock.h"
#include "ProcessControlEnums.h"
#include <iostream>
#include <fstream>

PCB_Controller::PCB_Controller(){
}

PCB_Controller::~PCB_Controller(){

}


ProcessControlBlock* PCB_Controller::AllocatePCB(){
    ProcessControlBlock* tempPCB;

    try{
        tempPCB = new ProcessControlBlock();
    }
    catch (std::exception& e){
        tempPCB = NULL;
    }

    return tempPCB;
}

ProcessControlBlock* PCB_Controller::FindPCB(std::string processToFind){
    ProcessControlBlock* tempPCB = NULL;

    if(tempPCB == NULL)
    {
        tempPCB = readyQueue.FindPCB(processToFind);
    }

    if(tempPCB == NULL)
    {
        tempPCB = suspendedReadyQueue.FindPCB(processToFind);
    }

    if(tempPCB == NULL)
    {
        tempPCB = blockedQueue.FindPCB(processToFind);
    }

    if(tempPCB == NULL)
    {
        tempPCB = suspendedBlockedQueue.FindPCB(processToFind);
    }

    return tempPCB;

}

void PCB_Controller::createPCB(){

    //Parses PCB setup fields and creates a PCB if data is valid

    std::string processName;
    ProcessControlBlock* tempPCB = NULL;
    char tempChar;
    ProcessClass tempClass;
    int tempPriority;
    bool validClass = false;
    bool validPriority = false;


    std::cout << "CREATE PROCESS" << std::endl;
    std::cout << "Name : ";
    std::cin >> processName;
    tempPCB = FindPCB(processName);


    if(tempPCB == NULL)
    {
        std::cout << "Priority : ";
        std::cin >> tempPriority;

        while(std::cin.fail() == true){
                std::cin.clear();
                std::cin.ignore(100, '\n');
            std::cout <<  std::endl <<"Invalid data. Enter Priority : ";
            std::cin >> tempPriority;
        }

        while(validClass == false)
        {
            std::cout << std::endl << "Choose a class :" << std::endl;
            std::cout << "A) Application" << std::endl;
            std::cout << "B) System" << std::endl;
            std::cin >> tempChar;
            tempChar = toupper(tempChar);

            switch(tempChar){
            case 'A':
                tempClass = APPLICATION;
                validClass = true;
                break;
            case 'B':
                tempClass = SYSTEM;
                validClass = true;
                break;
            default:
                std::cout << std::endl << "Invalid Selection, try again." << std::endl << std::endl;
            }
        }

        if(tempPriority >= -127 && tempPriority <= 128)
        {
            validPriority = true;
        }

        if(validPriority == true && validClass == true){
                tempPCB = AllocatePCB();

                if(tempPCB != NULL){
                    tempPCB->setupPCB(processName, tempPriority, tempClass);
                    tempPCB->setRunState(READY);

                    //enters the PCB into the correct queue
                    insertPCB(tempPCB);
                }
        }
        else{
            std::cout << std::endl << "The process is already running or the parameters are not valid"
                      << std::endl << std::endl;
        }

    }

    tempPCB = NULL;
}

void PCB_Controller::insertPCB(ProcessControlBlock* PCB){

    switch(PCB->getRunState()){
    case READY:
        readyQueue.insertNode(PCB);
        break;
    case SUSPENDED_READY:
        suspendedReadyQueue.insertNode(PCB);
        break;
    case BLOCKED:
        blockedQueue.insertNode(PCB);
        break;
    case SUSPENDED_BLOCKED:
        suspendedBlockedQueue.insertNode(PCB);
        break;
    default:
        break;
    }
}


void PCB_Controller::removePCB(ProcessControlBlock* PCB){
    bool PCBisFound = false;
    PCBisFound = readyQueue.removePCB(PCB);

    if(PCBisFound == false)
    {
        PCBisFound = suspendedReadyQueue.removePCB(PCB);
    }

    if(PCBisFound == false)
    {
        PCBisFound = blockedQueue.removePCB(PCB);
    }

    if(PCBisFound == false)
    {
        PCBisFound = suspendedBlockedQueue.removePCB(PCB);
    }
}


void PCB_Controller::freePCB(ProcessControlBlock* PCB){

    if(PCB != NULL){
        delete PCB;
        PCB = NULL;
    }
}

void PCB_Controller::deletePCB(){
    ProcessControlBlock* tempPCB = NULL;
    std::string processName;
    std::cout << std::endl << "Enter name of process to delete : ";
    std::cin >> processName;

    tempPCB = FindPCB(processName);
    if(tempPCB != NULL)
    {
        removePCB(tempPCB);
        freePCB(tempPCB);
        std::cout << "Successfully deleted " << processName << std::endl << std::endl;
    }
    else
    {
        std::cout << processName << " does not exist to delete." << std::endl << std::endl;
    }




}

void PCB_Controller::blockPCB(){
    ProcessControlBlock* tempPCB = NULL;
    std::string processName;
    std::cout << std::endl << "Enter name of process to block : ";
    std::cin >> processName;

    tempPCB = FindPCB(processName);
    if(tempPCB != NULL)
    {
        if(tempPCB->getRunState() != BLOCKED && tempPCB->getRunState() != SUSPENDED_BLOCKED){
            removePCB(tempPCB);

            //changes blocked state without changing suspended state
            if(tempPCB->getRunState() == READY)
            {
                tempPCB->setRunState(BLOCKED);
            }
            if(tempPCB->getRunState() == SUSPENDED_READY)
            {
                tempPCB->setRunState(SUSPENDED_BLOCKED);
            }

            insertPCB(tempPCB);

            std::cout << "Successfully blocked " << processName << std::endl << std::endl;
        }
        else{
            std::cout << processName << " already blocked." << std::endl << std::endl;
        }
    }
    else
    {
        std::cout << processName << " does not exist to block." << std::endl << std::endl;
    }
}


void PCB_Controller::unblockPCB(){
    ProcessControlBlock* tempPCB = NULL;
    std::string processName;
    std::cout << std::endl << "Enter name of process to unblock : ";
    std::cin >> processName;

    tempPCB = blockedQueue.FindPCB(processName);
    if(tempPCB == NULL){
        tempPCB = suspendedBlockedQueue.FindPCB(processName);
    }

    if(tempPCB != NULL)
    {
        if(tempPCB->getRunState() != READY && tempPCB->getRunState() != SUSPENDED_READY){
            removePCB(tempPCB);

            //changes blocked state without changing suspended state
            if(tempPCB->getRunState() == BLOCKED)
            {
                tempPCB->setRunState(READY);
            }
            if(tempPCB->getRunState() == SUSPENDED_BLOCKED)
            {
                tempPCB->setRunState(SUSPENDED_READY);
            }

            insertPCB(tempPCB);

            std::cout << "Successfully unblocked " << processName << std::endl << std::endl;
        }
        else{
            std::cout << processName << " not blocked." << std::endl << std::endl;
        }
    }
    else
    {
        std::cout << processName << " does not exist to unblock." << std::endl << std::endl;
    }
}

void PCB_Controller::suspendPCB(){
    ProcessControlBlock* tempPCB = NULL;
    std::string processName;
    std::cout << std::endl << "Enter name of process to suspend : ";
    std::cin >> processName;

    tempPCB = FindPCB(processName);
    if(tempPCB != NULL)
    {
        if(tempPCB->getRunState() != SUSPENDED_READY && tempPCB->getRunState() != SUSPENDED_BLOCKED){
            removePCB(tempPCB);

            //changes suspended state without changing blocked state
            if(tempPCB->getRunState() == READY)
            {
                tempPCB->setRunState(SUSPENDED_READY);
            }

            if(tempPCB->getRunState() == BLOCKED)
            {
                tempPCB->setRunState(SUSPENDED_BLOCKED);
            }

            insertPCB(tempPCB);

            std::cout << "Successfully suspended " << processName << std::endl << std::endl;
        }
        else{
            std::cout << processName << " already suspended." << std::endl << std::endl;
        }
    }
    else
    {
        std::cout << processName << " does not exist to suspend." << std::endl << std::endl;
    }
}


void PCB_Controller::resumePCB(){
    ProcessControlBlock* tempPCB = NULL;
    std::string processName;
    std::cout << std::endl << "Enter name of process to resume : ";
    std::cin >> processName;

    tempPCB = FindPCB(processName);
    if(tempPCB != NULL)
    {
        if(tempPCB->getRunState() != READY && tempPCB->getRunState() != BLOCKED){
            removePCB(tempPCB);

            //changes suspended state without changing blocked state
            if(tempPCB->getRunState() == SUSPENDED_READY)
            {
                tempPCB->setRunState(READY);
            }

            if(tempPCB->getRunState() == SUSPENDED_BLOCKED)
            {
                tempPCB->setRunState(BLOCKED);
            }

            insertPCB(tempPCB);

            std::cout << "Successfully resumed " << processName << std::endl << std::endl;
        }
        else{
            std::cout << processName << " not suspended." << std::endl << std::endl;
        }
    }
    else
    {
        std::cout << processName << " does not exist to resume." << std::endl << std::endl;
    }
}

void PCB_Controller::setPriority(){
    ProcessControlBlock* tempPCB = NULL;
    int tempPriority;
    std::string processName;
    std::cout << std::endl << "Enter name of process to assign new priority : ";
    std::cin >> processName;

    tempPCB = FindPCB(processName);

    if(tempPCB != NULL)
    {
        std::cout << "Priority : ";
        std::cin >> tempPriority;

        while(std::cin.fail() == true){
                std::cin.clear();
                //std::cin.ignore(100, '\n');
            std::cout <<  std::endl <<"Invalid value. Enter Priority : ";
            std::cin >> tempPriority;
        }

        if(tempPriority >= -127 && tempPriority <= 128)
        {
            tempPCB->setPriority(tempPriority);
            std::cout << processName << " now has a priority of " << tempPriority << std::endl << std::endl;
        }
        else{
            std::cout << std::endl << "Not a valid priority." << std::endl;
        }
    }
    else{
        std::cout << processName << " not found." << tempPriority << std::endl << std::endl;
    }
}

void PCB_Controller::showPCB(){
    ProcessControlBlock* tempPCB = NULL;
    std::string processName;
    std::cout << std::endl << "Enter name of process to show : ";
    std::cin >> processName;

    tempPCB = FindPCB(processName);

    if(tempPCB != NULL){
            tempPCB->printControlInfo(FULL_PRINT);
    }
    else
    {
        std::cout << std::endl << "Unable to locate " << processName << std::endl << std::endl;
    }
}

void PCB_Controller::showAllPCB(){
    std::cout << std::endl << "Ready" << std::endl << std::endl;
    readyQueue.printQueueContents(PARTIAL_PRINT);

    std::cout << std::endl << "Suspended Ready" << std::endl << std::endl;
    suspendedReadyQueue.printQueueContents(PARTIAL_PRINT);

    std::cout << std::endl << "Blocked" << std::endl << std::endl;
    blockedQueue.printQueueContents(PARTIAL_PRINT);

    std::cout << std::endl << "Suspended Blocked" << std::endl << std::endl;
    suspendedBlockedQueue.printQueueContents(PARTIAL_PRINT);
}

void PCB_Controller::showReady(){
    std::cout << std::endl << "Ready" << std::endl << std::endl;
    readyQueue.printQueueContents(PARTIAL_PRINT);

    std::cout << std::endl << "Suspended Ready" << std::endl << std::endl;
    suspendedReadyQueue.printQueueContents(PARTIAL_PRINT);
}

void PCB_Controller::showBlocked(){

    std::cout << std::endl << "Blocked" << std::endl << std::endl;
    blockedQueue.printQueueContents(PARTIAL_PRINT);

    std::cout << std::endl << "Suspended Blocked" << std::endl << std::endl;
    suspendedBlockedQueue.printQueueContents(PARTIAL_PRINT);
}

void PCB_Controller::testController(){

    for(int i = 0; i < 6; i++)
    {
        createPCB();
    }

    showAllPCB();


    for(int i = 0; i < 2; i++)
    {
        suspendPCB();
    }

    for(int i = 0; i < 2; i++)
    {
        resumePCB();
    }

    for(int i = 0; i < 2; i++)
    {
        blockPCB();
    }

    for(int i = 0; i < 2; i++)
    {
        unblockPCB();
    }

    for(int i = 0; i < 2; i++)
    {
        setPriority();
    }

    for(int i = 0; i < 4; i++)
    {
        deletePCB();
    }

    showAllPCB();
}

void PCB_Controller::testFileRead(){
    std::ifstream in;
    in.open("processes.txt");

    ProcessControlBlock* testPCB = NULL;
    if(in.is_open()){
        std::cout << "OPEN" << std::endl;
        testPCB = readPCBFile(in);

        if(testPCB == NULL)
        {
            std::cout << "NULL" << std::endl;
        }
        else{
            std::cout << testPCB->getProcessName() << std::endl;

            testPCB = readPCBFile(in);
            std::cout << testPCB->getProcessName() << std::endl;

        }

        in.close();
    }else
       std::cout << "NOT OPEN" << std::endl;
}

void PCB_Controller::shortestJobFirst(){
    std::ifstream in;
    std::string findFile;
    ProcessControlBlock* tempPCB = NULL;
    PCB_Queue tempQueue;
    bool processCompleted = true;
    totalTimeToCompletion = 0;
    totalTurnAroundTime = 0;
    totalCompletedPCBs = 0;
    executionTime = 0;

    std::cout << "Please enter a process file to load : ";
    std::cin >> findFile;

    in.open(findFile.c_str());

    if(in.is_open()){
        while(!in.eof()){
            tempPCB = readPCBFile(in);
            if(in.eof()){
                break;
            }

            if(tempPCB != NULL){
                //logic on how to handle the PCBs read in
                tempQueue.insertNode(tempPCB);
            }

        }
        tempPCB = NULL;

        while(tempQueue.isEmpty() != true){
            tempPCB = tempQueue.getLowestTimeRemaining();
            //move PCBs to the ready queue in time remaining order
            if(tempPCB != NULL){

                tempQueue.removePCB(tempPCB);
                readyQueue.insertNode(tempPCB);
            }
            tempPCB = NULL;
        }
        in.close();

        //prints the ready queue
        readyQueue.printQueueContents(TIME_REMAINING);


        //reset processName vector to size zero
        processNames.resize(0);

        //record names as you pop, and the command controller should list these names in order ran

        while(!readyQueue.isEmpty()){
            //represents pushing to running, but this is where you would handle running processes
            tempPCB = readyQueue.popNode();
            if(tempPCB != NULL){
                //grabs and totals time until completion
                tempPCB->setRunState(RUNNING);
                runningQueue.insertNode(tempPCB);


                while(!runningQueue.isEmpty()){
                    totalTimeToCompletion++;
                    processCompleted = runningQueue.runUntilComplete();

                    if(processCompleted == true){
                        tempPCB = runningQueue.popNode();
                        processNames.push_back(tempPCB->getProcessName());
                        totalCompletedPCBs++;
                    }

                }

            }
        }

            //in full knowledge SJF Scheduler, totalCompletionTime will equal totalTurnAround time
            totalTurnAroundTime = totalTimeToCompletion;
    }else
       std::cout << std::endl << "Unable to locate file." << std::endl << std::endl;
}

std::vector<std::string>& PCB_Controller::getProcessNames(){
    return processNames;
}


//call this function from within schedulers. Requires you to open/close the file
//but should allow you to read PCBs in a suitable form
ProcessControlBlock* PCB_Controller::readPCBFile(std::ifstream& in){
    ProcessControlBlock* tempPCB = AllocatePCB();
    std::string getName;
    char getClass;
    int getValue;
    ProcessClass processClass;

    if(tempPCB != NULL)
    {
        //Will grab the process name, class, and priority and setup before handling other fields
        in >> getName;
        in >> getClass;
        in >> getValue;
        if(getClass == 'A'){
            processClass = APPLICATION;
        }
        if(getClass == 'B'){
            processClass = SYSTEM;
        }
        tempPCB->setupPCB(getName, getValue, processClass);

        //grabs and sets memory
        in >> getValue;
        tempPCB->setMemory(getValue);

        //grabs and sets time remaining
        in >> getValue;
        tempPCB->setTimeRemaining(getValue);

        //grabs and sets time on arrival
        in >> getValue;
        tempPCB->setTimeOfArrival(getValue);

        //grabs and sets cpu %
        in >> getValue;
        tempPCB->setPercentOfCPU(getValue);
        tempPCB->setRunState(READY);
    }
    return tempPCB;
}

int PCB_Controller::getCompletedPCBs(){
    return totalCompletedPCBs;
}

int PCB_Controller::getCompletionTime(){
    return totalTimeToCompletion;
}

int PCB_Controller::getTotalTurnAround(){
    return totalTurnAroundTime;
}
