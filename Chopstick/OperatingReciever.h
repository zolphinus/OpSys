#ifndef OPERATING_RECIEVER
#define OPERATING_RECIEVER
#include "Reciever.h"
#include "PCBController.h"
#include <vector>
#include <string>

//struct CommandStruct;

class OperatingReciever : public Reciever{
public:
    void setAction(ACTION_LIST);
    void performAction(Global_Data&);
    void performAction(PCB_Controller&);

private:
    ACTION_LIST currentAction;
    void printInformation(std::vector <std::string>&);
    void setDate(Global_Data&);
};


#endif
