#ifndef OPERATING_RECIEVER
#define OPERATING_RECIEVER
#include "Reciever.h"
#include <vector>
#include <string>


class OperatingReciever : public Reciever{
public:
    void setAction(ACTION_LIST);
    void performAction(Global_Data&);

private:
    ACTION_LIST currentAction;
    void printInformation(std::vector <std::string>&);
    void setDate(Global_Data&);
};


#endif
