/* Exercise 1
 * From the main thread, create two threads, one of which prints "Hello, " and the other "world!\n".
 * Run your program a couple of times.
 */

#include <iostream>
#include <thread>

void print_hello()
{
    std::cout << "Hello ";
}

void print_world()
{
    std::cout << "World!\n";
}

int main()
{
    std::thread thread1(print_hello);
    std::thread thread2(print_world);

    thread1.join();
    thread2.join();
}
