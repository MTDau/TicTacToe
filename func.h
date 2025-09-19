#pragma once
#include "cons.h"

// Print the board out
void print_board(std::vector<std::vector<int>> &board);

// Put the check
bool put_down(std::vector<std::vector<int>> &board, int row, int col, int p);

bool check_win(std::vector<std::vector<int>> &board, int &winner);