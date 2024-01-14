/* Exercise 1
 * Create a function to check if nth bit is set in an value.
*/

#include <cstdint>
#include <iostream>
#include <vector>

template <typename T>
bool is_set(const T& value, const int n)
{
         return (value & (1 << n));
}

template <typename T>
void print_bits(const T& value)
{
    using decay_type = std::decay_t<T>;

    std::cout << "0b";

    for(int i = sizeof(decay_type) * 8 - 1; i >= 0; --i)
    {
         std::cout << (value & (1 << i) ? 1 : 0);
    }
    std::cout << "\n";
}


int main()

{
    uint16_t value = 500;
    int n {5};
    print_bits(value);
    std::cout << n << "th bit is: " << is_set(value, n) << "\n";

}