#include "food.h"
#include <iostream>
#include <string>


void print_food(const Food& food)
{
    std::cout << food.name << '\n';
    std::cout << food.price << '\n';   
    for(auto elem : food.ingredients)
    {
        std::cout << elem << ' ';
    }
    std::cout << '\n' << '\n';
}

int main()
{
    //Ingredients ingredients = {"Tomato sauce", "cheese"};
    print_food(add_food("Pizza Margherita", 10.50, {"basil", "mozzarella",}));
    print_food(add_food("Pizza Opera", 10.50, {"ham", "tuna fish", "cheese"}));
    print_food(add_food("Pizza Tropicana", 10.50, {"ham", "pineapple", "cheese"}));
    print_food(add_food("Pizza Margherita", 10.50, {"Tomato sauce", "cheese"}));
    return 0;
}