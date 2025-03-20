#include<iostream>
using namespace std;

// MAXIMAL SQUARE (LEETCODE 221)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. Define `solveUsingMem` function to recursively find the size of the largest square containing only '1's in the matrix using memoization.
// 2. Base case: If the current indices `i` or `j` go out of bounds (i.e., beyond the matrix dimensions `m` or `n`), return 0 because no square can exist outside the matrix.
// 3. Check if the result for the current cell `(i, j)` is already computed (stored in `dp`). If yes, return the stored value to avoid recalculations.
// 4. Recursively calculate the possible sizes of the square by checking the right (`i, j + 1`), diagonal (`i + 1, j + 1`), and down (`i + 1, j`) directions.
// 5. If the current cell contains '1', compute the size of the square by taking the minimum value among the right, diagonal, and down directions, then add 1 to include the current cell itself.
// 6. Update `maxi` to keep track of the maximum square size found so far.
// 7. If the current cell contains '0', return 0 as no square can be formed with a '0'.
// 8. Store the result for the current cell in `dp[i][j]`.
// 9. In `maximalSquare` function, initialize a `dp` array to store the results for subproblems.
// 10. Call `solveUsingMem` starting from the top-left corner (0, 0) and calculate the maximum square size.
// 11. Return the area of the largest square found by squaring the size (i.e., `maxSquares * maxSquares`).

int solveUsingMem(vector<vector<char>> &matrix, int i, int j, int &maxi, int &m, int &n, vector<vector<int>> &dp)
{
    if (i >= m || j >= n)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int right = solveUsingMem(matrix, i, j + 1, maxi, m, n, dp);
    int diagonal = solveUsingMem(matrix, i + 1, j + 1, maxi, m, n, dp);
    int down = solveUsingMem(matrix, i + 1, j, maxi, m, n, dp);
    if (matrix[i][j] == '1')
    {
        dp[i][j] = 1 + min(right, min(diagonal, down));
        maxi = max(dp[i][j], maxi);
        return dp[i][j];
    }
    else
    {
        return dp[i][j] = 0;
    }
}
int maximalSquare(vector<vector<char>> &matrix)
{
    int maxSquares = 0;
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    solveUsingMem(matrix, 0, 0, maxSquares, m, n, dp);
    return maxSquares * maxSquares;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N), SC=O(N)
// Steps:
// 1. Define the `solveUsingTab` function to use tabulation (bottom-up dynamic programming) to find the size of the largest square containing only '1's in the matrix.
// 2. Initialize a `dp` matrix of size `(m+1) x (n+1)` with all elements set to 0. The extra row and column are used to handle boundary cases easily.
// 3. Loop through the matrix from bottom-right to top-left (starting from `m-1` and `n-1`), checking each cell of the matrix.
// 4. For each cell, check its right (`i, j + 1`), down (`i + 1, j`), and diagonal (`i + 1, j + 1`) neighbors in the `dp` table.
// 5. If the current cell in the matrix contains '1', compute the size of the square by taking the minimum of the three neighbors and adding 1 (to include the current cell itself).
// 6. Update `maxi` to store the maximum size of any square found so far.
// 7. If the current cell contains '0', set `dp[i][j]` to 0 because no square can be formed with a '0'.
// 8. Return `maxi * maxi` (area of the largest square) after the loop completes.
// 9. In the `maximalSquare` function, call `solveUsingTab` and return the result as the maximum square area.

int solveUsingTab(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int maxi = 0;
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int right = dp[i][j + 1];
            int down = dp[i + 1][j];
            int diagonal = dp[i + 1][j + 1];
            if (matrix[i][j] == '1')
            {
                dp[i][j] = 1 + min(right, min(down, diagonal));
                maxi = max(dp[i][j], maxi);
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return maxi * maxi;
}
int maximalSquare(vector<vector<char>> &matrix)
{
    int ans = solveUsingTab(matrix);
    return ans;
}

// SPACE OPTIMIZATION APPROACH - TC=O(M*N), SC=O(N)
// Steps:
// 1. Define the `solveUsingSO` function to optimize space using only two 1D arrays, `curr` and `next`, instead of a 2D dp matrix.
// 2. Initialize `curr` and `next` arrays of size `n+1` (extra element for boundary handling) to 0. These arrays will store the intermediate results for each row.
// 3. Loop through the matrix from bottom-right to top-left (starting from `m-1` and `n-1`), checking each cell.
// 4. For each cell, calculate its right (`curr[j+1]`), down (`next[j]`), and diagonal (`next[j+1]`) neighbors from the arrays.
// 5. If the current cell contains '1', compute the size of the square by taking the minimum of the right, down, and diagonal neighbors and adding 1.
// 6. Update `maxi` to store the largest square size found so far.
// 7. If the current cell contains '0', set `curr[j]` to 0, as no square can be formed.
// 8. After processing each row, assign `curr` to `next` for the next iteration (moving to the previous row).
// 9. Return `maxi * maxi` (area of the largest square) after the loop completes.
// 10. In the `maximalSquare` function, call `solveUsingSO` and return the result as the maximum square area.

int solveUsingSO(vector<vector<char>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    int maxi = 0;
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int right = curr[j + 1];
            int down = next[j];
            int diagonal = next[j + 1];
            if (matrix[i][j] == '1')
            {
                curr[j] = 1 + min(right, min(down, diagonal));
                maxi = max(curr[j], maxi);
            }
            else
            {
                curr[j] = 0;
            }
        }
        next = curr;
    }
    return maxi * maxi;
}
int maximalSquare(vector<vector<char>> &matrix)
{
    int ans = solveUsingSO(matrix);
    return ans;
}