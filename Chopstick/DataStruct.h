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
    CREATE_PCB,
    DELETE_PCB,
    BLOCK_PCB,
    UNBLOCK_PCB,
    SUSPEND_PCB,
    RESUME_PCB,
    SET_PRIORITY,
    SHOW_PCB,
    SHOW_ALL,
    SHOW_READY,
    SHOW_BLOCKED,

    //Leave last for command initialization
    TOTAL_COMMANDS
};

enum COMMAND_MODE{
    SYSTEM_MODE,
    PCB_MODE
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
