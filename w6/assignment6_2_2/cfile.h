#ifndef CFILE_H
#define CFILE_H

#include <cstdlib>
#include <cstdio>
#include <string>

class CFile
{

    // constructor or static member function. opens a text file
    //  Uses RAII -> cleans up itself: eli huolehdi, että file suljetaan
    //  Function to read in the next line of the text file
    //  Optional: function to print the file size

public:
    CFile();
    ~CFile();
    CFile(const std::string &filename);

    std::string read_line();

private:
    // pointer to file
    FILE *file_handle;
    std::string line;
};

#endif