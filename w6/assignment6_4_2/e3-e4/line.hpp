/* Exercise 3
 * Using the TextFile class we created previously, create a function that reads a text file
 * line by line and creates an Object for each line and stores them in a container.
 * Exercise 4
 * Combine what we have to create a program that reads in a text file, creates the Objects
 * and then prints out the elements found in the container.
*/

#ifndef LINE_HPP
#define LINE_HPP

#include <iostream>

class Line
{
public:
    Line(std::string line)
    {
        line_ = line;
    }

    // For printing objects
    friend std::ostream &operator<<(std::ostream &os, const Line &line);

private:
    std::string line_{};
};

std::ostream &operator<<(std::ostream &os, const Line &line)
{
    os << line.line_ << "\n";

    return os;
}

#endif