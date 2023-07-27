#ifndef GRID_H
#define GRID_H

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
    // T& operator[](int i);
    // const T& operator[](int i) const;

    /*using value_type = T;
    using reference = &T;
    using T_without_pointer = typename strip_pointer<T>::type;
    using T_without_reference = typename strip_reference<T>::type;
    using T_without_const_reference = typename strip_const_reference<T>::type;
    using storage_type = std::vector<T>;
    using iterator = typename storage_type::iterator;
    using const_iterator = typename storage_type::const_iterator;
    using size_type = typename storage_type::size_type;*/

    // Exercise 1
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

    T &at(int row, int column)
    {
        return vect_[row * columns_ + column];
    }

    void set(int row, int column, int value)
    {
        vect_[row * columns_ + column] = value;
    }

    void print();

    iterator begin()
    {
        return vect_.begin();
    }

    iterator end()
    {
        return vect_.end();
    }

    int get_size()
    {
        return rows_*columns_;
    }

    void resize(int rows, int columns)
    {
        rows_ = rows;
        columns_ = columns;
        vect_.resize(rows*columns);
    }

private:
    std::vector<T> vect_;

    // Helper types
    int rows_;
    int columns_;
    // int length = rows*columns;
};

#endif