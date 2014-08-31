#ifndef COMMAND_MANAGER
#define COMMAND_MANAGER

#include "OperatingCommands.h"
#include "OperatingReciever.h"
#include "DataStruct.h"
#include <iostream>
#include <string>
#include <algorithm>

class CommandManager{
public:
    CommandManager();
    ~CommandManager();
    void enterCommand(Global_Data& system_data);

private:
    std::string commandLine;
    bool commandError;

    Reciever* operatingReciever;
    Command* command;

    bool parseCommand(std::string);
    std::string stringToUpper(std::string);
};



#endif // COMMAND_MANAGER
