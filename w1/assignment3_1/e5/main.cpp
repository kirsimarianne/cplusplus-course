#include <iostream>


int main(){

    
    int x {5};
        std::cout << x << std::endl;

    if(true){
        x = 4;
    }
    
    // Jos määritelty scopen ulkopuolella, näkyy scopen sisäpuolelle

    std::cout << x << std::endl;
    
    return 0;
}