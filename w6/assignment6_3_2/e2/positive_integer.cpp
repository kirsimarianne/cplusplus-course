#include "positive_integer.hpp"
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
PositiveInteger add(const PositiveInteger& obj1, const PositiveInteger& obj2)
{
    long int result = static_cast<long int>(obj1.value_) + static_cast<long int>(obj2.value_);
    // Should never reach this because constructor checks negatives.
    if (result < obj1.MIN_VALUE)
    {
        return PositiveInteger(obj1.MIN_VALUE);
    }
    else if (result > obj1.MAX_VALUE)
    {
        return PositiveInteger(obj1.MAX_VALUE);
    }
    return PositiveInteger(result);
}

/* Subtracts values of two objects together.
 * Saturates to 0 (min) or max value of int if result gets out of ranges
 */
PositiveInteger subtract(const PositiveInteger& obj1, const PositiveInteger& obj2)
{
    long int result = static_cast<long int>(obj1.value_) - static_cast<long int>(obj2.value_);
    if (result < obj1.MIN_VALUE)
    {
        return PositiveInteger(obj1.MIN_VALUE);
    }
    // Should never reach this.
    else if (result > obj1.MAX_VALUE)
    {
        return PositiveInteger(obj1.MAX_VALUE);
    }
    return PositiveInteger(result);
}

void PositiveInteger::print_value() const
{
    std::cout << value_ << "\n";
}

int main()
{
    std::cout << "\nDefault constructor 0\n";
    PositiveInteger num1;
    num1.print_value(); 

    std::cout << "\nConstructor with parameter 15\n";
    PositiveInteger num2{15};
    num2.print_value();

    std::cout << "\nCopy object 0 and 15\n";
    PositiveInteger num3{num1};
    num3.print_value();
    num3 = num2;
    num3.print_value();

    std::cout << "\nNegative value\n";
    try
    {
        num3 = -7;
    }
    catch (std::exception &e)
    {
        std::cout << e.what() << "\n";
    }

    std::cout << "\nTest value again 15\n";
    num3.print_value();

    std::cout << "\nSum of 3 and 15\n";
    num3 = 3;
    PositiveInteger sum = add(num2, num3);
    sum.print_value();

    std::cout << "\nSum of maximum and 15\n";
    num3 = std::numeric_limits<int>::max();
    sum = add(num2, num3);
    sum.print_value();

    std::cout << "\nDifference of 0 and 15\n";
    PositiveInteger difference = subtract(num1, num2);
    difference.print_value();

    std::cout << "\nDifference of 20 and 15\n";
    num1 = 20;
    difference = subtract(num1, num2);
    difference.print_value();
}