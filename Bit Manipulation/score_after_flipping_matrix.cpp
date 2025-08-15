#include<iostream>
using namespace std;

// SCORE AFTER FLIPPING MATRIX (LEETCODE 861)
// USING GREEDY APPROCH AND BIT MANIPULATION - TC=O(M*N), SC=O(1)

// Steps:
// 1. For each row, ensure the first column bit is 1 by flipping the row if `grid[i][0] == 0`.
// 2. For each column (starting from j=1), count zeros and ones.
//    - If zeros > ones, flip the column to maximize 1s in that position.
// 3. After adjustments, interpret each row as a binary number and sum their values to get the score.
// 4. Return the total score.

int matrixScore(vector<vector<int>> &grid)
{
    int m = grid.size(), n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        if (grid[i][0] == 0)
        {
            for (int j = 0; j < n; j++)
            {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }
    for (int j = 1; j < n; j++)
    {
        int countZero = 0;
        for (int i = 0; i < m; i++)
        {
            if (grid[i][j] == 0)
                countZero++;
        }
        int countOne = m - countZero;
        if (countZero > countOne)
        {
            for (int i = 0; i < m; i++)
            {
                grid[i][j] = 1 - grid[i][j];
            }
        }
    }
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int value = grid[i][j] * pow(2, n - j - 1);
            ans += value;
        }
    }
    return ans;
}