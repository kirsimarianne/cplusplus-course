#ifndef BANK_H
#define BANK_H

#include <unordered_map>
#include <string>
#include <vector>

using UserID = int;
using AccountID = int;

using Name = std::string;
using Address = std::string;
using PhoneNmbr = std::string;
using Balance = double;

struct UserStruct{
    Name name;
    Address address;
    PhoneNmbr phone_nmbr;
    std::vector<AccountID> accounts_vect {};   
};

struct AccountStruct{
    AccountID user_id;
    Balance balance;
};

using UsersMap = std::unordered_map<UserID, UserStruct>;
using AccountsMap = std::unordered_map<AccountID, AccountStruct>;

UserID create_user_id();
AccountID create_account_id();
bool user_account_exists(const UsersMap &users_map, const UserID &user_id);
bool bank_account_exists(const UsersMap& users_map, const UserID& user_id, const AccountID& account_id);
UserID add_user(UsersMap& users_map, AccountsMap& accounts_map, const Name& name, const Address& address, const PhoneNmbr& phone_nmbr);
AccountID add_new_account(UsersMap& users_map, AccountsMap& accounts_map, const UserID& user_id);

Balance get_balance(const AccountsMap &accounts_map, const AccountID &account_id);

bool add_money(const UsersMap& users_map, AccountsMap& accounts_map, const UserID& user_id, const AccountID& account_id, const double& amount);
bool withdraw_money(const UsersMap &users_map, AccountsMap &accounts_map, UserID &user_id, const AccountID &account_id, const double &amount);

#endif