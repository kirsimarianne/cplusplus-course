#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "pascal.h"


TEST_CASE("Pascal vector tests")
{
    int value = 5;
    std::vector<std::vector<int>> result {create_pascal(value)};

    CHECK(result.size() == 5);
    CHECK(result[4].size() == 9);
    CHECK(result[0][0] == 1);
    CHECK(result[2][2] == 1);
    CHECK(result[3][1] == 3);
    CHECK(result[4][2] == 6);
}