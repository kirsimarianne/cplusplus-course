#include "../includes/countchars.h"

void count_chars(std::ifstream& input_file)
{ 
    int char_counter{0};
    std::string str{};           
    while(input_file >> str)
    {
        char_counter += str.size();
    }
        std::cout << "Number of characters in the file: " << char_counter << '\n';
}
