#include<iostream>
using namespace std;

// SUDOKU SOLVER (LEETCODE 37)
// USING RECURSION AND BACKTRACKING - TC=O(9^(N^2)), SC=O(N^2)

// Steps:
// - Iterate over each cell in the board to find an empty cell ('.').
// - For each empty cell, try placing digits from '1' to '9' in the cell.
// - Use the `isSafe` function to check if placing a digit is valid.
// - Recursively attempt to solve the board with the new digit.
// - If placing a digit leads to a solution, return `true`.
// - If no solution is found, backtrack by resetting the cell and trying the next digit.
// - If all cells are filled correctly, return `true` to indicate a solution has been found.
// Returns `true` if the board is solved, otherwise `false`.

bool isSafe(int row, int col, char ch, vector<vector<char>> &board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        if (board[row][i] == ch)
        {
            return false;
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (board[j][col] == ch)
        {
            return false;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (board[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == ch)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>> &board)
{
    int n = board.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == '.')
            {
                for (int ch = '1'; ch <= '9'; ch++)
                {
                    if (isSafe(i, j, ch, board))
                    {
                        board[i][j] = ch;
                        bool recursionAns = solve(board);
                        if (recursionAns == true)
                        {
                            return true;
                        }
                        else
                        {
                            board[i][j] = '.';
                        }
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}