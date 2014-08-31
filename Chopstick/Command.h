#ifndef COMMAND
#define COMMAND
#include "DataStruct.h"

class Command{
protected:
    Reciever* myReciever;

private:
    Command(Reciever* reciever)
    : myReciever(reciever){

    }

    virtual void execute(Global_Data&) = 0;
};


#endif // COMMAND
