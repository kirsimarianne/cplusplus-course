/* Exercise 2
 * std::vector uses heap memory internally to store its contents.  
 * Create an std::vector, throw in some elements and print out 
 * the address of the vector itself and all of its elements.  
 * Think about what you see.  
 * Is the vector's position in the memory same as its contents?  Why?
*/
#include <iostream>
#include<vector>

int main()
{
    // Vector is in stack
    std::vector<int> vect = {1, 2, 3, 4};
    std::cout << &vect << "\n";
    // Elements are in heap 
    for(auto& elem : vect)
    {
        std::cout << &elem << "\n";
    }

    std::cout << &vect[0] << "\n";
    std::cout << &vect[1] << "\n";
}