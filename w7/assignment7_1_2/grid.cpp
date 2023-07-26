#include <iostream>
#include <vector>
#include <exception>

// Handle pointer
template <typename T>
struct strip_pointer
{
    using type = T;
};

template <typename T>
struct strip_pointer<T *>
{
    using type = T;
};

// Handle reference
template <typename T>
struct strip_reference
{
    using type = T;
};

template <typename T>
struct strip_reference<T &>
{
    using type = T;
};

// Handle const refrence
template <typename T>
struct strip_const_reference
{
    using type = T;
};

template <typename T>
struct strip_const_reference<const T &>
{
    using type = T;
};

template <typename T>
class Grid
{
    // value type T
    // reference T&
    // const reference const T&
    // iteratir for value type T
    // constant iterator for value type T
    // difference type: signed inetegr
    // size_type : unsigened integer

    // T& operator[](int i);
    // const T& operator[](int i) const;

    using value_type = T;
    using T_without_pointer = typename strip_pointer<T>::type;
    using T_without_reference = typename strip_reference<T>::type;
    using T_without_const_reference = typename strip_const_reference<T>::type;
    using storage_type = std::vector<T>;
    using iterator = typename storage_type::iterator;
    using const_iterator = typename storage_type::const_iterator;
    using size_type = typename storage_type::size_type;

public:
    Grid() = default;
    Grid(int rows, int columns);
    Grid(int rows, int columns, T value);

    void print();

    T &at(int row, int column)
    {
        
        return vect_[row * columns_ + column];
    }

    void change(int row, int column, int value)
    {
        vect_[row * columns_ + column] = value;
    }

private:
    std::vector<T> vect_;
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
    vect_.reserve(rows * columns);
}

// Constructor with size parameters and value parameter
template <typename T>
Grid<T>::Grid(int rows, int columns, T value)
{
    for (int i = 0; i < (rows * columns); i++)
    {
        vect_.push_back(value);
    }
}

template <typename T>
void Grid<T>::print()
{
    for (int i = 0; i < (rows_*columns_); i++)
    {
        std::cout << vect_[i] << ", ";
    }
    std::cout << "\n";
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
    grid.change(0, 0, 9);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << grid.at(i, j) << " ";
        }
        std::cout << "\n";
    }


    Grid<int> grid2(3, 4, 5);

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << grid2.at(i, j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    grid2.change(1, 2, 9);
    std::cout << "Print 1D vector:\n ";
    grid2.print();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << grid2.at(i, j) << " ";
        }
        std::cout << "\n";
    }

    /*Grid<int> *grid3 = &grid2;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            std::cout << grid3.at(i, j) << " ";
        }
        std::cout << "\n";
    }*/
}
