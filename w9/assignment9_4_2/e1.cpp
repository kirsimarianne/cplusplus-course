/* Exercise 1.
 * Create a class, and then a factory function (static member function)
 * to create a class instance.
 * The function should return std::optional.
 * Create a way for the function to fail, and return a std::nullopt in case of failure.
 * Then demonstrate both cases.
 */
#include <iostream>
#include <optional>

class Test_class
{
public:
    static std::optional<Test_class> test_value(int value)
    {
        if (value > 0)
        {
            return Test_class();
        }
        return std::nullopt;
    }
};

void test(const std::optional<Test_class> &instance)
{
    if (instance.has_value())
    {
        std::cout << "Instance created succesfully.\n";
    }
    else
    {
        std::cout << "Instance not created.\n";
    }
}

int main()
{
    auto instance = Test_class::test_value(2);
    test(instance);
    instance = Test_class::test_value(-1);
    test(instance);
}
