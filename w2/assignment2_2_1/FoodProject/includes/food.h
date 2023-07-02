#ifndef FOOD_H
#define FOOD_H

#include <vector>
#include <string>
#include <iostream>

using Ingredients = std::vector<std::string>;

struct Food{
    int id {};
    std::string name {};
    double price {};
    Ingredients ingredients {};
};

void print_food(const Food& food);

Food add_food(int id, std::string name, double price, Ingredients ingredients);


#endif