#ifndef FOOD_H
#define FOOD_H

#include <vector>
#include <string>

using Ingredients = std::vector<std::string>;

struct Food{
    std::string name {};
    double price {};
    Ingredients ingredients {};
};

void print_food(const Food& food);

Food add_food(std::string name, double price, std::vector<std::string> ingredients);

#endif