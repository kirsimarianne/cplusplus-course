/* The program allows user to 
 * 1) view menu of the restaurant,
 * 2) add food items to shopping chart 
 * 3) view shopping chart and total price,
*/

#include "food.h"
#include "menu.h"
#include "order.h"

#include <iostream>
#include <string>


/* Function gets order and menu as parameters,
 * asks commands from the user until the user quits the program,
 * calls add_food_to_order, display_order and print_menu functions
*/
void user_interface(Order& order, const Menu &menu)
{
    int cmd {};
    bool quit {false};
    while(!quit)
    {
        std::cout << "1: Add food to chart\n";
        std::cout << "2: View shopping chart\n";
        std::cout << "3: Menu\n";
        std::cout << "4: Quit \n";

        std::cin >> cmd;

        switch(cmd)
        {
            case 1:
            {
                std::cout << "Please give number of the food: ";
                int id{};
                std::cin >> id;
                if(add_food_to_order(order,menu, id))
                {
                    std::cout << "Food added succesfully!\n";
                }
                else
                {
                    std::cout << "Food not found.\n";
                }
            }    
            break;
            case 2:
            {
                display_order(order);
            }
            break;
            case 3:
            {
                print_menu(menu);
            }
            break;
            case 4:
            {
                std::cout << "Bye bye! \n";
                quit = true;
            }
            break;
        }
    }    
}

/* Function initializes menu and order vectors,
 * calls functions: add_food_to_menu, add_food, print_menu and user_interface.
 * and stores food items to menu vector.
*/

int main()
{
    Menu menu {};
    Order order {};

    add_food_to_menu(menu, add_food(1, "Pizza Margherita", 12.50, {"basil", "mozzarella",}));
    add_food_to_menu(menu, add_food(2, "Pizza Opera", 12.00, {"ham", "tuna fish", "cheese"}));//
    add_food_to_menu(menu, add_food(3, "Pizza Tropicana", 11.50, {"ham", "pineapple", "cheese"}));
    add_food_to_menu(menu, add_food(4, "Pizza Kebab", 15.90, {"kebab", "onion", "cheese"}));
    add_food_to_menu(menu, add_food(5, "Pizza Vegetarian", 10.90, {"olive", "tomato", "pepper"}));
    
    print_menu(menu);

    user_interface(order, menu);

    return 0;
}