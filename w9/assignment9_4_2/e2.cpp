/* Again, create a class with a factory function.
 * The function should return std::expected.
 * Create a way for the function to fail, and test out and demonstrate both outcomes.
 */

#include <iostream>
#include <expected>

enum class error
{
    zero,
    negative_value,
};

class Test_class
{
public:
    static std::expected<Test_class, error> test_value(int value)
    {
        if (value > 0)
        {
            return Test_class();
        }
        else if (value == 0)
        {
            return std ::unexpected{error::zero};
        }
        return std ::unexpected{error::negative_value};
    }
};

void test(const std::expected<Test_class, error> &instance)
{

    if (instance.has_value())
    {
        std::cout << "Instance created succesfully.\n";
    }
    else
    {
        switch (instance.error())
        {
        case error::zero:
        {
            std::cout << "Value zero."
                      << "\n";
            break;
        }
        case error::negative_value:
        {
            std::cout << "Negative value."
                      << "\n";
            break;
        }
        }
    }
}

int main()
{
    auto instance = Test_class::test_value(2);
    test(instance);
    instance = Test_class::test_value(-1);
    test(instance);
    instance = Test_class::test_value(0);
    test(instance);
}
