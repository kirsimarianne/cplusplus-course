#include <iostream>
#include <cstdint>

using Flagset = uint8_t;

constexpr static uint8_t IS_FUZZY = 0b1;
constexpr static uint8_t IS_LARGE = 0b10;
constexpr static uint8_t HAS_GOOGLY_EYES = 0b100;
constexpr static uint8_t IS_CUTE = 0b1000;
constexpr static uint8_t HAS_TEETH = 0b10000;
constexpr static uint8_t IS_ABOUT_TO_EAT_YOU = 0b100000;
constexpr static uint8_t IS_FRIENDLY = 0b1000000;
constexpr static uint8_t IS_SPIDER = 0b10000000;

void print_flagset(const Flagset &flagset)
{
    if (flagset & IS_FUZZY)
    {
        std::cout << "Is fuzzy.\n";
    }
    if (flagset & IS_LARGE)
    {
        std::cout << "Is large.\n";
    }
    if (flagset & HAS_GOOGLY_EYES)
    {
        std::cout << "Has googly eyes.\n";
    }
    if (flagset & IS_CUTE)
    {
        std::cout << "Is cute.\n";
    }
    if (flagset & HAS_TEETH)
    {
        std::cout << "Has teeth.\n";
    }
    if (flagset & IS_ABOUT_TO_EAT_YOU)
    {
        std::cout << "Is about to eat you.\n";
    }
    if (flagset & IS_FRIENDLY)
    {
        std::cout << "Is friendly.\n";
    }
    if (flagset & IS_SPIDER)
    {
        std::cout << "Is spider.\n";
    }
}

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

int main()
{
    Flagset flagset1 = IS_LARGE | IS_FUZZY;
    Flagset flagset2 = IS_CUTE | HAS_TEETH | IS_FRIENDLY;
    Flagset flagset3 = HAS_GOOGLY_EYES | IS_ABOUT_TO_EAT_YOU | IS_SPIDER;

    print_bits(flagset1);
    print_flagset(flagset1);

    print_bits(flagset2);
    print_flagset(flagset2);

    print_bits(flagset3);
    print_flagset(flagset3);
}
