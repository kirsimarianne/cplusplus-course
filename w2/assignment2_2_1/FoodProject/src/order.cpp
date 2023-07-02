#include "order.h"


bool add_food_to_order(Order& order,const Menu& menu, int id)
{
    for(auto food : menu)
    {
        if (food.id == id)
        {
            order.push_back(food);
            return true;
        }
        
    }
    return false;
}

void display_order(Order& order)
{
    double total{};
    std::cout << "Your order:\n";
    for(auto elem : order)
    {
        print_food(elem);
        total += elem.price;
    }
    std::cout << "Total: " << total << "\n\n";
}