#ifndef OPERATING_COMMANDS
#define OPERATING_COMMANDS

#include "Command.h"
#include "DataStruct.h"
#include "Reciever.h"
#include <iostream>

class Reciever;


//When you create a command, be sure to assign a default keyword string to autopopulate help menu/bindings.

class OperatingCommand : public Command{
public:
    OperatingCommand(Reciever* reciever)
    : Command(reciever){
    }

    void execute(Global_Data& system_data) = 0;
    void execute(PCB_Controller&){
    }
};



class ExitCommand : public OperatingCommand{
public:
    ExitCommand(Reciever* reciever)
    : OperatingCommand(reciever){
        keyWord = "EXIT";
        keyWordInfo = " - Terminates the OS";
    }

    void execute(Global_Data& system_data){
        myReciever->setAction(EXIT);
        myReciever->performAction(system_data);
    }
};

class VersionInfoCommand : public OperatingCommand{
public:
    VersionInfoCommand(Reciever* reciever)
    : OperatingCommand(reciever){
        keyWord = "VERSION";
        keyWordInfo = " - Displays current OS and Version number";
    }

    void execute(Global_Data& system_data){
        myReciever->setAction(DISPLAY_VERSION);
        myReciever->performAction(system_data);
    }
};


class AwaitCommand : public OperatingCommand{
public:
    AwaitCommand(Reciever* reciever)
    : OperatingCommand(reciever){
        keyWord = "";
        keyWordInfo = "";
    }

    void execute(Global_Data& system_data){
        myReciever->setAction(AWAIT_INPUT);
        myReciever->performAction(system_data);
    }
};

class DisplayDirectoryCommand : public OperatingCommand{
public:
    DisplayDirectoryCommand(Reciever* reciever)
    : OperatingCommand(reciever){
        keyWord = "LIST";
        keyWordInfo = " - Lists all files in the current directory";
    }

    void execute(Global_Data& system_data){
        myReciever->setAction(LIST_DIR_CONTENTS);
        myReciever->performAction(system_data);
    }
};

class GetDateCommand : public OperatingCommand{
public:
    GetDateCommand(Reciever* reciever)
    : OperatingCommand(reciever){
        keyWord = "GDATE";
        keyWordInfo = " - Gets the Current Date";
    }

    void execute(Global_Data& system_data){
        myReciever->setAction(GET_DATE);
        myReciever->performAction(system_data);
    }
};

class SetDateCommand : public OperatingCommand{
public:
    SetDateCommand(Reciever* reciever)
    : OperatingCommand(reciever){
        keyWord = "SDATE";
        keyWordInfo = " - Sets the Current Date";
    }

    void execute(Global_Data& system_data){
        myReciever->setAction(SET_DATE);
        myReciever->performAction(system_data);
    }
};

class HelpCommand : public OperatingCommand{
public:
    HelpCommand(Reciever* reciever)
    : OperatingCommand(reciever){
        keyWord = "HELP"; //cannot map help command
        keyWordInfo = " - Lists Keywords for Commands";
    }

    void execute(Global_Data& system_data){
        myReciever->setAction(HELP);
        myReciever->performAction(system_data);
    }

};


#endif // OPERATING_COMMANDS
