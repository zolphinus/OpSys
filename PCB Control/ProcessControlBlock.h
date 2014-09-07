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

    void setupPCB(std::string, int, ProcessClass);
    void setRunState(RunState);
    void testControlBlock();
    void printControlInfo(PrintMode);

private:
    std::string processName;
    ProcessClass processClass;
    int priority;
    RunState runState;
    int memory;

};


#endif // PROCESS_CONTROL_BLOCK
