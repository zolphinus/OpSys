#ifndef OPERATING_COMMANDS
#define OPERATING_COMMANDS

#include "Command.h"
#include "DataStruct.h"
#include "Reciever.h"
#include <iostream>

class Reciever;


class ExitCommand : public Command{
public:
    ExitCommand(Reciever* reciever)
    : Command(reciever){

    }

    void execute(Global_Data& system_data){
        myReciever->setAction(EXIT);
        myReciever->performAction(system_data);
    }
};

class VersionInfoCommand : public Command{
public:
    VersionInfoCommand(Reciever* reciever)
    : Command(reciever){

    }

    void execute(Global_Data& system_data){
        myReciever->setAction(DISPLAY_VERSION);
        myReciever->performAction(system_data);
    }
};


class AwaitCommand : public Command{
public:
    AwaitCommand(Reciever* reciever)
    : Command(reciever){

    }

    void execute(Global_Data& system_data){
        myReciever->setAction(AWAIT_INPUT);
        myReciever->performAction(system_data);
    }
};

class DisplayDirectoryCommand : public Command{
public:
    DisplayDirectoryCommand(Reciever* reciever)
    : Command(reciever){

    }

    void execute(Global_Data& system_data){
        myReciever->setAction(LIST_DIR_CONTENTS);
        myReciever->performAction(system_data);
    }
};


#endif // OPERATING_COMMANDS
