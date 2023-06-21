#include "../includes/game.h"
#include "../includes/ai.h"

#include <climits>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>



void fill_board(GameBoard &game_board)
{
    for (int i = 0; i < 3; i++)
    {
        std::vector<char> row;

        for (int j = 0; j < 3; j++)
        {
            row.push_back(EMPTY);
        }
        game_board.push_back(row);
    }
}

void print_board(const GameBoard &game_board)
{
    std::cout << "  A   B   C\n";
    for (int i = 0; i < SIZE; ++i)
    {
        std::cout << i << ' ';
        for (int j = 0; j < SIZE; ++j)
        {
            if (j == 0 || j == 1)
                std::cout << game_board[i][j] << " | ";
            else
                std::cout << game_board[i][j];
        }
        std::cout << '\n';
        if (i == 0 || i == 1)
            std::cout << "  ----------\n";
    }
}

int parse_string(std::pair<int, int> &position, std::string str)
{
    if ((str[1] == '0') || (str[1] == '1') || (str[1] == '2'))
        position.first = str[1] - '0';
    else
        return 1;

    if ((str[0] == 'A') || (str[0] == 'a'))
        position.second = 0;
    else if ((str[0] == 'B') || (str[0] == 'b'))
        position.second = 1;
    else if ((str[0] == 'C') || (str[0] == 'c'))
        position.second = 2;
    else
        return 1;

    return 0;
}


std::pair<int, int> get_position(const GameBoard &game_board)
{
    std::pair<int, int> position;
    while (true)
    {
        std::cout << "Give position row and column: ";
        std::string line{};
        std::getline(std::cin >> std::ws, line);
        int valid_input = parse_string(position, line);
        if (valid_input == 1)
        {
            std::cout << "Invalid input.\n";
            continue;
        }
        else if (game_board[position.first][position.second] != EMPTY)
        {
            std::cout << "Position is not free.";
            continue;
        }
        break;
    }
    return position;
}


/* Function checks the position is right formated and empty
 */


void update_board(GameBoard &game_board, const std::pair<int, int> &position,
                  const bool &player_1)
{
    if (player_1)
    {
        game_board[position.first][position.second] = PLAYER_1;
    }
    else
    {
        game_board[position.first][position.second] = PLAYER_2;
    }
}


// check if current player has won the game
int check_board(const GameBoard& game_board)
{
        // Check rows
    for (int i = 0; i < SIZE; ++i) {
        if (game_board[i][0] == game_board[i][1] && game_board[i][1] == game_board[i][2]) {
            if (game_board[i][0] == PLAYER_1)
                return 1;
            else if (game_board[i][0] == PLAYER_2)
                return -1;
        }
    }

    // Check columns
    for (int j = 0; j < SIZE; ++j) {
        if (game_board[0][j] == game_board[1][j] && game_board[1][j] == game_board[2][j]) {
            if (game_board[0][j] == PLAYER_1)
                return 1;
            else if (game_board[0][j] == PLAYER_2)
                return -1;
        }
    }

    // Check diagonals
    if (game_board[0][0] == game_board[1][1] && game_board[1][1] == game_board[2][2]) {
        if (game_board[0][0] == PLAYER_1)
            return 1;
        else if (game_board[0][0] == PLAYER_2)
            return -1;
    }

    if (game_board[0][2] == game_board[1][1] && game_board[1][1] == game_board[2][0]) {
        if (game_board[0][2] == PLAYER_1)
            return 1;
        else if (game_board[0][2] == PLAYER_2)
            return -1;
    }

    // If no winner, it's a draw
    return 0;
}


void change_turn(bool &player_1) { player_1 = !player_1; }

// check if game if over (draw)
bool is_board_full(const GameBoard &game_board)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (game_board[i][j] == EMPTY)
                return false;
        }
    }
    return true;
}


void game_loop(bool ai_minimax)
{
    GameBoard game_board{};
    std::pair<int, int> position{};
    bool player_1 = true;

    system("clear");

    fill_board(game_board);
    print_board(game_board);

    while (true)
    {
        if (ai_minimax && !player_1)
        {
            position = find_best_move(game_board);
        }
        else
        {
            position = get_position(game_board);
        }
        update_board(game_board, position, player_1);
        system("clear");
        print_board(game_board);
        int winner = check_board(game_board);
        if (winner)
        {
            if(winner == 1)
            {
                std::cout << "Player 1 win!\n\n";
            }
            else{
                std::cout << "Player 2 win!\n\n";
            }
            break;
        }
        if (is_board_full(game_board))
        {
            std::cout << "It's a draw.\n\n";
            break;
        }
        change_turn(player_1);
    }
}