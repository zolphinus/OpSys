#ifndef CHOPSTICK_SYSTEM
#define CHOPSTICK_SYSTEM
#include "DataStruct.h"
#include "CommandManager.h"
#include "PCBController.h"
#include <time.h>

class ChopSystem{
public:
    ChopSystem();
    ~ChopSystem();
    void runOS();

private:
    Global_Data system_data;
    CommandManager commandManager;
    PCB_Controller pcbController;
    time_t tempTime;

    void initializeData();
    void getCurrentDate();
    void welcomeScreen();
    bool isRunning();
    std::string getWorkingDirectory();

};


#endif // CHOPSTICK_SYSTEM
