#include <iostream>

// local scope
void calculate()
{
    int x {5};
    std::cout << x << std::endl;
}



int main(){

    // Does not work
    // x inside local scope calculate function
    std::cout << x << std::endl;
    
    return 0;
}