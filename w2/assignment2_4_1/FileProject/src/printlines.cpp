#include "printlines.h"

/* Function opens file and prints it's content
 *
*/
void print_file_content(std::ifstream& input_file)
{ 
    std::string s{};
    while(input_file >> s)
    {
        std::cout << s << ' ';
    }
    std::cout << '\n';
}