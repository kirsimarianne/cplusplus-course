#include <vector>

template <typename T>
class Stack
{
    using value_type = T;
    using pointer = T *;
    using const_pointer = const T *;

public:
    void push(T value)
    {
        vect.push_back(value);
    }

    value_type pop()
    {
        value_type value = vect[vect.size() - 1];
        vect.pop_back();
        return value;
    }

    pointer begin()
    {
        return &vect[0];
    }

    pointer end()
    {
        return &vect[0] + x.size();
    }

    const_pointer begin()
    {
        return const & vect[0];
    }

    const_pointer end()
    {
        return const & vect[0] + vect.size();
    }

    std::vector<T> vect;
};
