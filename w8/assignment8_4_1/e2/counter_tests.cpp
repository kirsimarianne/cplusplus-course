#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "counter.hpp"
#include "doctest.h"

TEST_CASE("Counter")
{

    SUBCASE("Instances 0")
    {
        {
            Counter obj1;
            Counter obj2 = std::move(obj1);
            CHECK(Counter::count == 1);
        }
        CHECK(Counter:: count == 0);
    }
}