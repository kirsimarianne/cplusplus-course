/* Exercise 6:
 * Add a function that will output the smallest and largest number in the array.
 */
#include <iostream>
#include <array>
#include <algorithm>
   

int main()
{
    std::array<int, 10> a {5, 2, 9, 1, 10, 8, 6, 3, 4, 7};
    std::sort(a.begin(), a.end());
    std::cout << "Min: " << a[0] << " Max: " << a[a.size()-1] << '\n';
    return 0;
}