#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H
#include <string>
#include <vector>

class Command;

enum ACTION_LIST
{
    //These commands need to stay in this order because their help/names are locked
    //and the for loops to populate these start with DISPLAY_VERSION
    AWAIT_INPUT,
    HELP,


    DISPLAY_VERSION,
    LIST_DIR_CONTENTS,
    GET_DATE,
    SET_DATE,
    EXIT,

    //Leave last for command initialization
    TOTAL_COMMANDS
};



struct Global_Data{
        bool isRunning;
        std::string versionInfo;
        std::string currentDirectory;
        std::string month;
        std::string day;
        std::string year;
        std::string date;
        std::vector <std::string> directoryList;
        std::vector <std::string> keywordList;
        std::vector <std::string> keywordHelpList;

        std::vector <Command*> commandList;
};



#endif // DATA_STRUCT_H
