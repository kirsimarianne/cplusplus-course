/* Exercise 4:
 * Create a  program that that prints out the product of all elements in an array
*/

#include <iostream>
#include <array>
#include <vector>
#include <numeric>
   

int main()
{
    std::array<int,10> arr{5, 2, 9, 1, 10, 8, 6, 3, 4, 7};

    int product {1};
    for(const auto& a : arr){
        product *= a;
    }
    
    std::cout << product << '\n';

    return 0;
}