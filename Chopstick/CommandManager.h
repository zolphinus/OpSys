#ifndef COMMAND_MANAGER
#define COMMAND_MANAGER

#include "OperatingCommands.h"
#include "OperatingReciever.h"
#include "DataStruct.h"
#include <iostream>
#include <string>


class CommandManager{
public:
    CommandManager();
    void enterCommand(Global_Data system_data);

private:
    std::string commandLine;
    OperatingReciever operatingReciever;
    Command* command;
    ExitCommand exit;
    AwaitCommand awaitInput;

};


void enterCommand(Global_Data system_data){
}

#endif // COMMAND_MANAGER
