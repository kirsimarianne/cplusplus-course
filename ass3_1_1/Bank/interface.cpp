#include "interface.h"
#include <iostream>
#include <cctype>

int string_to_int(std::string str)
{
    int integer{};
    try
    {
        integer = std::stoi(str);
    }
    catch (const std::invalid_argument &e)
    {
        throw e;
    }
    catch (const std::out_of_range &e)
    {
        throw e;
    }
    return integer;
}

/* Function asks information from user: name, address and phone number.
 * Calls add_user function to create new user.
 * Prints created user id number and bank account number
 * Future development: error handling: function does not check inputs in any way.
 */
void register_user(UsersMap &users_map, AccountsMap &accounts_map)
{
    std::cout << "Name:\n";
    Name name{};
    std::getline(std::cin, name);
    std::cout << "Address: ";
    Address address{};
    std::getline(std::cin, address);
    std::cout << "Telephone number: ";
    PhoneNmbr phone_nmbr{};
    std::getline(std::cin, address);
    UserID new_user_id = add_user(users_map, accounts_map, name, address, phone_nmbr);
    std::cout << "Account added succesfully!"
              << "\n"
              << "Your user number is: " << new_user_id << "\n"
              << "Your bank account number is: " << users_map.at(new_user_id).accounts_vect.at(0) << "\n";
}

/* Function asks user id in a loop.
 * Calls string_to_input function and bank: user_account_exists functiron.
 * Prints error message if input is not integer or id does not exists.
 * Returns valid user_id.
 */
UserID get_user_id(UsersMap &users_map)
{
    while (true)
    {
        std::cout << "Please enter your user number: ";
        std::string input;
        std::getline(std::cin, input);
        UserID user_id{};
        try
        {
            user_id = string_to_int(input);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid user number.\n";
            continue;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Invalid user number.\n";
            continue;
        }
        if (!user_account_exists(users_map, user_id))
        {
            std::cerr << "Invalid user number.\n";
            continue;
        }
        return user_id;
    }
}

AccountID get_account_id(UsersMap &users_map, UserID user_id)
{
    while (true)
    {
        std::cout << "Please enter your bank account number: ";
        std::string input;
        std::getline(std::cin, input);
        AccountID account_id{};

        try
        {
            account_id = string_to_int(input);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid bank account number.\n";
            continue;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Invalid bank account number.\n";
            continue;
        }
        if (!bank_account_exists(users_map, user_id, account_id))
        {
            std::cerr << "Invalid bank account number.\n";
            continue;
        }
        return account_id;
    }
}

void sign_in(UsersMap &users_map, AccountsMap &accounts_map)
{
    UserID user_id{get_user_id(users_map)};
    while (true)
    {
        std::cout << "What would you like to do? \n1: Add money \n2: Withdraw money \n"
                  << "3: See the balance of the bank account \n4: Add a new bank account \n5: Return\n";
        std::string input{};
        std::getline(std::cin, input);
        int cmd{};
        try
        {
            cmd = string_to_int(input);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid command.\n";
            continue;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Invalid command:\n";
            continue;
        }

        if (!(cmd == 1 || cmd == 2 || cmd == 3 || cmd == 4 || cmd == 5))
        {
            std::cerr << "Invalid command.\n";
            continue;
        }

        switch (cmd)
        {
        case 1:
        {
            AccountID account_id{get_account_id(users_map, user_id)};
            std::cin >> account_id;
            std::cin.ignore(256, '\n');
            std::cout << "Give the amount: ";
            double amount{};
            std::cin >> amount;
            if (add_money(user_id, account_id, amount))
            {
                std::cout << "Money added succesfully!"
                          << "\n";
            }
            else
            {
                std::cout << "Wrong bank account number."
                          << "\n";
            }
            break;
        }
        case 2:
        {
        }
        case 3:
        {
        }
        case 4:
        {
        }
        case 5:
        {
        }
        }
    }
}

int main()
{
    UsersMap users_map{};
    AccountsMap accounts_map{};
    while (true)
    {
        std::cout << "What would you like to do? \n1: Register \n2: Sign in \n3: Quit\n";
        std::string input{};
        std::getline(std::cin, input);
        int cmd{};
        try
        {
            cmd = string_to_int(input);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid command.\n";
            continue;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Invalid command:\n";
            continue;
        }

        if (!(cmd == 1 || cmd == 2 || cmd == 3))
        {
            std::cerr << "Invalid command.\n";
            continue;
        }

        switch (cmd)
        {
        case 1:
        {
            register_user(users_map, accounts_map);
        }
        case 2:
        {
            sign_in(users_map, accounts_map);
        }
        case 3:
        {
            std::cout << "Bye bye!";
            // print_data_to_file();
            return 0;
        }
        }
    }
}