#include "interface.h"

void print_data_to_file(AccountsMap& accounts_map){
    // create and open a text file
    std::ofstream outfile{ "account_data.txt" };
    for(auto& pair: accounts_map){
        outfile << "Account: " << pair.first << " user_id: " << pair.second.user_id 
        << " Balance: " << pair.second.balance << std::endl;
    }
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

/* Function asks bank account from the user.
 * Checks that input is integer.
 * Calls bank_account_exists function,
 * to check given account is found from users_map with given user id.
 * Loops until user gives right bank account.
 * Returns account id.
 */

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
            std::cerr << "Invalid bank account number.\n\n";
            continue;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Invalid bank account number.\n\n";
            continue;
        }
        if (!bank_account_exists(users_map, user_id, account_id))
        {
            std::cerr << "Invalid bank account number.\n\n";
            continue;
        }
        return account_id;
    }
}

/* Function asks amount from user.
 * Checks input is double type.
 * Calls function to check input has maximum two decimals.
 * Checks amount is not negative.
 * Returns amount.
 */
double get_amount()
{
    while (true)
    {
        std::cout << "Please give the amount: ";
        std::string input;
        std::getline(std::cin, input);
        double amount{};
        try
        {
            amount = string_to_double(input);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid amount.\n\n";
            continue;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Invalid amount.\n\n";
            continue;
        }
        if (amount <= 0)
        {
            std::cerr << "Invalid amount.\n\n";
            continue;
        }
        if (!max_two_decimals(amount))
        {
            std::cerr << "Invalid amount.\n\n";
            continue;
        }
        return amount;
    }
}

/* Function calls get_user_id to get existing user id from the user.
 * Checks command is correct and loops until correct command is given.
 * Function have 5 cases.
 * 1. Add money
 *      Calls get_account_id function to get a correct bank account
 *      (checks bank account belongs to user id)
 *      Calls get_amount function to get amount in double maximum two decimals.
 *      Calls add_money function.
 *      Error handling done when checking user_id and bank_account and amount,
 *      should never call add_money with false input.
 * 2: Withdraw money
 *      Works same as Add money case
 *      Except calls withdraw_function, which can return false if balance <= amount.
 * 3: View balance
 *      Calls get_account function.
 *      Calls get_balance function.
 *      Should never call get_balance with false input.
 * 4: Add a new bank account
 *      Calls add_new_bank_account
 * 5: Return
 *      Breaks the loop
 */

void sign_in(UsersMap &users_map, AccountsMap &accounts_map)
{
    UserID user_id{get_user_id(users_map)};
    std::cout << "User id " << user_id << " found.\n";
    bool continue_cases{true};
    while (continue_cases)
    {
        std::cout << "What would you like to do? \n1: Add money \n2: Withdraw money \n"
                  << "3: View the balance of the bank account \n4: Add a new bank account \n5: Return\n";
        std::string input{};
        std::getline(std::cin, input);
        int cmd{};
        try
        {
            cmd = string_to_int(input);
        }
        catch (const std::invalid_argument &e)
        {
            std::cerr << "Invalid command.\n\n";
            continue;
        }
        catch (const std::out_of_range &e)
        {
            std::cerr << "Invalid command:\n\n";
            continue;
        }

        if (!(cmd == 1 || cmd == 2 || cmd == 3 || cmd == 4 || cmd == 5))
        {
            std::cerr << "Invalid command.\n\n";
            continue;
        }

        switch (cmd)
        {
        case 1:
        {
            AccountID account_id{get_account_id(users_map, user_id)};
            double amount{get_amount()};
            if (add_money(users_map, accounts_map, user_id, account_id, amount))
            {
                std::cout << amount << "€ added succesfully to bank account: " << account_id << "\n\n";
            }

            else
            {
                // Should never reach this.
                // Checking done already in get_account_id function.
                std::cout << "Function suspended.\n\n";
            }
            break;
        }
        case 2:
        {
            AccountID account_id{get_account_id(users_map, user_id)};
            std::cout << "Account id " << account_id << " found.\n\n";
            double amount{get_amount()};
            if (withdraw_money(users_map, accounts_map, user_id, account_id, amount))
            {
                std::cout << amount << "€ withdrawed succesfully from bank account: " << account_id << "\n\n";
            }
            else
            {
                // Should reach only if balance is smaller than amount.
                // Bank account checking done already in get_account function.
                std::cout << "Function suspended.\n\n";
            }
            break;
        }
        case 3:
        {
            AccountID account_id{get_account_id(users_map, user_id)};
            Balance balance = get_balance(accounts_map, account_id);
            // Should never reach this.
            if (balance == -1)
            {
                std::cout << "Function suspended.\n\n";
            }
            else
            {
                std::cout << "Balance of " << account_id << " is: " << balance << "\n\n";
            }
            break;
        }
        case 4:
        {
            add_new_account(users_map, accounts_map, user_id);
            std::cout << "New bank account number is:  " << users_map.at(user_id).accounts_vect.back() << "\n\n";
            break;
        }
        case 5:
        {
            continue_cases = false;
            break;
        }
        }
    }
}

/* Function asks command from the user as long as the command is correct.
 * Has 3 cases:
 * 1: Register: calls register_user function
 * 2: Sign in: calls sign_in function
*/
void start_interface(UsersMap& users_map, AccountsMap& accounts_map)
{
    bool continue_cases{true};
    while (continue_cases)
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
                break;
            }
            case 2:
            {
                sign_in(users_map, accounts_map);
                break;
            }
            case 3:
            {
                std::cout << "Bye bye!";
                print_data_to_file(accounts_map);
                continue_cases = false;
                break;
            }
        }
    }
}

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