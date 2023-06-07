#include <iostream>

struct MyNumber{
    public:
        MyNumber(){
            number = 3;
        }
        int get_number(){
            return number;
        }
        void set_number(int new_number){
            number = new_number;
        }

    private:
        int number;
};



int main()
{

    MyNumber my_number;
    int y = my_number.get_number();
    std::cout << y << std::endl;
    my_number.set_number(5);
    std::cout << my_number.get_number(); 

    
    return 0;
}