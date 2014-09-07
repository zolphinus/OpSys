#include "PCB_Node.h"
#include "ProcessControlBlock.h"
#include "ProcessControlEnums.h"
#include <exception>
#include <iostream>

PCB_Node::PCB_Node(){
    nextNode = NULL;
    priorNode = NULL;
    PCB = AllocatePCB();
}

PCB_Node::PCB_Node(ProcessControlBlock* newPCB){
    nextNode = NULL;
    priorNode = NULL;
    PCB = newPCB;
}

ProcessControlBlock* PCB_Node::getPCB(){
    return PCB;
}

std::string PCB_Node::getProcessName(){
    if(PCB != NULL)
    {
        return PCB->getProcessName();
    }
    else
        return "PCB IS NULL";
}

PCB_Node* PCB_Node::getNext(){
    return nextNode;
}

PCB_Node* PCB_Node::getPrior(){
    return priorNode;
}

ProcessControlBlock* PCB_Node::AllocatePCB(){
    ProcessControlBlock* tempPCB;

    try{
        tempPCB = new ProcessControlBlock();
    }
    catch (std::exception& e){
        tempPCB = NULL;
    }

    return tempPCB;
}

void PCB_Node::freePCB(){
    if(PCB != NULL)
    {
        delete PCB;
    }
}

void PCB_Node::setupPCB(std::string name, int priority, ProcessClass newClass){
    PCB->setupPCB(name, priority, newClass);
}

void PCB_Node::testNode(){

    if(PCB != NULL)
    {
        setupPCB("Node Test", 999, APPLICATION);
        PCB->setRunState(BLOCKED);
        PCB->printControlInfo(FULL_PRINT);
        std::cout << "Memory Location : " << PCB << std::endl;
    }
    else
    {
        std::cout << "PCB didn't allocate properly" << std::endl << std::endl;
    }
}



void PCB_Node::setNext(PCB_Node* newNext){
    nextNode = newNext;
}

void PCB_Node::setPrior(PCB_Node* newPrior){
    priorNode = newPrior;
}


void PCB_Node::printPCBInfo(PrintMode printMode){
    if(PCB != NULL){
        PCB->printControlInfo(printMode);
    }
}
