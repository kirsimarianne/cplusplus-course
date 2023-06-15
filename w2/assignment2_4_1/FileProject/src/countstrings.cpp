#include "countstrings.h"

void count_strings(std::ifstream& input_file)
{
    int str_count{0}; 
    std::string str{};           
    while(input_file >> str)
    {
        str_count++;
    }
    std::cout << "Number of words in the file: " << str_count << '\n';
}