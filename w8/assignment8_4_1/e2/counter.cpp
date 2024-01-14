#include "counter.hpp"
#include <iostream>

// init once
int Counter::count = 0;

// Default constructor: increase count by one
Counter::Counter()
{
    std::cout << "Default constructor\n";
    count++;
}

// Destructor: decrease count by one if instance is not moved
Counter::~Counter()
{
    std::cout << "Destructor\n";
    if (!is_moved)
    {
        --count;
    }
}

// Move instance: change other object's is_moved value
Counter::Counter(Counter &&other)
{
    std::cout << "Move\n";
    other.is_moved = true;
}

// Move instance: change other object's is_moved value
Counter &Counter::operator=(Counter &&other)
{
    std::cout << "Move\n";
    other.is_moved = true;
    return *this;
}
