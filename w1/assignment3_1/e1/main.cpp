#include <iostream>

// local scope
void declare_var()
{
    int x {5};
    std::cout << x << std::endl;
}


int main(){

    declare_var(); 
    return 0;
}