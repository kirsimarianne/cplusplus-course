#include "../includes/game.h"
#include "../includes/ai.h"

#include <climits>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>

using GameBoard = std::vector<std::vector<char>>;

void clear_cin()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int get_input()
{
    while (true)
    {
        int cmd{};
        std::cin >> cmd;
        if (!std::cin)
        {
            std::cout << "Invalid input\n";
            clear_cin();
            continue;
        }
        return cmd;
    }
}


int main()
{
    bool ai_minimax{true};
    system("clear");
    while (true)
    {
        std::cout << "1) Multiplayer \n2) Play against professonal tic tac toe \n3) quit\n";
        int cmd{get_input()};

        if (cmd == 1)
        {
            ai_minimax = false;
        }
        else if (cmd == 2)
        {
            ai_minimax = true;
        }
        else if (cmd == 3)
        {
            return 0;
        }
        else
        {
            continue;
        }
        game_loop(ai_minimax);
    }

    return 0;
}

