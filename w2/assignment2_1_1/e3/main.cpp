/* Exercise 3:
 * Create a program that has a function that returns the sum of all the elements in an array. 
 * The vector will be filled automatically with different numbers
*/

#include <iostream>
#include <array>
#include <vector>
#include <numeric>
   

int main()
{
    std::array<int,10> arr{5, 2, 9, 1, 10, 8, 6, 3, 4, 7};
    
    std::cout << std::accumulate(arr.begin(), arr.end(), 0) << '\n';

    return 0;
}