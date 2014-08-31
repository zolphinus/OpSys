#ifndef OPERATING_RECIEVER
#define OPERATING_RECIEVER
#include "Reciever.h"


class OperatingReciever : public Reciever{
public:
    void setAction(TYPES::ACTION_LIST);
    void performAction(Global_Data&);

private:
    TYPES::ACTION_LIST currentAction;
};

void setAction(TYPES::ACTION_LIST newAction){
    currentAction = newAction;
}

void performAction(Global_Data& system_data)
{
    if(currentAction == EXIT)
    {
        systemData.isRunning = false;
    }

}

#endif
