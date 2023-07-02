/* Program can be used from command line or interface.
 * Program uses external library for reading commandline arguments.
 * Add, substract, multiply and divide are possible to use from command line.
 * All are possible to use from interface and also encrypt and decrypt functions.
 * Future development: 
 *  1) Add error handling to commandline use
 *  2) Add error handling for parsing string to double vector 
 *  in case where seperator is something else than comma.
 *  3) Combine user interface and command line reading if possible.
*/

#include "external/cxxopts/include/cxxopts.hpp"
//#define NDEBUG
#include <cassert>
#include <iostream>

#include "includes/utils.h"

const std::string INVALID_CMD = "Invalid command.";
const std::string INVALID_INPUT = "Invalid input.";
const std::string INVALID_VALUES = "Invalid values.";
const std::string INVALID_VALUES_AMOUNT = "Need at least two values";

/* Function returns false if any of possible divisors equals to zero.
 * Iteration starts from second value of vector, because first value (divinded)
 * is allowed to equal zero.
 */
bool check_divider_not_zero(std::vector<double> vect)
{
    std::vector<double>::iterator it = vect.begin();
    for (it = vect.begin() + 1; it != vect.end(); it++)
    {
        if (*it == 0)
        {
            return false;
        }
    }
    return true;
}

/* Function takes string as a parameter,
 * parses string, changes strings to double,
 * pushes doubles to vector and returns double vector.
 * Function throws exception if token can not be changed to double.
 * Future development: does not handle situation, where seperator is something else than comma.
 */
std::vector<double> parse_string_to_double(std::string str)
{
    std::vector<double> values_vect{};
    double value{};
    std::stringstream ss(str);
    std::string token{};
    while (std::getline(ss, token, ','))
    {
        try
        {
            value = std::stod(token);
        }
        catch (std::invalid_argument const &ex)
        {
            throw std::invalid_argument(std::string(INVALID_VALUES));
        }
        catch (std::out_of_range const &ex)
        {
            throw std::out_of_range(std::string(INVALID_VALUES));
        }
        values_vect.push_back(value);
    }
    return values_vect;
}

/* Function takes parameters: string cmd and string values.
 * Calls parse_string function and handles errors if function throws them.
 * Calls function from utils pointed in cmd.
 * Returns false, if cmd or values is invalid
 * Returns true if calculation is made.
 */
bool interface(std::string cmd, std::string values)
{

    if ((cmd == "encrypt") || (cmd == "e"))
    {
        std::string key_str{};
        int key{};
        std::cout << "Please give key as an integer:\n";
        std::getline(std::cin, key_str);
        try
        {
            key = std::stoi(key_str);
        }
        catch (std::invalid_argument const &ex)
        {
            std::cout << INVALID_INPUT << '\n';
            return false;
        }
        catch (std::out_of_range const &ex)
        {
            std::cout << INVALID_INPUT << '\n';
            return false;
        }
        std::cout << "Encrypted string: " << encrypt(values, key) << "\n";
        return true;
    }

    else if((cmd == "decrypt") || (cmd == "de"))
    {
        std::string key_str{};
        int key{};
        std::cout << "Please give key as an integer:\n";
        std::getline(std::cin, key_str);
        try
        {
            key = std::stoi(key_str);
        }
        catch (std::invalid_argument const &ex)
        {
            std::cout << INVALID_INPUT << '\n';
            return false;
        }
        catch (std::out_of_range const &ex)
        {
            std::cout << INVALID_INPUT << '\n';
            return false;
        }
        std::cout << "Decrypted string: " << decrypt(values, key) << "\n";
        return true;
    }

    // Call parse_string function to get vector of doubles
    std::vector<double> values_vect{};
    try
    {
        values_vect = parse_string_to_double(values);
    }
    catch (std::invalid_argument const &ex)
    {
        std::cout << ex.what() << "\n";
        return false;
    }
    catch (std::out_of_range const &ex)
    {
        std::cout << ex.what() << "\n";
        return false;
    }

    // Check that vector has more than one values.
    if (values_vect.size() < 2)
    {
        std::cout << INVALID_VALUES_AMOUNT << "\n";
        return false;
    }

    if ((cmd == "add") || (cmd == "a"))
    {
        std::cout << add(values_vect) << '\n';
    }
    else if ((cmd == "subtract") || (cmd == "s"))
    {
        std::cout << subtract(values_vect) << '\n';
    }
    else if (cmd == "multiply" || (cmd == "m"))
    {
        std::cout << multiply(values_vect) << '\n';
    }
    else if (cmd == "divide" || (cmd == "d"))
    {
        if (check_divider_not_zero(values_vect))
        {
            std::cout << divide(values_vect) << '\n';
        }
        else
        {
            std::cout << "infinity\n";
        }
    }
    else
    {
        std::cout << INVALID_CMD << "\n";
        return false;
    }
    return true;
}

