#include "utility.h"

/* Function gets string as a parameter,
 * converts string to int and returns integer.
 * Throws exception if converting fails.
*/
int string_to_int(std::string str)
{
    int integer{};
    try
    {
        integer = std::stoi(str);
    }
    catch (const std::invalid_argument &e)
    {
        throw e;
    }
    catch (const std::out_of_range &e)
    {
        throw e;
    }
    return integer;
}

/* Function gets string as a parameter
 * converts string to double and returns doubel type numeber.
 * Throws exception if converting fails.
*/

double string_to_double(std::string str)
{
    double number{};
    try
    {
        number = std::stod(str);
    }
    catch (const std::invalid_argument &e)
    {
        throw e;
    }
    catch (const std::out_of_range &e)
    {
        throw e;
    }
    return number;
}

/* Function takes douböe type number as a parameter,
 * returns false if number has more than 2 decimals otherwise returns true.
*/

bool max_two_decimals(double number)
{
    // Multiple 100, to get 2 decomals to integer side.
    number *= 100;

    double integer_part;
    // modf returns number without integer part, for example 200.34 => 0.34
    double fractional_part = std::modf(number, &integer_part);
    if(fractional_part != 0.0)
    {
        return false;
    }
    return true;
}
