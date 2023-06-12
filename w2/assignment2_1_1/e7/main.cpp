/* Exercise 7:
 * Create a function that will remove all instances of a value 
 * from the vector and inform if the value was found and removed.
*/

#include <iostream>
#include <vector>
#include <algorithm>


void print(const std::vector<int>& v){
    for(const auto& element : v)
    {
        std::cout << element << ' ';
    }
    std::cout << '\n';
}

bool remove_value(std::vector<int>& v, int value)
{
    bool found {false};
    auto it = v.begin();
    while(it != v.end())
    {
        if(*it == value)
        {
            it = v.erase(it);
            found = true;
        }
        else
        {
            ++it;
        }
    }
    return found;
}

int main()
{

    std::vector<int> vect {3, 2, 3, 4, 5, 1, 3};
    print(vect);
    if(remove_value(vect, 3) == true)
    {
        std::cout << "Value found and removed." << '\n';
        print(vect);
    }
    else
    {
        std::cout << "Value not found." << '\n';
    }

    return 0;
}