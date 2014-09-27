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
    ProcessControlBlock* getLowestTimeRemaining(int currentProcessTime);
    ProcessControlBlock* getHighestPriority();
    ProcessControlBlock* getHighestPriority(int currentProcessTime);
    ProcessControlBlock* getLotteryWinner(int currentProcessTime, int lottery);

    ProcessControlBlock* getEarliestArrival();


    bool removePCB(ProcessControlBlock* PCB);
    void testQueue();
    void printQueueContents(PrintMode);
    bool isEmpty();
    int getNumNodes();
    bool runUntilComplete();

    int getTimeRemaining();
    int getPriority();
    void boostPriority(int);

    std::string getProcessName();


    ProcessControlBlock* FindPCB(std::string);


private:
    PCB_Node* head;
    PCB_Node* tail;
    int numberOfNodes;

};

#endif // PCB_QUEUE
