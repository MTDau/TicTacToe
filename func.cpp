#include "func.h"

void print_board(std::vector<std::vector<int>> &board)
{
    for (auto &row : board)
    {
        for (int &x : row)
        {
            std::cout << "| ";
            if (x == 0)
                std::cout << " ";
            else if (x == 1)
                std::cout << "X";
            else
                std::cout << "O";
            std::cout << " ";
        }
        std::cout << '|' << std::endl;
        for (int i{}; i < 13; i++)
            std::cout << "-";
        std::cout << std::endl;
    }
}

bool put_down(std::vector<std::vector<int>> &board, int row, int col, int p)
{
    if (board[row][col] != 0)
    {
        std::cout << "This slot is not empty\n";
        return false;
    }
    board[row][col] = p;
    return true;
}

bool check_win(std::vector<std::vector<int>> &board, int &winner)
{
    // Check row
    for (int i = 0; i < SIZE; i++)
    {
        auto x = board[i][0];
        if (x == 0)
            continue;
        winner = x;
        bool win{true};
        for (auto y : board[i])
        {
            if (x != y)
            {
                win = false;
                break;
            }
        }
        if (win)
            return true;
    }
    // Check collum
    for (int i = 0; i < SIZE; i++)
    {
        auto x = board[0][i];
        if (x == 0)
            continue;
        winner = x;
        bool win{true};
        for (int j = 0; j < SIZE; j++)
        {
            int y = board[j][i];
            if (x != y)
            {
                win = false;
                break;
            }
        }
        if (win)
            return true;
    }
    // Check middle
    if (board[0][0] != 0)
    {
        auto x = board[0][0];
        winner = x;
        bool win{true};
        for (int i{}, j{}; i < SIZE && j < SIZE; i++, j++)
        {
            if (x != board[i][j])
            {
                win = false;
                break;
            }
        }
        if (win)
            return true;
    }
    if (board[0][SIZE - 1] != 0)
    {
        auto x = board[0][SIZE - 1];
        winner = x;
        bool win{true};
        for (int i{}, j{SIZE - 1}; i < SIZE && j >= 0; i++, j--)
        {
            if (x != board[i][j])
            {
                win = false;
                break;
            }
        }
        if (win)
            return true;
    }

    return false;
}