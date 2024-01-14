#include "../includes/countlines.h"

/* Function opens file 
 *
*/
void count_lines(std::ifstream& input_file)
{ 
    int line_count{0};
    std::string line{};
    while(std::getline(input_file, line))
    {
        line_count++;
    }
    std::cout << "Number of lines in the file: " << line_count << '\n';

}