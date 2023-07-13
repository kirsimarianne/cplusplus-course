#include "includes/bank.h"
#include "includes/interface.h"
#include "includes/utility.h"

#include <iostream>

int main()
{
    UsersMap users_map{};
    AccountsMap accounts_map{};

    std::cout << "Add test user\n";
    UserID user_id = add_user(users_map, accounts_map, "Pekka Pennonen", "Puutarhakatu 4", "0408372617");
    std::cout << "User id : " << user_id << " bank account: " << users_map.at(user_id).accounts_vect[0] << "\n\n";

    start_interface(users_map, accounts_map);
    return 0;

}