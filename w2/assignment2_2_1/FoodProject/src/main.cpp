// Paired header files
// Other headers from your project
// 3rd party library headers
// Standard library headers

#include "food.h"
#include "menu.h"
#include "order.h"

#include <iostream>
#include <string>


void print_food(const Food& food)
{
    std::cout << food.id << '\n';
    std::cout << food.name << '\n';
    std::cout << food.price << '\n';   
    for(auto elem : food.ingredients)
    {
        std::cout << elem << ' ';
    }
    std::cout << '\n' << '\n';
}

void print_menu(const Menu& menu)
{
    std::cout << "Menu \n\n" ;
    for(auto elem : menu)
    {
        print_food(elem);
    }
}

void get_order_from_user(Order& order, Food food)
{

    int cmd {};
    std::cout << "1: add food to chart\n";
    std::cout << "2:  go to chopping basket\n";
    std::cout << "3: quit \n";

    std::cin >> cmd;

    switch(cmd)
    {
        case 1:
        {

        }
        case 2:
        {

        }
        case 3:
        {
            
        }
    }
}

int main()
{
    Menu menu {};
    Order order {};

    //print_food(add_food("Pizza Margherita", 10.50, {"basil", "mozzarella",}));
    //print_food(add_food("Pizza Opera", 10.50, {"ham", "tuna fish", "cheese"}));
    //print_food(add_food("Pizza Tropicana", 10.50, {"ham", "pineapple", "cheese"}));
    
    //Food pizza = (add_food("Pizza Margherita", 10.50, {"Tomato sauce", "cheese"}));  
    //add_food_to_menu(menu, pizza);
    //print_menu(menu);

    add_food_to_menu(menu, add_food(1, "Pizza Margherita", 10.50, {"basil", "mozzarella",}));
    add_food_to_menu(menu, add_food(2, "Pizza Opera", 12.00, {"ham", "tuna fish", "cheese"}));//
    add_food_to_menu(menu, add_food(3, "Pizza Tropicana", 11.50, {"ham", "pineapple", "cheese"}));
    add_food_to_menu(menu, add_food(4, "Pizza Kebab", 1.90, {"kebab", "onion", "cheese"}));
    add_food_to_menu(menu, add_food(5, "Pizza Vegetarian", 1.90, {"olive", "tomato", "pepper"}));
    
    print_menu(menu);



    return 0;
}