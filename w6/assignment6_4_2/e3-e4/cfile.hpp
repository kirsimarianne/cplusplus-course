#ifndef CFILE_HPP
#define CFILE_HPP

#include "line.hpp"
#include <cstdlib>
#include <cstdio>
#include <string>
#include <vector>

class CFile
{

public:
    CFile();
    CFile(const std::string &filename);
    ~CFile();

    std::string get_single_line();
    void read_lines(std::vector<Line>& lines);

private:
    FILE *file_handle;
};

#endif