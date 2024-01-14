#ifndef AI_H
#define AI_H

#include "game.h"

#include <climits>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>

using GameBoard = std::vector<std::vector<char>>;

int minimax(GameBoard game_board, int depth, bool player_1);

std::vector<std::pair<int, int>> possible_moves(const GameBoard& game_board);

std::pair<int, int> find_best_move(const GameBoard& game_board);

int minimax(GameBoard game_board, int depth, bool player_1);


#endif