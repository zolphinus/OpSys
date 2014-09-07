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

PCB_Node* PCB_Queue::popNode(){

    PCB_Node* tempNode = NULL;
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
        return tempNode;
    }
    else
        return NULL;
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
