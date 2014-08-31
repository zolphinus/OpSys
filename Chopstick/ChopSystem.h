#ifndef CHOPSTICK_SYSTEM
#define CHOPSTICK_SYSTEM
#include "DataStruct.h"
#include "CommandManager.h"
#include <time.h>

class ChopSystem{
public:
    ChopSystem();
    void runOS();

private:
    Global_Data system_data;
    CommandManager commandManager;
    time_t tempTime;

    void initializeData();
    void getCurrentDate();
    void welcomeScreen();
    bool isRunning();
    std::string getWorkingDirectory();

};


#endif // CHOPSTICK_SYSTEM
