/* Exercise 2
 * Create a function that adds an integer n times to a static global variable.
 * e.g. void add(int increment int times);  Use a loop to do the increments.
 * Create 100 threads from the main() function to call the add-function.
 * Compare the result to straight-up calculation.
 */

#include <iostream>
#include <thread>
#include <vector>

static int sum{0};

void add(int increment, int times)
{
    for (int i = 0; i < times; ++i)
    {
        sum = sum + increment;
    }
}

void print_sum()
{
    std::cout << sum << "\n";
}

int main()
{
    const int increment = 5;
    const int times = 1000;
    std::vector<std::thread> threads;

    for (int i = 0; i < 100; ++i)
    {
        threads.push_back(std::thread(add, increment, times));
    }

    for (int i = 0; i < 100; ++i)
    {
        threads[i].join();
    }

    std::cout << "Sum from threads: ";
    print_sum();

    std::cout << "Check sum: ";
    sum = 0;
    for (int i = 0; i < 100; ++i)
    {
        add(increment, times);
    }

    print_sum();
}