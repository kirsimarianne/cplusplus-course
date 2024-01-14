#ifndef SPACE_3D_H
#define SPACE_3D_h

#include <limits>
#include <ostream>

namespace Space3D
{
    class Point
    {

    public:
        // Default constructor
        Point();
        // Constructor with parameters
        Point(int x, int y, int z);

        friend std::ostream &operator<<(std::ostream &os, const Point &point);
        Point operator+(const Point &other) const;
        Point operator-(const Point &other) const;
        Point operator+=(const Point &other);
        Point operator-=(const Point &other);

    private:
        int x_{};
        int y_{};
        int z_{};
        static const long int MAX_VALUE = std::numeric_limits<int>::max();
        static const long int MIN_VALUE = std::numeric_limits<int>::min();
        int add(const int value1, const int value2) const;
        int subtract(const int value1, const int value2) const;
    };

}

#endif