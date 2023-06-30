#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "user.h"

TEST_CASE("add_user")
{
    std::unordered_map<int, UserStruct> users_map{};
    std::unordered_map<int, AccountStruct> accounts_map{};
    std::string test_name{"Pekka Pennonen"};
    std::string test_address{"Puistokatu 20 B 35, 33100, Tampere"};
    std::string test_phone{"0402536385"};
    SUBCASE("Add user succesfully")
    {
        int test_id = add_user(accounts_map, users_map, test_name, test_address, test_phone);
        CHECK(users_map.at(test_id).name == test_name);
    }
}

TEST_CASE("add_user")
{
    std::unordered_map<int, UserStruct> users_map{};
    std::unordered_map<int, AccountStruct> accounts_map{};
    std::string test_name{"Pekka Pennonen"};
    std::string test_address{"Puistokatu 20 B 35, 33100, Tampere"};
    std::string test_phone{"0402536385"};
    SUBCASE("Add user succesfully")
    {
        int test_id = add_user(accounts_map, users_map, test_name, test_address, test_phone);
        CHECK(users_map.at(test_id).name == test_name);
    }
}