#include "countchars.h"
#include "countlines.h"
#include "countstrings.h"
#include "printlines.h"

#include <filesystem>
#include <vector>
#include <algorithm>


void read_cmds(int argc, char** argv)
{
  
    auto it = std::find(argv+1, argv+argc, "-l");
    if(it != argv+argc)
    {
        std::cout << "-l found!";
    }
   
}

int main(int argc, char** argv)
{
    read_cmds(argc, argv);

    // Check amount of arguments
    if(argc < 2)
    {
        std::cout << "Please give filename as a comman-line argument" << std::endl;
        return 1;
    }

    // if file is only argument
    if(argc == 2)
    {
        std::ifstream input_file(argv[1]);
        if(!input_file.is_open())
        {
            std::cout << "Failed to open the file.\n";
            return 1;
        }
        print_file_content(input_file);

    }
    //loop arguments, quit program if false argument
    else 
    {
        
        for(size_t i = 2; i < argc; i++)
        {   
            std::ifstream input_file(argv[1]);
            if(!input_file.is_open())
            {
                std::cout << "Failed to open the file.\n";
                return 1;
            }
            else if(std::string(argv[i]).compare("-l")==0|| std::string(argv[i]).compare("--lines")==0)
            {
                count_lines(input_file);
            }
            else if(std::string(argv[i]).compare("-w")==0 || std::string(argv[i]).compare("--words")==0)
            {
                count_strings(input_file);
            }
            else if(std::string(argv[i]).compare("-c")==0 || std::string(argv[i]).compare("--chars")==0)
            {
                count_chars(input_file);
            }
            else{
                std::cout << "False argument: " << argv[i] << '\n';
                return 1;
            }
        }
    }

    // Find path
    std::filesystem::path directory_path{std::filesystem::current_path()};
    std::cout << "Path: " << directory_path;
    
    std::vector<std::string> textFiles;
    // Find files and store them in vector
    for(const auto& entry : std::filesystem::directory_iterator(directory_path))
    {
        if(entry.is_regular_file() && entry.path().extension()== ".txt")
        {
            textFiles.push_back(entry.path().filename().string());
        }
    }

    // print size of the file
    for(auto elem : textFiles)
    {
        std::cout << elem << " size : " << std::filesystem::file_size(elem) << '\n';
    }

    return 0;
}