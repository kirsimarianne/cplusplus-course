/* The program counts time difference between two time structs.
*/
#include <iostream>

struct Time
{
    int seconds{};
    int minutes{};
    int hours{};
};

/* Function does not handle situation where day changes
 * between start and stop time
 */
Time get_difference(Time t1, Time t2)
{
    Time difference;

    if(t1.seconds > t2.seconds)
    {
        --t2.minutes;
        t2.seconds += 60;
    }

    if(t1.minutes > t2.minutes)
    {
        --t2.hours;
        t2.minutes += 60;
    }

    difference.seconds = t2.seconds - t1.seconds;
    difference.minutes = t2.minutes - t1.minutes;
    difference.hours = t2.hours-t1.hours;

    return difference;
}

Time get_time_from_user()
{
    Time t;
    std::cout << "Hours: ";
    std::cin >> t.hours;
    std::cout << "Minutes: ";
    std::cin >> t.minutes;
    std::cout << "Seconds: ";
    std::cin >> t.seconds;

    return t;
}

void print_difference(Time t)
{
    std::cout << "Time difference: " << t.hours << ":"<< t.minutes << ":" << t.seconds << std::endl;
}

int main()
{
    struct Time t1, t2;
    std::cout << "Enter start time" << std::endl;
    t1 = get_time_from_user();

    std::cout << "Enter stop time" << std::endl;
    t2 = get_time_from_user();

    print_difference(get_difference(t1, t2));

    return 0;
}