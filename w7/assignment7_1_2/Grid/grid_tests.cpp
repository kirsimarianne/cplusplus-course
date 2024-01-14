#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include "grid.hpp"

TEST_CASE("Test constructors")
{
    SUBCASE("Default init 3x4 int grid")
    {
        Grid<int> integer_grid(3, 4);
        CHECK(integer_grid.at(0, 0) == 0);
        CHECK(integer_grid.at(0, 1) == 0);
        CHECK(integer_grid.at(0, 2) == 0);
        CHECK(integer_grid.at(0, 3) == 0);

        CHECK(integer_grid.at(1, 0) == 0);
        CHECK(integer_grid.at(1, 1) == 0);
        CHECK(integer_grid.at(1, 2) == 0);
        CHECK(integer_grid.at(1, 3) == 0);

        CHECK(integer_grid.at(2, 0) == 0);
        CHECK(integer_grid.at(2, 1) == 0);
        CHECK(integer_grid.at(2, 2) == 0);
        CHECK(integer_grid.at(2, 3) == 0);
    }

    SUBCASE("Init 3x4 char grid with value 'x'")
    {
        Grid<char> character_grid(3, 4, 'x');
        CHECK(character_grid.at(0, 0) == 'x');
        CHECK(character_grid.at(0, 1) == 'x');
        CHECK(character_grid.at(0, 2) == 'x');
        CHECK(character_grid.at(0, 3) == 'x');

        CHECK(character_grid.at(1, 0) == 'x');
        CHECK(character_grid.at(1, 1) == 'x');
        CHECK(character_grid.at(1, 2) == 'x');
        CHECK(character_grid.at(1, 3) == 'x');

        CHECK(character_grid.at(2, 0) == 'x');
        CHECK(character_grid.at(2, 1) == 'x');
        CHECK(character_grid.at(2, 2) == 'x');
        CHECK(character_grid.at(2, 3) == 'x');
    }
}

TEST_CASE("Test set function")
{
    SUBCASE("Default init 3x4 int grid")
    {
        Grid<int> integer_grid(3, 4);
        integer_grid.set(0, 0, 1);
        integer_grid.set(2, 3, 2);
        integer_grid.set(1, 2, 3);
        CHECK(integer_grid.at(0, 0) == 1);
        CHECK(integer_grid.at(0, 1) == 0);
        CHECK(integer_grid.at(0, 2) == 0);
        CHECK(integer_grid.at(0, 3) == 0);

        CHECK(integer_grid.at(1, 0) == 0);
        CHECK(integer_grid.at(1, 1) == 0);
        CHECK(integer_grid.at(1, 2) == 3);
        CHECK(integer_grid.at(1, 3) == 0);

        CHECK(integer_grid.at(2, 0) == 0);
        CHECK(integer_grid.at(2, 1) == 0);
        CHECK(integer_grid.at(2, 2) == 0);
        CHECK(integer_grid.at(2, 3) == 2);
    }

    SUBCASE("Init 3x4 char grid with value 'x'")
    {
        Grid<char> character_grid(3, 4, 'x');
        character_grid.set(0, 3, 'a');
        character_grid.set(1, 1, 'b');
        character_grid.set(2, 0, 'c');
        CHECK(character_grid.at(0, 0) == 'x');
        CHECK(character_grid.at(0, 1) == 'x');
        CHECK(character_grid.at(0, 2) == 'x');
        CHECK(character_grid.at(0, 3) == 'a');

        CHECK(character_grid.at(1, 0) == 'x');
        CHECK(character_grid.at(1, 1) == 'b');
        CHECK(character_grid.at(1, 2) == 'x');
        CHECK(character_grid.at(1, 3) == 'x');

        CHECK(character_grid.at(2, 0) == 'c');
        CHECK(character_grid.at(2, 1) == 'x');
        CHECK(character_grid.at(2, 2) == 'x');
        CHECK(character_grid.at(2, 3) == 'x');
    }
}

TEST_CASE("Get size and resize")
{
    Grid<int> integer_grid(2, 2);
    SUBCASE("First size")
    {
        CHECK(integer_grid.get_size() == 4);
    }
    SUBCASE("Make size bigger")
    {
        integer_grid.resize(5, 5);
        CHECK(integer_grid.get_size() == 25);
    }
    SUBCASE("Make size smaller")
    {
        integer_grid.resize(5, 1);
        CHECK(integer_grid.get_size() == 5);
    }

    
}