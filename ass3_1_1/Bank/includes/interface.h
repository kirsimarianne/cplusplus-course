#ifndef INTERFACE_H
#define INTERFACE_H

#include "bank.h"
#include "utility.h"

#include <fstream>

void print_data_to_file(AccountsMap& accounts_map);
void register_user(UsersMap &users_map, AccountsMap &accounts_map);
UserID get_user_id(UsersMap &users_map);
AccountID get_account_id(UsersMap &users_map, UserID user_id);
double get_amount();
void sign_in(UsersMap &users_map, AccountsMap &accounts_map);
void start_interface(UsersMap& users_map, AccountsMap& accounts_map);

#endif