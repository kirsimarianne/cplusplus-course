/* Exercise 1
 * Create a table of functions (std::vector is fine).
 * Then read user input from command line, standard input or a file (your choice),
 * where user determines which function in the array to call.
 */

#include <functional>
#include <iostream>
#include <vector>

void function1()
{
    std::cout << "Function1 called.\n";
}

void function2()
{
    std::cout << "Function2 called\n";
}

void function3()
{
    std::cout << "Function3 called\n";
}

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << "Please give function as a comman-line argument\n";
        return 1;
    }

    std::string function_name{argv[1]};

    std::vector<std::function<void()>> functions = {
        function1,
        function2,
        function3};

    if(function_name == "function1")
    {
        functions[0]();
    }

    else if (function_name == "function2")
    {
        functions[1]();
    }

    else if(function_name == "function3")
    {
        functions[2]();
    }
    else{
        std::cout << "Incorrect input.\n";
    }

}
