#include <cassert>
#include <iostream>
#include <string>

int sum(int numbr1, int numbr2)
{
    return numbr1+numbr2;
}    


int main() 
{
    assert(sum(4, 4) > 0 && "Sum(4, 4) is negative");
    std::cout << "The sum(4, 4) is positive" << "\n";
    assert(sum(-1, -2) > 0 && "Sum(-1, -2) is negative");
    std::cout << "The sum(-1, -2) is positive" << "\n";
    assert(sum(1, -2) > 0 && "Sum(1, -2) is negative");
    std::cout << "The sum(1, -2) is positive" << "\n";
    
}