int main(int argc, char **argv)
{
    assert(interface("a", "1,2,3") == true); 
    assert(interface("add", "1.0,2.0") == true);
    assert(interface("s", "1.00,0.5") == true);
    assert(interface("subtract", "1.0,2.9") == true);
    assert(interface("m", "1,2,3") == true);
    assert(interface("multiply", "5.0,5.05") == true);
    assert(interface("d", "1,2,3") == true);
    assert(interface("divide", "5.0,5.05") == true);
    assert(interface("divide", "5.0,0") == true);
    assert(interface("", "5.0,5.5") == false);
    assert(interface("jdkas", "1,2,3") == false);
    assert(interface("a", "") == false);
    assert(interface("a", "ss,aaaa") == false);  
    assert(interface("a", "ss") == false);  
    assert(interface("a", "ss,1,2") == false);     
    // Does not handle invalid seperator.
    //assert(get_calculation("a", "1 2 3") == false);

    if (argc == 1)
    {
        std::cout << "Choose operation: \na or add \ns or subtract \nm or multiply \nd or divide\ne or encrypt\nde or decrypt\n";
        std::string cmd{};
        std::getline(std::cin, cmd);
        std::string values{};
        if ((cmd == "encrypt") || (cmd == "e") || (cmd == "decrypt") || (cmd == "de"))
        {
            std::cout << "Please give string:\n";
            std::getline(std::cin, values);
        }
        else
        {
            std::cout << "Please give values seperated by comma:\n";
            std::getline(std::cin, values);
        }
        interface(cmd, values);
        return 0;
    }

    cxxopts::Options options("Calculator", "This program supports addition, subtraction, multiplication and division");
    //("s,sum", "Sum two values", cxxopts::value<std::vector<int>>())
    cxxopts:options.add_options()
    ("vector", "A list of doubles", cxxopts::value<std::vector<double>>())
    ("a,add", "Sum of values", cxxopts::value<std::vector<double>>())
    ("s,subtract", "Difference of values", cxxopts::value<std::vector<double>>())
    ("m,multiply", "Product of values", cxxopts::value<std::vector<double>>())
    ("d,divide", "Quotient of values", cxxopts::value<std::vector<double>>())
    ("h,help", "Print usage");
    //("i,integer", "Int param", cxxopts::value<int>())
    //("f,file", "File name", cxxopts::value<std::string>())
    //("v,verbose", "Verbose output", cxxopts::value<bool>()->default_value("false"))

    auto result = options.parse(argc, argv);

    if (result.count("help"))
    {
        std::cout << options.help() << '\n';
        return 0;
    }
    if (result.count("add"))
    {
        const std::vector<double> values = result["add"].as<std::vector<double>>();
        std::cout << add(values) << '\n';
    }
    if (result.count("subtract"))
    {
        std::vector<double> values = result["subtract"].as<std::vector<double>>();
        std::cout << subtract(values) << '\n';
    }
    if (result.count("multiply"))
    {
        const std::vector<double> values = result["multiply"].as<std::vector<double>>();
        std::cout << multiply(values) << '\n';
    }

    if (result.count("divide"))
    {
        std::vector<double> values = result["divide"].as<std::vector<double>>();
        if (check_divider_not_zero(values))
        {
            std::cout << divide(values) << '\n';
        }
        else
        {
            std::cout << "infinity\n";
        }
    }

    if (result.count("vector"))
    {
        std::cout << "vector = ";
        auto values = result["vector"].as<std::vector<double>>();
        for (auto &v : values)
        {
            std::cout << v << ", ";
        }
        std::cout << std::endl;
    }
}