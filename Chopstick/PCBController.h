#ifndef PCB_CONTROLLER
#define PCB_CONTROLLER

#include "PCB_Queue.h"
#include <string>
#include <istream>
#include <vector>

class ProcessControlBlock;

class PCB_Controller{
public:
    PCB_Controller();
    ~PCB_Controller();

    void testController();
    void testFileRead();

    void createPCB();
    void deletePCB();
    void blockPCB();
    void unblockPCB();
    void suspendPCB();
    void resumePCB();
    void setPriority();
    void showPCB();
    void showAllPCB();
    void showReady();
    void showBlocked();
    ProcessControlBlock* readPCBFile(std::ifstream& in);
    std::vector<std::string>& getProcessNames();

    int getCompletionTime();
    int getTotalTurnAround();
    int getCompletedPCBs();

    //Schedulers
    bool sjfFullKnowledge();
    bool incompleteFIFO();
    bool incompleteSJF();
    bool incompleteFPPS();
    bool incompleteRoundRobin();
    bool incompleteMLFQ();
    bool incompleteLottery();


private:
    PCB_Queue readyQueue;
    PCB_Queue suspendedReadyQueue;
    PCB_Queue blockedQueue;
    PCB_Queue suspendedBlockedQueue;
    PCB_Queue runningQueue;
    int totalTimeToCompletion;
    int totalTurnAroundTime;
    int totalCompletedPCBs;
    int executionTime;
    int turnAroundTime;


    std::vector<std::string> processNames;

    ProcessControlBlock* AllocatePCB();
    ProcessControlBlock* FindPCB(std::string);
    void insertPCB(ProcessControlBlock* PCB);

    void removePCB(ProcessControlBlock* PCB);
    void freePCB(ProcessControlBlock* PCB);

};


#endif // PCB_CONTROLLER
