#ifndef PROCESS_CONTROL_BLOCK
#define PROCESS_CONTROL_BLOCK

#include "ProcessControlEnums.h"
#include <string>

class ProcessControlBlock{
public:
    ProcessControlBlock();
    std::string getProcessName();
    ProcessClass getProcessClass();
    RunState getRunState();
    int getPriority();
    int getMemory();
    int getTimeRemaining();
    int getTimeOfArrival();
    int getPercentOfCPU();
    int getTurnAround();

    void setupPCB(std::string, int, ProcessClass);
    void setRunState(RunState);
    void printControlInfo(PrintMode);
    void setPriority(int);
    void setMemory(int);
    void setTimeRemaining(int);
    void setTimeOfArrival(int);
    void setPercentOfCPU(int);
    void lowerPriority();



    void testControlBlock();
    void run();
    void calculateTurnAround(int completionTime);

private:
    std::string processName;
    ProcessClass processClass;
    int priority;
    RunState runState;
    int memory;
    int timeRemaining;
    int timeOfArrival;
    int percentOfCPU;
    int turnAround;
};


#endif // PROCESS_CONTROL_BLOCK
