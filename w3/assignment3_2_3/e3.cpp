/* Exercise 3
 * Write a recursive function to calculate the power of a number. 
 * Your recursive function should be able to handle any size of x to the power of n.
*/

#include <iostream>

int power(int x, int n)
{
    if(n == 1)
    {
        return x;
    }
    return power(x*x,n-1);
}

int main()
{
    std::cout << "Give value: ";
    int x {};
    std::cin >> x;
    std::cout << "Give power: ";
    int n {};
    std::cin >> n;
    std::cout << "Result is: " << power(x, n) << "\n";

}