/*#define NDEBUG*/
#include <cassert>
#include <iostream>
#include <string>
#include <cmath>

int square_root(float numbr)
{   
    assert(numbr >= 0 && "Square root not defined for negative numbers") ;
    return sqrt(numbr);
}    


int main() 
{
    assert(square_root(5) && "Failed");
    std::cout << "Test 1 passed" << "\n";
    assert(square_root(-1) && "Failed");
    std::cout << "Test 2 passed" << "\n";
    
}