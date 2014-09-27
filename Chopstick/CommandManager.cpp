#include "CommandManager.h"
#include <fstream>


CommandManager::CommandManager(){

    operatingReciever = new OperatingReciever;
    commandError = false;
    commandLine = "";
    command = new AwaitCommand(operatingReciever);
    currentCommandMode = SYSTEM_MODE;
}

CommandManager::~CommandManager(){
    command = NULL;

    delete operatingReciever;
    operatingReciever = NULL;

}


void CommandManager::enterCommand(Global_Data& system_data, PCB_Controller& pcbController){
    std::cout << std::endl << "Type a command and press enter. Type help for more options" << std::endl;
    std::cout << "Enter a command: ";


    std::getline(std::cin, commandLine);
    std::cin.clear();

    commandError = parseCommand(commandLine, system_data);

    if(commandError == true){
        std::cout << std::endl << "Invalid command. Please use the help command for more options."
                  << std::endl << std::endl;
    }
    else{
            switch(currentCommandMode)
            {
            case SYSTEM_MODE :
                command->execute(system_data);
                break;
            case PCB_MODE :
                command->execute(pcbController);
                break;
            }
        std::cin.ignore();
        std::cin.clear();

    }
}

bool CommandManager::parseCommand(std::string newCommand, Global_Data& system_data){
    newCommand = stringToUpper(newCommand);

    //as you add commands, be sure to change the current command mode to match the command issued

    if(newCommand == system_data.keywordList[EXIT]){
        command = system_data.commandList[EXIT];
        currentCommandMode = SYSTEM_MODE;
        return false;
    }
    else if(newCommand == system_data.keywordList[DISPLAY_VERSION]){
        command = system_data.commandList[DISPLAY_VERSION];
        currentCommandMode = SYSTEM_MODE;
        return false;
    }
    else if(newCommand == system_data.keywordList[LIST_DIR_CONTENTS]){
        command = system_data.commandList[LIST_DIR_CONTENTS];
        currentCommandMode = SYSTEM_MODE;
        return false;
    }
    else if(newCommand == system_data.keywordList[GET_DATE])
    {
        command = system_data.commandList[GET_DATE];
        currentCommandMode = SYSTEM_MODE;
        return false;
    }
    else if(newCommand == system_data.keywordList[SET_DATE]){
        command = system_data.commandList[SET_DATE];;
        currentCommandMode = SYSTEM_MODE;
        return false;
    }
    else if(newCommand == system_data.keywordList[HELP]){
        command = system_data.commandList[HELP];
        currentCommandMode = SYSTEM_MODE;
        return false;
    }
    else

        /*if(newCommand == system_data.keywordList[CREATE_PCB]){

        command = system_data.commandList[CREATE_PCB];
        currentCommandMode = PCB_MODE;
        return false;
    }else if(newCommand == system_data.keywordList[DELETE_PCB]){

        command = system_data.commandList[DELETE_PCB];
        currentCommandMode = PCB_MODE;
        return false;
    }else if(newCommand == system_data.keywordList[BLOCK_PCB]){

        command = system_data.commandList[BLOCK_PCB];
        currentCommandMode = PCB_MODE;
        return false;
    }else if(newCommand == system_data.keywordList[UNBLOCK_PCB]){

        command = system_data.commandList[UNBLOCK_PCB];
        currentCommandMode = PCB_MODE;
        return false;
    }else */
    if(newCommand == system_data.keywordList[SUSPEND_PCB]){

        command = system_data.commandList[SUSPEND_PCB];
        currentCommandMode = PCB_MODE;
        return false;
    }else if(newCommand == system_data.keywordList[RESUME_PCB]){

        command = system_data.commandList[RESUME_PCB];
        currentCommandMode = PCB_MODE;
        return false;
    }else if(newCommand == system_data.keywordList[SET_PRIORITY]){

        command = system_data.commandList[SET_PRIORITY];
        currentCommandMode = PCB_MODE;
        return false;
    }else if(newCommand == system_data.keywordList[SHOW_PCB]){

        command = system_data.commandList[SHOW_PCB];
        currentCommandMode = PCB_MODE;
        return false;
    }else if(newCommand == system_data.keywordList[SHOW_ALL]){

        command = system_data.commandList[SHOW_ALL];
        currentCommandMode = PCB_MODE;
        return false;
    }else if(newCommand == system_data.keywordList[SHOW_READY]){

        command = system_data.commandList[SHOW_READY];
        currentCommandMode = PCB_MODE;
        return false;
    }else if(newCommand == system_data.keywordList[SHOW_BLOCKED]){

        command = system_data.commandList[SHOW_BLOCKED];
        currentCommandMode = PCB_MODE;
        return false;
    }
    else if(newCommand == system_data.keywordList[SHORTEST_JOB_FULL_KNOWLEDGE]){

        command = system_data.commandList[SHORTEST_JOB_FULL_KNOWLEDGE];
        currentCommandMode = PCB_MODE;
        return false;
    }
    else if(newCommand == system_data.keywordList[INCOMPLETE_FIFO]){

        command = system_data.commandList[INCOMPLETE_FIFO];
        currentCommandMode = PCB_MODE;
        return false;
    }
    else if(newCommand == system_data.keywordList[INCOMPLETE_FPPS]){

        command = system_data.commandList[INCOMPLETE_FPPS];
        currentCommandMode = PCB_MODE;
        return false;
    }
    else if(newCommand == system_data.keywordList[INCOMPLETE_SJF]){

        command = system_data.commandList[INCOMPLETE_SJF];
        currentCommandMode = PCB_MODE;
        return false;
    }else if(newCommand == system_data.keywordList[INCOMPLETE_RR]){

        command = system_data.commandList[INCOMPLETE_RR];
        currentCommandMode = PCB_MODE;
        return false;
    }else if(newCommand == system_data.keywordList[INCOMPLETE_MLFQ]){

        command = system_data.commandList[INCOMPLETE_MLFQ];
        currentCommandMode = PCB_MODE;
        return false;
    }else if(newCommand == system_data.keywordList[INCOMPLETE_LOTTO]){

        command = system_data.commandList[INCOMPLETE_LOTTO];
        currentCommandMode = PCB_MODE;
        return false;
    }else{
        command = system_data.commandList[AWAIT_INPUT];
        currentCommandMode = SYSTEM_MODE;
        return true;
    }
}


