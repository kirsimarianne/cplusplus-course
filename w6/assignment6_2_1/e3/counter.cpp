#include "counter.h"
#include <iostream>

// Init counter once
int Counter::count = 0;

// Constructor
Counter::Counter()
{
    count++;
}

// Destructor
Counter::~Counter()
{
    count--;
}

int main()
{
    // Test creating objects
    Counter obj1;
    std::cout << obj1.get() << "\n";
    Counter obj2;
    std::cout << obj2.get() << "\n";
    Counter obj3;
    std::cout << obj3.get() << "\n";
    Counter obj4;
    std::cout << obj4.get() << "\n";
    // Test destructor
    obj1.~Counter();
    std::cout << obj4.get() << "\n";
}
