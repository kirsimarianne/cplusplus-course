#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <iostream>
#include <limits>

template <typename T, size_t array_size>
class HeapArray
{

public:
    using value_type = T;
    using reference = T &;
    using const_reference = const T &;
    using iterator = T *;
    using const_iterator = const iterator;
    using size_type = size_t;

    /* Default constructor.
     * Throws exception if size is negative.
     */
    HeapArray()
    {
        if (array_size < 0)
        {
            throw std::out_of_range("Negative size");
        }
        size_ = array_size;
        ptr_ = new T[size_]{};
    }

    /* Destructor deletes pointer and frees memory
     */
    ~HeapArray()
    {
        delete[] ptr_;
    }

    /* Copy constructor.
     * Copys elements inside heap_array.
     */
    HeapArray(const HeapArray &other)
    {
        size_ = other.size_;
        ptr_ = new T[size_];
        for (size_t i = 0; i < size_; ++i)
        {
            ptr_[i] = other.ptr_[i];
        }
    }

    /* Copy assign operator
     */
    HeapArray &operator=(const HeapArray &other)
    {
        if (this != &other)
        {
            // Free earlier resources.
            delete[] ptr_;

            size_ = other.size_;
            ptr_ = new T[size_];
            for (size_t i = 0; i < size_; ++i)
            {
                ptr_[i] = other.ptr_[i];
            }
        }

        return *this;
    }

    /* Move constructor.
     * Copys elements inside heap_array.
     */
    HeapArray(HeapArray &&other)
    {
        size_ = other.size_;
        ptr_ = other.ptr_;
        other.size_ = 0;
        other.ptr_ = nullptr;
    }

    /* Move assignment operator
     */
    HeapArray &operator=(HeapArray &&other) noexcept
    {
        if (this != &other)
        {
            // Free earlier resources.
            delete[] ptr_;

            size_ = other.size_;
            ptr_ = other.ptr_;
            other.size_ = 0;
            other.ptr_ = nullptr;
        }
        return *this;
    }

    reference operator[](size_t index) { return ptr_[index]; }
    size_t size() const { return size_; }
    iterator begin() { return ptr_; }
    iterator end() { return ptr_ + size_; }
    const_iterator begin() const { return begin(); }
    const_iterator end() const { return end(); }
    void swap(HeapArray &other) noexcept
    {
        std::swap(size_, other.size_);
        std::swap(ptr_, other.ptr_);
    }

    bool empty() { return begin() == end(); }

private:
    value_type *ptr_ = nullptr;
    size_t size_{};
    static constexpr size_t MAX_VALUE{std::numeric_limits<size_t>::max()};
};
#endif
