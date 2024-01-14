#ifndef POSITIVE_INTEGER_HPP
#define POSITIVE_INTEGER_HPP

#include <limits>

class PositiveInteger
{

public:
    // Initialising withh a negative number reports an error to the user and cleans up correctly
    // Can be copied a = b works
    // Has a memeber function to print the contents

    PositiveInteger();
    PositiveInteger(const int value);

    void print_value() const;
    friend PositiveInteger add(const PositiveInteger& obj1, const PositiveInteger& obj2); 
    friend PositiveInteger subtract(const PositiveInteger& obj1, const PositiveInteger& obj2);

private:
    int value_;
    static const long int MAX_VALUE = std::numeric_limits<int>::max();
    static const long int MIN_VALUE = 0;
};

#endif