/* Exercise 3:
 * Create a program that has a function that returns the sum of all the elements in an array. 
 * The vector will be filled automatically with different numbers
*/

#include <iostream>
#include <array>
#include <numeric>

int get_sum(const std::array<int, 10> arr)
{
    return std::accumulate(arr.begin(), arr.end(), 0);
}
   

int main()
{
    std::array<int,10> arr{1, 2, 1, 2}; 
    std::cout << "Sum is: " << get_sum(arr) << '\n';

    return 0;
}