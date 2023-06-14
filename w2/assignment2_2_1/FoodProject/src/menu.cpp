#include "menu.h"


void add_food_to_menu(Menu& menu, Food food)
{
    menu.push_back(food);
}

void print_menu(const Menu& menu)
{
    std::cout << "MENU \n\n" ;
    for(auto elem : menu)
    {
        print_food(elem);
    }
}
