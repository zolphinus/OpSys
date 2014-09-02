#ifndef OPERATING_COMMANDS
#define OPERATING_COMMANDS

#include "Command.h"
#include "DataStruct.h"
#include "Reciever.h"
#include <iostream>

class Reciever;


//When you create a command, be sure to assign a default keyword string to autopopulate help menu/bindings.

class ExitCommand : public Command{
public:
    ExitCommand(Reciever* reciever)
    : Command(reciever){
        keyWord = "EXIT";
        keyWordInfo = " - Terminates the OS";
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
        keyWord = "VERSION";
        keyWordInfo = " - Displays current OS and Version number";
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
        keyWord = "";
        keyWordInfo = "";
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
        keyWord = "LIST";
        keyWordInfo = " - Lists all files in the current directory";
    }

    void execute(Global_Data& system_data){
        myReciever->setAction(LIST_DIR_CONTENTS);
        myReciever->performAction(system_data);
    }
};

class GetDateCommand : public Command{
public:
    GetDateCommand(Reciever* reciever)
    : Command(reciever){
        keyWord = "GDATE";
        keyWordInfo = " - Gets the Current Date";
    }

    void execute(Global_Data& system_data){
        myReciever->setAction(GET_DATE);
        myReciever->performAction(system_data);
    }
};

class SetDateCommand : public Command{
public:
    SetDateCommand(Reciever* reciever)
    : Command(reciever){
        keyWord = "SDATE";
        keyWordInfo = " - Sets the Current Date";
    }

    void execute(Global_Data& system_data){
        myReciever->setAction(SET_DATE);
        myReciever->performAction(system_data);
    }
};

class HelpCommand : public Command{
public:
    HelpCommand(Reciever* reciever)
    : Command(reciever){
        keyWord = "HELP"; //cannot map help command
        keyWordInfo = " - Lists Keywords for Commands";
    }

    void execute(Global_Data& system_data){
        myReciever->setAction(HELP);
        myReciever->performAction(system_data);
    }

};


#endif // OPERATING_COMMANDS
