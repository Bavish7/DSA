#include<iostream>
using namespace std;

// WORD SEARCH (LEETCODE 79)
// USING RECURSION AND BACKTRACKING - TC=O(M*N*4^L), SC=O(L)

// Steps:
// 1. Use a recursive function `solve` to find the word in the board starting from the current cell.
//    - Base Case: If the index reaches the end of the word, return true.
//    - For each valid neighbor cell, check if the character matches the current character of the word.
//    - Mark the current cell as visited (to avoid revisiting) and recursively call `solve` for the next character.
//    - Backtrack by unmarking the current cell after recursion.
// 2. Iterate through each cell of the board and check if the first character of the word matches.
//    - If the first character matches, call the `solve` function to find the word starting from that cell.
// 3. Return true if the word is found, else return false.

bool solve(vector<vector<char>> &board, string word, int i, int j, int index)
{
    if (index == word.size())
    {
        return true;
    }
    int delRow[4] = {-1, 0, 1, 0};
    int delCol[4] = {0, 1, 0, -1};
    bool ans = false;
    for (int x = 0; x < 4; x++)
    {
        int newI = i + delRow[x];
        int newJ = j + delCol[x];
        if (newI >= 0 && newI < board.size() && newJ >= 0 && newJ < board[0].size() && board[newI][newJ] == word[index] && board[newI][newJ] != '-1')
        {
            char ch = board[i][j];
            board[i][j] = '-1';
            ans = ans || solve(board, word, newI, newJ, index + 1);
            board[i][j] = ch;
        }
    }
    return ans;
}
bool exist(vector<vector<char>> &board, string word)
{
    int m = board.size();
    int n = board[0].size();
    bool ans = false;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (board[i][j] == word[0])
            {
                ans = ans || solve(board, word, i, j, 1);
            }
        }
    }
    return ans;
}