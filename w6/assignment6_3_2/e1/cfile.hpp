/* To demonstrate RAII, we are going to wrap some C functionality into a class of our own.
 * This is a common task since we often want to use C libraries and still benefit from RAII.
 * (And with some improvement, the end result might actually be useful to you later)
 */

#ifndef CFILE_HPP
#define CFILE_HPP

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