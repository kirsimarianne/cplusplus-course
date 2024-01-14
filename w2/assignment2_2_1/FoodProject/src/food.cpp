#include "food.h"
#include <string>

/* Function gets food struct as a reference, name, 
 * price and vector of ingredients as parameters.
 * Function adds food name, price and ingredients vector to food structure.
*/
Food add_food(int id, std::string name, double price, Ingredients ingredients)
{
    Food food;
    food.id = id;
    food.name = name;
    food.price = price;

    for(auto elem : ingredients)
    {
        food.ingredients.push_back(elem);
    }
    return food;
}

void print_food(const Food& food)
{
    std::cout << food.id << ". ";
    std::cout << food.name << '\n';
    std::cout << food.price << "€\n";   
    for(auto elem : food.ingredients)
    {
        std::cout << elem << ' ';
    }
    std::cout << '\n' << '\n';
}