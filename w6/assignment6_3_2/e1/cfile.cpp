#include "cfile.hpp"
#include <iostream>

// Default constructor
CFile::CFile() : file_handle(nullptr) {}

// Constructor with parameter: filename
CFile::CFile(const std::string &filename)
{
    file_handle = fopen(filename.c_str(), "r");
    if (file_handle == NULL)
    {
        throw std::runtime_error("Cannot open file");
    }
}

// Deconstructor: close file
CFile::~CFile()
{
    if (file_handle)
    {
        fclose(file_handle);
        file_handle = nullptr;
    }
}

std::string CFile::read_line()
{
    std::string line{};
    int symbol{};
    while ((symbol = std::fgetc(file_handle)) != EOF && symbol != '\n')
    {
        line.push_back(static_cast<char>(symbol));
    }
    return line;
}

int main()
{
    CFile file_object("testi.txt");
    std::string line = file_object.read_line();
    while (!line.empty())
    {
        std::cout << line;
        line = file_object.read_line();
    }
    std::cout << "\n";
    return 0; 
}