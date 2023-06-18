/* Exercise 1: 
 * Write a program that sorts an array of integers in ascending order using std::sort
 * Exercise 2:
 * Use std::sort with std::greater<int>() to sort an array of integers in descending order.
 */

#include <algorithm>
#include <array>
#include <iostream>

void sort_array_ascending(std::array<int, 10>& arr)
{
    std::sort(arr.begin(), arr.end());
}

void sort_array_descending(std::array<int, 10>& arr)
{
    std::sort(arr.begin(), arr.end(), std::greater<int>());
}

void print_array(const std::array<int, 10>& vect)
{
    for(auto element : vect)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::array<int, 10> arr = {2, 4, 3, 2, 10, 5, 4, 2, 9, 8};
    print_array(arr);
    sort_array_ascending(arr);
    print_array(arr);
    sort_array_descending(arr);
    print_array(arr);
}