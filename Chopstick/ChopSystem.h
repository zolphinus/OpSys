#ifndef CHOPSTICK_SYSTEM
#define CHOPSTICK_SYSTEM
#include "DataStruct.h"
#include "CommandManager.h"


class ChopSystem{
public:
    ChopSystem();
    void runOS();

private:
    Global_Data system_data;
    CommandManager commandManager;

    void initializeData();
    void welcomeScreen();
    bool isRunning();
    std::string getWorkingDirectory();

};


#endif // CHOPSTICK_SYSTEM
