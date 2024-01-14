#ifndef MENU_H
#define MENU_H

#include "food.h"

#include <iostream>
#include <string>
#include <vector>

using Menu = std::vector<Food>;

void add_food_to_menu(Menu& menu, Food food);
void print_menu(const Menu& menu);

#endif