#include "../includes/ai.h"
#include "../includes/game.h"

#include <climits>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>


/* Function checks all possible moves
 */
std::vector<std::pair<int, int>> possible_moves(const GameBoard &game_board)
{
    std::vector<std::pair<int, int>> moves{};
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (game_board.at(i).at(j) == EMPTY)
            {
                moves.push_back(std::make_pair(i, j));
            }
        }
    }
    return moves;
}

std::pair<int, int> find_best_move(const GameBoard& game_board)
{
    std::pair<int, int> best_move{};
    int best_eval = INT_MIN;
    for (int i = 0; i < SIZE; ++i)
    {
        for (int j = 0; j < SIZE; ++j)
        {
            if (game_board[i][j] == EMPTY)
            {
                GameBoard temp_board = game_board;
                temp_board[i][j] = PLAYER_1;

                int eval = minimax(temp_board, 0, false);
                
                if (eval > best_eval)
                {
                    best_eval = eval;
                    best_move = std::make_pair(i, j);
                }
            }
        }
    }
    return best_move;
}

int minimax(GameBoard game_board, int depth, bool player_1)
{
    int score = check_board(game_board);

    if (score == 1)
        return score - depth;
    else if (score == -1)
        return score + depth;
    else if (score == 0)
        return score;

    if (player_1)
    {
        int highest_score = INT_MIN;
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                if (game_board[i][j] == EMPTY)
                {
                    game_board[i][j] = PLAYER_1;
                    int current_score = minimax(game_board, depth + 1, false);
                    highest_score = std::max(highest_score, current_score);
                    game_board[i][j] = EMPTY;
                }
            }
        }
        return highest_score;
    }
    else
    {
        int highest_score = INT_MAX;
        for (int i = 0; i < SIZE; ++i)
        {
            for (int j = 0; j < SIZE; ++j)
            {
                if (game_board[i][j] == EMPTY)
                {
                    game_board[i][j] = PLAYER_2;
                    int current_score = minimax(game_board, depth + 1, true);
                    highest_score= std::min(highest_score, current_score);
                    game_board[i][j] = EMPTY;
                }
            }
        }
        return highest_score;
    }
}
