#include "cfile.hpp"
#include "line.hpp"
#include <iostream>
#include <vector>

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

/* Future development stops reading middle of file 
 * if file seperator exists in middle of file.
 */
std::string CFile::get_single_line()
{
    std::string line{};
    int symbol{};
    while ((symbol = std::fgetc(file_handle)) != EOF && symbol != '\n')
    {
        line.push_back(static_cast<char>(symbol));
    }
    return line;
}

void CFile::read_lines(std::vector<Line> &lines_vect)
{
    std::string line = get_single_line();
    while (!line.empty())
    {
        Line line_obj(line);
        lines_vect.push_back(line_obj);
        line = get_single_line();
    }
}

int main()
{
    CFile file_object("testi.txt");

    std::vector<Line> lines_vect;
    file_object.read_lines(lines_vect);
    for (const auto &line : lines_vect)
    {
        std::cout << line;
    }

    return 0;
}