#include<iostream>
using namespace std;

// CHOCOLATE PICKUP
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(R*C*C), SC=O(R*C*C)

// Steps:
// 1. Handle base cases: out-of-bound moves return -1e9, last row returns chocolates for both players.  
// 2. Recursively explore all possible moves for both players using nested loops.  
// 3. Compute current chocolates based on whether players land on the same cell or different cells.  
// 4. Add maximum chocolates from next states and store results in the dp table.  
// 5. Return the maximum chocolates starting from the first row for both players.

int solveUsingMem(int i, int j1, int j2, vector<vector<int>> &grid, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= grid[0].size() || j2 < 0 || j2 >= grid[0].size())
        return -1e9;
    if (i == grid.size() - 1)
    {
        if (j1 == j2)
            return grid[i][j1];
        else
            return grid[i][j1] + grid[i][j2];
    }
    if (dp[i][j1][j2] != -1)
        return dp[i][j1][j2];
    int maxi = -1e9;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {
            int value = 0;
            if (j1 == j2)
            {
                value = grid[i][j1];
            }
            else
            {
                value = grid[i][j1] + grid[i][j2];
            }
            value += solveUsingMem(i + 1, j1 + dj1, j2 + dj2, grid, dp);
            maxi = max(maxi, value);
        }
    }
    return dp[i][j1][j2] = maxi;
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1)));
    return solveUsingMem(0, 0, c - 1, grid, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(R*C*C), SC=O(R*C*C)
// Steps:
// 1. Initialize a 3D dp table with dimensions[r][c][c] to store maximum chocolates collected.2. Traverse the grid in reverse row order.3. For the last row, if both players are on the same cell, add only that cell’s value; otherwise, add the values of both players’ cells.  
// 4. For earlier rows, recursively calculate the maximum chocolates by considering all possible moves for both players in all 9 directions.  
// 5. If the players move out of bounds, assign a negative value.  
// 6. Store the maximum chocolates in the dp table for each state.  
// 7. The answer is stored at dp[0][0][c-1], representing the starting positions of both players at the first row.

int solveUsingTab(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(c, vector<int>(c, -1e9)));
    for (int i = r - 1; i >= 0; i--)
    {
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                if (i == r - 1)
                {
                    if (j1 == j2)
                        dp[i][j1][j2] = grid[i][j1];
                    else
                        dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
                }
                else
                {
                    int maxi = -1e9;
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            int value = 0;
                            if (j1 == j2)
                            {
                                value = grid[i][j1];
                            }
                            else
                            {
                                value = grid[i][j1] + grid[i][j2];
                            }
                            if (j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 >= 0 && j2 + dj2 < c)
                            {
                                value += dp[i + 1][j1 + dj1][j2 + dj2];
                            }
                            else
                            {
                                value += -1e9;
                            }
                            maxi = max(maxi, value);
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
    }
    return dp[0][0][c - 1];
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    return solveUsingTab(r, c, grid);
}

// SPACE OPTIMIZATION APPROACH - TC=O(R*C*C), SC=O(R*C)
// Steps:
// 1. Initialize a 2D table 'front' for storing the maximum chocolates for the current row.  
// 2. Traverse the grid in reverse row order, starting from the last row.  
// 3. For the last row, if both players are on the same cell, add only that cell’s value; otherwise, add the values of both players’ cells.  
// 4. For earlier rows, recursively calculate the maximum chocolates by considering all possible moves for both players in all 9 directions.  
// 5. If the players move out of bounds, assign a negative value.  
// 6. Store the maximum chocolates in the 'curr' table for each state, which represents the current row.  
// 7. After processing a row, update 'front' to hold the current row's results, then move to the previous row.  
// 8. The final result is stored in front[0][c-1], representing the starting positions of both players at the first row.

int solveUsingSO(int r, int c, vector<vector<int>> &grid)
{
    vector<vector<int>> front(c, vector<int>(c, -1e9));
    for (int i = r - 1; i >= 0; i--)
    {
        vector<vector<int>> curr(c, vector<int>(c, -1e9));
        for (int j1 = 0; j1 < c; j1++)
        {
            for (int j2 = 0; j2 < c; j2++)
            {
                if (i == r - 1)
                {
                    if (j1 == j2)
                        curr[j1][j2] = grid[i][j1];
                    else
                        curr[j1][j2] = grid[i][j1] + grid[i][j2];
                }
                else
                {
                    int maxi = -1e9;
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            int value = 0;
                            if (j1 == j2)
                            {
                                value = grid[i][j1];
                            }
                            else
                            {
                                value = grid[i][j1] + grid[i][j2];
                            }
                            if (j1 + dj1 >= 0 && j1 + dj1 < c && j2 + dj2 >= 0 && j2 + dj2 < c)
                            {
                                value += front[j1 + dj1][j2 + dj2];
                            }
                            else
                            {
                                value += -1e9;
                            }
                            maxi = max(maxi, value);
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
        }
        front = curr;
    }
    return front[0][c - 1];
}
int maximumChocolates(int r, int c, vector<vector<int>> &grid)
{
    return solveUsingSO(r, c, grid);
}