#include<iostream>
using namespace std;

// UNIQUE PATHS (LEETCODE 62)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. Use memoization to calculate the number of unique paths from (0,0) to (m-1,n-1) in a grid.
// 2. Base Case: Return 1 if the cell is (0,0), as there is only one way to reach the starting point.
// 3. Boundary Condition: Return 0 if indices go out of bounds (i < 0 or j < 0).
// 4. Recurrence Relation: The number of paths to reach (i,j) is the sum of paths coming from the top cell (i-1,j) and the left cell (i,j-1).
// 5. Use a 2D `dp` array to store results of subproblems and avoid redundant calculations.

int solveUsingMem(int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = solveUsingMem(i - 1, j, dp);
    int left = solveUsingMem(i, j - 1, dp);
    return dp[i][j] = up + left;
}
int uniquePaths(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solveUsingMem(m - 1, n - 1, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(M*N), SC=O(M*N)
// Steps:
// 1. Use tabulation to calculate the number of unique paths in a grid of size m x n.
// 2. Initialize a 2D dp array, where dp[i][j] represents the number of ways to reach cell (i,j).
// 3. Base Case: dp[0][0] = 1, as there is only one way to start at the top-left corner.
// 4. Transition Relation: For each cell (i,j), calculate the sum of paths coming from the top cell (i-1,j) and the left cell (i,j-1), if valid.
// 5. Iterate through the entire grid and fill the dp table row by row.
// 6. Return dp[m-1][n-1] as the result, which represents the number of unique paths to the bottom-right corner.

int solveUsingTab(int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[0][0] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                {
                    up = dp[i - 1][j];
                }
                if (j > 0)
                {
                    left = dp[i][j - 1];
                }
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}
int uniquePaths(int m, int n)
{
    return solveUsingTab(m, n);
}

// SPACE OPTIMIZATION APPROACH - TC=O(M*N), SC=O(N)
// Steps:
// 1. Use space optimization to calculate the number of unique paths in a grid of size m x n.
// 2. Instead of a 2D dp array, use two 1D arrays (`prev` for the previous row and `curr` for the current row).
// 3. Base Case: curr[0] = 1 for the starting cell (0,0).
// 4. Transition Relation: For each cell in the current row, calculate the sum of paths coming from the cell above (prev[j]) and the cell to the left (curr[j-1]).
// 5. After processing each row, update `prev` to be equal to `curr`.
// 6. Return `prev[n-1]` as the result, representing the number of unique paths to the bottom-right corner.

int solveUsingSO(int m, int n)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                curr[0] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                {
                    up = prev[j];
                }
                if (j > 0)
                {
                    left = curr[j - 1];
                }
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}
int uniquePaths(int m, int n)
{
    return solveUsingSO(m, n);
}

// UNIQUE PATHS II (LEETCODE 63)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(M*N), SC=O(M*N)
int solveUsingMem(vector<vector<int>> &obstacleGrid, int i, int j, vector<vector<int>> &dp)
{
    if (i >= 0 && j >= 0 && obstacleGrid[i][j] == 1)
        return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = solveUsingMem(obstacleGrid, i - 1, j, dp);
    int left = solveUsingMem(obstacleGrid, i, j - 1, dp);
    return dp[i][j] = up + left;
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solveUsingMem(obstacleGrid, m - 1, n - 1, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(M*N), SC=O(M*N)
int solveUsingTab(vector<vector<int>> &obstacleGrid, int m, int n)
{
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
                dp[i][j] = 0;
            else if (i == 0 && j == 0)
                dp[0][0] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                {
                    up = dp[i - 1][j];
                }
                if (j > 0)
                {
                    left = dp[i][j - 1];
                }
                dp[i][j] = up + left;
            }
        }
    }
    return dp[m - 1][n - 1];
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    return solveUsingTab(obstacleGrid, m, n);
}

// SPACE OPTIMIZATION APPROACH - TC=O(M*N), SC=O(N)
int solveUsingSO(vector<vector<int>> &obstacleGrid, int m, int n)
{
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (obstacleGrid[i][j] == 1)
                curr[j] = 0;
            else if (i == 0 && j == 0)
                curr[0] = 1;
            else
            {
                int up = 0, left = 0;
                if (i > 0)
                {
                    up = prev[j];
                }
                if (j > 0)
                {
                    left = curr[j - 1];
                }
                curr[j] = up + left;
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}
int uniquePathsWithObstacles(vector<vector<int>> &obstacleGrid)
{
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    return solveUsingSO(obstacleGrid, m, n);
}