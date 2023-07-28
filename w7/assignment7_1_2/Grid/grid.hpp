#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <vector>
#include <exception>

template <typename T>
class Grid
{

    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using storage_type = std::vector<T>;
    using iterator = typename storage_type::iterator;
    using const_iterator = typename storage_type::const_iterator;
    using size_type = typename storage_type::size_type;

public:
    Grid() = default;
    Grid(int rows, int columns);
    Grid(int rows, int columns, T value);

    void print();
    T &at(int row, int column);
    void set(int row, int column, int value);
    int get_size();
    void resize(int rows, int columns);

    iterator begin()
    {
        return data_.begin();
    }

    iterator end()
    {
        return data_.end();
    }

    const_iterator const_begin() const
    {
        return data_.begin();
    }

    const_iterator const_end() const
    {
        return data_.end();
    }

    // Further developemnt
    // T& operator[](int i);
    // const T& operator[](int i) const;

private:
    storage_type data_;
    int rows_;
    int columns_;
};

template <typename T>
Grid<T>::Grid(int rows, int columns)
{
    if (rows < 0 || columns < 0)
    {
        throw std::runtime_error("Grid_2D constructor: negative size");
    }
    rows_ = rows;
    columns_ = columns;
    data_.reserve(rows * columns);
}
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
        data_.push_back(value);
    }
}
template <typename T>
void Grid<T>::print()
{
    for (int i = 0; i < rows_ * columns_; i++)
    {
        std::cout << data_[i];
        if ((i + 1) % columns_ == 0)
        {
            std::cout << "\n";
        }
        else
        {
            std::cout << " ";
        }
    }
    std::cout << "\n";
}

template <typename T>
T &Grid<T>::at(int row, int column)
{
    return data_[row * columns_ + column];
}

template <typename T>
void Grid<T>::set(int row, int column, int value)
{
    data_[row * columns_ + column] = value;
}

template <typename T>
int Grid<T>::get_size()
{
    return rows_ * columns_;
}

template <typename T>
void Grid<T>::resize(int rows, int columns)
{
    rows_ = rows;
    columns_ = columns;
    data_.resize(rows * columns);
}

#endif