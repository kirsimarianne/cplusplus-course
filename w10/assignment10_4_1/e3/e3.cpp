/* Exercise 3
 * Try nlohmann's json library.Links to an external site.  
 * Use it to read a json file from your hard drive and print the stored contents.  
 * (You can use e.g. json files from https://github.com/LearnWebCode/json-exampleLinks to an external site.)  
 * Then create a json file from your code and save that to your hard drive.
 * JSON is pretty common format to pass data around as a text.  
 * You are bound to run into it so this is quite useful (and commonly used) library for the task.
*/

#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>

using json = nlohmann::json;

int main()
{
    // Read json data from file.
    std::ifstream input_file("input.json");

    if(!input_file.is_open())
    {
        std::cerr << "Failed to open file.\n";
        return 1;
    }

    json data = json::parse(input_file);

    std::cout << data["name"] << "\n";
    std::cout << data["age"] << "\n";

    input_file.close();

    // Create json data to file.
    json person;
    person["name"] = "Pekka";
    person["age"] = 40;

    std::ofstream output_file("output.json");

    if(!output_file.is_open())
    {
        std::cerr << "Failed to open file for writing.\n";
        return 1;
    }

    output_file << std::setw(4) << person << "\n";
    output_file.close();

    std::cout << "Output file created!\n";

    return 0;

}