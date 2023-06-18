/* Exercise 4:
 * Create a vector of strings and sort them in lexicographical order. Also, sort them based on the string length.
 */

#include <algorithm>
#include <iostream>
#include <vector>



void sort_vector(std::vector<std::string>& vect)
{
    std::sort(vect.begin(), vect.end(), []
    (const std::string& first, const std::string& second){
        return first.size() < second.size();
    });
}

void print_vector(const std::vector<std::string>& vect)
{
    for(auto element : vect)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

int main()
{
    std::vector<std::string> string_vect = {"abc", "bbd", "aab", "a", "aa", "bbbda", "abca"};
    print_vector(string_vect);
    sort_vector(string_vect);
    print_vector(string_vect);
}