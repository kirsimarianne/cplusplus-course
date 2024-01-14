#include "../includes/utility.h"
#include <cctype>
#include <iostream>

/* Function gets string message as a parameter.
 * Gets input from user and changes the input to integer.
 * Returns -1 if changing string to integer fails.
 */
int get_int_input(std::string message)
{
    std::cout << message;
    std::string input{};
    std::getline(std::cin, input);
    int nmbr{};
    // Check input is int type
    try
    {
        nmbr = std::stoi(input);
        return nmbr;
    }
    catch (const std::invalid_argument &e)
    {
        return -1;
    }
    catch (const std::out_of_range &e)
    {
        return -1;
    }
}