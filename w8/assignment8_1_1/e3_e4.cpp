/* Exercise 3
 * Elements being contiguous in memory is an important concept.
 * This means they are located in the memory one after another.
 * Create a (template) function that takes a container as its input,
 * and checks if the elements in the container are next to each other.
 * Create few container types (list, vector, array, deque) and check if this holds true.
 * Try it with different counts of elements (e.g. with 1000, 1000000, 100000000 elements)
 */

#include <iostream>
#include <array>
#include <deque>
#include <list>
#include <vector>
#include <unordered_map>

// Can be assumed parameter is a container
template <typename Sequence>
bool elements_next_to(Sequence s)
{
    for (auto it = s.begin(); it != s.end(); ++it)
    {

        auto next_it = std::next(it);
        if (next_it != s.end())
        {
            // Difference between iterator and next iterator should be 1
            // Otherwise elements are not net to each others and return false.
            if (!((&(*it) - &(*(next_it)) == 1) || (&(*it) - &(*(next_it)) == -1)))
            {

                return false;
            }
        }
    }
    return true;
}

int main()
{
    std::list<int> list(10000);
    std::vector<int> vect(10000);
    std::array<int, 10000> arr{};
    std::deque<int> deq(10000);
    std::unordered_map<int,int> umap(10000000);
    // Exercixe 4
    // Check if std::vector of std::vectors is contiguous.
    std::vector<std::vector<int>> vect2(1000000);

    std::cout << elements_next_to(list) << "\n";
    std::cout << elements_next_to(vect) << "\n";
    std::cout << elements_next_to(arr) << "\n";
    std::cout << elements_next_to(deq) << "\n";
    std::cout << elements_next_to(umap) << "\n";
    std::cout << elements_next_to(vect2) << "\n";
}
