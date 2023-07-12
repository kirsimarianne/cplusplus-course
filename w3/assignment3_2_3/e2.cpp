/* Exercise 2
 * Write a recursive function that finds the Greatest Common Divisor of two numbers.
*/

#include <algorithm>
#include <iostream>

int greatest_common_divisor(int x, int y)
{
    if(x < y)
    {
        std::swap(x,y);
    }
    if(x % y == 0)
    {
        return y;
    }
    return greatest_common_divisor(y, x%y);
}

int main()
{
    std::cout << "Give first integer: ";
    int x {};
    std::cin >> x;
    std::cout << "Give second integer: ";
    int y {};
    std::cin >> y;
    std::cout << "The greatest common divisor is: " << greatest_common_divisor(x, y) << "\n";
}