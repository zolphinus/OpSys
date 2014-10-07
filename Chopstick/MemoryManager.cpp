#include "MemoryManager.h"
#include "DataStruct.h"
#include <iostream>

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
        if(travel->isFree == true && placeHolder->isFree == true){
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
}


void MemoryManager::compact(){
    MemoryNode* travel = head;
    MemoryNode* newMemoryList = NULL;
    //used for deleting old free nodes
    MemoryNode* markedNode = NULL;
    int freeMemory = 0;

    //totals the amount of free memory
    while(travel != NULL){
        if(travel->isFree == true){
            freeMemory += travel->memoryUsed;
        }
        travel = travel->next;
    }

    travel = head;

    //if there is no free memory, cannot compact
    if(freeMemory > 0){
        //creates a new list that starts with free memory
        newMemoryList = new MemoryNode(freeMemory);

        //head now controls new list, so we can use newMemoryList as an iterator
        head = newMemoryList;

        while(travel != NULL){
            if(travel->isFree == true){
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


void MemoryManager::coalesce(std::fstream& out){
    printMemory(out);
    out << std::endl << "COALESCING" << std::endl;
    coalesce();
    printMemory(out);
}

void MemoryManager::compact(std::fstream& out){
    printMemory(out);
    out << std::endl << "COMPACTING" << std::endl;
    compact();
    printMemory(out);
}

void MemoryManager::printMemory(std::fstream& out){
    MemoryNode* temp = head;
    out << std::endl << "MEMORY CONTENTS" << std::endl;
    while(temp != NULL){
        temp->printDetails(out);
        temp = temp->next;
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
    bool validSelection = false;
    std::cout << "Which memory mode will the scheduler use?" << std::endl;
    std::cout << "A) First Fit" << std::endl;
    std::cout << "B) Next Fit" << std::endl;
    std::cout << "C) Best Fit" << std::endl;
    std::cout << "D) Worst Fit" << std::endl;

    while(validSelection == false){
        std::cout << std::endl << "Please select a memory mode : ";
        std::cin >> selector;
        selector = toupper(selector);

        switch(selector){
        case 'A': case 'B' : case 'C' : case 'D':
            validSelection = true;
            break;
        default:
            std::cout << selector << std::endl;
        }
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
bool MemoryManager::fitPCB(ProcessControlBlock* pcb, std::fstream& out){
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


bool MemoryManager::firstFit(ProcessControlBlock* pcb, std::fstream& out){
    bool isSuccessful = false;
    MemoryNode* travel = head;
    MemoryNode* placeHolder = travel;

    if(travel != NULL){
            //tries to fit, then coalesces if needed and tries again, then compacts then tries again
            for(int numAttempts = 0; numAttempts < 3; numAttempts++){
                //resets the attempt
                travel = head;
                placeHolder = travel;

                while(travel != NULL){
                    if(travel->isFree == true){
                        //only cares about free memory
                        if(travel == head){
                            //if first free slot is at beginning
                            if(pcb->getMemory() <= travel->memoryUsed){
                                //if there is enough free memory in one chunk
                                head = new MemoryNode(pcb);
                                head->next = travel;
                                //subtracts the memory taken from the free node
                                travel->memoryUsed = travel->memoryUsed - pcb->getMemory();
                                travel = head;

                                //process inserted successfully, breaks
                                isSuccessful = true;
                                break;
                            }
                        }else{
                            //if first free slot is not at beginning
                            if(pcb->getMemory() <= travel->memoryUsed){
                                //if there is enough free memory in one chunk

                                placeHolder->next = new MemoryNode(pcb);

                                //subtracts the memory taken from the free node
                                travel->memoryUsed = travel->memoryUsed - pcb->getMemory();
                                if(travel->memoryUsed > 0){
                                    //the free node still has memory
                                    placeHolder = placeHolder->next;
                                    placeHolder->next = travel;
                                }else{
                                    placeHolder = placeHolder->next;
                                    placeHolder->next = travel->next;
                                    delete travel;
                                    travel = placeHolder;
                                }

                                //process inserted successfully, breaks
                                isSuccessful = true;
                                break;


                            }
                        }
                    }


                    placeHolder = travel;
                    if(travel != NULL){
                        travel = travel->next;
                    }
                }



                if(isSuccessful == true){
                    break;
                }

                if(numAttempts == 0){
                    coalesce(out);
                }

                if(numAttempts == 1){
                    compact(out);
                }
            }
    }


    return isSuccessful;
}


bool MemoryManager::nextFit(ProcessControlBlock* pcb, std::fstream& out){
    return false;
}


bool MemoryManager::bestFit(ProcessControlBlock* pcb, std::fstream& out){
    return false;
}

bool MemoryManager::worstFit(ProcessControlBlock* pcb, std::fstream& out){
    return false;
}
