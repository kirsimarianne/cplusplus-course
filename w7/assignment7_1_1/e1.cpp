#include <iostream>

template <typename T>
constexpr bool is_same_type(T, T)
{
    return true;
}

template <typename T, typename U>
constexpr bool is_same_type(T, U)
{
    return false;
}

int main()
{

    std::cout << is_same_type(2, 2) << "\n";
    std::cout << is_same_type(2.5, 2) << "\n";

    return 0;
}