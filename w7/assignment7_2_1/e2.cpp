/* Exercise 2.
 * Create a function that takes arbitrary number of arguments and returns the sum of the
 * arguments.  How should you handle errors (such as argument not being a number) here?
 */

// (note to self: jos paluuarvo constexpr valikoi paluuarvon argumenttilistan esimmäisen muuttujan tyypin mukaan.)
#include <iostream>
#include <type_traits>
template <typename T, typename... Ts>
double sum(T &&first, Ts &&...rest)
{
    // Needs decay_type because of reference argument
    static_assert(std::is_arithmetic_v<std::decay_t <T>>, "Error, not arithmetic value");
    if constexpr (sizeof...(Ts) > 0)
    {
        return first + sum(rest...);
    }
    else
    {
        return first;
    }
}

int main()
{
    std::cout << sum(10, 3, 5.5f, -1, 5.55) << "\n";
    //std::cout << sum(10, 3, "moro", 1, -1) << "\n";
}