#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "heap_array.hpp"
#include "doctest.h"

HeapArray<char, 3> arr3{};

TEST_CASE("Empty heap_array")
{
    HeapArray<int, 0> empty_arr{};
    SUBCASE("Size")
    {
        CHECK(empty_arr.size() == 0);
    }
    SUBCASE("Begin and end iterators same")
    {
        CHECK(empty_arr.begin() == empty_arr.end());
    }
    SUBCASE("empty() true")
    {
        CHECK(empty_arr.empty() == 1);
    }
}

TEST_CASE("Int heap_array with 5 elements")
{
    HeapArray<int, 5> arr5{};
    SUBCASE("Deafault values: values with index")
    {
        CHECK(arr5.size() == 5);
        CHECK(arr5[0] == 0);
        CHECK(arr5[1] == 0);
        CHECK(arr5[2] == 0);
        CHECK(arr5[3] == 0);
        CHECK(arr5[4] == 0);
    }

    SUBCASE("Deafault values: values with iterators")
    {
        CHECK(*arr5.begin() == 0);
        CHECK(*(arr5.begin() + 1) == 0);
        CHECK(*(arr5.begin() + 2) == 0);
        CHECK(*(arr5.begin() + 3) == 0);
        CHECK(*(arr5.end() - 1) == 0);
    }

    arr5[0] = 1;
    arr5[1] = 2;
    arr5[2] = 3;
    arr5[3] = 4;
    arr5[4] = 5;

    SUBCASE("Set values: values with index")
    {
        CHECK(arr5[0] == 1);
        CHECK(arr5[1] == 2);
        CHECK(arr5[2] == 3);
        CHECK(arr5[3] == 4);
        CHECK(arr5[4] == 5);
    }
    SUBCASE("Values with iterators")
    {
        CHECK(*arr5.begin() == 1);
        CHECK(*(arr5.begin() + 1) == 2);
        CHECK(*(arr5.begin() + 2) == 3);
        CHECK(*(arr5.begin() + 3) == 4);
        CHECK(*(arr5.end() - 1) == 5);
    }

    HeapArray<int, 5> arr_copy = arr5;
    SUBCASE("arr_copy: values with index")
    {
        CHECK(arr5[0] == 1);
        CHECK(arr5[1] == 2);
        CHECK(arr5[2] == 3);
        CHECK(arr5[3] == 4);
        CHECK(arr5[4] == 5);

        CHECK(arr_copy[0] == 1);
        CHECK(arr_copy[1] == 2);
        CHECK(arr_copy[2] == 3);
        CHECK(arr_copy[3] == 4);
        CHECK(arr_copy[4] == 5);
    }

    HeapArray<int, 5> arr_move(std::move(arr5));
    SUBCASE("arr_move: values with index")
    {
        CHECK(arr_move[0] == 1);
        CHECK(arr_move[1] == 2);
        CHECK(arr_move[2] == 3);
        CHECK(arr_move[3] == 4);
        CHECK(arr_move[4] == 5);
    }
}
