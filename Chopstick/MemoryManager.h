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
    void coalesce(std::fstream&);
    void compact(std::fstream&);
    void freeMemory(ProcessControlBlock*);
    void promptMemoryMode();
    bool fitPCB(ProcessControlBlock*, std::fstream&);

    void printMemory(std::fstream&);

private:
    void coalesce();
    void compact();
    bool firstFit(ProcessControlBlock*, std::fstream&);
    bool nextFit(ProcessControlBlock*, std::fstream&);
    bool bestFit(ProcessControlBlock*, std::fstream&);
    bool worstFit(ProcessControlBlock*, std::fstream&);



    MEMORY_MODE memoryMode;

    MemoryNode* head;

    MemoryNode* lastChecked;
};

#endif // MEMORY_MANAGER
