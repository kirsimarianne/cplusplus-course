#include <iostream>

int function_x()
{
    static int x{0};
    return ++x;
}    

int main()
{

std::cout << function_x() << std::endl; // prints 1
std::cout << function_x() << std::endl; // prints 2
std::cout << function_x() << std::endl; // prints 3

std::cout << x << std::endl; // x ei näy tänne

// eli staattisen muuttujan näkyvyys funktion sisällä,
// mutta elinikä koko ohjelman ajan.

}