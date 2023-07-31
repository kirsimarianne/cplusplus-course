/* Exercise 3.
 * In exercise 7.1.1. we created a function to check if two types are the same.  Expand on this
 * to check if any number of types given are all the same.
 */

#include <iostream>
#include <type_traits>

template <typename T, typename U>
bool is_same_type(const T&, const U&)
{
    return std::is_same_v<T, U>;
}

template <typename T, typename U, typename ...Ts>
bool is_same_type(const T& first, const U& second, const Ts&... others)
{
    return std::is_same<T, U>::value && is_same_type(second, others...);
}

int main()
{

    std::cout << is_same_type(2, 2, 'a', "moi") << "\n";
    std::cout << is_same_type(2.5f, 2.0f, 4.3f, 100.00f) << "\n";

    return 0;
}