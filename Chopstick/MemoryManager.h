#ifndef MEMORY_MANAGER
#define MEMORY_MANAGER
#include "MemoryNode.h"
#include <fstream>
#include "ProcessControlBlock.h"
#include "DataStruct.h"

#define DEFAULT_MEMORY 1024

class MemoryManager{
public:
    MemoryManager();
    void coalesce(std::ofstream&);
    void compact(std::ofstream&);
    void freeMemory(ProcessControlBlock*);
    void promptMemoryMode();
    bool fitPCB(ProcessControlBlock*, std::ofstream&);

private:
    void coalesce();
    void compact();
    void printMemory(std::ofstream&);
    void firstFit(ProcessControlBlock*, std::ofstream&);
    void nextFit(ProcessControlBlock*, std::ofstream&);
    void bestFit(ProcessControlBlock*, std::ofstream&);
    void worstFit(ProcessControlBlock*, std::ofstream&);



    MEMORY_MODE memoryMode;

    MemoryNode* head;

    MemoryNode* lastChecked;
};

#endif // MEMORY_MANAGER
