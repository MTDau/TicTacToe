#include "play.h"

bool finish(std::vector<std::vector<int>> &board, int &winner)
{
    if (check_win(board, winner))
        return true;
    winner = 0;
    for (auto row : board)
    {
        for (auto x : row)
        {
            if (x == 0)
                return false;
        }
    }
    return true;
}

void print_result(int winner)
{
    if (winner != 0)
    {
        if (winner == 1)
            std::cout << "X";
        else
            std::cout << "O";
        std::cout << " win";
    }
    else
        std::cout << "Draw\n";
}

void play()
{
    {
        std::cout << "Welcome to Minh's tic tac toe \n";
        std::vector<std::vector<int>> board(SIZE, std::vector<int>(SIZE, 0));
        int winner{0};
        int turn{}, player{};
        while (!finish(board, winner))
        {
            int row{-1}, col{-1};
            while (true)
            {
                if (turn % 2 == 0)
                {
                    std::cout << "Now X player turn.\n";
                    player = 1;
                }
                else
                {
                    std::cout << "Now O player turn.\n";
                    player = 2;
                }
                std::cout << "Please enter your location in row and collum separate by space (between 0 - 2): ";
                std::cin >> row >> col;
                std::cin.clear();
                std::cin.ignore(INT_MAX, '\n');
                if (row < 0 || row > 2 || col < 0 || col > 2)
                {
                    std::cout << "Invalid input.\n";
                    print_board(board);
                }
                else
                    break;
            }
            if (!put_down(board, row, col, player))
            {
                print_board(board);
                continue;
            }
            print_board(board);
            turn++;
        }
        print_result(winner);
    }
}