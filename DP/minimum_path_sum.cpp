#include<iostream>
using namespace std;

// MINIMUM PATH SUM (LEETCODE 64)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. Use memoization to find the minimum path sum from the top-left corner to the bottom-right corner of the grid.
// 2. Base Case: At the starting cell (0,0), return its value as there's no other path.
// 3. Recursive Relation: For each cell (i, j), the minimum path sum is the cell's value plus the minimum of:
//    - The path sum from the cell directly above (i-1, j).
//    - The path sum from the cell directly to the left (i, j-1).
// 4. Use a dp array to store intermediate results and avoid recalculating the same state.
// 5. If a cell is out of bounds (i < 0 or j < 0), return a large value (`1e9`) to ensure invalid paths are not chosen.

int solveUsingMem(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return grid[i][j];
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = grid[i][j] + solveUsingMem(grid, i - 1, j, dp);
    int left = grid[i][j] + solveUsingMem(grid, i, j - 1, dp);
    return dp[i][j] = min(up, left);
}
int minPathSum(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return solveUsingMem(grid, m - 1, n - 1, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(M*N), SC=O(M*N)
// Steps:
// 1. Use tabulation to compute the minimum path sum from the top-left corner to the bottom-right corner of the grid.
// 2. Base Case: The top-left cell (0,0) directly holds its grid value as there is no previous path.
// 3. For each cell (i,j):
//    - Add the grid value at (i,j) to the minimum of:
//        a) The value from the cell above (i-1, j), if it exists.
//        b) The value from the cell to the left (i, j-1), if it exists.
//    - If no valid cell exists above or to the left, treat it as an invalid path (assign a large value).
// 4. The final value at dp[m-1][n-1] represents the minimum path sum from start to end.

int solveUsingTab(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                dp[i][j] = grid[i][j];
            else
            {
                int up = grid[i][j];
                if (i > 0)
                    up += dp[i - 1][j];
                else
                    up += 1e9;
                int left = grid[i][j];
                if (j > 0)
                    left += dp[i][j - 1];
                else
                    left += 1e9;
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[m - 1][n - 1];
}
int minPathSum(vector<vector<int>> &grid)
{
    return solveUsingTab(grid);
}

// SPACE OPTIMIZATION APPROACH - TC=O(M*N), SC=O(N)
// Steps:
// 1. Optimize the space complexity by using two 1D arrays: `prev` (for the previous row) and `curr` (for the current row).
// 2. Base Case: For the top-left cell (0,0), its value directly corresponds to the grid value.
// 3. For each cell (i,j):
//    - Add the grid value at (i,j) to the minimum of:
//        a) Value from the cell directly above (using `prev` array).
//        b) Value from the cell to the left (using `curr` array).
//    - If no valid cell exists above or to the left, treat it as an invalid path (assign a large value).
// 4. Update `prev` with the values from `curr` after processing each row.
// 5. The value at `prev[n-1]` (last column of the last row) represents the minimum path sum from start to end.

int solveUsingSO(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<int> prev(n, 0);
    for (int i = 0; i < m; i++)
    {
        vector<int> curr(n, 0);
        for (int j = 0; j < n; j++)
        {
            if (i == 0 && j == 0)
                curr[j] = grid[i][j];
            else
            {
                int up = grid[i][j];
                if (i > 0)
                    up += prev[j];
                else
                    up += 1e9;
                int left = grid[i][j];
                if (j > 0)
                    left += curr[j - 1];
                else
                    left += 1e9;
                curr[j] = min(up, left);
            }
        }
        prev = curr;
    }
    return prev[n - 1];
}
int minPathSum(vector<vector<int>> &grid)
{
    return solveUsingSO(grid);
}