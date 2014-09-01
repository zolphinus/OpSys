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

private:

    struct CommandStruct{
        std::vector <std::string> keywordList;
        std::vector <Command*> commandList;

    };

    CommandStruct command_data;
    std::string commandLine;
    bool commandError;

    Reciever* operatingReciever;
    Command* command;

    bool parseCommand(std::string);
    void initCommandList(CommandStruct&);
};



#endif // COMMAND_MANAGER
