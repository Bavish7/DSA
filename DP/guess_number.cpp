#include<iostream>
using namespace std;

// GUESS NUMBER HIGHER OR LOWER II (LEETCODE 375)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^3), SC=O(N^2)

// Steps:
// 1. Base case: If start >= end, return 0.
// 2. If dp[start][end] is already computed, return dp[start][end].
// 3. Initialize ans to INT_MAX.
// 4. Iterate through each number i from start to end:
//    a. Calculate the cost: i + max(solveUsingMem(start, i-1, dp), solveUsingMem(i+1, end, dp)).
//    b. Update ans with the minimum of ans and the calculated cost.
// 5. Store ans in dp[start][end].
// 6. Return dp[start][end] as the minimum cost required for worst-case scenario.

int solveUsingMem(int start, int end, vector<vector<int>> &dp)
{
    if (start >= end)
    {
        return 0;
    }
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    int ans = INT_MAX;
    for (int i = start; i <= end; i++)
    {
        ans = min(ans, i + max(solveUsingMem(start, i - 1, dp), solveUsingMem(i + 1, end, dp)));
    }
    dp[start][end] = ans;
    return dp[start][end];
}
int getMoneyAmount(int n)
{
    int start = 0;
    int end = n;
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = solveUsingMem(start, end, dp);
    return ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^3), SC=O(N^2)
// Steps:
// 1. Initialize dp[n+2][n+1] where n is the upper limit of numbers.
// 2. Iterate from end to start and start to end:
//    a. Initialize ans to INT_MAX.
//    b. Iterate through each number i from start to end:
//       i. Calculate the cost: i + max(dp[start][i-1], dp[i+1][end]).
//       ii. Update ans with the minimum of ans and the calculated cost.
//    c. Store ans in dp[start][end].
// 3. Return dp[1][n] as the minimum cost required for worst-case scenario.

int solveUsingTab(int n)
{
    vector<vector<int>> dp(n + 2, vector<int>(n + 1, 0));
    for (int start = n; start >= 1; start--)
    {
        for (int end = start + 1; end <= n; end++)
        {
            int ans = INT_MAX;
            for (int i = start; i <= end; i++)
            {
                ans = min(ans, i + max(dp[start][i - 1], dp[i + 1][end]));
            }
            dp[start][end] = ans;
        }
    }
    return dp[1][n];
}
int getMoneyAmount(int n)
{
    int ans = solveUsingTab(n);
    return ans;
}