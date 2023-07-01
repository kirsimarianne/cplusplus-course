#include "bank.h"

/* Function returns unique user number
 */
UserID create_user_id()
{
    static int id = 1;
    return id++;
}

/* Function returns unique account number
 */
AccountID create_account_id()
{
    static int id = 1000;
    return id++;
}

/* Function takes parameters: users_map and user_id
 * 1) Iterates through users_map
 * 2) Returns true if matching user_id is found
 * 3) Returns false if matching user_id is not foundm
 */
bool user_account_exists(const UsersMap &users_map, const UserID &user_id)
{
    UsersMap::const_iterator it = users_map.find(user_id);
    if (it != users_map.end())
    {
        return true;
    }
    return false;
}

/* Function takes parameters: user_id and account_id
 * 1) Iterates vector of user's bank accounts
 * 2) Returns true if matching account_id is found
 * 3) returns false if matching account_id is not found
 * 4) returns false if matching user_id is not found
 */
bool bank_account_exists(const UsersMap &users_map, const UserID &user_id, const AccountID &account_id)
{
    UsersMap::const_iterator it = users_map.find(user_id);
    if (it != users_map.end())
    {
        for (auto &id_in_vect : users_map.at(user_id).accounts_vect)
        {
            if (id_in_vect == account_id)
            {
                return true;
            }
        }
        return false;
    }

    return false;
}

/* Function takes parameters: name, address and phone_nmbr
 * 1) calls function create_user_id
 * 2) adds new instance to users_map, and adds name, address and phone_nmbr to the struct
 * 3) calls add_new_account function with user_id created in this function.
 * Error handling: if create_user_id returns id which is already in use, returns -1.
 */
UserID add_user(UsersMap& users_map, AccountsMap &accounts_map,
                const Name &name, const Address &address, const PhoneNmbr &phone_nmbr)
{
    UserID user_id = create_user_id();

    UsersMap::iterator it_user = users_map.find(user_id);
    if (it_user != users_map.end())
    {
        return -1;
    }

    UserStruct user;
    user.name = name;
    user.address = address;
    user.phone_nmbr = phone_nmbr;

    users_map.insert(std::pair<int, UserStruct>(user_id, user));
    add_new_account(users_map, accounts_map, user_id);

    return user_id;
}

/* Function takes parameters: accounts_map, users_map and user_id
 * 1) calls create_account_id function
 * 2) stores new account to the user's account_vect
 * 3) stores new account to accounts_map
 * Error handling: if user_id is not found, returns -1.
 */
AccountID add_new_account(UsersMap& users_map, AccountsMap &accounts_map, const UserID &user_id)
{
    // If user does not exists return -1.
    UsersMap::iterator it_user = users_map.find(user_id);
    if (it_user == users_map.end())
    {
        return -1;
    }

    AccountID account_id = create_account_id();

    // If created iterator exists already return -1.
    AccountsMap::iterator it_account = accounts_map.find(account_id);
    if (it_account != accounts_map.end())
    {
        return -1;
    }

    AccountStruct account;
    account.user_id = user_id;
    account.balance = 0;
    accounts_map.insert(std::pair<AccountID, AccountStruct>(account_id, account));
    users_map.at(user_id).accounts_vect.push_back(account_id);

    return account_id;
}

/* Function takes parameters: users_map, accounts_map, user_id, account_id and amount
 * 1) Adds amount to the balance  and returns true,
 *    if given bank account exists in given user's data
 * 2) Returns false if given bank account is not found from user's data.
 */
bool add_money(const UsersMap &users_map, AccountsMap &accounts_map, const UserID &user_id, const AccountID &account_id, const double &amount)
{
    if (bank_account_exists(users_map, user_id, account_id))
    {
        accounts_map.at(account_id).balance += amount;
        return true;
    }
    return false;
}

/* Function takes parameters: user_id, account_id and amount
 * 1) Decreases amount of the balance and returns true,
 *    if given bank account exists in given user's data
 * 2) Returns false if given bank account is not found from user's data.
 */
bool withdraw_money(const UsersMap &users_map, AccountsMap &accounts_map, UserID &user_id, const AccountID &account_id, const double &amount)
{
    // check if bank account is correst
    if (bank_account_exists(users_map, user_id, account_id))
    {
        if (accounts_map.at(account_id).balance >= amount)
        {
            accounts_map.at(account_id).balance -= amount;
            return true;
        }
        return false;
    }
    return false;
}

Balance get_balance(const AccountsMap &accounts_map, const AccountID &account_id)
{
    AccountsMap::const_iterator it = accounts_map.find(account_id);

    if (it == accounts_map.end())
    {
        return -1;
    }

    return accounts_map.at(account_id).balance;
}