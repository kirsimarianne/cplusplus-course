#include <iostream>

// local scope
void print_number()
{
    int x {5};
    std::cout << x << std::endl;
}


int main(){

    print_number(); 
    return 0;
}