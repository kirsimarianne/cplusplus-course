#ifndef GAME_H
#define GAME_H

#include "ai.h"

#include <climits>
#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>

#define SIZE 3
#define EMPTY ' '
#define PLAYER_1 'X'
#define PLAYER_2 'O'

using GameBoard = std::vector<std::vector<char>>;

void fill_board(GameBoard &game_board);

void print_board(const GameBoard &game_board);

int parse_string(std::pair<int, int> &position, std::string str);

std::pair<int, int> get_position(const GameBoard &game_board);

void update_board(GameBoard &game_board, const std::pair<int, int> &position,
                  const bool &player_1);

int check_board(const GameBoard& game_board);

void change_turn(bool &player_1); 

bool is_board_full(const GameBoard &game_board);

void game_loop(bool ai_minimax);

#endif