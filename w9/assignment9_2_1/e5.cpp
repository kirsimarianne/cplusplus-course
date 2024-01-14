/* Exercise 5
 * Bitmasking is a technique to mark locations of certain values.  We now want to create a bitmask from a string input.
 * Create a program, where you let user input a string (either read it from command line or use I/O functions,
 * it doesn't matter as long as the string is given by the end-user)  You may assign a max size for the string.
 * Go through bytes in the string, and for each character of the string, mark the bit set if the character represents a comma.
 * Print out the resulting bits.
 * e.g. ( "123,43,55" would produce a value of 0b1001000, as fourth and seventh character is a comma)
 */

#include <iostream>
#include <bit>
#include <cstdint>

// Function prints bits
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
    const int MAX_SIZE = 16;
    std::cout << "Please enter a string:\n";
    std::string input;
    std::getline(std::cin, input);

    if(input.size() > MAX_SIZE )
    {
        std::cout << "String can be maximum " << MAX_SIZE << " characters long.\n";
        return 1;
    }

    uint16_t result = 0b0;
    uint16_t bitmask = 0b1;
    // shift setted value to left side
    bitmask = bitmask << 15;


    for(int i = 0; i < MAX_SIZE; ++i)
    {
        if(input[i] == ',')
        {   
            //Use bitmask to change bit to 1
            result = result | bitmask;
        }
        // Shift setted value one step to right for the next iteration
        bitmask = bitmask >> 1;
    }

    print_bits(result);


    
}