#ifndef PCB_QUEUE
#define PCB_QUEUE

#include <string>


class PCB_Node;
class ProcessControlBlock;

class PCB_Queue{
public:
    PCB_Queue();
    ~PCB_Queue();

    void insertNode(ProcessControlBlock*);
    ProcessControlBlock* popNode();

    bool removePCB(ProcessControlBlock* PCB);
    void testQueue();
    void printQueueContents();
    ProcessControlBlock* FindPCB(std::string);

private:
    PCB_Node* head;
    PCB_Node* tail;
    int numberOfNodes;
};

#endif // PCB_QUEUE
