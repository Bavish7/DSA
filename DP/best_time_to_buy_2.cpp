#include<iostream>
using namespace std;

// BEST TIME TO BUY AND SELL STOCK II (LEETCODE 122)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N), SC=O(N)

// Steps:
// 1. Define `solve(prices, index, canBuy, dp)` to calculate max profit at each day `index`, based on whether buying or selling is allowed (`canBuy`).
// 2. Base case: If `index` is out of range, return 0 (no transactions possible).
// 3. Use `dp[index][canBuy]` to store and reuse results to avoid redundant calculations.
// 4. If `canBuy` is true:
//      - Either buy at `prices[index]` and move to `index + 1` with `canBuy=0`, or skip buying and stay at `index + 1` with `canBuy=1`.
// 5. If `canBuy` is false:
//      - Either sell at `prices[index]` and move to `index + 1` with `canBuy=1`, or skip selling and stay at `index + 1` with `canBuy=0`.
// 6. Store and return the maximum profit of these choices.
// 7. Initialize `dp` in `maxProfit` and call `solve(prices, 0, 1, dp)` for the answer.

int solveUsingMem(vector<int> &prices, int index, bool canBuy, vector<vector<int>> &dp)
{
    if (index >= prices.size())
    {
        return 0;
    }
    if (dp[index][canBuy] != -1)
    {
        return dp[index][canBuy];
    }
    int ans = INT_MIN;
    if (canBuy == 1)
    {
        int buy = -prices[index] + solveUsingMem(prices, index + 1, 0, dp);
        int notBuy = 0 + solveUsingMem(prices, index + 1, 1, dp);
        ans = max(buy, notBuy);
    }
    else
    {
        int sell = prices[index] + solveUsingMem(prices, index + 1, 1, dp);
        int notSell = 0 + solveUsingMem(prices, index + 1, 0, dp);
        ans = max(sell, notSell);
    }
    dp[index][canBuy] = ans;
    return dp[index][canBuy];
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solveUsingMem(prices, 0, 1, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N), SC=O(N)
// Steps:
// 1. Initialize a 2D `dp` table where `dp[index][canBuy]` stores the max profit from `index` to end of prices, with `canBuy` indicating if buying is allowed.
// 2. Traverse `prices` from the last index to the first:
//      - For each `index`, iterate over possible actions (`canBuy=1` and `canBuy=0`).
//      - If `canBuy` is true, choose the maximum of:
//           - Buying at `prices[index]` and adding the result from the next day with `canBuy=0`.
//           - Skipping buy and using the result from the next day with `canBuy=1`.
//      - If `canBuy` is false, choose the maximum of:
//           - Selling at `prices[index]` and adding the result from the next day with `canBuy=1`.
//           - Skipping sell and using the result from the next day with `canBuy=0`.
// 3. Store the result in `dp[index][canBuy]`.
// 4. Return `dp[0][1]`, representing the max profit starting at day 0 with buying allowed.

int solveUsingTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            int ans = INT_MIN;
            if (canBuy == 1)
            {
                int buy = -prices[index] + dp[index + 1][0];
                int notBuy = 0 + dp[index + 1][1];
                ans = max(buy, notBuy);
            }
            else
            {
                int sell = prices[index] + dp[index + 1][1];
                int notSell = 0 + dp[index + 1][0];
                ans = max(sell, notSell);
            }
            dp[index][canBuy] = ans;
        }
    }
    return dp[0][1];
}
int maxProfit(vector<int> &prices)
{
    return solveUsingTab(prices);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N), SC=O(1)
// Steps:
// 1. Initialize two 1D arrays, `curr` and `next`, where:
//      - `next` holds results for the next day's profits, and `curr` is for the current day's calculations.
// 2. Traverse `prices` in reverse from the last index to the first:
//      - For each `index`, calculate profits based on two options (`canBuy=1` and `canBuy=0`):
//          - If `canBuy` is true, choose the maximum between:
//              - Buying at `prices[index]` and moving to the next day with `canBuy=0`.
//              - Skipping buy and staying on the next day with `canBuy=1`.
//          - If `canBuy` is false, choose the maximum between:
//              - Selling at `prices[index]` and moving to the next day with `canBuy=1`.
//              - Skipping sell and staying on the next day with `canBuy=0`.
//      - Store the maximum result in `curr[canBuy]` for both options.
// 3. Update `next` to be `curr` for each day's iteration.
// 4. Return `next[1]`, representing the maximum profit starting at day 0 with buying allowed.

int solveUsingSO(vector<int> &prices)
{
    int n = prices.size();
    vector<int> curr(2, 0);
    vector<int> next(2, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            int ans = INT_MIN;
            if (canBuy == 1)
            {
                int buy = -prices[index] + next[0];
                int notBuy = 0 + next[1];
                ans = max(buy, notBuy);
            }
            else
            {
                int sell = prices[index] + next[1];
                int notSell = 0 + next[0];
                ans = max(sell, notSell);
            }
            curr[canBuy] = ans;
        }
        next = curr;
    }
    return next[1];
}
int maxProfit(vector<int> &prices)
{
    return solveUsingSO(prices);
}