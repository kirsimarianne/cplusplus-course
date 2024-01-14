#include <iostream>

namespace A
{
    void a_function()
    {
        std::cout << "This is function inside namepsace A.\n";
    }
    class B
    {
        public:
        void static b_function()
        {
            std::cout << "This is function inside namespace A and class B\n";
        }
    };
}


int main()
{
    A::a_function();
    A::B::b_function();
    
}