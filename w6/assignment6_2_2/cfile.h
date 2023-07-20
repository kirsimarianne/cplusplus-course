#ifndef CFILE_H
#define CFILE_H

#include <cstdlib>
#include <cstdio>
#include <string>

class CFile
{

public:
    CFile();
    CFile(const std::string &filename);
    ~CFile();

    std::string read_line();

private:
    FILE *file_handle;
};

#endif