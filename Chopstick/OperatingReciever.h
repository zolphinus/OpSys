#ifndef OPERATING_RECIEVER
#define OPERATING_RECIEVER
#include "Reciever.h"


class OperatingReciever : public Reciever{
public:
    void setAction(ACTION_LIST);
    void performAction(Global_Data&);

private:
    ACTION_LIST currentAction;
};


#endif
