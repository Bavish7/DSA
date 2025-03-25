#include<iostream>
using namespace std;

// MINIMUM SCORE TRIANGULATION OF PLOYGON (LEETCODE 1039)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^3), SC=O(N^2)

// Steps:
// 1. Define the recursive function `solveUsingMem` to calculate the minimum score of triangulating the polygon between indices `i` and `j`.
// 2. Base Case: If only two vertices are left between `i` and `j`, return 0 because no triangle can be formed.
// 3. Memoization: If the result for a pair `(i, j)` is already computed, return the stored result from the `dp` table.
// 4. Initialize `ans` as a large number to store the minimum score for the current range.
// 5. Loop through each possible third vertex `k` between `i` and `j` and compute the triangulation score for the triangle formed by `values[i]`, `values[j]`, and `values[k]`.
// 6. Recursively compute the score for the subproblems of triangulating the polygon from `i` to `k` and from `k` to `j`.
// 7. Update the result `ans` by considering the score of the current triangle and the scores from both subproblems.
// 8. Store the result in the `dp` table for future reference.
// 9. In the `minScoreTriangulation` function, initialize the `dp` table with `-1` to indicate uncomputed results.
// 10. Call `solveUsingMem` for the full range (0 to `n-1`) and return the final result.

int solveUsingMem(vector<int> &values, int i, int j, vector<vector<int>> &dp)
{
    if (i + 1 == j)
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = INT_MAX;
    for (int k = i + 1; k < j; k++)
    {
        ans = min(ans, values[i] * values[j] * values[k] + solveUsingMem(values, i, k, dp) + solveUsingMem(values, k, j, dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}
int minScoreTriangulation(vector<int> &values)
{
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solveUsingMem(values, 0, n - 1, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^3), SC=O(N^2)
// Steps:
// 1. Initialize a 2D `dp` array of size `n x n` where `dp[i][j]` represents the minimum score for triangulating the polygon between indices `i` and `j`.
// 2. Iterate over all possible values of `i` from `n-1` to 0, where `i` represents the starting vertex.
// 3. For each starting vertex `i`, iterate over all possible `j` such that `j > i + 1`, where `j` represents the ending vertex.
// 4. Initialize `ans` to store the minimum score for the current subproblem (i, j).
// 5. Loop through all possible third vertices `k` between `i` and `j`.
// 6. For each `k`, calculate the triangulation score for the triangle formed by `values[i]`, `values[j]`, and `values[k]`.
// 7. Update `dp[i][j]` with the minimum score for the current range by considering the current triangle's score and the subproblem solutions stored in `dp[i][k]` and `dp[k][j]`.
// 8. Once all subproblems are solved, return `dp[0][n-1]`, which represents the minimum score to triangulate the entire polygon.

int solveUsingTab(vector<int> &values)
{
    int n = values.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i + 2; j < n; j++)
        {
            int ans = INT_MAX;
            for (int k = i + 1; k < j; k++)
            {
                ans = min(ans, values[i] * values[j] * values[k] + dp[i][k] + dp[k][j]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][n - 1];
}
int minScoreTriangulation(vector<int> &values)
{
    return solveUsingTab(values);
}