#include<iostream>
using namespace std;

// BURST BALLOONS (LEETCODE 312)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^3), SC=O(N^2)

// Steps:
// 1. Add virtual balloons with value `1` at the start and end of `nums` for boundary handling.
// 2. Define `solveUsingMem` to find the maximum coins achievable by bursting balloons between indices `start` and `end`:
//    - If `start > end`, return `0` as there are no balloons left to burst.
//    - If the value is already computed in `dp`, return it.
//    - Initialize `coins` to track the maximum coins collected.
//    - For each balloon `i` between `start` and `end`, calculate:
//      - `ans` as coins obtained by bursting `i` last in this range (`nums[start-1] * nums[i] * nums[end+1]`).
//      - Recursively calculate coins from bursting balloons in sub-ranges `[start, i-1]` and `[i+1, end]`.
//      - Update `coins` to the maximum of current `coins` and the sum of `ans` and sub-range results.
//    - Store the computed result in `dp[start][end]`.
// 3. Call `solveUsingMem` from `1` to `n-2` to avoid boundary balloons.

int solveUsingMem(vector<int> &nums, int start, int end, vector<vector<int>> &dp)
{
    if (start > end)
        return 0;
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    int coins = INT_MIN;
    for (int i = start; i <= end; i++)
    {
        int ans = nums[start - 1] * nums[i] * nums[end + 1];
        coins = max(coins, ans + solveUsingMem(nums, start, i - 1, dp) + solveUsingMem(nums, i + 1, end, dp));
    }
    dp[start][end] = coins;
    return dp[start][end];
}
int maxCoins(vector<int> &nums)
{
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solveUsingMem(nums, 1, n - 2, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^3), SC=O(N^2)
// Steps:
// 1. Add virtual balloons with value `1` at the beginning and end of `nums` to handle boundary cases.
// 2. Initialize a 2D `dp` array where `dp[start][end]` stores the maximum coins obtainable by bursting balloons from index `start` to `end`.
// 3. Use a bottom-up approach to fill `dp`:
//    - Iterate `start` from `n-2` to `1` (where `n` is the size of `nums`).
//    - For each `start`, iterate `end` from `start` to `n-2`.
//    - For each possible balloon `i` within the `start` to `end` range, calculate `coins` as the maximum of:
//      - `ans`, which is the result of bursting balloon `i` last in this sub-array (`nums[start-1] * nums[i] * nums[end+1]`).
//      - The sum of `ans`, `dp[start][i-1]`, and `dp[i+1][end]` (coins from subarrays before and after `i`).
//    - Update `dp[start][end]` with the maximum coins for that range.
// 4. Return `dp[1][n-2]` as the maximum coins from bursting all non-boundary balloons.

int solveUsingTab(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int start = n - 2; start >= 1; start--)
    {
        for (int end = start; end <= n - 2; end++)
        {
            int coins = INT_MIN;
            for (int i = start; i <= end; i++)
            {
                int ans = nums[start - 1] * nums[i] * nums[end + 1];
                coins = max(coins, ans + dp[start][i - 1] + dp[i + 1][end]);
            }
            dp[start][end] = coins;
        }
    }
    return dp[1][n - 2];
}
int maxCoins(vector<int> &nums)
{
    nums.insert(nums.begin(), 1);
    nums.insert(nums.end(), 1);
    return solveUsingTab(nums);
}