/* Exercise 3.
 * In exercise 7.1.1. we created a function to check if two types are the same.  Expand on this
 * to check if any number of types given are all the same.
 */

#include <iostream>

template <typename T>
constexpr bool is_same_type(T, T)
{
    return true;
}

template <typename T, typename U, typename ...Ts>
constexpr bool is_same_type(T, U)
{
    return false;
}

int main()
{

    std::cout << is_same_type(2, 2, 5.5f, "moi") << "\n";
    std::cout << is_same_type(2.5f, 2.0f, 4.3f, 100.00f) << "\n";

    return 0;
}