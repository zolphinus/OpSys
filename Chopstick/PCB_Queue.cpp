#include "PCB_Queue.h"
#include "PCB_Node.h"
#include "ProcessControlBlock.h"
#include <iostream>
#include <limits.h>

PCB_Queue::PCB_Queue(){
    head = NULL;
    tail = NULL;
    numberOfNodes = 0;
}

PCB_Queue::~PCB_Queue(){
    PCB_Node* tempNode;
    if(head != NULL)
    {
        tempNode = head;

        while(tempNode != tail)
        {
            head = head->getNext();
            delete tempNode;
            tempNode = head;
        }

        delete head;
        head = NULL;
        tail = NULL;
    }

}

void PCB_Queue::insertNode(ProcessControlBlock* PCB){
    //inserts at end of list
    PCB_Node* nodeToInsert = new PCB_Node(PCB);

    PCB_Node* iterateNode = NULL;
    if(head == NULL)
    {
        head = nodeToInsert;
        head->setPrior(NULL);
        head->setNext(NULL);
        tail = head;
        numberOfNodes++;
    }
    else{
        iterateNode = head;


        while(iterateNode->getNext() != NULL){
            //As long as there is a subsequent node, travels the list
            iterateNode = iterateNode->getNext();
        }

        iterateNode->setNext(nodeToInsert);

        nodeToInsert->setPrior(iterateNode);
        nodeToInsert->setNext(NULL);

        tail = nodeToInsert;
        numberOfNodes++;
    }
}

ProcessControlBlock* PCB_Queue::popNode(){

    PCB_Node* tempNode = NULL;
    ProcessControlBlock* tempPCB = NULL;

    if(head != NULL)
    {
        tempNode = head;
        if(head->getNext() != NULL)
        {
            head = head->getNext();
            head->setPrior(NULL);
            numberOfNodes--;
        }
        else{
            head = NULL;
            tail = head;
            numberOfNodes--;
        }
        tempPCB = tempNode->getPCB();
        delete tempNode;
        tempNode = NULL;
        return tempPCB;
        numberOfNodes--;
    }
    else{
        return NULL;
    }
}


bool PCB_Queue::removePCB(ProcessControlBlock* PCB){
    PCB_Node* tempNode = head;
    PCB_Node* placeholder = tempNode;
    bool PCBisFound = false;


    if(head != NULL){
        if(head->getNext() != NULL){
            while(tempNode != NULL){

                if(tempNode->getPCB() == PCB)
                {
                    //the PCB was found, removes node and pcb from the queue
                    if(tempNode->getPCB() == placeholder->getPCB()){
                        //This case should only be true at the head node, if it points somewhere
                        tempNode = tempNode->getNext();
                        tempNode->setPrior(placeholder->getPrior());
                        delete placeholder;
                        numberOfNodes--;

                        head = tempNode;

                        //exits the loop if the process is head process and found
                        tempNode = NULL;
                        PCBisFound = true;
                    }
                    else{
                        //This case is if the process is found but not the head node
                        if(tempNode->getPCB() == PCB)
                        {
                            if(tempNode->getNext() != NULL){
                                //points to next node in queue
                                placeholder->setNext(tempNode->getNext());

                                //sets the next node to point to the last known not removed
                                tempNode->getNext()->setPrior(placeholder);
                                delete tempNode;
                                numberOfNodes--;

                                //exits the loop if found
                                tempNode = NULL;
                                PCBisFound = true;
                            }
                            else{
                                //This case is if the process is found at the tail node
                                placeholder->setNext(NULL);
                                tail = placeholder;
                                delete tempNode;
                                numberOfNodes--;
                                tempNode = NULL;

                                PCBisFound = true;

                            }

                        }

                    }

                }
                else{
                    //the PCB wasn't found, iterates to next node
                    placeholder = tempNode;
                    tempNode = tempNode->getNext();
                }
            }
        }
        else{
            if(head->getPCB() == PCB)
            {
                delete head;
                head = NULL;
                tail = head;
                numberOfNodes--;
            }
        }
    }

    return PCBisFound;
}


void PCB_Queue::testQueue(){
    ProcessControlBlock* tempOne = new ProcessControlBlock();
    ProcessControlBlock* tempTwo = new ProcessControlBlock();
    ProcessControlBlock* tempThree = new ProcessControlBlock();
    ProcessControlBlock* tempFour = new ProcessControlBlock();
    ProcessControlBlock* tempFive = new ProcessControlBlock();

    tempOne->setupPCB("Test1", 25, APPLICATION);
    tempTwo->setupPCB("Test2", 35, SYSTEM);
    tempThree->setupPCB("Test3", 45, SYSTEM);
    tempFour->setupPCB("Test4", 55, SYSTEM);
    tempFive->setupPCB("Test5", 65, SYSTEM);


    insertNode(tempOne);
    insertNode(tempTwo);
    insertNode(tempThree);
    insertNode(tempFour);
    insertNode(tempFive);

    printQueueContents(PARTIAL_PRINT);

    removePCB(tempThree);

    std::cout << std::endl << "Removing test 3 from queue" << std::endl;
    std::cout << std::endl;
    printQueueContents(PARTIAL_PRINT);

    removePCB(tempOne);

    std::cout << std::endl << "Removing test 1 from queue" << std::endl;
    std::cout << std::endl;
    printQueueContents(PARTIAL_PRINT);

    removePCB(tempFive);

    std::cout << std::endl << "Removing test 5 from queue" << std::endl;
    std::cout << std::endl;
    printQueueContents(PARTIAL_PRINT);

    tempOne = NULL;
    tempTwo = NULL;
    tempThree = NULL;
    tempFour = NULL;
    tempFive = NULL;
}

