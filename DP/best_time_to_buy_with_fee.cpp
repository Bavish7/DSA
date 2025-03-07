#include<iostream>
using namespace std;

// BEST TO BUY AND SELL STOCK WITH TRANSACTION FEE (LEETCODE 714)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N), SC=O(N)

// Steps:
// 1. Define `solve(prices, fee, index, canBuy, dp)` to compute the maximum profit recursively with memoization.
// 2. Base case: If `index >= prices.size()`, return 0 as there are no more prices to process.
// 3. If `dp[index][canBuy]` is precomputed, return it to avoid redundant calculations.
// 4. If `canBuy` is true:
//      - Option 1: Buy stock at current `prices[index]` and move to `index+1` in a "can't buy" state (subtract `prices[index]` from profit).
//      - Option 2: Skip buying to stay in the same state.
//      - Store the max of the above two in `profit`.
// 5. If `canBuy` is false:
//      - Option 1: Sell stock at `prices[index]` (with `fee` subtracted) and move to "can buy" state.
//      - Option 2: Skip selling and stay in the same state.
//      - Store the max of the above two in `profit`.
// 6. Memoize and return `profit` as `dp[index][canBuy]`.
// 7. Call `solve(prices, fee, 0, 1, dp)` from `maxProfit()` to get the final result.

int solveUsingMem(vector<int> &prices, int fee, int index, bool canBuy, vector<vector<int>> &dp)
{
    if (index >= prices.size())
    {
        return 0;
    }
    if (dp[index][canBuy] != -1)
    {
        return dp[index][canBuy];
    }
    int profit = INT_MIN;
    if (canBuy == 1)
    {
        int buy = -prices[index] + solveUsingMem(prices, fee, index + 1, 0, dp);
        int notBuy = 0 + solveUsingMem(prices, fee, index + 1, 1, dp);
        profit = max(buy, notBuy);
    }
    else
    {
        int sell = prices[index] - fee + solveUsingMem(prices, fee, index + 1, 1, dp);
        int notSell = 0 + solveUsingMem(prices, fee, index + 1, 0, dp);
        profit = max(sell, notSell);
    }
    dp[index][canBuy] = profit;
    return dp[index][canBuy];
}
int maxProfit(vector<int> &prices, int fee)
{
    int n = prices.size();
    vector<vector<int>> dp(n, vector<int>(2, -1));
    return solveUsingMem(prices, fee, 0, 1, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N), SC=O(N)
// Steps:
// 1. Define `dp[index][canBuy]` where `index` is the current day and `canBuy` indicates whether a stock can be bought (1) or must be sold (0).
// 2. Base cases: Set all `dp[n][canBuy]` to 0, representing zero profit when no more prices remain.
// 3. Traverse prices in reverse (index = n-1 to 0):
//      - If `canBuy` is true:
//          - Option 1: Buy stock at `prices[index]` and move to `index+1` in a "can't buy" state (subtract `prices[index]` from profit).
//          - Option 2: Skip buying to stay in the same state.
//      - If `canBuy` is false:
//          - Option 1: Sell stock at `prices[index]` (subtract `fee`) and move to "can buy" state.
//          - Option 2: Skip selling to remain in the same state.
// 4. Store max of the two options in `dp[index][canBuy]`.
// 5. Return `dp[0][1]` as the maximum profit with all choices considered.

int solveUsingTab(vector<int> &prices, int fee)
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
                int sell = prices[index] - fee + dp[index + 1][1];
                int notSell = 0 + dp[index + 1][0];
                ans = max(sell, notSell);
            }
            dp[index][canBuy] = ans;
        }
    }
    return dp[0][1];
}
int maxProfit(vector<int> &prices, int fee)
{
    return solveUsingTab(prices, fee);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N), SC=O(1)
// Steps:
// 1. Use two vectors, `curr` and `next`, to represent `dp[index][canBuy]` in a space-optimized way.
// 2. Traverse prices in reverse (index = n-1 to 0):
//      - If `canBuy` is true:
//          - Option 1: Buy stock at `prices[index]` and move to the "can't buy" state (subtract `prices[index]` from profit).
//          - Option 2: Skip buying to remain in the same state.
//      - If `canBuy` is false:
//          - Option 1: Sell stock at `prices[index]` (subtract `fee`) and move to the "can buy" state.
//          - Option 2: Skip selling to remain in the same state.
// 3. Store max of the options in `curr[canBuy]` and update `next` at the end of each iteration.
// 4. Return `next[1]` as the maximum profit after all choices are considered.

int solveUsingSO(vector<int> &prices, int fee)
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
                int sell = prices[index] - fee + next[1];
                int notSell = 0 + next[0];
                ans = max(sell, notSell);
            }
            curr[canBuy] = ans;
        }
        next = curr;
    }
    return next[1];
}
int maxProfit(vector<int> &prices, int fee)
{
    return solveUsingSO(prices, fee);
}