#include <functional>
#include <iostream>
#include <stdexcept>
#include <unordered_map>
#include <vector>

using Values = std::vector<double>;
using Calculator = std::unordered_map<char, std::function<double(Values)>>;

double add(Values values)
{
    double sum{};
    for (const auto &elem : values)
    {
        sum = sum + elem;
    }
    return sum;
}

double subtract(Values values)
{
    double sub{};
    for (const auto &elem : values)
    {
        sub = sub - elem;
    }
    return sub;
}

double multiply(Values values)
{
    double product{};
    for (const auto &elem : values)
    {
        product = product * elem;
    }
    return product;
}

double divide(Values values)
{
    double div{values[0]};
    for (int i = 1; i < values.size(); ++i)
    {
        if (values[i] == 0)
        {
            throw std::runtime_error("Undefined");
        }
        div = div / values[i];
    }
    return div;
}

int main(int argc, char **argv)
{

    if (argc < 4)
    {
        std::cout << "Please give as command line arguments: operator and at least two values seperated by space.\n";
        return 1;
    }

    Values values{};
    char *operation = argv[1];
    for (int i = 2; i < argc; i=i+2)
    {
        try
        {
            values.push_back(std::stod(argv[i]));
        }
        catch(std::exception &e)
        {
            std::cout << "Invalid value." << "\n";
            return 1;
        }
    }

    Calculator calculator = {
        {'+', add},
        {'-', subtract},
        {'*', multiply},
        {'/', divide}};

    auto it = calculator.find(*operation);

    if (it == calculator.end())
    {
        std::cout << "Operation not found.\n";
    }

    std::cout << "Result: " << it->second(values) << "\n";
}