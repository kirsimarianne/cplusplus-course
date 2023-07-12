/* Exercise 1
 * Write a recursive function that takes a string as input and returns the string reversed.
*/

#include <iostream>
#include <algorithm>

std::string reverse_string(std::string str, int start, int end)
{
    if(start >= end)
    {
        return str;
    }
    std::swap(str.at(start), str.at(end));
    return reverse_string(str, start+1, end-1);
}

int main()
{
    std::cout << "Give string: ";
    std::string str{};
    std::getline(std::cin, str);
    std::cout << "Reversed string is: " << reverse_string(str, 0, str.size()-1) << "\n";
}