
#include <climits>
#include <iostream>
#include <limits>
#include <string>
#include <vector>

using GameBoard = std::vector<std::vector<char>>;

#define SIZE 3
#define EMPTY ' '
#define PLAYER_1 'X'
#define PLAYER_2 'O'

/*struct Cell
{
    char empty = ' ';
    char player_1 = 'O';
    char player_2 = 'X';
} cell;

struct Player
{
    bool turn {};
    bool human {};
};*/

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

/* Function checks the position is right formated and empty
 */
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

void update_board(GameBoard &game_board, const std::pair<int, int> &position,
                  const bool &player_1)
{
    std::cout << "Testi: " << position.first << position.second << '\n';
    if (player_1)
    {
        game_board[position.first][position.second] = PLAYER_1;
    }
    else
    {
        game_board[position.first][position.second] = PLAYER_2;
    }
}

void change_turn(bool &player_1) { player_1 = !player_1; }

// check if current player has won the game
bool check_win(const std::vector<std::vector<char>> &game_board, bool player_1)
{
    char player = (player_1) ? PLAYER_1 : PLAYER_2;
    // Check rows and columns
    for (int i = 0; i < SIZE; i++)
    {
        if ((game_board[i][0] == player && game_board[i][1] == player &&
             game_board[i][2] == player) ||
            (game_board[0][i] == player && game_board[1][i] == player &&
             game_board[2][i] == player))
        {
            return true;
        }
    }

    // Check diagonals
    if ((game_board[0][0] == player && game_board[1][1] == player &&
         game_board[2][2] == player) ||
        (game_board[0][2] == player && game_board[1][1] == player &&
         game_board[2][0] == player))
    {
        return true;
    }

    return false;
}

// check if game if over (draw)
bool is_board_full(const std::vector<std::vector<char>> &game_board)
{
    for (int i = 0; i < SIZE; i++)
    {
        for (int j = 0; j < SIZE; j++)
        {
            if (game_board[i][j] == ' ')
                return false;
        }
    }
    return true;
}

/* Function checks all possible moves
 */
std::vector<std::pair<int, int>> possible_moves(const std::vector<std::vector<char>> &game_board)
{
    std::vector<std::pair<int, int>> moves {};
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


std::pair<int, int> find_best_move(const GameBoard& board, std::vector<std::pair<int,int>> legal_moves) {
    std::pair<int,int> best_move {};
    int best_eval = INT_MIN;

        for(auto& move : legal_moves)
        {
            GameBoard temp_board = board;
            update_board(temp_board, move, false);

            int eval = minimax(temp_board, 0, false);
            if (eval > best_eval) {
                best_eval = eval;
                best_move = i;
            }    
        }
    return best_move;
}


int minimax(const std::vector<std::vector<char>> &game_board)
{
    if (check_win(game_board, PLAYER_1))
    {
        return 1;
    }
    else if(check_win(game_board, PLAYER_2))
    {
        return -1;
    }
    else if (is_board_full(game_board))
    {
        return 0; // DRAW
    }

    // if(current_player == 'X')
    // value = INT_MIN
    //  sitten loopataan kaikki mahdolliset siirrot
    //  value = std::max(value, Minimax(Result(game_board, a))); // a:lla tarkoiteen mahdollista laillista siirtoa
    // return value

    // if(current_player == 'O)
    // value = INT_MAX
    // loopataan kaikki mahdolliset siirrot
    // value = std::min(value, Minimax(Result,(game_board,a)))
    // return value
}

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
        if(ai_minimax && !player_1)
        {
            position = find_best_move(game_board, possible_moves(game_board));
        }
        else
        {
            position = get_position(game_board);
        }
        update_board(game_board, position, player_1);
        system("clear");
        print_board(game_board);
        if (check_win(game_board, player_1))
        {
            std::cout << "You win!\n\n";
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

int main()
{
    bool ai_minimax {true};
    system("clear");
    while (true)
    {
        std::cout << "1) Multiplayer \n2) Play against professonal tic tac toe \n3) quit\n";
        int cmd{get_input()};

        if(cmd == 1)
        {
            ai_minimax = false;
        }
        else if(cmd == 3)
        {
            return 0;
        }
        else
        {
            continue;
        }
        game_loop(ai_minimax);
    }    
}