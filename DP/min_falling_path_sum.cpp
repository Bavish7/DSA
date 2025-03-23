#include<iostream>
using namespace std;

// MINIMUM FALLING PATH SUM (LEETCODE 931)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. Recursive function with memoization to minimize overlapping subproblems.
// 2. Base case: Return `matrix[i][j]` when reaching the last row.
// 3. Explore all possible paths (down, left diagonal, right diagonal) recursively:
//    - Down: move to row `i + 1`, column `j`
//    - Left diagonal: move to row `i + 1`, column `j - 1` if within bounds
//    - Right diagonal: move to row `i + 1`, column `j + 1` if within bounds
// 4. Store and return the minimum of these path sums in the `dp` table.
// 5. Iterate over all possible starting points in the first row and compute the global minimum.
// 6. Return the smallest falling path sum.

int solveUsingMem(int i, int j, vector<vector<int>> &matrix, vector<vector<int>> &dp)
{
    if (i == matrix.size() - 1)
        return matrix[i][j];
    if (dp[i][j] != 1e9)
        return dp[i][j];
    int down = matrix[i][j] + solveUsingMem(i + 1, j, matrix, dp);
    int left = 1e9;
    if (j > 0)
    {
        left = matrix[i][j] + solveUsingMem(i + 1, j - 1, matrix, dp);
    }
    int right = 1e9;
    if (j < matrix.size() - 1)
    {
        right = matrix[i][j] + solveUsingMem(i + 1, j + 1, matrix, dp);
    }
    return dp[i][j] = min(down, min(left, right));
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        int ans = solveUsingMem(0, i, matrix, dp);
        mini = min(mini, ans);
    }
    return mini;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(M*N), SC=O(M*N)
// Steps:
// 1. Use a bottom-up tabulation approach to compute the minimum falling path sum.
// 2. Initialize the `dp` table such that the last row is filled directly from the matrix.
// 3. Iterate from the second last row upwards to the first row.
// 4. For each element, compute the sum of the current value with possible paths:
//    - Down: move to the row below in the same column
//    - Left diagonal: move to the row below, left column if within bounds
//    - Right diagonal: move to the row below, right column if within bounds
// 5. Store the minimum of these sums in the `dp` table.
// 6. Find the smallest falling path sum by checking all values in `dp[0]`.
// 7. Return the result.

int solveUsingTab(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, 1e9));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == n - 1)
                dp[i][j] = matrix[i][j];
            else
            {
                int down = matrix[i][j] + dp[i + 1][j];
                int left = 1e9;
                if (j > 0)
                {
                    left = matrix[i][j] + dp[i + 1][j - 1];
                }
                int right = 1e9;
                if (j < n - 1)
                {
                    right = matrix[i][j] + dp[i + 1][j + 1];
                }
                dp[i][j] = min(down, min(left, right));
            }
        }
    }
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, dp[0][i]);
    }
    return mini;
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    return solveUsingTab(matrix);
}

// SPACE OPTIMIZATION APPROACH - TC=O(M*N), SC=O(N)
// Steps:
// 1. Use space optimization by reducing the 2D DP table to two 1D vectors: `curr` and `next`.
// 2. `next` stores results for the row below the current row, and `curr` is used for computation.
// 3. Start from the last row of the matrix and move upwards.
// 4. For each cell, compute the minimum sum from possible paths (down, left, right).
// 5. Update `curr[j]` with the minimum value and set `next` to `curr` after completing each row.
// 6. Return the smallest value in `next` after processing all rows.

int solveUsingSO(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    vector<int> next(n, 1e9);
    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> curr(n, 1e9);
        for (int j = n - 1; j >= 0; j--)
        {
            if (i == n - 1)
                curr[j] = matrix[i][j];
            else
            {
                int down = matrix[i][j] + next[j];
                int left = 1e9;
                if (j > 0)
                {
                    left = matrix[i][j] + next[j - 1];
                }
                int right = 1e9;
                if (j < n - 1)
                {
                    right = matrix[i][j] + next[j + 1];
                }
                curr[j] = min(down, min(left, right));
            }
        }
        next = curr;
    }
    int mini = INT_MAX;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, next[i]);
    }
    return mini;
}
int minFallingPathSum(vector<vector<int>> &matrix)
{
    return solveUsingSO(matrix);
}