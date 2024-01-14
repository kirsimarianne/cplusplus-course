/* Create a std::list<int> with 10 elements. 
 * Use std::adjacent_find to find the first two adjacent elements that are equal. 
 * If no such elements exist, print a suitable message.
 */
#include <iostream>
#include <list>
#include <algorithm>
#include <iterator>
   
void print(const std::list<int>& l)
{
    for(auto element : l)
    {
        std::cout << element << ' ';
    }
}

void find_first_adjacent_elements(const std::list<int>& l)
{
    auto it = std::adjacent_find(l.begin(), l.end());
 
    if (it == l.end())
        std::cout << "No matching adjacent elements\n";
    else
        std::cout << "The first adjacent pair of equal elements is at "
                  << std::distance(l.begin(), it) << ", *i1 = "
                  << *it << '\n';
}


int main()
{
    std::list<int> l{5, 2, 9, 1, 10, 10, 6, 3, 4, 7};   
    find_first_adjacent_elements(l);
    print(l);
    return 0;
}