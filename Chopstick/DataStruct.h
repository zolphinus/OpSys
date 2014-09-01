#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H
#include <string>
#include <vector>


enum ACTION_LIST
{
    //These commands need to be in this order for algorithms.
    AWAIT_INPUT,
    HELP,


    DISPLAY_VERSION,
    LIST_DIR_CONTENTS,
    GET_DATE,
    SET_DATE,
    EXIT,

    //Leave last for algorithms
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
};




#endif // DATA_STRUCT_H
