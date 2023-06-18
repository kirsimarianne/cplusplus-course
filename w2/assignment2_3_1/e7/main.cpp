/* Exercise 7:
 * Use std::partial_sort to find the top 5 elements from a vector of integers. 
 * The vector should have at least 20 elements.
 */

#include <algorithm>
#include <iostream>
#include <vector>

// Moves top 5 elements to end of the vector
void sort_vector_partial(std::vector<int>& vect)
{
    std::partial_sort(vect.rbegin(), vect.rbegin() + 5, vect.rend(), std::greater{});
}

void print_int_vector(const std::vector<int>& vect)
{
    for(auto element : vect)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}
 int main()
 {
    std::vector<int> vect = {5, 20, 11, 19, 16, 9, 7, 13, 1, 17, 15, 10, 3, 6, 12, 14, 4, 2, 18};
    print_int_vector(vect);
    sort_vector_partial(vect);
    print_int_vector(vect);
 }   