#ifndef MEMORY_NODE
#define MEMORY_NODE
#include <string>
#include "ProcessControlBlock.h"
#include <fstream>


class MemoryNode{
public:
    MemoryNode(int);
    MemoryNode(ProcessControlBlock*);

    void freeMemory(ProcessControlBlock*);
    void printDetails(std::ofstream& out);

    MemoryNode* next;
    int memoryUsed;
    std::string processName;
    bool isFree;
};

#endif // MEMORY_NODE
