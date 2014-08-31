#ifndef OPERATING_COMMANDS
#define OPERATING_COMMANDS

#include "Command.h"
#include "DataStruct.h"


class ExitCommand : public Command{
    ExitCommand(Reciever* reciever)
    : Command(reciever){

    }

    void execute(Global_Data& system_data){
        myReciever->setAction(TYPE::ACTION_LIST::EXIT);
        myReciever->performAction(system_data);
    }
};

class AwaitCommand : public Command{
    ExitCommand(Reciever* reciever)
    : Command(reciever){

    }

    void execute(Global_Data& system_data){
        myReciever->setAction(TYPE::ACTION_LIST::AWAIT_INPUT);
        myReciever->performAction(system_data);
    }
};


#endif // OPERATING_COMMANDS
