#include "cfile.h"
#include <iostream>

CFile::CFile() : file_handle(nullptr) {}

CFile::~CFile()
{
    if(file_handle)
    {
        fclose(file_handle);
        file_handle = nullptr;
    }
}

CFile::CFile(const std::string& filename)
{
    file_handle = fopen(filename.c_str(), "r");
}


std::string CFile::read_line()
{
    std::string line {""};
    int symbol {};
    while(symbol = std::fgetc(file_handle) != EOF)
    {
        line.push_back(static_cast<char>(symbol));
    }
    return line;
}

int main()
{
    CFile file_object("testi.txt");
    std::string line{};
    while(true)
    {
        std::cout << line << "\n";
    }

}    