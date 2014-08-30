#ifndef CHOPSTICK_SYSTEM
#define CHOPSTICK_SYSTEM
#include "DataStruct.h"


class ChopSystem{
public:
    ChopSystem();
    void runOS();

private:
    Global_Data system_data;
    void initializeData();
    bool isRunning();
};


#endif // CHOPSTICK_SYSTEM
