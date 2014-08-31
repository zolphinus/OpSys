#ifndef RECIEVER_H
#define RECIEVER_H
#include "DataStruct.h"


class Reciever{
public:
    virtual void setAction(ACTION_LIST action) = 0;
    virtual void performAction(Global_Data&) = 0;
};

#endif // RECIEVER_H
