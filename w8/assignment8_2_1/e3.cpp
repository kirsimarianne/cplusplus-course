/* Exercise 3
 * Earlier, we created a class that counted the number of instances created.
 * Delete the classes copy constructor and implement the move constructor.
 * (This kind of class is extremely useful when wrapping libraries.
 * You can avoid user having to deal with library initialisation
 * / destruction by doing the init on the first created instance of a type and then cleaning up when the last goes poof.
 * If you have tried libraries such as SDL, GLFW, or other low-level windowing libraries, this is the way to go.)
 */
#include <iostream>

class Counter
{

public:
    Counter();
    ~Counter();

    Counter(const Counter &) = delete;

    Counter(Counter &&other);
    Counter &operator=(Counter &&other);

    int static count;

private:
    bool is_moved{false};
};

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

void test()
{
    Counter obj1;
    Counter obj2 = std::move(obj1);
    std::cout << "Count: " << Counter::count << "\n";
}

int main()
{
    test();
    std::cout << "Count: " << Counter::count << "\n";
}