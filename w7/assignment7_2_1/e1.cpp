#include <iostream>

/* Exercise 1a.
 * Create a function with an integer template parameters, that prints out the first integer
 * value, and then calls the function with remaining values.  Break the recursion using
 * overload resolution.
 */

/* Base case: only one value left.
 */
template <typename T>
void print(T first)
{
    std::cout << first << "\n";
}

/* Recursively called function to print values one by one.
 */
template <typename T, typename... Ts>
void print(T &&first, Ts &&...rest)
{
    std::cout << first << ", ";
    print(rest...);
}

/* Exercise 1b.
 * Create a function with an integer template parameters, that prints out the first integer
 * value, and then calls the function with remaining values.  Break the recursion using
 * if contexpr
 */
template <typename T, typename... Ts>
void print2(T &&first, Ts &&...rest)
{
    std::cout << first;
    if constexpr (sizeof...(Ts) > 0)
    {
        std::cout << ", ";
        print2(rest...);
    }
    else
    {
        std::cout << "\n";
    }
}

int main()
{
    print(1.938733, -373, 30, 28, -4);

    print2(1, 3.9, 1000, 50.737, -8);

    return 0;
}