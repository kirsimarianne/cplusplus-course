/* Exercise 1:
 * Create a vector<int> with 10 numbers in it. 
 * Use std::partition to separate the even and odd numbers. 
 * Print out the vector after partitioning.
 */
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
   
void print(const std::vector<int>& v)
{
    for(auto element : v)
    {
        std::cout << element << ' ';
    }
}

int main()
{
    std::vector<int> v{5, 2, 9, 1, 10, 8, 6, 3, 4, 7};
    auto it = std::partition(v.begin(), v.end(), [](int i) {return i % 2 == 0;});
    print(v);

    return 0;
}