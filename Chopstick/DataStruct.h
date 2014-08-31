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
    EXIT
};



struct Global_Data{
        bool isRunning;
        std::string versionInfo;
        std::string currentDirectory;
        std::vector <std::string> directoryList;
};

#endif // DATA_STRUCT_H