void CommandManager::initCommandList(Global_Data& system_data){

    std::ifstream readFile("Help/help.txt");


    system_data.commandList.resize(TOTAL_COMMANDS);
    system_data.keywordList.resize(TOTAL_COMMANDS);
    system_data.keywordHelpList.resize(TOTAL_COMMANDS);

    //Add commands to avoid NULL pointers.
    system_data.commandList[AWAIT_INPUT] = new AwaitCommand(operatingReciever);
    system_data.commandList[HELP] = new HelpCommand(operatingReciever);
    system_data.commandList[DISPLAY_VERSION] = new VersionInfoCommand(operatingReciever);
    system_data.commandList[LIST_DIR_CONTENTS] = new DisplayDirectoryCommand(operatingReciever);
    system_data.commandList[GET_DATE] = new GetDateCommand(operatingReciever);
    system_data.commandList[SET_DATE] = new SetDateCommand(operatingReciever);
    system_data.commandList[EXIT] = new ExitCommand(operatingReciever);

    //Add PCB commands to list of commands
    system_data.commandList[CREATE_PCB] = new CreateCommand(operatingReciever);
    system_data.commandList[DELETE_PCB] = new DeleteCommand(operatingReciever);
    system_data.commandList[BLOCK_PCB] = new BlockCommand(operatingReciever);
    system_data.commandList[UNBLOCK_PCB] = new UnblockCommand(operatingReciever);
    system_data.commandList[SUSPEND_PCB] = new SuspendCommand(operatingReciever);
    system_data.commandList[RESUME_PCB] = new ResumeCommand(operatingReciever);
    system_data.commandList[SET_PRIORITY] = new SetPriorityCommand(operatingReciever);
    system_data.commandList[SHOW_PCB] = new ShowPCBCommand(operatingReciever);
    system_data.commandList[SHOW_ALL] = new ShowAllCommand(operatingReciever);
    system_data.commandList[SHOW_READY] = new ShowReadyCommand(operatingReciever);
    system_data.commandList[SHOW_BLOCKED] = new ShowBlockedCommand(operatingReciever);
    system_data.commandList[SHORTEST_JOB_FULL_KNOWLEDGE] = new ShortestJobFullCommand(operatingReciever);
    system_data.commandList[INCOMPLETE_FIFO] = new IncompleteFIFOCommand(operatingReciever);
    system_data.commandList[INCOMPLETE_SJF] = new IncompleteSJFCommand(operatingReciever);
    system_data.commandList[INCOMPLETE_FPPS] = new IncompleteFPPSCommand(operatingReciever);
    system_data.commandList[INCOMPLETE_RR] = new IncompleteRoundRobinCommand(operatingReciever);
    system_data.commandList[INCOMPLETE_MLFQ] = new IncompleteMLFQCommand(operatingReciever);
    system_data.commandList[INCOMPLETE_LOTTO] = new IncompleteLottoCommand(operatingReciever);

    if(readFile.is_open())
    {
        //obtain data from file and change i = 0 to i = DISPLAY_VERSION


        for(int i = 0; i < TOTAL_COMMANDS; i++)
            {
                system_data.keywordList[i] = system_data.commandList[i]->getKeyword();
                system_data.keywordHelpList[i] = system_data.keywordList[i] +
                                                 system_data.commandList[i]->getKeywordInfo();
            }
        readFile.close();
    }
    else{
            for(int i = 0; i < TOTAL_COMMANDS; i++)
            {
                system_data.keywordList[i] = system_data.commandList[i]->getKeyword();
                system_data.keywordHelpList[i] = system_data.keywordList[i] +
                                                 system_data.commandList[i]->getKeywordInfo();
            }
    }

}
