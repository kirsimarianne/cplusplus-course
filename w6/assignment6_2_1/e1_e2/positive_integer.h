#ifndef POSITIVE_INTEGER_H
#define POSITIVE_INTEGER_H

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
    PositiveInteger add(const PositiveInteger &other);
    PositiveInteger subtract(const PositiveInteger &other);

private:
    int value_;
    static const long int MAX_VALUE = std::numeric_limits<int>::max();
    static const long int MIN_VALUE = 0;
};

#endif