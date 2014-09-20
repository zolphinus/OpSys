#ifndef PCB_QUEUE
#define PCB_QUEUE

#include <string>
#include "ProcessControlEnums.h"

class PCB_Node;
class ProcessControlBlock;

class PCB_Queue{
public:
    PCB_Queue();
    ~PCB_Queue();

    void insertNode(ProcessControlBlock*);

    ProcessControlBlock* popNode();
    ProcessControlBlock* getLowestTimeRemaining();

    bool removePCB(ProcessControlBlock* PCB);
    void testQueue();
    void printQueueContents(PrintMode);
    bool isEmpty();
    int getNumNodes();
    bool runUntilComplete();


    ProcessControlBlock* FindPCB(std::string);


private:
    PCB_Node* head;
    PCB_Node* tail;
    int numberOfNodes;

};

#endif // PCB_QUEUE
