#ifndef COMMAND
#define COMMAND
#include "DataStruct.h"
#include "Reciever.h"

class Command{
protected:
    Reciever* myReciever;
    Command(Reciever* reciever)
    : myReciever(reciever){

    }

public:
    virtual void execute(Global_Data&) = 0;
};


#endif // COMMAND
