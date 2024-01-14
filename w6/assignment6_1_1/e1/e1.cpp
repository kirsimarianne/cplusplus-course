/* Exercise 1:
 * Create a header file that contains definition for enum class "status", and add a
 * success status, and couple of error statuses
 * Create a function that returns a status code at random
 * Create a program to call the function and handle the status using `switch`-statement
 */

#include "e1.h"
#include <iostream>
#include <random>
#include <chrono>

int get_random(int a, int b)
{
    std::random_device rd{};
    std::seed_seq ss{
        static_cast<std::seed_seq::result_type>(std::chrono::steady_clock::now().time_since_epoch().count()),
        rd(), rd(), rd(), rd(), rd(), rd(), rd()};
    std::mt19937 mt{ss};
    std::uniform_int_distribution distr{a, b};
    return distr(mt);
}

int main()
{
    Status random_status = static_cast<Status>(get_random(-3, 0));

    switch (random_status)
    {
        case Status::success:
        {
            std::cout << "Success\n";
            break;
        }
        case Status::error1:
        {
            std::cout << "Error1\n";
            break;
        }
        case Status::error2:
        {
            std::cout << "Error2\n";
            break;
        }
        case Status::error3:
        {
            std::cout << "Error3\n";
            break;
        }
    }
}
