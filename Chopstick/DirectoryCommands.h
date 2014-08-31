#ifndef DIRECTORY_COMMANDS
#define DIRECTORY_COMMANDS

#include <Windows.h>
#include <vector>
#include <string>
#include <stdio.h>
#include "DataStruct.h"


void getAllFilesInFolder(Global_Data& system_data)
{

    char search_path[200];
    system_data.directoryList.resize(0);
    std::cout << system_data.currentDirectory << std::endl;

    sprintf(search_path, "*.*", system_data.currentDirectory.c_str());
    WIN32_FIND_DATA fd;
    HANDLE hFind = ::FindFirstFile(search_path, &fd);

    if(hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            // read all (real) files in current folder
            // , delete '!' read other 2 default folder . and ..
            if( !(fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
               && fd.cFileName != "."
               && fd.cFileName != ".." )
            {
                std::cout << "filename is : " << fd.cFileName << std::endl;
                system_data.directoryList.push_back(fd.cFileName);
            }
        }while(::FindNextFile(hFind, &fd));
        ::FindClose(hFind);
    }
    else{
        std::cout << "There was an error obtaining directory files." << std::endl;
    }
}

#endif // DIRECTORY_COMMANDS
