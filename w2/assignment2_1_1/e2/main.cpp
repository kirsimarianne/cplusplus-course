/* Exercise 2:
 * Add a function that receives an std::array and a number, 
 * and checks whether the number is in the array. 
 * The function should return a boolean value.
*/

#include <iostream>
#include <array>
#include <algorithm>

bool find_number(const std::array<int, 10>& arr, const int& n)
{
    auto it = std::find(arr.begin(), arr.end(), n);
    if(it != arr.end())
    {
        return true;
    }
    return false;
}    

int main()
{
    std::array<int, 10> arr{5, 2, 9, 1, 10, 8, 6, 3, 4, 7};
    std::cout << "array contains 2: " << find_number(arr, 2) << '\n';
    std::cout << "array contains 15: " << find_number(arr, 15) << '\n';
}