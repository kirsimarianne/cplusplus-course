#include "openfile.h"

#include <iostream>
#include <fstream>


int main()
{

    std::cout << "File name:\n";
    std::string filename {};
    std::cin >> filename;

    if(!print_file_content(filename))
    {
        return 0;
    }


    return 0;
}