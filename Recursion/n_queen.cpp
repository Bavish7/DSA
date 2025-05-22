#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// N-QUEEN PROBLEM (LEETCODE 51)
// USING RECURSION AND BACKTRACKING - TC=O(N!), SC=O(N^2)

// Steps:
// 1. Base Case: If all columns are processed, store the solution.
// 2. Try placing a queen in every row of the current column if it's safe.
// 3. Mark the row and diagonals as occupied and make a recursive call for the next column.
// 4. Remove the queen and mark the row and diagonals as unoccupied.

unordered_map<int, bool> rowCheck;
unordered_map<int, bool> topDiagonal;
unordered_map<int, bool> bottomDiagonal;
bool isSafe(int row, int col, vector<vector<char>> &board)
{
    if (rowCheck[row] == true)
    {
        return false;
    }
    if (topDiagonal[col - row] == true)
    {
        return false;
    }
    if (bottomDiagonal[col + row] == true)
    {
        return false;
    }
    return true;
}
void storeSolution(vector<vector<char>> &board, vector<vector<string>> &ans)
{
    vector<string> tempSol;
    for (auto vec : board)
    {
        string temp = "";
        for (auto ch : vec)
        {
            temp.push_back(ch);
        }
        tempSol.push_back(temp);
    }
    ans.push_back(tempSol);
}
void solve(vector<vector<char>> &board, vector<vector<string>> &ans, int n, int col)
{
    if (col >= n)
    {
        storeSolution(board, ans);
        return;
    }
    for (int row = 0; row < n; row++)
    {
        if (isSafe(row, col, board))
        {
            board[row][col] = 'Q';
            rowCheck[row] = true;
            topDiagonal[col - row] = true;
            bottomDiagonal[col + row] = true;
            solve(board, ans, n, col + 1);
            board[row][col] = '.';
            rowCheck[row] = 0;
            topDiagonal[col - row] = 0;
            bottomDiagonal[col + row] = 0;
        }
    }
}
vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    vector<vector<char>> board(n, vector<char>(n, '.'));
    int col = 0;
    solve(board, ans, n, col);
    return ans;
}