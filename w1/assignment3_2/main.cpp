/* The program
 * 1) Gets user data as input: name, address and telephone number.
 * 2) Creates an unique number and bank account number for the new user.
 * 3) Stores users data to users_map:
 *    Key: user number, 
 *    Value: UserStruct: name, address, telephone number and vector of user's bank accounts numbers
 * 4) Stores bank accounts to accounts_map:
 *    Key: bank account number
 *    Value: AccountStruct: user number and balance
 * 5) Interface, where user can:
 *    1. Register
 *    2. Sign in
 *      2.1. Add money
 *      2.2. Withdraw money
 *      2.3. Show balance
 *      2.4. Add a new account
 *      2.5. Return
 *    3. Quit
*/

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <fstream>

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
    UserID user_id;
    Balance balance;
};

using UsersMap = std::unordered_map<UserID, UserStruct>;
using AccountsMap = std::unordered_map<AccountID, AccountStruct>;

// Global datastructures
UsersMap users_map;
AccountsMap accounts_map;

/* Function returns unique bank account number
*/
AccountID create_account_id()
{
    static AccountID id = 1000;
    return id++;
}

/* Function returns unique user number
*/
UserID create_user_id()
{
    static UserID id = 1;
    return id++;
}

/* Function takes parameters: user_id
 * 1) calls create_account_id function
 * 2) stores new account to the user's account_vect
 * 3) stores new account to accounts_map
*/
void add_new_account(const UserID& user_id)
{
    AccountID account_id = create_account_id();

    AccountStruct account;
    account.user_id = user_id;
    account.balance = 0;

    accounts_map.insert(std::pair<AccountID, AccountStruct>(account_id, account));

    users_map.at(user_id).accounts_vect.push_back(account_id);
    
}

/* Function takes parameters: name, address and phone_nmbr
 * 1) calls function create_user_id
 * 2) adds new instance to users_map, and adds name, address and phone_nmbr to the struct
 * 3) calls add_new_account function with user_id created in this function.
 */
UserID add_user(const Name& name, const Address& address, const PhoneNmbr& phone_nmbr)
{
    UserID user_id = create_user_id();
   
    UserStruct user;
        
    user.name = name;
    user.address = address;
    user.phone_nmbr = phone_nmbr;

    // Create a user to user map
    users_map.insert(std::pair<UserID, UserStruct>(user_id, user));

    add_new_account(user_id);

    return user_id;
}

/* Function takes parameters: user_id and account_id
 * 1) Iterates vector of user's bank accounts
 * 2) Returns true if matching account_id is found
 * 3) returns false if matching account_id is not found
*/
bool bank_account_exists(const UserID& user_id, const AccountID& account_id)
{   
    for(auto& id_in_vect : users_map.at(user_id).accounts_vect){
        if(id_in_vect == account_id)
        {
            return true;
        }
    }
    return false;
}

/* Function takes parameter: user_id
 * 1) Iterates through users_map
 * 2) Returns true if matching user_id is found
 * 3) Returns false if matching user_id is not foundm
*/
bool user_account_exists(const UserID& user_id)
{
    UsersMap::iterator it = users_map.find(user_id);
    if(it != users_map.end())
    {
        return true;
    }
    return false;
}

