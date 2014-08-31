#ifndef DATA_STRUCT_H
#define DATA_STRUCT_H
#include <string>


enum ACTION_LIST
{
    AWAIT_INPUT,
    DISPLAY_VERSION,
    LIST_DIR_CONTENTS,
    EXIT
};



struct Global_Data{
        bool isRunning;
        std::string versionInfo;
};

#endif // DATA_STRUCT_H
