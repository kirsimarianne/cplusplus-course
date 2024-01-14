/* Exercise 2.
 * Write unit tests for a string utility program. 
 * Write unit tests that check if your program can correctly handle reversing a string, 
 * a method to convert a string to uppercase, a method to convert a string to lowercase 
 * and a method to check if a string is a palindrome.
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../external/doctest.h"
#include "../includes/string_utility.h"

TEST_CASE("Check reverse_string")
{

    CHECK(reverse_string("abcd") == "dcba");
    CHECK(reverse_string("a") == "a");
}

TEST_CASE("Check uppercase_string")
{
    CHECK(uppercase_string("abcd") == "ABCD");
    CHECK(uppercase_string("aBcd") == "ABCD");
}    

TEST_CASE("Check lowercase_string")
{
    CHECK(lowercase_string("ABCD") == "abcd");
    CHECK(lowercase_string("ABcd") == "abcd");
    
}  

TEST_CASE("Check palindrome")
{
    CHECK(is_palindrome("abccba"));
    CHECK(is_palindrome("abcdcba"));
    CHECK(!is_palindrome("abcdefg"));
    CHECK(is_palindrome("a"));
}  