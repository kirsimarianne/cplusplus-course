/* Exercise 8:
 * Create a vector of pairs with repeating first elements. 
 * After sorting, check if the pairs with equal first elements maintain their relative order.
*/

#include <algorithm>
#include <iostream>
#include <vector>

void sort_pair_vector(std::vector<std::pair<int, int>>& vect)
{
    std::sort(vect.begin(), vect.end());
}

void print_pair_vector(const std::vector<std::pair<int, int>>& vect)
{
    for(auto element : vect)
    {
        std::cout<< "(" << element.first << " " << element.second << ") ";
    }
    std::cout << '\n';
}

int main()
{
    std::vector<std::pair<int,int>> v = {std::make_pair(1,2), std::make_pair(3, 4), std::make_pair(1,3), std::make_pair(1,1),std::make_pair(0,9), std::make_pair(0,0)};
    print_pair_vector(v);
    sort_pair_vector(v);
    print_pair_vector(v); 
    // pairs with equal first elements maintain their relative order.
}