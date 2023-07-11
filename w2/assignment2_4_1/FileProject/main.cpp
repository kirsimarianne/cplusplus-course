#include "countchars.h"
#include "countlines.h"
#include "countstrings.h"
#include "printlines.h"

#include <filesystem>
#include <vector>
#include <algorithm>

//const std::string line = enum {-l, --lines};

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

    // Create an input file stream
    //std::ifstream input_file(argv[1]);

    // Check file can be opened

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
    else
    {
        
        for(size_t i = 2; i < 5; i++)
        {   
            std::ifstream input_file(argv[1]);
            if(!input_file.is_open())
            {
                std::cout << "Failed to open the file.\n";
                return 1;
            }
            if(std::string(argv[i]).compare("-l")==0 || std::string(argv[i]).compare("--lines")==0)
            {
                count_lines(input_file);
            }
            if(std::string(argv[i]).compare("-w")==0 || std::string(argv[i]).compare("--words")==0)
            {
                count_strings(input_file);
            }
            if(std::string(argv[i]).compare("-c")==0 || std::string(argv[i]).compare("--chars")==0)
            {
                count_chars(input_file);
            }
        }
    }

    std::filesystem::path directory_path{std::filesystem::current_path()};
    std::cout << "Path: " << directory_path;
    
    std::vector<std::string> textFiles;

    for(const auto& entry : std::filesystem::directory_iterator(directory_path))
    {
        if(entry.is_regular_file() && entry.path().extension()== ".txt")
        {
            textFiles.push_back(entry.path().filename().string());
        }
    }

    for(auto elem : textFiles)
    {
        std::cout << elem << ": " << std::filesystem::file_size(elem) << '\n';
    }

    return 0;
}