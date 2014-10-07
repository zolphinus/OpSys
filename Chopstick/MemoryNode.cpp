#include "MemoryNode.h"
#include "ProcessControlBlock.h"
#include <fstream>

#include <iostream>


//constructor used for creating a free node
MemoryNode::MemoryNode(int memoryUsed){
    this->memoryUsed = memoryUsed;
    processName = "FREE";
    isFree = true;
    next = NULL;
}

MemoryNode::MemoryNode(ProcessControlBlock* pcb){
    this->memoryUsed = pcb->getMemory();
    processName = pcb->getProcessName();
    isFree = false;
    next = NULL;
}


void MemoryNode::freeMemory(ProcessControlBlock* pcb){
    if(pcb->getProcessName() == this->processName){
        isFree = true;
        this->processName = "FREE";
    }
}

void MemoryNode::printDetails(std::fstream& out){
    //writes details of the node into the appropriate information file
    out << this->processName << "   Memory Used: " << this->memoryUsed << '\n';
}
