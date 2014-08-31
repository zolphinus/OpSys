#include "CommandManager.h"

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
    std::cout << "Type a command and press enter. Type help for more options" << std::endl;
    std::cout << "Enter a command: ";
    std::cin >> commandLine;

    commandError = parseCommand(commandLine);

    if(commandError == true){
        std::cout << std::endl << "Invalid command. Please use the help command for more options." << std::endl;
    }
    else{
        command->execute(system_data);
    }
}

bool CommandManager::parseCommand(std::string newCommand){
    newCommand = stringToUpper(newCommand);


    delete command;
    if(newCommand == "EXIT"){
        command = new ExitCommand(operatingReciever);
        return false;
    }
    else if(newCommand == "VERSION"){
        command = new VersionInfoCommand(operatingReciever);
        return false;
    }else{
        command = new AwaitCommand(operatingReciever);
        return true;
    }
}

std::string CommandManager::stringToUpper(std::string strToConvert)
{
    std::transform(strToConvert.begin(), strToConvert.end(), strToConvert.begin(), ::toupper);

    return strToConvert;
}
