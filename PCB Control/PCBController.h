#ifndef PCB_CONTROLLER
#define PCB_CONTROLLER

#include "PCB_Queue.h"
#include <string>

class ProcessControlBlock;

class PCB_Controller{
public:
    PCB_Controller();
    ~PCB_Controller();

    void testController();
    void createPCB();

private:
    PCB_Queue readyQueue;
    PCB_Queue suspendedReadyQueue;
    PCB_Queue blockedQueue;
    PCB_Queue suspendedBlockedQueue;

    ProcessControlBlock* AllocatePCB();
    ProcessControlBlock* FindPCB(std::string);
    void insertPCB(ProcessControlBlock* PCB);

    void removePCB(ProcessControlBlock* PCB);
    void freePCB(ProcessControlBlock* PCB);



};


#endif // PCB_CONTROLLER
