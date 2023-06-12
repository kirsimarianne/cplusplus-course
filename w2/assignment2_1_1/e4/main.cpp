/* Exercise 4:
 * Create a  program that that prints out the product of all elements in an array
*/

#include <iostream>
#include <array>
#include <numeric>
   
int get_product(const std::array<int, 4>& arr)   
{
    int product {1};
    for(const auto& element : arr){
        product *= element;
    }
    return product;
}

int main()
{
    std::array<int,4> arr{1, 2, 3, 1};
    std::cout << "Product is: " << get_product(arr) << '\n';

    return 0;
}