/* Exercise 6:
 * Create a function that will output the smallest and largest number in the list.
*/

#include <iostream>
#include <list>
#include <algorithm>


int main()
{
    std::list<int> l = {4, 3, 6, 1};
    const auto [min, max] = std::minmax_element(begin(l), end(l));
    std::cout << "min: " << *min << " max: " << *max << '\n';

    return 0;
}