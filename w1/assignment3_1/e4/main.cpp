#include <iostream>


int main(){

    {
        int x {5};
        std::cout << x << std::endl;
    }

    // x not visible here
    //std::cout << x << std::endl;
    
    return 0;
}