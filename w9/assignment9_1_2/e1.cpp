/* Exercise 1a
 * Create a template class, that takes an arbitrary function as its template parameter.
 * Use the constructor to deduce the template types so user doesn't have to provide them.
 */

#include <iostream>

template <typename Func, typename... Args>
class Caller
{
public:
    // Return type of the function.
    using return_type = Func;
    // Amount of arguments.
    static constexpr std::size_t arguments{sizeof...(Args)};
    // Constructor gets parameters: pointer to function, and arguments of function.
    Caller(Func (*)(Args... args)) {}
};

int add(int first, int second)
{
    return first + second;
}

int main()
{
    Caller caller(add);

    std::cout << typeid(decltype(caller)::return_type).name() << "\n";
    std::cout << decltype(caller)::arguments << "\n";
}
