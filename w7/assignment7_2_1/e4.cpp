/* Exercise 4.
 * Create a function that takes arbitrary number of arguments and return the product of the
 * arguments times the number of arguments.
 */

#include <iostream>

template<typename ... Ts>
double product(Ts&&... values)
{
    return (values* ...);
}

int main()
{
    std::cout << "product: " << product(1, 2, 3, 0.5) << "\n";
}