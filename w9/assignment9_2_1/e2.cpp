#include <bit>
#include <iostream>

template <typename T>
void print_bits(const T &value)
{
    using decay_type = std::decay_t<T>;

    std::cout << "0b";

    for (int i = sizeof(decay_type) * 8 - 1; i >= 0; --i)
    {
        std::cout << (value & (1 << i) ? 1 : 0);
    }
    std::cout << "\n";
}

template <typename T>
T swap(const T &value)
{
    T result = 0;
    size_t size = sizeof(T);
    for(size_t i = 0; i < size; ++i)
    {
        result <<= 8;
        result |= (value >> (8 * i) & 0xFF);
    }

    return result;
}

int main()
{
    uint32_t value = 5;
    std::cout << value << "\n";
    print_bits(value);
    value = swap(value);
    std::cout << value << "\n";
    print_bits(value);
}
