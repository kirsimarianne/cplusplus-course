#include "grid.hpp"

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
    vect_.reserve(rows * columns);
}

// Constructor with size parameters and value parameter
template <typename T>
Grid<T>::Grid(int rows, int columns, T value)
{
    if (rows < 0 || columns < 0)
    {
        throw std::runtime_error("Grid_2D constructor: negative size");
    }
    rows_ = rows;
    columns_ = columns;
    for (int i = 0; i < (rows * columns); i++)
    {
        vect_.push_back(value);
    }
}

template <typename T>
void Grid<T>::print()
{
    for (int i = 0; i < rows_*columns_; i++)
    {
        std::cout << vect_[i];
        if ((i + 1) % columns_ == 0)
        {
            std::cout << "\n";
        }
        else{
            std::cout << " ";
        }
    }
    std::cout << "\n";
}

/*int main()
{
    std::cout << "Create grid\n";
    Grid<int> grid(3, 4);
    grid.print();
   
    std::cout << "\n";
    grid.set(0, 0, 9);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << grid.at(i, j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    grid.set(0, 1, 8);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << grid.at(i, j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    grid.set(1, 1, 5);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << grid.at(i, j) << " ";
        }
        std::cout << "\n";
    }
    std::cout << "\n";
    grid.set(1, 2, 3);
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << grid.at(i, j) << " ";
        }
        std::cout << "\n";
    }

    std::cout << "Create Grid2 \n";
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
    grid2.set(1, 2, 9);
    grid2.print();
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            std::cout << grid2.at(i, j) << " ";
        }
        std::cout << "\n";
    }

    auto itr = grid2.begin() + 6;

    std::cout << "Test iterator: " << *itr << "\n";
}*/
