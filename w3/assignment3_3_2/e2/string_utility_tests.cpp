#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "string_utility.h"

TEST_CASE("Check reverse_string")
{

    CHECK(reverse_string("abcd") == "dcba");
    CHECK(reverse_string("a") == "a");
}

TEST_CASE("Check uppercase_string")
{
    CHECK(uppercase_string("abcd") == "ABCD");
}    

TEST_CASE("Check lowercase_string")
{
    CHECK(lowercase_string("ABCD") == "abcd");
}  

TEST_CASE("Check palindrome")
{
    CHECK(is_palindrome("abccba"));
    CHECK(is_palindrome("abcdcba"));
    CHECK(!is_palindrome("abcdefg"));
    CHECK(is_palindrome("a"));
}  