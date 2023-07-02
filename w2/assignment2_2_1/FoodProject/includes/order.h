#ifndef ORDER_H
#define ORDER_H

#include "food.h"
#include "menu.h"

#include <vector>

using Order = std::vector<Food> ;

bool add_food_to_order(Order& order, const Menu& menu, int id);
void display_order(Order& order);

#endif