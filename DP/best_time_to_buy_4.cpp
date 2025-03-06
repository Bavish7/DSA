#include<iostream>
using namespace std;

// BEST TIME TO BUY AND SELL STOCK IV (LEETCODE 188)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*K), SC=O(N*K)

// Steps:
// 1. Define `solveUsingMem(k, prices, index, operations, dp)` to recursively compute max profit at each `index`
//    given the current operation count (`operations`).
// 2. Base cases:
//      - If `index` reaches the end of `prices`, return `0` (no further profit possible).
//      - If `operations == 2 * k`, return `0` (maximum transactions reached).
// 3. Check if `dp[index][operations]` is computed; if so, return it to avoid redundant calculations.
// 4. For each state of `operations`:
//      - If `operations` is even (can buy), compute max profit between buying and skipping buying.
//      - If `operations` is odd (can sell), compute max profit between selling and skipping selling.
// 5. Store and return the result in `dp[index][operations]`.
// 6. Call `solveUsingMem(k, prices, 0, 0, dp)` from `maxProfit` to get the final maximum profit.

int solveUsingMem(int k, vector<int> &prices, int index, int operations, vector<vector<int>> &dp)
{
    if (index == prices.size())
    {
        return 0;
    }
    if (operations == 2 * k)
    {
        return 0;
    }
    if (dp[index][operations] != -1)
    {
        return dp[index][operations];
    }
    int profit = INT_MIN;
    if (~operations & 1)
    {
        int buy = -prices[index] + solveUsingMem(k, prices, index + 1, operations + 1, dp);
        int notBuy = 0 + solveUsingMem(k, prices, index + 1, operations, dp);
        profit = max(buy, notBuy);
    }
    else
    {
        int sell = prices[index] + solveUsingMem(k, prices, index + 1, operations + 1, dp);
        int notSell = 0 + solveUsingMem(k, prices, index + 1, operations, dp);
        profit = max(sell, notSell);
    }
    dp[index][operations] = profit;
    return dp[index][operations];
}
int maxProfit(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k, -1));
    return solveUsingMem(k, prices, 0, 0, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*K), SC=O(N*K)
// Steps:
// 1. Define `solveUsingTab(k, prices)` to calculate maximum profit iteratively using a `dp` table.
// 2. Initialize `dp` as a 2D array where `dp[index][operations]` stores the max profit at each `index` for a given number of operations.
// 3. Iterate backwards through `prices` from `index = n-1` to `0`.
// 4. For each `operations` (0 to 2*k-1):
//      - If `operations` is even (buy state), compute the max profit between buying and not buying.
//      - If `operations` is odd (sell state), compute the max profit between selling and not selling.
// 5. Store the result in `dp[index][operations]`.
// 6. Return `dp[0][0]`, which holds the maximum profit for the full array with all operations available.

int solveUsingTab(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> dp(n + 1, vector<int>(2 * k + 1, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int operations = 0; operations < 2 * k; operations++)
        {
            int profit = INT_MIN;
            if (~operations & 1)
            {
                int buy = -prices[index] + dp[index + 1][operations + 1];
                int notBuy = 0 + dp[index + 1][operations];
                profit = max(buy, notBuy);
            }
            else
            {
                int sell = prices[index] + dp[index + 1][operations + 1];
                int notSell = 0 + dp[index + 1][operations];
                profit = max(sell, notSell);
            }
            dp[index][operations] = profit;
        }
    }
    return dp[0][0];
}
int maxProfit(int k, vector<int> &prices)
{
    return solveUsingTab(k, prices);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N), SC=O(K)
// Steps:
// 1. Define `solveUsingTab(k, prices)` to compute maximum profit iteratively, using only two 1D arrays `curr` and `next` to save space.
// 2. Initialize `curr` and `next` arrays where `curr[operations]` holds the max profit for each `index` at a specific `operations`.
// 3. Iterate backwards through `prices` from `index = n-1` to `0`.
// 4. For each `operations` (0 to 2*k-1):
//      - If `operations` is even (buy state), compute the max profit between buying and not buying.
//      - If `operations` is odd (sell state), compute the max profit between selling and not selling.
// 5. Store the result in `curr[operations]`, and at the end of each `index` iteration, set `next = curr`.
// 6. Return `next[0]`, which holds the maximum profit starting from the beginning with all operations available.

int solveUsingSO(int k, vector<int> &prices)
{
    int n = prices.size();
    vector<int> curr(2 * k + 1, 0);
    vector<int> next(2 * k + 1, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        for (int operations = 0; operations < 2 * k; operations++)
        {
            int profit = INT_MIN;
            if (~operations & 1)
            {
                int buy = -prices[index] + next[operations + 1];
                int notBuy = 0 + next[operations];
                profit = max(buy, notBuy);
            }
            else
            {
                int sell = prices[index] + next[operations + 1];
                int notSell = 0 + next[operations];
                profit = max(sell, notSell);
            }
            curr[operations] = profit;
        }
        next = curr;
    }
    return next[0];
}
int maxProfit(int k, vector<int> &prices)
{
    return solveUsingSO(k, prices);
}