#include "Command.h"

std::string Command::getKeyword(){
    return keyWord;
}

void Command::setKeyword(std::string newKeyword){
    newKeyword = stringToUpper(newKeyword);

    keyWord = newKeyword;
}

