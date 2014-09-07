#include "ProcessControlBlock.h"
#include "PCB_Node.h"
#include "PCB_Queue.h"
#include "PCBController.h"

void testPCB();
void testNode();
void testQueue();
void testController();

int main(){
    //testPCB();
    //testNode();
    //testQueue();
    testController();

    return 0;
}


void testPCB(){
    ProcessControlBlock testBlock;
    testBlock.testControlBlock();
}


void testNode(){
    PCB_Node testNode;
    testNode.testNode();
}

void testQueue(){
    PCB_Queue testQueue;

    testQueue.testQueue();
}

void testController(){
    PCB_Controller testController;
    testController.testController();
}
