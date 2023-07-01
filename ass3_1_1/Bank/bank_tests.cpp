#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "bank.h"

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

TEST_CASE("Test add_user and side-effects of add_account functions")
{
    SUBCASE("Add user succesfully")
    {
        test_user_id = add_user(accounts_map, users_map, test_name, test_address, test_phone);
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

TEST_CASE("user_account_exists")
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

TEST_CASE("bank_account_exists")
{
    SUBCASE("Call function with existing user_id and account_id")
    {
        CHECK(bank_account_exists(users_map, accounts_map, test_user_id, test_account_id) == true);
    }
    SUBCASE("Call function false values")
    {
        CHECK(bank_account_exists(users_map, accounts_map, false_account_id, test_account_id) == false);
        CHECK(bank_account_exists(users_map, accounts_map, test_account_id, false_account_id) == false);
        CHECK(bank_account_exists(users_map, accounts_map, false_account_id, false_account_id) == false);
    }
}

TEST_CASE("Function add_account")
{
    SUBCASE("Try add account for non-existing user")
    {
        AccountID tmp_account_id = add_new_account(accounts_map, users_map, false_user_id);
        CHECK(tmp_account_id == ERROR_CODE);
    }
    SUBCASE("Add new account succesfully")
    {
        AccountID tmp_account_id = add_new_account(accounts_map, users_map, test_user_id);
        CHECK(tmp_account_id != ERROR_CODE);
        // Check account can be found from accounts_vect in second place.
        CHECK(tmp_account_id == users_map.at(test_user_id).accounts_vect.at(1));
        // Check account can be found from accounts_map
        AccountsMap::iterator it = accounts_map.find(test_account_id);
        CHECK(it != accounts_map.end());
    }
}

double test_amount{123.55};
char false_type_amount{'a'};
double test_amount{123.55555555};

TEST_CASE("Function add_money and bank_account_exists: side-effects")
{

    // users_map.at(test_user_id).vects
    SUBCASE("Add money succesfully")
    {
        Balance tmp_balance = accounts_map.at(test_account_id).balance;
        add_money(users_map, accounts_map, test_user_id, test_account_id, test_amount);
        Balance new_balance = accounts_map.at(test_account).balance;
        CHECK(tmp_balance = new_balance)

        CHECK(accounts_map.at(test_account).balance ==)
    }
    SUBCASE("Add money with false account_id")
    {
        CHECK(add_money())
    }
}