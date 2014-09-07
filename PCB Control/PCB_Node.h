#ifndef PCB_NODE
#define PCB_NODE

#include <string>
#include "ProcessControlEnums.h"

class ProcessControlBlock;

class PCB_Node{
    public:
    PCB_Node();
    PCB_Node(ProcessControlBlock*);


    ProcessControlBlock* getPCB();
    std::string getProcessName();
    RunState getRunState();
    PCB_Node* getNext();
    PCB_Node* getPrior();
    void setNext(PCB_Node*);
    void setPrior(PCB_Node*);


    ProcessControlBlock* AllocatePCB();
    void freePCB();
    void setupPCB(std::string name, int priority, ProcessClass newClass);
    void printPCBInfo(PrintMode printMode);

    void testNode();

private:
    PCB_Node* nextNode;
    PCB_Node* priorNode;
    ProcessControlBlock* PCB;

};

#endif // PCB_NODE
