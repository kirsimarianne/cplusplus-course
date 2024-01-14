/* Exercise 1.
 * Create a template class and overload its equality operator.
 * The overridden operator should `static_cast` its arguments to a type given as a template parameter and do the comparison.
 */
#include <iostream>
#include <typeinfo>

template <typename Derived>
class compare
{
};

class BaseClass :compare<BaseClass>
{
public:
   
    bool operator==(const BaseClass lhs, const BaseClass rhs) const
    {
        return internal_value == other.internal_value;
    }

private:
    int internal_value;
};

template <typename Derived>
class SubClass : public BaseClass
{
public:
    bool operator==(const compare<Derived> &lhs, const compare<Derived> &rhs) noexcept
    {
        return static_cast<const Derived &>(rhs) == static_cast<const Derived &>(lhs);
    }
};

int main()
{
    BaseClass a{1};
    BaseClass b{0};
    // template class, tyhjb{}ä tyyppi: toiminnallisuus: overload == joka siis vertaa
    // toinen class mikä perii base class
}
