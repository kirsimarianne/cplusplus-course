#ifndef INTERFACE_H
#define INTERFACE_H

#include "bank.h"
#include "utility.h"

#include <fstream>

int string_to_int(std::string str);
void register_user(UsersMap& users_map, AccountsMap& accounts_map);


#endif