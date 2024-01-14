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

// Exercise 4: create some combinations.
// Ghost is fuzzy and has googly eyes
//constexpr static uint8_t IS_GHOST = 0b00000101;
// Dog is cute, has teeth and is friendly.
//constexpr static uint8_t IS_DOG = 0b01011000;
// Monster is large, has googly eyes, has teeth and is about to eat you
//constexpr static uint8_t IS_MONSTER = 0b00110110;

/* Exercise 3
 * Prints the flags that flagset contains.
 */
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

/* Exercise 4
 * Check if flagset is one of created combinations.
 */
void check_combination(const Flagset &flagset)
{
    if ((flagset & IS_FUZZY) && (flagset & HAS_GOOGLY_EYES))
    {
        std::cout << "Is a ghost!\n";
    }
    if ((flagset & IS_CUTE) && (flagset & HAS_TEETH) && (flagset & IS_FRIENDLY))
    {
        std::cout << "Is a dog!\n";
    }
    if ((flagset & IS_LARGE) && (flagset & HAS_GOOGLY_EYES) && (flagset & HAS_TEETH) && (flagset & IS_ABOUT_TO_EAT_YOU))
    {
        std::cout << "Is a monster!\n";
    }
}

/* For testing purposes.
 */
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

    Flagset flagset1 = IS_FUZZY | HAS_GOOGLY_EYES;
    Flagset flagset2 = IS_CUTE | HAS_TEETH | IS_FRIENDLY;
    Flagset flagset3 = HAS_GOOGLY_EYES | IS_ABOUT_TO_EAT_YOU;
    Flagset flagset4 = IS_LARGE | HAS_GOOGLY_EYES | HAS_TEETH | IS_ABOUT_TO_EAT_YOU;

    print_bits(flagset1);
    print_flagset(flagset1);
    check_combination(flagset1);

    print_bits(flagset2);
    print_flagset(flagset2);
    check_combination(flagset2);

    print_bits(flagset3);
    print_flagset(flagset3);
    check_combination(flagset3);

    print_bits(flagset4);
    print_flagset(flagset4);
    check_combination(flagset4);
}
