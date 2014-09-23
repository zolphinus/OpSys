#ifndef PCB_COMMANDS
#define PCB_COMMANDS

#include "Command.h"
#include "DataStruct.h"
#include "Reciever.h"
#include <iostream>

class Reciever;


//When you create a command, be sure to assign a default keyword string to autopopulate help menu/bindings.

class PCBCommand : public Command{
public:
    PCBCommand(Reciever* reciever)
    : Command(reciever){
    }

    void execute(Global_Data& system_data){
    }
    void execute(PCB_Controller&) = 0;
};

class CreateCommand : public PCBCommand{
public:
    CreateCommand(Reciever* reciever)
    : PCBCommand(reciever){
        keyWord = "CREATE PCB";
        keyWordInfo = " - Creates a Process Control Block";
    }

    void execute(PCB_Controller& pcbController){
        myReciever->setAction(CREATE_PCB);
        myReciever->performAction(pcbController);
    }
};

class DeleteCommand : public PCBCommand{
public:
    DeleteCommand(Reciever* reciever)
    : PCBCommand(reciever){
        keyWord = "DELETE PCB";
        keyWordInfo = " - Deletes a Process Control Block";
    }

    void execute(PCB_Controller& pcbController){
        myReciever->setAction(DELETE_PCB);
        myReciever->performAction(pcbController);
    }
};

class BlockCommand : public PCBCommand{
public:
    BlockCommand(Reciever* reciever)
    : PCBCommand(reciever){
        keyWord = "BLOCK PCB";
        keyWordInfo = " - Blocks a Process Control Block";
    }

    void execute(PCB_Controller& pcbController){
        myReciever->setAction(BLOCK_PCB);
        myReciever->performAction(pcbController);
    }
};

class UnblockCommand : public PCBCommand{
public:
    UnblockCommand(Reciever* reciever)
    : PCBCommand(reciever){
        keyWord = "UNBLOCK PCB";
        keyWordInfo = " - Unblocks a Process Control Block";
    }

    void execute(PCB_Controller& pcbController){
        myReciever->setAction(UNBLOCK_PCB);
        myReciever->performAction(pcbController);
    }
};

class SuspendCommand : public PCBCommand{
public:
    SuspendCommand(Reciever* reciever)
    : PCBCommand(reciever){
        keyWord = "SUSPEND PCB";
        keyWordInfo = " - Suspend a Process Control Block";
    }

    void execute(PCB_Controller& pcbController){
        myReciever->setAction(SUSPEND_PCB);
        myReciever->performAction(pcbController);
    }
};

class ResumeCommand : public PCBCommand{
public:
    ResumeCommand(Reciever* reciever)
    : PCBCommand(reciever){
        keyWord = "RESUME PCB";
        keyWordInfo = " - Resumes a Process Control Block";
    }

    void execute(PCB_Controller& pcbController){
        myReciever->setAction(RESUME_PCB);
        myReciever->performAction(pcbController);
    }
};

class SetPriorityCommand : public PCBCommand{
public:
    SetPriorityCommand(Reciever* reciever)
    : PCBCommand(reciever){
        keyWord = "SET PRIORITY";
        keyWordInfo = " - Sets the priority of a Process Control Block";
    }

    void execute(PCB_Controller& pcbController){
        myReciever->setAction(SET_PRIORITY);
        myReciever->performAction(pcbController);
    }
};

class ShowPCBCommand : public PCBCommand{
public:
    ShowPCBCommand(Reciever* reciever)
    : PCBCommand(reciever){
        keyWord = "SHOW PCB";
        keyWordInfo = " - Shows a Process Control Block";
    }

    void execute(PCB_Controller& pcbController){
        myReciever->setAction(SHOW_PCB);
        myReciever->performAction(pcbController);
    }
};

class ShowAllCommand : public PCBCommand{
public:
    ShowAllCommand(Reciever* reciever)
    : PCBCommand(reciever){
        keyWord = "SHOW ALL";
        keyWordInfo = " - Shows all PCBs";
    }

    void execute(PCB_Controller& pcbController){
        myReciever->setAction(SHOW_ALL);
        myReciever->performAction(pcbController);
    }
};

class ShowReadyCommand : public PCBCommand{
public:
    ShowReadyCommand(Reciever* reciever)
    : PCBCommand(reciever){
        keyWord = "SHOW READY";
        keyWordInfo = " - Shows all ready PCBs";
    }

    void execute(PCB_Controller& pcbController){
        myReciever->setAction(SHOW_READY);
        myReciever->performAction(pcbController);
    }
};

class ShowBlockedCommand : public PCBCommand{
public:
    ShowBlockedCommand(Reciever* reciever)
    : PCBCommand(reciever){
        keyWord = "SHOW BLOCKED";
        keyWordInfo = " - Shows all blocked PCBs";
    }

    void execute(PCB_Controller& pcbController){
        myReciever->setAction(SHOW_BLOCKED);
        myReciever->performAction(pcbController);
    }
};

class ShortestJobFullCommand : public PCBCommand{
public:
    ShortestJobFullCommand(Reciever* reciever)
    : PCBCommand(reciever){
        keyWord = "SJF";
        keyWordInfo = " - shortest job first scheduler";
    }

    void execute(PCB_Controller& pcbController){
        myReciever->setAction(SHORTEST_JOB_FULL_KNOWLEDGE);
        myReciever->performAction(pcbController);
    }
};


class IncompleteFIFOCommand : public PCBCommand{
public:
    IncompleteFIFOCommand(Reciever* reciever)
    : PCBCommand(reciever){
        keyWord = "FIFO";
        keyWordInfo = " - first in, first out scheduler";
    }

    void execute(PCB_Controller& pcbController){
        myReciever->setAction(INCOMPLETE_FIFO);
        myReciever->performAction(pcbController);
    }
};

class IncompleteSJFCommand : public PCBCommand{
public:
    IncompleteSJFCommand(Reciever* reciever)
    : PCBCommand(reciever){
        keyWord = "STCF";
        keyWordInfo = " - incomplete preemptive SJF scheduler";
    }

    void execute(PCB_Controller& pcbController){
        myReciever->setAction(INCOMPLETE_SJF);
        myReciever->performAction(pcbController);
    }
};

class IncompleteFPPSCommand : public PCBCommand{
public:
    IncompleteFPPSCommand(Reciever* reciever)
    : PCBCommand(reciever){
        keyWord = "FPPS";
        keyWordInfo = " - incomplete preemptive Fixed Priority scheduler";
    }

    void execute(PCB_Controller& pcbController){
        myReciever->setAction(INCOMPLETE_FPPS);
        myReciever->performAction(pcbController);
    }
};


#endif // PCB_COMMANDS
