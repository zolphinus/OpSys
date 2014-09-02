#ifndef COMMAND
#define COMMAND
#include "DataStruct.h"
#include "Reciever.h"
#include <string>
#include <algorithm>
#include "GeneralFunctions.h"

class Command{
protected:
    Reciever* myReciever;
    Command(Reciever* reciever)
    : myReciever(reciever){

    }
    std::string keyWord;
    std::string keyWordInfo;

public:
    virtual void execute(Global_Data&) = 0;

    std::string getKeyword();
    std::string getKeywordInfo();
};

#endif // COMMAND
