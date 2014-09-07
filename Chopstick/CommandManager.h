#ifndef COMMAND_MANAGER
#define COMMAND_MANAGER

#include "OperatingCommands.h"
#include "PCB_Commands.h"

#include "OperatingReciever.h"
#include "DataStruct.h"
#include "PCBController.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class CommandManager{
public:
    CommandManager();
    ~CommandManager();
    void enterCommand(Global_Data& system_data, PCB_Controller& pcbController);
    void initCommandList(Global_Data& system_data);

private:
    std::string commandLine;
    bool commandError;

    Reciever* operatingReciever;
    Command* command;
    COMMAND_MODE currentCommandMode;

    bool parseCommand(std::string, Global_Data&);
};



#endif // COMMAND_MANAGER
