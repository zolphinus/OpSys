#include "MemoryManager.h"
#include "DataStruct.h"

MemoryManager::MemoryManager(){
    //creates a block of free memory equal to the default amount
    head = new MemoryNode(DEFAULT_MEMORY);
    lastChecked = head;

    //provides a default memory mode in case of errors in selection
    memoryMode = MEMORY_MODE_ERROR;
}

void MemoryManager::coalesce(){
    MemoryNode* travel = head;
    MemoryNode* placeHolder = travel;

    //should always have one node, so at worst, travel equals NULL
    travel = travel->next;

    //and if travel is NULL, skips the coalesce as this means there is only free memory or there is zero free memory
    while(travel != NULL){
        //both nodes should be different. If both are free memory, combines them
        if(travel->isFree == TRUE && placeHolder->isFree == TRUE){
            placeHolder->memoryUsed += travel->memoryUsed;
            placeHolder->next = travel->next;
            placeHolder = travel;
            travel = travel->next;
            delete placeHolder;
        }

        placeHolder = travel;
        //checks that travel didn't reach the end early
        if(travel != NULL){
            travel = travel->next;
    }

    lastChecked = head;
}

void MemoryManager::compact(){
    MemoryNode* travel = head;
    MemoryNode* newMemoryList = NULL;
    //used for deleting old free nodes
    MemoryNode* markedNode = NULL;
    int freeMemory = 0;

    //totals the amount of free memory
    while(travel != NULL){
        if(travel->isFree == TRUE){
            freeMemory += travel->memoryUsed;
        }
    }

    travel = head;

    //if there is no free memory, cannot compact
    if(freeMemory > 0){
        //creates a new list that starts with free memory
        newMemoryList = new MemoryNode(freeMemory);

        //head now controls new list, so we can use newMemoryList as an iterator
        head = newMemoryList;

        while(travel != NULL){
            if(travel->isFree == TRUE){
                markedNode = travel;
                travel = travel->next;
                delete markedNode;
                markedNode = NULL;
            }else{
                //if travel is not free, attaches to memory list
                newMemoryList->next = travel;

                //advances travel node to next node to check
                travel = travel->next;

                //advances newMemory to the end and terminates the list
                newMemoryList = newMemoryList->next;
                newMemoryList->next = NULL;

            }
        }
    }
    lastChecked = head;
}


void coalesce(std::ofstream& out){
    printMemory(out);
    out << std::endl << "COALESCING" << std::endl;
    coalesce();
    printMemory();
}

void compact(std::ofstream& out){
    printMemory(out);
    out << std::endl << "COMPACTING" << std::endl;
    compact();
    printMemory(out);
}

void MemoryManager::printMemory(std::ofstream& out){
    MemoryNode* temp = head;
    out << std::endl << "MEMORY CONTENTS" << std::endl;
    while(temp != NULL){
        temp->printDetails(out);
    }
}



void MemoryManager::freeMemory(ProcessControlBlock* pcb){
    MemoryNode* travel = head;
    while(travel != NULL){
        travel->freeMemory(pcb);
    }
}


void MemoryManager::promptMemoryMode(){
    char selector;
    std::cout << "Which memory mode will the scheduler use?" << std::endl;
    std::cout << "A) First Fit" << std::endl;
    std::cout << "B) Next Fit" << std::endl;
    std::cout << "C) Best Fit" << std::endl;
    std::cout << "D) Worst Fit" << std::endl;

    while(selector < 'A' && selector > 'D'){
        std::cout << std::endl << "Please select a memory mode : ";
        std::cin >> selector;
        selector = toupper(selector);
    }

    switch(selector){
    case 'A':
        memoryMode = FIRST_FIT;
        break;
    case 'B':
        memoryMode = NEXT_FIT;
        break;
    case 'C':
        memoryMode = BEST_FIT;
        break;
    case 'D':
        memoryMode = WORST_FIT;
        break;
    default:
        memoryMode = MEMORY_MODE_ERROR;

    }
}


//used by the schedulers to determine if a process should run
bool MemoryManager::fitPCB(ProcessControlBlock* pcb, std::ofstream& out){
    bool fitSuccessful = false;

    //attempts to fit memory based on the selected memory mode
    //allows each scheduler to use memory with a generic function
    //which can then be used for expanding memory algorithms
    switch(memoryMode){
    case FIRST_FIT:
        fitSuccessful = firstFit(pcb, out);
        break;
    case NEXT_FIT:
        fitSuccessful = nextFit(pcb, out);
        break;
    case BEST_FIT:
        fitSuccessful = bestFit(pcb, out);
        break;
    case WORST_FIT:
        fitSuccessful = worstFit(pcb, out);
        break;
    default:
        std::cout << "memory error" << std::endl;
    }

    return fitSuccessful;
}


bool firstFit(ProcessControlBlock* pcb, std::ofstream& out){
    return false;
}


bool nextFit(ProcessControlBlock* pcb, std::ofstream& out){
    return false;
}


bool bestFit(ProcessControlBlock* pcb, std::ofstream& out){
    return false;
}

bool worstFit(ProcessControlBlock* pcb, std::ofstream& out){
    return false;
}