/* Function takes parameters: user_id, account_id and amount
 * 1) Adds amount to the balance  and returns true, 
 *    if given bank account exists in given user's data
 * 2) Returns false if given bank account is not found from user's data.
*/
bool add_money(const UserID& user_id, const AccountID& account_id, const double& amount)
{   
    if(bank_account_exists(user_id, account_id))
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
bool withdraw_money(const UserID& user_id, const AccountID& account_id, const double& amount)
{   
    // check if bank account is correst
    if(bank_account_exists(user_id, account_id))
    {
        accounts_map.at(account_id).balance -= amount;
        return true;
    }
    return false;
}

/* Function prints accounts_map to the file account_data.txt
*/
void print_data_to_file(){
    // create and open a text file
    std::ofstream outfile{ "account_data.txt" };
    for(auto& pair: accounts_map){
        outfile << "Account: " << pair.first << " user_id: " << pair.second.user_id 
        << " Balance: " << pair.second.balance << std::endl;
    }
}

// For esting
void add_test_users(){
    add_user("Pekka Pennonen", "Puistokatu 20 B 35, 33100, Tampere", "0402536385");
    add_user("Risto Rahakas", "Puutarhakatu 7, 33400, Tampere", "0404002285");
    add_user("Martti Markkanen", "Tikkukuja 25, 33100, Tampere", "0404005585");

}

// For testing
void test(){

    std::cout << "--------TEST STARTS--------" << "\n";
    std::cout << "Iterating users_map " << "\n";
    for(auto& pair : users_map){
        std::cout << pair.first << " : " << pair.second.name<< " " << pair.second.address << " " 
        << pair.second.phone_nmbr << " " << std::endl;

        std::cout << "Iterating accounts_vect" << "\n";
        for(auto& account_id : pair.second.accounts_vect){
        std::cout << account_id << ", ";
        }
        std::cout << "\n";
    }

    std::cout << "Iterating accounts_map" << "\n";
    for(auto& pair: accounts_map){
        std::cout << "Account: " << pair.first << " user_id: " << pair.second.user_id 
        << " Balance: " << pair.second.balance << std::endl;
    }

    std::cout << "--------TEST ENDS--------" << "\n";
}


int main()
{

    add_test_users();
    test();


    while(true)
    {
        std::cout << "What would you like to do?" << "\n"
        << "1: Register" << "\n"
        << "2: Sign in" << "\n"
        << "3: Quit" << "\n";
        
        int cmd {0};
        std::cin >> cmd;
        std::cin.ignore(256, '\n');

        switch (cmd)
        {
            case 1:
            {
                std::cout << "Name: ";
                Name name {};
                std::getline(std::cin, name);
                std::cout << "Address: ";
                Address address {};
                std::getline(std::cin, address);
                std::cout << "Telephone number: ";
                PhoneNmbr phone_nmbr {};
                std::getline(std::cin, address);
                UserID new_user_id = add_user(name, address, phone_nmbr);
                std::cout << "Account added succesfully!" << "\n"
                << "Your user number is: " << new_user_id << "\n"
                << "Your bank account number is: " << users_map.at(new_user_id).accounts_vect.at(0) << "\n";
            }
            break;
            //Sign in
            case 2:  
            {   
                std::cout << "Please enter your user number: ";
                bool continue_case2 = true;
                UserID user_id {};
                std::cin >> user_id;
                std::cin.ignore(256, '\n');
                if(user_account_exists(user_id))
                {
                    while(continue_case2)
                    {
                        std::cout << "What would you like to do?" << "\n"
                        << "1: Add money" << "\n"
                        << "2: Withdraw money" << "\n"
                        << "3: See the balance of the bank account" << "\n"
                        << "4: Add a new bank account" << "\n"
                        << "5: Return" << "\n";
                        int cmd2 {};
                        std::cin >> cmd2;
                        std::cin.ignore(256, '\n');
                        switch(cmd2)
                        {
                            // Add money
                            case 1:
                            {
                                std::cout << "Give your bank account number: ";  
                                AccountID account_id {};
                                std::cin >> account_id;
                                std::cin.ignore(256, '\n');
                                std::cout << "Give the amount: "; 
                                double amount {};
                                std::cin >> amount;
                                if(add_money(user_id, account_id, amount))
                                {
                                    std::cout << "Money added succesfully!" << "\n";
                                }
                                else
                                {
                                    std::cout << "Wrong bank account number." << "\n";
                                }
                                break;
                            }
                            // Withdraw money
                            case 2:
                            {
                                std::cout << "Give your bank account number: ";  
                                AccountID account_id {};
                                std::cin >> account_id;
                                std::cin.ignore(256, '\n');
                                std::cout << "Give the amount: "; 
                                double amount {};
                                std::cin >> amount;
                                std::cin.ignore(256, '\n');
                                if(withdraw_money(user_id, account_id, amount))
                                {
                                    std::cout << "Money withdrawed succesfully!" << "\n";
                                }
                                else
                                {
                                    std::cout << "Wrong bank account number." << "\n";
                                }
                                break;
                            }
                            // Show the balance
                            case 3:
                            {
                                std::cout << "Give the bank account number: ";
                                AccountID account_id {};
                                std::cin >> account_id;
                                std::cin.ignore(256, '\n');
                                if(bank_account_exists(user_id, account_id))
                                {
                                    std::cout << "Balance of: " << account_id << " is " << accounts_map.at(account_id).balance << "\n"; 
                                }
                                else
                                {
                                    std::cout << "Wrong bank account number." << "\n";
                                }     
                                break;                 
                            }
                            case 4:
                            {
                                add_new_account(user_id);
                                std::cout << "New bank account number is:  " << users_map.at(user_id).accounts_vect.back() << "\n";
                                break;
                            }
                            case 5:
                            {
                                continue_case2 = false;
                                break;
                            }
                        }
                    }    
                }        
                else
                {
                    std::cout << "User number not found." << "\n";
                }    
                break;
            }    
            // Quit the program
            case 3:
            {
                std::cout << "Bye bye!";
                print_data_to_file();
                return 0;
            }
        }
    }
    return -1;
}    