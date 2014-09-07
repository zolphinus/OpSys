#include "PCBController.h"
#include "ProcessControlBlock.h"
#include "ProcessControlEnums.h"
#include <iostream>

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
            std::cout << std::endl << "The process is already running or the parameters are not valid" <<
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


void PCB_Controller::testController(){

    for(int i = 0; i < 6; i++)
    {
        createPCB();
    }

    std::cout << std::endl << "ReadyQueue" << std::endl;
    readyQueue.printQueueContents();
}
