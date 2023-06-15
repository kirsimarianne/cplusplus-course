#include "openfile.h"

/* Function opens file and prints it's content
 *
*/
bool print_file_content(std::string filename)
{ 
    std::ifstream inputFile(filename);

    if(!inputFile.is_open())
    {
        std::cout << "Failed to open the file.\n";
        return false;
    }
    std::string s{};
    while(inputFile >> s)
    {
        std::cout << s << ' ';
    }

    return true;
}