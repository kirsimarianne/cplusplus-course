/* Exercise 1:
 * Create an array with 10 random numbers in it. 
 * Your program should also be able to output the elements in the array.
*/

#include <iostream>
#include <array>

void print(const std::array<int, 10>& arr)
{
    for(const auto& element : arr)
     {
        std::cout << element << ' ';
     }
}

int main()
{
    std::array<int, 10> arr{5, 2, 9, 1, 10, 8, 6, 3, 4, 7};
    print(arr);
}