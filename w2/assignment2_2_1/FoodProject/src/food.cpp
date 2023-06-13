#include "food.h"
#include <string>


Food add_food(std::string name, double price, std::vector<std::string> ingredients)
{
    Food food {};
    food.name = name;
    food.price = price;
    food.ingredients = {"base", "sauce", "cheese"};

    for(auto elem : ingredients)
    {
        food.ingredients.push_back(elem);
    }

    return food;
}
