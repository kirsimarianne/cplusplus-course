#include "space_3d.h"
#include <limits>
#include <ostream>
#include <iostream>

namespace Space3D
{
    /* Define constructor with values (0, 0, 0)
     */
    Point::Point() : x_{0}, y_{0}, z_{0} {}

    /* Constructor with parameters.
     */
    Point::Point(int x, int y, int z)
    {
        x_ = x;
        y_ = y;
        z_ = z;
    }

    /* Function adds two values together
     * Returns maximum value or minimum value in overflow situation.
     */
    int Point::add(const int value1, const int value2) const
    {
        long int result = static_cast<long int>(value1) + static_cast<long int>(value2);
        if (result < MIN_VALUE)
        {
            return (MIN_VALUE);
        }
        else if (result > MAX_VALUE)
        {
            return (MAX_VALUE);
        }
        return static_cast<int>(result);
    }

    /* Function adds two values together
     * Returns maximum value or minimum value in overflow situation.
     */
    int Point::subtract(const int value1, const int value2) const
    {
        long int result = static_cast<long int>(value1) - static_cast<long int>(value2);
        if (result < MIN_VALUE)
        {
            return (MIN_VALUE);
        }
        else if (result > MAX_VALUE)
        {
            return (MAX_VALUE);
        }
        return static_cast<int>(result);
    }

    /* Function overloads + -operator
     * Calls add function.
     */
    Point Point::operator+(const Space3D::Point &other) const
    {
        return Space3D::Point(add(x_, other.x_), add(y_, other.y_), add(z_, other.z_));
    }

    /* Function overloads - -operator
     * Calls subtract function.
     */
    Point Point::operator-(const Space3D::Point &other) const
    {
        return Space3D::Point(subtract(x_, other.x_), subtract(y_, other.y_), subtract(z_, other.z_));
    }

    /* Function overloads += -operator
     * Calls add function.
     */
    Point Point::operator+=(const Point &other)
    {
        x_ = add(x_, other.x_);
        y_ = add(y_, other.y_);
        z_ = add(z_, other.z_);
        return *this;
    }

    /* Function overloads -= -operator
     * Calls subtract function.
     */
    Point Point::operator-=(const Point &other)
    {
        x_ = subtract(x_, other.x_);
        y_ = subtract(y_, other.y_);
        z_ = subtract(z_, other.z_);
        return *this;
    }

    /* Function makes << point << print point in form (x, y, z)
    */
    std::ostream &operator<<(std::ostream &os, const Space3D::Point &point)
    {

        os << "(" << point.x_ << ", " << point.y_ << ", " << point.z_ << ")";
        return os;
    }

}

int main()
{
    // Testing functionality
    Space3D::Point i(1, 2, 3);
    std::cout << "i: " << i << "\n";
    Space3D::Point j(1, 0, 5);
    std::cout << "j: " << j << "\n";
    Space3D::Point k = i + j;
    std::cout << "k: " << k << "\n";
    k = i - j;
    std::cout << "k: " << k << "\n";
    i += j;
    std::cout << "i: " << i << "\n";
    i -= j;
    std::cout << "i: " << i << "\n";

    // Test overload
    std::cout << "Overload min:\n";
    Space3D::Point i_min(std::numeric_limits<int>::min(), -2, 3);
    std::cout << "i_min: " << i_min << "\n";
    Space3D::Point j_min(2, -2, 2);
    std::cout << "j_min: " << j_min << "\n";
    Space3D::Point k_min = i_min - j_min;
    std::cout << "k_min: " << k_min << "\n";

    std::cout << "Overload max:\n";
    Space3D::Point i_max(std::numeric_limits<int>::max(), 2, 2);
    std::cout << "i_max: " << i_max << "\n";
    Space3D::Point j_max(2, 2, std::numeric_limits<int>::max());
    std::cout << "j_max: " << j_max << "\n";
    Space3D::Point k_max = i_max + j_max;
    std::cout << "k_max: " << k_max << "\n";
}
