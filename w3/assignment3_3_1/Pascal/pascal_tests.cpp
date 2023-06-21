#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "pascal.h"


TEST_CASE("Pascal vector tests")
{
    std::vector<std::vector<int>> result {create_pascal(5)};

    /*int sum {};
    for(auto elem : row)
    {
        sum += elem;
    }
    return sum;*/
    CHECK(result[0][0] == 1);
    CHECK(result.size() == 5);
    CHECK(result[4].size() == 9);
}


/*TEST_CASE("Math util tests")
{
    CHECK(sum(1,2) == 3);
    CHECK(divide(4,0) == -1);
}*/
