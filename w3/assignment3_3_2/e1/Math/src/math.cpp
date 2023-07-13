#include "../includes/math.h"

int add(int x, int y)
{
   return x + y;
}

int subtract(int x, int y)
{
    return x - y;
}

int multiply(int x, int y)
{
   return x * y;
}

double divide(double x, double y)
{
    if(y == 0)
    {
        throw std::runtime_error("Divisor 0");
    }
    double division {x/y};

    return std::round(division*100.0)/100.0;
}