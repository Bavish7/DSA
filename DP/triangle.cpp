#include<iostream>
using namespace std;

// TRIANGLE (LEETCODE 120)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(N^2)

// Steps:
// 1. Use memoization to optimize the recursive solution by storing intermediate results in `dp`.
// 2. Base Case: When reaching the last row of the triangle, return the triangle value as no further steps are possible.
// 3. For each cell (i, j):
//    - Calculate the sum of the current triangle value and the minimum of:
//        a) Down path (moving to the same column in the next row)
//        b) Diagonal path (moving to the next column in the next row)
// 4. Store the computed result in `dp[i][j]` to avoid redundant calculations.
// 5. Return the minimum path sum from the top to the bottom of the triangle.

int solveUsingMem(int i, int j, vector<vector<int>> &triangle, vector<vector<int>> &dp)
{
    if (i == triangle.size() - 1)
        return triangle[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = triangle[i][j] + solveUsingMem(i + 1, j, triangle, dp);
    int diagonal = triangle[i][j] + solveUsingMem(i + 1, j + 1, triangle, dp);
    return dp[i][j] = min(down, diagonal);
}
int minimumTotal(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solveUsingMem(0, 0, triangle, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^2), SC=O(N^2)
// Steps:
// 1. Use tabulation to iteratively solve the problem from the base to the top.
// 2. Base case: Initialize the last row of `dp` with corresponding values from the triangle since no further paths are possible.
// 3. Traverse from the second-last row to the top of the triangle:
//    - For each cell (i, j), calculate the minimum of:
//        a) Down path: triangle[i][j] + dp[i + 1][j]
//        b) Diagonal path: triangle[i][j] + dp[i + 1][j + 1]
// 4. Store the computed result in `dp[i][j]`.
// 5. Return `dp[0][0]`, representing the minimum path sum from top to bottom.

int solveUsingTab(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j >= 0; j--)
        {
            if (i == n - 1)
                dp[i][j] = triangle[i][j];
            else
            {
                int down = triangle[i][j] + dp[i + 1][j];
                int diagonal = triangle[i][j] + dp[i + 1][j + 1];
                dp[i][j] = min(down, diagonal);
            }
        }
    }
    return dp[0][0];
}
int minimumTotal(vector<vector<int>> &triangle)
{
    return solveUsingTab(triangle);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N^2), SC=O(N)
// Steps:
// 1. Use space optimization by maintaining only two 1D vectors: `curr` and `next`.
// 2. Base case: Initialize the last row of `next` with corresponding triangle values.
// 3. Traverse from the second-last row to the top:
//    - For each cell (i, j), compute the minimum of:
//        a) Down path: triangle[i][j] + curr[j]
//        b) Diagonal path: triangle[i][j] + curr[j + 1]
// 4. Store the result in `next[j]`.
// 5. Update `curr` as the previous row for the next iteration.
// 6. Return `curr[0]`, representing the minimum path sum from top to bottom.

int solveUsingSO(vector<vector<int>> &triangle)
{
    int n = triangle.size();
    vector<int> curr(n, -1);
    for (int i = n - 1; i >= 0; i--)
    {
        vector<int> next(n, -1);
        for (int j = i; j >= 0; j--)
        {
            if (i == n - 1)
                next[j] = triangle[i][j];
            else
            {
                int down = triangle[i][j] + curr[j];
                int diagonal = triangle[i][j] + curr[j + 1];
                next[j] = min(down, diagonal);
            }
        }
        curr = next;
    }
    return curr[0];
}
int minimumTotal(vector<vector<int>> &triangle)
{
    return solveUsingSO(triangle);
}