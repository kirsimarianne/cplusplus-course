#include <cassert>
#include <iostream>
#include <string>

int factorial(int n)
{
    int factorial {};
    for(int i = 0; i < n; i++)
    {
        factorial = n*(n-i);
    }
    return factorial;
}


int main() 
{
    assert(factorial(1) > 0 && "Not defined for negative numbers");
    std::cout << "Test 1 passed" << std::endl;
    assert(factorial(100) > 0 && "Not defined for negative numbers");
    std::cout << "Test 2 passed" << std::endl;
    assert(factorial(-1) > 0 && "Not defined for negative numbers");
    std::cout << "Test 3 passed" << std::endl;
}