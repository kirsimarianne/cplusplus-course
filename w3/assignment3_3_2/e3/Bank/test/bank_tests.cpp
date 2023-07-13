/* Exercise 3.
 * Add unit tests to your banking program that you had built earlier. Try and get as high test coverage as possible.
 *
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../external/doctest.h"
#include "../includes/bank.h"

const int ERROR_CODE = -1;

UsersMap users_map{};
AccountsMap accounts_map{};
Name test_name{"Pekka Pennonen"};
Address test_address{"Puistokatu 20 B 35, 33100, Tampere"};
PhoneNmbr test_phone{"0402536385"};
Balance test_balance{};
UserID test_user_id{};
UserID false_user_id{-1};
AccountID test_account_id{};
AccountID false_account_id{-1};

TEST_CASE("Function add_user and side-effects of add_account")
{
    SUBCASE("Add user succesfully")
    {
        test_user_id = add_user(users_map, accounts_map, test_name, test_address, test_phone);
        CHECK(test_user_id != ERROR_CODE);
        CHECK(users_map.at(test_user_id).name == test_name);
        CHECK(users_map.at(test_user_id).address == test_address);
        CHECK(users_map.at(test_user_id).phone_nmbr == test_phone);
        CHECK(users_map.at(test_user_id).accounts_vect.size() == 1);
    }
    SUBCASE("First bank account created succesfully after add_user call")
    {
        // find created bank account from test_user struct inside accounts_vect
        test_account_id = users_map.at(test_user_id).accounts_vect.at(0);
        // Check the same account is inside accounts_map
        AccountsMap::iterator it = accounts_map.find(test_account_id);
        CHECK(it != accounts_map.end());
    }
}

TEST_CASE("Function user_account_exists")
{
    SUBCASE("Call function with existing id")
    {
        CHECK(user_account_exists(users_map, test_user_id) == true);
    }
    SUBCASE("Call function with non-existing id")
    {
        CHECK(user_account_exists(users_map, false_user_id) == false);
    }
}

TEST_CASE("Function bank_account_exists")
{
    SUBCASE("Call function with existing user_id and account_id")
    {
        CHECK(bank_account_exists(users_map, test_user_id, test_account_id) == true);
    }
    SUBCASE("Call function false values")
    {
        CHECK(bank_account_exists(users_map, false_user_id, test_account_id) == false);
        CHECK(bank_account_exists(users_map, test_user_id, false_account_id) == false);
        CHECK(bank_account_exists(users_map, false_user_id, false_account_id) == false);
    }
}

TEST_CASE("Function add_account")
{
    SUBCASE("Try add account for non-existing user")
    {
        AccountID tmp_account_id = add_new_account(users_map, accounts_map, false_user_id);
        CHECK(tmp_account_id == ERROR_CODE);
    }
    SUBCASE("Add new account succesfully")
    {
        AccountID tmp_account_id = add_new_account(users_map, accounts_map, test_user_id);
        CHECK(tmp_account_id != ERROR_CODE);
        // Check account can be found from accounts_vect in second place.
        CHECK(tmp_account_id == users_map.at(test_user_id).accounts_vect.at(1));
        // Check account can be found from accounts_map
        AccountsMap::iterator it = accounts_map.find(test_account_id);
        CHECK(it != accounts_map.end());
    }
}

TEST_CASE("Function add_money and bank_account_exists: side-effects")
{
    double test_amount{123.55};
    // users_map.at(test_user_id).vects
    SUBCASE("Add money succesfully")
    {
        Balance before_balance = accounts_map.at(test_account_id).balance;
        bool add_money_succesfully{add_money(users_map, accounts_map, test_user_id, test_account_id, test_amount)};
        Balance after_balance = accounts_map.at(test_account_id).balance;
        CHECK(add_money_succesfully == true);
        CHECK(after_balance == before_balance + test_amount);
    }
    SUBCASE("Add money with false id values")
    {
        CHECK(add_money(users_map, accounts_map, false_user_id, test_account_id, test_amount) == false);
        CHECK(add_money(users_map, accounts_map, test_user_id, false_account_id, test_amount) == false);
        CHECK(add_money(users_map, accounts_map, false_user_id, false_account_id, test_amount) == false);
    }
}

TEST_CASE("Function add_money and bank_account_exists: side-effects")
{
    double test_amount{100.00};
    double false_amount{200.00};
    // users_map.at(test_user_id).vects
    SUBCASE("Withdraw money succesfully")
    {
        Balance before_balance = accounts_map.at(test_account_id).balance;
        bool withdraw_money_succesfully{add_money(users_map, accounts_map, test_user_id, test_account_id, test_amount)};
        Balance after_balance = accounts_map.at(test_account_id).balance;
        CHECK(withdraw_money_succesfully == true);
        CHECK(after_balance == before_balance - test_amount);
    }
    SUBCASE("Withdraw money with false id values")
    {
        CHECK(withdraw_money(users_map, accounts_map, false_user_id, test_account_id, test_amount) == false);
        CHECK(withdraw_money(users_map, accounts_map, test_user_id, false_account_id, test_amount) == false);
        CHECK(withdraw_money(users_map, accounts_map, false_user_id, false_account_id, test_amount) == false);
    }
}