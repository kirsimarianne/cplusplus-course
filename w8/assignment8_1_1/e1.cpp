/* Exercise 1
 * Create a stack variable of any fundamental type in main() function (so just an usual declaration).  Then print out
 * its memory address.
 * Create a function in the same program and do the same.  Compute the difference between the addresses and
 * print that out too.
*/

#include <cstdint>
#include <iostream>

void my_function()
{
}

int main()
{
    int16_t stack_variable {};
    std::cout << &stack_variable<< "\n";
    void (*function_pointer)() {&my_function};
    // This gives 1, which is wrong
    std::cout << function_pointer << "\n";
    // This gives addresses in hexadesimals
    auto address1 = reinterpret_cast<int*>(&stack_variable);
    auto address2 = reinterpret_cast<int*>(function_pointer);
    std::cout << address2 << "\n";
    std::cout << "Difference: " << address1 - address2 << "\n";
}
