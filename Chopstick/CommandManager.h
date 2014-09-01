#ifndef COMMAND_MANAGER
#define COMMAND_MANAGER

#include "OperatingCommands.h"
#include "OperatingReciever.h"
#include "DataStruct.h"
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class CommandManager{
public:
    CommandManager();
    ~CommandManager();
    void enterCommand(Global_Data& system_data);
    void initCommandList(Global_Data& system_data);

private:
    std::string commandLine;
    bool commandError;

    Reciever* operatingReciever;
    Command* command;

    bool parseCommand(std::string, Global_Data&);
};



#endif // COMMAND_MANAGER
