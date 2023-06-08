#include <iostream>


void modify_value(int tmp) // tmp lifetime starts
{
    tmp = 3;
    // tmp lifetime ends
}


int main(){

    int x {5}; // x lifetime starts
    std::cout << x << std::endl; 
    modify_value(x); 
    std::cout << x << std::endl; // x value is not changed, prints still 5
    return 0; // x lifetime ends
}