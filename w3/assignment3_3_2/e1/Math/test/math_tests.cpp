/* Exericse 1.
 * Test basic math functions.First write your unit tests 
 * and then create simple math functions like addition, subtraction, 
 * multiplication and division. Try and think about meaningful unit tests. 
 * Your program does not need a user interface now that you are using unit tests to check for functionality.
 * Remember error handling.
*/

#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "../external/doctest.h"
#include "../includes/math.h"

TEST_CASE("Check sum")
{
    CHECK(add(2, 1) == 3);
    CHECK(add(1, 2) == 3);
    CHECK(add(-1, 2) == 1);
    CHECK(add(1, -2) == -1);
    CHECK(add(-1, -2) == -3);
    CHECK(add(0, 2) == 2);
    CHECK(add(0, 0) == 0);
}

TEST_CASE("Check subtract")
{
    CHECK(subtract(2, 1) == 1);
    CHECK(subtract(1, 2) == -1);
    CHECK(subtract(-1, 2) == -3);
    CHECK(subtract(1, -2) == 3);
    CHECK(subtract(-1, -2) == 1);
    CHECK(subtract(0, 2) == -2);
    CHECK(subtract(2, 0) == 2);
    CHECK(subtract(0, 0) == 0);
}

TEST_CASE("Check multiply")
{
    CHECK(multiply(2, 1) == 2);
    CHECK(multiply(1, 2) == 2);
    CHECK(multiply(-1, 2) == -2);
    CHECK(multiply(1, -2) == -2);
    CHECK(multiply(-1, -2) == 2);
    CHECK(multiply(0, 2) == 0);
    CHECK(multiply(2, 0) == 0);
    CHECK(multiply(0, 0) == 0);
}

TEST_CASE("Check divide")
{
    CHECK(divide(4.0, 2.0) == 2);
    CHECK(divide(2.0, 4.0) == 0.5);
    CHECK(divide(-2.0, 4.0) == -0.5);
    CHECK(divide(2.0, -4.0) == -0.5);
    CHECK(divide(-2.0, -4.0) == 0.5);
    CHECK(divide(0.0, 2.0) == 0);
    CHECK(divide(1.0, 3.0) == 0.33);
}

TEST_CASE("Check dividing with 0")
{
    CHECK_THROWS_AS(divide(1.0,0.0), std::runtime_error);
}