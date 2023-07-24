#include <iostream>

template <typename T>
constexpr void print_decay_type()
{
    using decay_type = std::decay_t<T>;

    std::cout << "is_const_v<T> " << std::is_const_v<T> << "\n";
    std::cout << "is_const_v<decay_type> " << std::is_const_v<decay_type> << "\n";
    std::cout << "is_reference_v<T> " << std::is_reference_v<T> << "\n";
    std::cout << "is_reference_v<decay_type> " << std::is_reference_v<decay_type> << "\n";
    std::cout << "is_pointer_v<T> " << std::is_pointer_v<T> << "\n";
    std::cout << "is_pointer_v<decay_type> " << std::is_pointer_v<decay_type> << "\n";
    std::cout << "is_array_v<T> " << std::is_array_v<T> << "\n";
    std::cout << "is_array_v<decay_type> " << std::is_array_v<decay_type> << "\n";
}

int main()
{
    std::cout << "int \n";
    print_decay_type<int>();
    std::cout << "\nconst int \n";
    print_decay_type<const int>();
    std::cout << "\nint& \n";
    print_decay_type<int &>();
    std::cout << "\nint* \n";
    print_decay_type<int*>();
    std::cout << "\nint[] \n";
    print_decay_type<int[]>();
}