#include "CommandManager.h"
#include <fstream>


CommandManager::CommandManager(){

    operatingReciever = new OperatingReciever;
    commandError = false;
    commandLine = "";
    command = new AwaitCommand(operatingReciever);
    initCommandList(command_data);
}

CommandManager::~CommandManager(){
    delete command;
    command = NULL;

    delete operatingReciever;
    operatingReciever = NULL;

    for(int i = 0; i < TOTAL_COMMANDS; i++){
        delete command_data.commandList[i];
    }

    command_data.commandList.resize(0);
    command_data.keywordList.resize(0);
}


void CommandManager::enterCommand(Global_Data& system_data){
    std::cout << std::endl << "Type a command and press enter. Type help for more options" << std::endl;
    std::cout << "Enter a command: ";
    std::cin >> commandLine;

    commandError = parseCommand(commandLine);

    if(commandError == true){
        std::cout << std::endl << "Invalid command. Please use the help command for more options."
                  << std::endl << std::endl;
    }
    else{
        command->execute(system_data);
    }
}

bool CommandManager::parseCommand(std::string newCommand){
    newCommand = stringToUpper(newCommand);

    if(newCommand == "EXIT"){
        command = command_data.commandList[EXIT];
        return false;
    }
    else if(newCommand == "VERSION"){
        command = command_data.commandList[DISPLAY_VERSION];
        return false;
    }
    else if(newCommand == "LIST"){
        command = command_data.commandList[LIST_DIR_CONTENTS];
        return false;
    }
    else if(newCommand == "GDATE")
    {
        command = command_data.commandList[GET_DATE];
        return false;
    }
    else if(newCommand == "SDATE"){
        command = command_data.commandList[SET_DATE];;
        return false;
    }
    else if(newCommand == "HELP"){
        command = command_data.commandList[HELP];
        return false;
    }
    else{
        command = command_data.commandList[AWAIT_INPUT];
        return true;
    }
}


void CommandManager::initCommandList(CommandStruct& command_data){

    std::ifstream readFile("Help/help.txt");


    command_data.commandList.resize(TOTAL_COMMANDS);
    command_data.keywordList.resize(TOTAL_COMMANDS);

    //Add commands to avoid NULL pointers.
    command_data.commandList[AWAIT_INPUT] = new AwaitCommand(operatingReciever);
    command_data.commandList[HELP] = new HelpCommand(operatingReciever);
    command_data.commandList[DISPLAY_VERSION] = new VersionInfoCommand(operatingReciever);
    command_data.commandList[LIST_DIR_CONTENTS] = new DisplayDirectoryCommand(operatingReciever);
    command_data.commandList[GET_DATE] = new GetDateCommand(operatingReciever);
    command_data.commandList[SET_DATE] = new SetDateCommand(operatingReciever);
    command_data.commandList[EXIT] = new ExitCommand(operatingReciever);

    if(readFile.is_open())
    {
        std::cout << "SUP BRO" << std::endl;
        readFile.close();
    }
    else{
            for(int i = 0; i < TOTAL_COMMANDS; i++)
            {
                command_data.keywordList[i] = command_data.commandList[i]->getKeyword();
            }
    }

}
