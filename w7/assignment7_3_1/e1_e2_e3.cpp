#include <iostream>
#include <typeinfo>

template <typename Derived>
class BaseClass
{
};

template <typename Derived>
class BaseClass2
{
};

class SubClass : BaseClass<SubClass>
{
public:
    SubClass() noexcept = default;
    SubClass(int value) noexcept
    {
        value_ = value;
    }
    bool operator==(const SubClass &other) const
    {

        return value_ < other.value_;
    }

    const void print_type(const SubClass &object) const
    {
        std::cout << "Type of object: " << typeid(object).name() << "\n";
    }

private:
    int value_;
};

template <typename Derived>
bool operator==(const BaseClass<Derived> &lhs, const BaseClass<Derived> &rhs) noexcept
{
    return !(static_cast<const Derived &>(rhs) < static_cast<const Derived &>(lhs)) && !(static_cast<const Derived &>(lhs) < static_cast<const Derived &>(rhs));
}

template <typename Derived>
bool operator!=(const BaseClass<Derived> &lhs, const BaseClass<Derived> &rhs) noexcept
{
    return (static_cast<const Derived &>(rhs) < static_cast<const Derived &>(lhs)) || (static_cast<const Derived &>(lhs) < static_cast<const Derived &>(rhs));
}

template <typename Derived>
bool operator>(const BaseClass<Derived> &lhs, const BaseClass<Derived> &rhs) noexcept
{
    return static_cast<const Derived &>(lhs) > static_cast<const Derived &>(rhs);
}

template <typename Derived>
bool operator<(const BaseClass<Derived> &lhs, const BaseClass<Derived> &rhs) noexcept
{
    return static_cast<const Derived &>(lhs) < static_cast<const Derived &>(rhs);
}

template <typename Derived>
const void print_type(const BaseClass2<Derived> &object)
{
    std::cout << "Type of object: " << typeid(object).name() << "\n";
}

int main()
{
    SubClass object1{1};
    SubClass object2{3};
    std::cout << std::boolalpha << (object1 == object2) << "\n";
    object1.print_type(object1);
}
