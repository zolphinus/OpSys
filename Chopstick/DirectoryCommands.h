#ifndef DIRECTORY_COMMANDS
#define DIRECTORY_COMMANDS

#include <Windows.h>
#include <vector>
#include <string>
#include <stdio.h>


std::vector<std::string> get_all_files_names_within_folder(std::string folder)
{
    std::vector<std::string> names;
    char search_path[200];
    sprintf(search_path, "%s*.*", folder.c_str());
    WIN32_FIND_DATA fd;
    HANDLE hFind = ::FindFirstFile(search_path, &fd);
    if(hFind != INVALID_HANDLE_VALUE)
    {
        do
        {
            // read all (real) files in current folder
            // , delete '!' read other 2 default folder . and ..
            if(! (fd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) )
            {
                names.push_back(fd.cFileName);
            }
        }while(::FindNextFile(hFind, &fd));
        ::FindClose(hFind);
    }
    return names;
}

#endif // DIRECTORY_COMMANDS
