#include<iostream>
using namespace std;

// COUNT SQUARE SUBMATRICES WITH ALL ONES (LEETCODE 1277)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. Define `solveUsingMem()` to recursively find the size of the largest square sub-matrix ending at each cell.
// 2. Base case: If the indices `i` or `j` exceed matrix bounds, return 0.
// 3. Use memoization with `dp[i][j]` to store the solution for each subproblem.
// 4. Compute results for the right, diagonal, and down directions recursively.
// 5. If the current cell contains `1`, calculate the side length of the largest square ending at `(i, j)` as `1 + min(right, diagonal, down)`.
// 6. Update the `count` of squares by adding the value of `dp[i][j]`.
// 7. Return `count` after processing the matrix using `solveUsingMem()`.

int solveUsingMem(vector<vector<int>> &matrix, int i, int j, int &count, int &m, int &n, vector<vector<int>> &dp)
{
    if (i >= m || j >= n)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int right = solveUsingMem(matrix, i, j + 1, count, m, n, dp);
    int diagonal = solveUsingMem(matrix, i + 1, j + 1, count, m, n, dp);
    int down = solveUsingMem(matrix, i + 1, j, count, m, n, dp);
    if (matrix[i][j] == 1)
    {
        dp[i][j] = 1 + min(right, min(diagonal, down));
        count += dp[i][j];
        return dp[i][j];
    }
    else
    {
        return dp[i][j] = 0;
    }
}
int countSquares(vector<vector<int>> &matrix)
{
    int count = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    solveUsingMem(matrix, 0, 0, count, m, n, dp);
    return count;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*M), SC=O(N*M)
// Steps:
// 1. Initialize the `dp` table to store the size of the largest square ending at each position.
// 2. Copy the first row and the first column from `matrix` to `dp` since these directly represent possible 1x1 squares.
// 3. Traverse the matrix starting from position `(1, 1)`.
// 4. If the current cell `matrix[i][j] == 1`, compute `dp[i][j]` as `1 + min(dp[i-1][j], dp[i-1][j-1], dp[i][j-1])`.
// 5. Accumulate the count of squares by adding the values in `dp`.
// 6. Return the total sum of square counts.

int countSquares(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = matrix[i][0];
    }
    for (int j = 0; j < m; j++)
    {
        dp[0][j] = matrix[0][j];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 1; j < m; j++)
        {
            if (matrix[i][j] == 1)
            {
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
            }
        }
    }
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            sum += dp[i][j];
        }
    }
    return sum;
}
