#include <iostream>

namespace my_space{
    int number {1};
}

int main()
{
    int number {5};

    std::cout << number<< '\n'; // prints local scope variable
    std::cout << my_space::number << '\n'; // prints the variable in namespace my_space

    return 0;
}