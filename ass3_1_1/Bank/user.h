#ifndef USER_H
#define USER_H

#include <unordered_map>
#include <string>
#include <vector>


struct UserStruct{
    std::string name;
    std::string address;
    std::string phone_nmbr;
    std::vector<int> accounts_vect {};   
};

struct AccountStruct{
    int user_id;
    double balance;
};

int create_user_id();
int create_account_id();
int add_user(std::unordered_map<int, AccountStruct>& accounts_map, 
std::unordered_map<int, UserStruct>& users_map, 
const std::string& name, const std::string& address, const std::string& phone_nmbr);
//bool user_account_exists(UsersMap& users_map, const int& user_id);
void add_new_account(std::unordered_map<int, AccountStruct>& accounts_map, std::unordered_map<int, UserStruct>& users_map, const int& user_id);

#endif