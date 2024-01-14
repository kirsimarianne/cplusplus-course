/* Exercise 5:
 * Create a program that will ask the user for the size of a vector.
*/

#include <iostream>
#include <vector>   

int main()
{
    int size {};
    std::cout << "Size of vector:" << '\n';
    std::cin >> size;

    std::vector<int> v(size);
    std::cout << "Size is: " << v.size() << '\n';

    return 0;
}