ProcessControlBlock* PCB_Queue::FindPCB(std::string processToFind){
    bool isFound = false;
    PCB_Node* tempNode = head;
    if(head != NULL)
    {
        while(isFound == false && tempNode != NULL)
        {
            if(tempNode->getProcessName() == processToFind){
                return tempNode->getPCB();
            }
            tempNode = tempNode->getNext();
        }
    }

    return NULL;
}

//add print mode as parameter
void PCB_Queue::printQueueContents(PrintMode printMode){
    PCB_Node* tempNode;


    //Setup if statements based on printMode

    if(printMode == PARTIAL_PRINT){
        std::cout << std::endl << "Name/State/Priority" << std::endl;
    }
    if(printMode == TIME_REMAINING){
        std::cout << std::endl << "Name/Time Remaining" << std::endl;
    }

    //scroll array, but using the print mode instead of a set print
    if(head != NULL)
    {
        tempNode = head;
        while(tempNode != tail){
            tempNode->printPCBInfo(printMode);
            tempNode = tempNode->getNext();
        }
        //prints tail
        tempNode->printPCBInfo(printMode);
    }
}

bool PCB_Queue::isEmpty(){
    if(numberOfNodes == 0)
        return true;
    else
        return false;
}


ProcessControlBlock* PCB_Queue::getEarliestArrival(){
    int earliestArrivalTime = INT_MAX;
    PCB_Node* tempNode = head;
    PCB_Node* earliestArrival = NULL;

    if(tempNode != NULL){
        while(tempNode != NULL){
            if(tempNode->getPCB()->getTimeOfArrival() < earliestArrivalTime){
                earliestArrivalTime = tempNode->getPCB()->getTimeOfArrival();
                earliestArrival = tempNode;
            }

                tempNode = tempNode->getNext();

        }
        return earliestArrival->getPCB();
    }

    return NULL;
}

ProcessControlBlock* PCB_Queue::getLowestTimeRemaining(){
    int lowestTime = INT_MAX;
    PCB_Node* tempNode = head;
    PCB_Node* lowestRemaining = NULL;

    if(tempNode != NULL){
        while(tempNode != NULL){
            if(tempNode->getPCB()->getTimeRemaining() < lowestTime){
                lowestTime = tempNode->getPCB()->getTimeRemaining();
                lowestRemaining = tempNode;
            }

                tempNode = tempNode->getNext();

        }
        return lowestRemaining->getPCB();
    }

    return NULL;
}


ProcessControlBlock* PCB_Queue::getHighestPriority(){
    int highestPriority = -128;
    PCB_Node* tempNode = head;
    PCB_Node* mostUrgent = NULL;

    if(tempNode != NULL){
        while(tempNode != NULL){
            if(tempNode->getPCB()->getPriority() > highestPriority){
                highestPriority = tempNode->getPCB()->getPriority();
                mostUrgent = tempNode;
            }

                tempNode = tempNode->getNext();

        }
        return mostUrgent->getPCB();
    }

    return NULL;
}


//used for FPPS
int PCB_Queue::getTimeRemaining(){
    if(head != NULL)
    {
        return head->getPCB()->getTimeRemaining();
    }

    return INT_MAX;
}

std::string PCB_Queue::getProcessName(){
    if(head != NULL)
    {
        return head->getPCB()->getProcessName();
    }

    return "NULL PROCESS";
}



int PCB_Queue::getPriority(){
    if(head != NULL)
    {
        return head->getPCB()->getPriority();
    }

    return -128;
}


//should only return the shortest job process that has "arrived"
ProcessControlBlock* PCB_Queue::getLowestTimeRemaining(int currentProcessTime){
    int lowestTime = INT_MAX;
    PCB_Node* tempNode = head;
    PCB_Node* lowestRemaining = NULL;


    if(tempNode != NULL){
        while(tempNode != NULL){
            if(tempNode->getPCB()->getTimeRemaining() < lowestTime &&
               tempNode->getPCB()->getTimeOfArrival() <= currentProcessTime){
                lowestTime = tempNode->getPCB()->getTimeRemaining();
                lowestRemaining = tempNode;
            }
                tempNode = tempNode->getNext();
        }
        if(lowestRemaining != NULL){
            return lowestRemaining->getPCB();
        }else{
            return NULL;
        }
    }
    return NULL;
}


//should only return the highest priority process that has "arrived"
ProcessControlBlock* PCB_Queue::getHighestPriority(int currentProcessTime){
    int highestPriority = -128;
    PCB_Node* tempNode = head;
    PCB_Node* mostUrgent = NULL;


    if(tempNode != NULL){
        while(tempNode != NULL){
            if(tempNode->getPCB()->getPriority() > highestPriority &&
               tempNode->getPCB()->getTimeOfArrival() <= currentProcessTime){
                highestPriority = tempNode->getPCB()->getPriority();
                mostUrgent = tempNode;
            }
                tempNode = tempNode->getNext();
        }
        if(mostUrgent != NULL){
            return mostUrgent->getPCB();
        }else{
            return NULL;
        }
    }
    return NULL;
}




bool PCB_Queue::runUntilComplete(){
    if(head != NULL){
        head->getPCB()->run();
    }

    if(head->getPCB()->getTimeRemaining() == 0){
        return true;
    }

    return false;
}


int PCB_Queue::getNumNodes(){
    return numberOfNodes;
}
