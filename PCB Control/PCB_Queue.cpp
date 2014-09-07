#include "PCB_Queue.h"
#include "PCB_Node.h"
#include "ProcessControlBlock.h"
#include <iostream>

PCB_Queue::PCB_Queue(){
    head = NULL;
    tail = NULL;
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
        }
        else{
            head = NULL;
            tail = head;
        }
        tempPCB = tempNode->getPCB();
        delete tempNode;
        tempNode = NULL;
        return tempPCB;
    }
    else
        return NULL;
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

                                //exits the loop if found
                                tempNode = NULL;
                                PCBisFound = true;
                            }
                            else{
                                //This case is if the process is found at the tail node
                                placeholder->setNext(NULL);
                                tail = placeholder;
                                delete tempNode;
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

    printQueueContents();

    removePCB(tempThree);

    std::cout << std::endl << "Removing test 3 from queue" << std::endl;
    std::cout << std::endl;
    printQueueContents();

    removePCB(tempOne);

    std::cout << std::endl << "Removing test 1 from queue" << std::endl;
    std::cout << std::endl;
    printQueueContents();

    removePCB(tempFive);

    std::cout << std::endl << "Removing test 5 from queue" << std::endl;
    std::cout << std::endl;
    printQueueContents();

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


void PCB_Queue::printQueueContents(){
    PCB_Node* tempNode;

    std::cout << "Name/State/Priority" << std::endl;
    if(head != NULL)
    {
        tempNode = head;
        while(tempNode != tail){
            tempNode->printPCBInfo(PARTIAL_PRINT);
            tempNode = tempNode->getNext();
        }
        tempNode->printPCBInfo(PARTIAL_PRINT);
    }
}
