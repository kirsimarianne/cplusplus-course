#include <cassert>
#include <iostream>
#include <string>
#include <cmath>

bool play_game(int numbr, int limit1, int limit2)
{   

    if(numbr >= limit1 && numbr <= limit2)
    {
        return true;
    }
    else{
        return false;
    }
}    


int main() 
{

    assert(play_game(33, 1, 100) && "The value is out of range of 1 and 100");
    std::cout << "Test 1 passed" << std::endl;
    assert(play_game(-1, 1, 100) && "The value is out of range of 1 and 100");
    std::cout << "Test 2 passed" << std::endl;  
    assert(play_game(100, 1, 100) && "The value is out of range of 1 and 100");
    std::cout << "Test 3 passed" << std::endl;
   
}
