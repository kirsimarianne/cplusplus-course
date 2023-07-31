/* Exercise 5.
 * Create a function that takes arbitrary number of containers as arguments and creates a
 * concatenated container.  (e.g. concatenate(std::vector{1, 2}, std::list{5, 8}) -> std::vector{1, 2, 5, 8};
 */

#include <algorithm>
#include <iostream>
#include <vector>
#include <list>

template <typename T, typename U>
T combine_containers(const T &first, const U &second)
{
    T result {};
    result.insert(result.end(), first.begin(), first.end());
    result.insert(result.end(), second.begin(), second.end());
    return result;
}

template <typename T, typename... Ts>
T combine_containers(const T &first, const Ts &...rest)
{
    T result = combine_containers(first, combine_containers(rest...));
    return result;
}

int main()
{
    std::vector<int> vect1 = {2, 5, 20, 7, 14};
    std::list<int> list1 = {25, 77, 56};
    std::vector<int> vect2 = {0, 1, 2, 3, 4};

    std::vector<int> vect_result = combine_containers(vect1, list1, vect2);

    for (const auto &elem : vect_result)
    {
        std::cout << elem << " ";
    }
    std::cout << "\n";
}
