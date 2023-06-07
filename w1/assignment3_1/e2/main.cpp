#include <iostream>

// x not visible here

int main(){

    // x not visible here

    for(int i = 0; i < 5; i++)
    {
        int x {1};
        std::cout << x << std::endl;
    }

    return 0;
}