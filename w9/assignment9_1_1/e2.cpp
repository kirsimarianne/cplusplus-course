#include <cmath>
#include <functional>
#include <iostream>
#include <stdexcept>
#include <unordered_map>

using Value = double;
using Calculator = std::unordered_map<char, std::function<Value(Value, Value)>>;

Value add(Value left, Value right)
{
    return round((left + right)*100)/100;
}

Value subtract(Value left, Value right)
{
    return round((left - right)*100)/100;
}

Value multiply(Value left, Value right)
{
    return round((left * right)*100)/100;
}

Value divide(Value left, Value right)
{
    if (right == 0)
    {
        throw std::runtime_error("Undefined");
    }

    return round((left / right)*100)/100;
}

Value exponent(Value left, Value right)
{
    return round((pow(left, right))*100)/100;
}


int main(int argc, char **argv)
{
    /* Check at least 3 arguments are given.
     */
    if (argc < 4)
    {
        std::cout << "Please give command line arguments: at least two values and operator between them seprated by space.\n";
        return 1;
    }

    /* Calculator map, operations as a key, functions as a value.
     */
    Calculator calculator = {
        {'+', add},
        {'-', subtract},
        {'*', multiply},
        {'/', divide},
        {'^', exponent}};

    /* Inits left value with first argument.
     * Throws exception if variable not double.
     */
    Value left_value{};
    try
    {
        left_value = std::stod(argv[1]);
    }
    catch (std::exception &e)
    {
        std::cout << "Invalid value."
                  << "\n";
        return 1;
    }

    /* Loops arguments vector.
     * Handles opration and right value in every loop.
     * Adds result to left value.
     * Throws exception if value is not double.
     * Prints error message if operation is not found.
     */
    Value right_value{};
    char *operation{};
    for (int i = 2; i < argc; i = i + 2)
    {
        try
        {
            right_value = std::stod(argv[i + 1]);
        }
        catch (std::exception &e)
        {
            std::cout << "Invalid value. * needs \\ infront of it"
                      << "\n";
            return 1;
        }

        // Find operation from map.
        auto it = calculator.find(*argv[i]);

        if (it == calculator.end())
        {
            std::cout << "Operation not found.\n";
        }
        // Add result to left value for next loop.
        left_value = it->second(left_value, right_value);
    }

    std::cout << "Result: " << left_value << "\n";
}