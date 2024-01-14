/* Exercise 3
 * Repeat exercise 2, but use mutexes to lock the
 * summation so only one thread can do the increment at a time (check out std::lock_guard as well)
 */

#include <atomic>
#include <iostream>
#include <mutex>
#include <thread>
#include <vector>

// static int sum {0};
std::atomic_int sum{0};
static std::mutex sum_mutex;

void add(int increment, int times)
{
    std::lock_guard<std::mutex> sum_lock{sum_mutex};
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
    const int times = 10000000;
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