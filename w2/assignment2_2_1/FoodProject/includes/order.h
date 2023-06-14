#ifndef ORDER_H
#define ORDER_H

#include "food.h"

#include <vector>

using Order = std::vector<Food> ;

void add_food_to_order(Order& order, Food food);
double get_total();

#endif