#include "user.h"

/* Function returns unique user number
*/
int create_user_id()
{
    static int id = 1;
    return id++;
}

int create_account_id()
{
    static int id = 1000;
    return id++;
}

/* Function takes parameters: name, address and phone_nmbr
 * 1) calls function create_user_id
 * 2) adds new instance to users_map, and adds name, address and phone_nmbr to the struct
 * 3) calls add_new_account function with user_id created in this function.
 */
int add_user(std::unordered_map<int, AccountStruct>& accounts_map, 
std::unordered_map<int, UserStruct>& users_map, 
const std::string& name, const std::string& address, const std::string& phone_nmbr)
{
    int user_id = create_user_id();
   
    UserStruct user;
        
    user.name = name;
    user.address = address;
    user.phone_nmbr = phone_nmbr;

    // Create a user to user map
    users_map.insert(std::pair<int, UserStruct>(user_id, user));

    add_new_account(accounts_map, users_map, user_id);

    return user_id;
}

/* Function takes parameter: user_id
 * 1) Iterates through users_map
 * 2) Returns true if matching user_id is found
 * 3) Returns false if matching user_id is not foundm
*/
bool user_account_exists(std::unordered_map<int, UserStruct>& users_map, const int& user_id)
{
    std::unordered_map<int, UserStruct>::iterator it = users_map.find(user_id);
    if(it != users_map.end())
    {
        return true;
    }
    return false;
}


/* Function takes parameters: user_id
 * 1) calls create_account_id function
 * 2) stores new account to the user's account_vect
 * 3) stores new account to accounts_map
*/
void add_new_account(std::unordered_map<int, AccountStruct>& accounts_map, std::unordered_map<int, UserStruct>& users_map, const int& user_id)
{
    int account_id = create_account_id();

    AccountStruct account;
    account.user_id = user_id;
    account.balance = 0;

    accounts_map.insert(std::pair<int, AccountStruct>(account_id, account));

    users_map.at(user_id).accounts_vect.push_back(account_id);
    
}