/* Exercise 2
 * Create a class with following properties:
 * Has template parameter that enables or disables console output
 * Counts number of calls to
 * Default constructor
 * Copy constructor
 * Move constructor
 * Destructor
 * If enabed, prints out when its constructor / destructor is called
 * This kind of class will be your friend while debugging.
 */

#include <iostream>

template <bool enable_output>
class Debug
{
public:
    // Default constructor
    Debug()
    {
        if (enable_output)
        {
            std::cout << "Default constructor called.\n";
        }
        ++count_def;
    }
    // copy constructor
    Debug(const Debug &other)
    {
        if (enable_output)
        {
            std::cout << "Copy constructor called.\n";
        }
        ++count_copy;
    }
    // move constructor
    Debug(Debug &&other)
    {
        if (enable_output)
        {
            std::cout << "Move constructor called.\n";
        }
        ++count_move;
    }
    // Copy constructor
    ~Debug()
    {
        if (enable_output)
        {
            std::cout << "Destructor called.\n";
        }
        ++count_destr;
    }

    inline int static count_def;
    inline int static count_copy;
    inline int static count_move;
    inline int static count_destr;
};

int main()
{
    // Test class
    std::cout << "Create object\n";
    Debug<true> obj{};
    std::cout << "\nCreate second object\n";
    Debug<true> obj2{};
    std::cout << "\nCopy object\n";
    Debug<true> obj3 = obj;
    std::cout << "\nMove object\n";
    Debug<true> obj4(std::move(obj));
    std::cout << "\nCreate object with false enable_output\n";
    Debug<false> obj5{};

    std::cout << "\nDefault constructor constructor calls count: " << Debug<true>::count_def << "\n";
    std::cout << "Copy constructor calls count: " << Debug<true>::count_copy << "\n";
    std::cout << "Move constructor calls count: " << Debug<true>::count_move << "\n";
    std::cout << "Destructor constructor calls count: " << Debug<true>::count_destr << "\n";

    std::cout << "\nDefault constructor constructor calls count: " << Debug<false>::count_def << "\n";
    std::cout << "Copy constructor calls count: " << Debug<false>::count_copy << "\n";
    std::cout << "Move constructor calls count: " << Debug<false>::count_move << "\n";
    std::cout << "Destructor constructor calls count: " << Debug<false>::count_destr << "\n";
}