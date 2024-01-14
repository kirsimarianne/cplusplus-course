/* Exercise 5:
 * Create a vector of pairs where each pair contains a string and an integer 
 * (like a name and an age). Sort the vector based on the integer.
 */ 
#include <algorithm>
#include <iostream>
#include <vector>

void sort_vector(std::vector<std::pair<std::string, int>>& vect)
{
    std::sort(vect.begin(), vect.end(),
    [](const auto& left, const auto& right) 
    { 
        return left.second < right.second; 
    });
}

void print_vector(const std::vector<std::pair<std::string, int>>& vect)
{
    for(auto element : vect)
    {
        std::cout<< "(" << element.first << " " << element.second << ") ";
    }
    std::cout << '\n';
}

int main()
{
    std::vector<std::pair<std::string, int>> pair_vect = {std::make_pair("ab", 1), std::make_pair("dddd", 2), 
                                                        std::make_pair("aa", 4), std::make_pair("aa", 1)};
    print_vector(pair_vect);
    sort_vector(pair_vect);
    print_vector(pair_vect);
}