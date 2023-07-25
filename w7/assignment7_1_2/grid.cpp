#include <iostream>
#include <vector>
#include <exception>

template <typename T>
class Grid
{
    using value_type = T;
    using reference = T&;
    using const_reference = const T&;
    using storage_type = std::vector<T>;
    using iterator = typename storage_type::iterator;
    using const_iterator = typename storage_type::const_iterator;
    using size_type = typename storage_type::size_type;

public:
    Grid() = default;
    Grid(int rows, int columns);
    Grid(int rows, int columns, T value);

    T &at(int row, int column)
    {
        return vect[row * columns_ + column];
    }

    // value type T

    // reference T&

    // const reference const T&

    // iteratir for value type T

    // constant iterator for value type T

    // difference type: signed inetegr

    // size_type : unsigened integer

     //T& operator[](int i);
    // const T& operator[](int i) const;

private:
    std::vector<T> vect;
    int rows_;
    int columns_;
    // int length = rows*columns;
};

// Constructor with size parameters.
template <typename T>
Grid<T>::Grid(int rows, int columns)
{
    if (rows < 0 || columns < 0)
    {
        throw std::runtime_error("Grid_2D constructor: negative size");
    }
    rows_ = rows;
    columns_ = columns;
    std::cout << "Length: " << rows * columns << "\n";
    vect.reserve(rows * columns);
}

// Constructor with size parameters and value parameter
template <typename T>
Grid<T>::Grid(int rows, int columns, T value)
{
    for (int i = 0; i < (rows * columns); i++)
    {
        vect.push_back(value);
    }
}

// Implement begin() and end()



int main()
{
    std::cout << "Create grid\n";
    Grid<int> grid(3, 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << grid.at(i, j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    Grid<int> grid2(3, 3, 5);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << grid2.at(i, j) << " ";
        }
        std::cout << "\n";
    }

    Grid<int> *grid3 = &grid2;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << grid3.at(i, j) << " ";
        }
        std::cout << "\n";
    }
}
