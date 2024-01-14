#include <iostream>

void print_array(int* numbers_arr, int array_size)
{
    for(int i = 0; i < array_size; ++i)
    {
        std::cout << numbers_arr[i] << std::endl;
    }

    std::cout << '\n';
}


/*int* create_array(int size){
    int* array = new int[size];

    for(int i = 0; i < size; ++i){
        array[i] = i;
    }
}*/


int main()
{

    //int* array{new int[4]{1, 2, 3, 4}};
    

    int length{5};

    int* int_array{new int[5] {1, 2, 6, 4, 5}};

    print_array(int_array, 5);
    
    delete[] int_array;


}