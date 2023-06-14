#include "order.h"


void add_food_to_order(Order& order, Food food)
{
    order.push_back(food);
}