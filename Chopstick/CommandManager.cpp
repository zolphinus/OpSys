#include "CommandManager.h"
#include <fstream>


CommandManager::CommandManager(){

    operatingReciever = new OperatingReciever;
    commandError = false;
    commandLine = "";
    command = new AwaitCommand(operatingReciever);
}

CommandManager::~CommandManager(){
    delete command;
    command = NULL;

    delete operatingReciever;
    operatingReciever = NULL;

}


void CommandManager::enterCommand(Global_Data& system_data){
    std::cout << std::endl << "Type a command and press enter. Type help for more options" << std::endl;
    std::cout << "Enter a command: ";
    std::cin >> commandLine;

    commandError = parseCommand(commandLine, system_data);

    if(commandError == true){
        std::cout << std::endl << "Invalid command. Please use the help command for more options."
                  << std::endl << std::endl;
    }
    else{
        command->execute(system_data);
    }
}

bool CommandManager::parseCommand(std::string newCommand, Global_Data& system_data){
    newCommand = stringToUpper(newCommand);

    if(newCommand == system_data.keywordList[EXIT]){
        command = system_data.commandList[EXIT];
        return false;
    }
    else if(newCommand == system_data.keywordList[DISPLAY_VERSION]){
        command = system_data.commandList[DISPLAY_VERSION];
        return false;
    }
    else if(newCommand == system_data.keywordList[LIST_DIR_CONTENTS]){
        command = system_data.commandList[LIST_DIR_CONTENTS];
        return false;
    }
    else if(newCommand == system_data.keywordList[GET_DATE])
    {
        command = system_data.commandList[GET_DATE];
        return false;
    }
    else if(newCommand == system_data.keywordList[SET_DATE]){
        command = system_data.commandList[SET_DATE];;
        return false;
    }
    else if(newCommand == system_data.keywordList[HELP]){
        command = system_data.commandList[HELP];
        return false;
    }
    else{
        command = system_data.commandList[AWAIT_INPUT];
        return true;
    }
}


void CommandManager::initCommandList(Global_Data& system_data){

    std::ifstream readFile("Help/help.txt");


    system_data.commandList.resize(TOTAL_COMMANDS);
    system_data.keywordList.resize(TOTAL_COMMANDS);

    //Add commands to avoid NULL pointers.
    system_data.commandList[AWAIT_INPUT] = new AwaitCommand(operatingReciever);
    system_data.commandList[HELP] = new HelpCommand(operatingReciever);
    system_data.commandList[DISPLAY_VERSION] = new VersionInfoCommand(operatingReciever);
    system_data.commandList[LIST_DIR_CONTENTS] = new DisplayDirectoryCommand(operatingReciever);
    system_data.commandList[GET_DATE] = new GetDateCommand(operatingReciever);
    system_data.commandList[SET_DATE] = new SetDateCommand(operatingReciever);
    system_data.commandList[EXIT] = new ExitCommand(operatingReciever);

    if(readFile.is_open())
    {
        std::cout << "SUP BRO" << std::endl;
        readFile.close();
    }
    else{
            for(int i = 0; i < TOTAL_COMMANDS; i++)
            {
                system_data.keywordList[i] = system_data.commandList[i]->getKeyword();
            }
    }

}
