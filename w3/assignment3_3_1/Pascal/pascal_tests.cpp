#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "pascal.h"
#include "doctest.h"

int row = 10;
std::vector<std::vector<int>> result = create_pascal(row);

TEST_CASE("Pascal vector")
{
    SUBCASE("Size of vector")
    {
        CHECK(result.size() == row);
        CHECK(result[0].size() == 1);
        CHECK(result[4].size() == 5);
        CHECK(result[row-1].size() == row );
    }

    SUBCASE("Single places")
    {
        CHECK(result[0][0] == 1);
        CHECK(result[3][1] == 3);
        CHECK(result[5][2] == 10);
    }

    SUBCASE("Check sum of last line")
    {
        int sum {};
        for(auto elem : result[row-1])
        {
            sum += elem;
        }
        CHECK( pow(2, row-1)== sum);
    }
}