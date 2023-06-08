#define NDEBUG
#include <cassert>
#include <iostream>
#include <string>

int divide(int dividend, int divisor)
{
    assert(divisor != 0 && "Division by zero not allowed");
    return dividend/divisor;
}    


int main() 
{
    assert(divide(4,2) && "division by zero not allowed");
    std::cout << "Test 1 passed" << "\n";

    assert(divide(4,0) && "division by zero not allowed");
    std::cout << "Test 2 passed" << "\n";
    
}