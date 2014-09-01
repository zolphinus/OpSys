#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H
#include <string>
#include <vector>


enum ACTION_LIST
{
    AWAIT_INPUT,
    DISPLAY_VERSION,
    HELP,
    LIST_DIR_CONTENTS,
    GET_DATE,
    SET_DATE,
    EXIT,
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
