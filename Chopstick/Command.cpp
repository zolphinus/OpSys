#include "Command.h"

//Keywords are the commands in the help list

std::string Command::getKeyword(){
    return keyWord;
}

void Command::setKeyword(std::string newKeyword){
    newKeyword = stringToUpper(newKeyword);

    keyWord = newKeyword;
}

//Keyword Info is the descriptions in the help list

std::string Command::getKeywordInfo(){
    return keyWordInfo;
}

void Command::setKeywordInfo(std::string newKeywordInfo){
    keyWordInfo = newKeywordInfo;
}
