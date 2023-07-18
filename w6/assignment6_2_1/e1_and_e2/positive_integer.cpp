#include "positive_integer.h"
#include <stdexcept>
#include <iostream>

/* Default constructor
 */
PositiveInteger::PositiveInteger() : value_{0} {}

/* Constructor with value.
 * Throws exception if value is negative.
 */
PositiveInteger::PositiveInteger(const int value)
{
    if (value < MIN_VALUE)
    {
        throw std::runtime_error("Negative number");
    }
    else if (value > MAX_VALUE)
    {
        throw std::runtime_error("Number out of range of type int");
    }
    value_ = value;
}

/* Adds values of two objects together.
 * Saturates to 0 (min) or max value of int if result gets out of ranges
 */
PositiveInteger PositiveInteger::add(const PositiveInteger &other)
{
    long int result = static_cast<long int>(value_) + static_cast<long int>(other.value_);
    // Should never reach this because constructor checks negatives.
    if (result < MIN_VALUE)
    {
        return PositiveInteger(0);
    }
    else if (result > MAX_VALUE)
    {
        return PositiveInteger(MAX_VALUE);
    }
    return PositiveInteger(result);
}

/* Subtracts values of two objects together.
 * Saturates to 0 (min) or max value of int if result gets out of ranges
 */
PositiveInteger PositiveInteger::subtract(const PositiveInteger &other)
{
    long int result = static_cast<long int>(value_) - static_cast<long int>(other.value_);
    if (result < MIN_VALUE)
    {
        return PositiveInteger(0);
    }
    // Should never reach this.
    else if (result > MAX_VALUE)
    {
        return PositiveInteger(MAX_VALUE);
    }
    return PositiveInteger(result);
}

void PositiveInteger::print_value() const
{
    std::cout << value_ << "\n";
}

int main()
{
    std::cout << "Default constructor\n";
    PositiveInteger i;
    i.print_value();
    std::cout << "Constructor with parameter\n";
    PositiveInteger i2{15};
    i2.print_value();
    std::cout << "Copy object\n";
    PositiveInteger i3{i};
    i3.print_value();
    i3 = i2;
    i3.print_value();
    std::cout << "Negative value\n";
    try
    {
        i3 = -7;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }
    i3.print_value();

    std::cout << "Sum of 3 and 15\n";
    i3 = 3;
    PositiveInteger sum = i2.add(i3);
    sum.print_value();

    std::cout << "Sum of maximum and 15\n";
    i3 = std::numeric_limits<int>::max();
    sum = i2.add(i3);
    sum.print_value();

    std::cout << "Difference of 0 and 15\n";
    PositiveInteger difference = i.subtract(i2);
    difference.print_value();

    std::cout << "Difference of 20 and 15\n";
    i = 20;
    difference = i.subtract(i2);
    difference.print_value();
}