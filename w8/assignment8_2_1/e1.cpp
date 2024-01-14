/* Exercise 1
 * Create a function that takes universal reference as is argument (template T&&) to print out
 * whether or not its argument is an lvalue reference or an rvalue reference
 * Make a program and call the function to demonstrate both cases.
 */

#include <type_traits>
#include <iostream>

template <typename T>
void print_reference_type(T &&value)
{
    std::cout << std::boolalpha;
    std::cout << "is_lvalue " << std::is_lvalue_reference<T>::value << '\n';
    std::cout << "is_lvalue & " <<std::is_lvalue_reference<T&>::value << '\n';
    std::cout << "is_lvalue && " << std::is_lvalue_reference<T&&>::value << '\n';
    std::cout << "is_rvalue " << std::is_rvalue_reference<T>::value << '\n';
    std::cout << "is_rvalue & " << std::is_rvalue_reference<T&>::value << '\n';
    std::cout << "is_rvalue && " << std::is_rvalue_reference<T&&>::value << "\n\n";
}

int main()
{
    int value{};
    print_reference_type(value);
    print_reference_type(2);
}