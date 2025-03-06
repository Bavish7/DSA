#include<iostream>
using namespace std;

// BEST TIME TO BUY AND SELL STOCK III (LEETCODE 123)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N), SC=O(N)

// Steps:
// 1. Define `solveUsingMem(prices, index, canBuy, trans, dp)` to calculate maximum profit for a day `index` with the option to `buy` or `sell` and `trans` transactions completed.
// 2. Base cases:
//      - If `index` exceeds the number of days or `trans` equals 2, return 0 (no more transactions possible).
//      - If the result for `index`, `canBuy`, and `trans` is already computed in `dp`, return it.
// 3. Recursive steps based on `canBuy`:
//      - If `canBuy` is true:
//          - `buy`: Choose to buy at `prices[index]` and move to the next day with `canBuy` as false.
//          - `notBuy`: Skip buying and stay at the next day with `canBuy` as true.
//          - `ans` stores the max of these options.
//      - If `canBuy` is false:
//          - `sell`: Choose to sell at `prices[index]`, move to the next day with `canBuy` as true,
//            and increment `trans`.
//          - `notSell`: Skip selling and stay on the next day with `canBuy` as false.
//          - `ans` stores the max of these options.
// 4. Store `ans` in `dp[index][canBuy][trans]` and return it.
// 5. Call `solveUsingMem(prices, 0, 1, 0, dp)` from `maxProfit` to get the final result.

int solveUsingMem(vector<int> &prices, int index, bool canBuy, int trans, vector<vector<vector<int>>> &dp)
{
    if (index >= prices.size() || trans >= 2)
    {
        return 0;
    }
    if (dp[index][canBuy][trans] != -1)
    {
        return dp[index][canBuy][trans];
    }
    int ans = INT_MIN;
    if (canBuy == 1)
    {
        int buy = -prices[index] + solveUsingMem(prices, index + 1, 0, trans, dp);
        int notBuy = 0 + solveUsingMem(prices, index + 1, 1, trans, dp);
        ans = max(buy, notBuy);
    }
    else
    {
        int sell = prices[index] + solveUsingMem(prices, index + 1, 1, trans + 1, dp);
        int notSell = 0 + solveUsingMem(prices, index + 1, 0, trans, dp);
        ans = max(sell, notSell);
    }
    dp[index][canBuy][trans] = ans;
    return dp[index][canBuy][trans];
}
int maxProfit(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(3, -1)));
    return solveUsingMem(prices, 0, 1, 0, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N), SC=O(N)
// Steps:
// 1. Define `dp[index][canBuy][trans]` to store maximum profit for day `index` given a `canBuy` or `sell` option
//    and `trans` transactions completed.
// 2. Initialize `dp[n][canBuy][trans] = 0` for all `canBuy` and `trans` values, since no profit is possible after
//    the last day.
// 3. Fill `dp` bottom-up, starting from the last valid day and moving backward to day 0.
// 4. For each `index`, check both `canBuy` states:
//      - If `canBuy` is true:
//          - `buy`: Deduct `prices[index]` and move to the next day with `canBuy` as false.
//          - `notBuy`: Skip buying, keeping `canBuy` as true the next day.
//          - Store the max of `buy` and `notBuy` in `dp[index][canBuy][trans]`.
//      - If `canBuy` is false:
//          - `sell`: Add `prices[index]`, move to the next day with `canBuy` as true, and increment `trans`.
//          - `notSell`: Skip selling, keeping `canBuy` as false the next day.
//          - Store the max of `sell` and `notSell` in `dp[index][canBuy][trans]`.
// 5. Return `dp[0][1][0]` from `solveUsingTab` in `maxProfit` for the maximum profit starting on day 0 with
//    the option to buy and zero transactions completed.

int solveUsingTab(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3, 0)));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            for (int trans = 0; trans < 2; trans++)
            {
                int ans = INT_MIN;
                if (canBuy == 1)
                {
                    int buy = -prices[index] + dp[index + 1][0][trans];
                    int notBuy = 0 + dp[index + 1][1][trans];
                    ans = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[index] + dp[index + 1][1][trans + 1];
                    int notSell = 0 + dp[index + 1][0][trans];
                    ans = max(sell, notSell);
                }
                dp[index][canBuy][trans] = ans;
            }
        }
    }
    return dp[0][1][0];
}
int maxProfit(vector<int> &prices)
{
    return solveUsingTab(prices);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N), SC=O(1)
// Steps:
// 1. Define `curr[canBuy][trans]` and `next[canBuy][trans]` to store max profit for day `index` in terms of
//    buying/selling states and completed transactions.
// 2. Initialize both `curr` and `next` as 2D arrays with dimensions `2 x 3`, representing `canBuy` and `trans` states.
// 3. Traverse backwards from the last valid day to the first (day `n-1` to `0`).
// 4. For each day and `canBuy` state, compute two options:
//      - If `canBuy` is `1`:
//          - `buy`: Deduct price at `index` and reference `next[0][trans]` for post-buy profit.
//          - `notBuy`: Continue without buying, referencing `next[1][trans]`.
//          - Store max of `buy` and `notBuy` in `curr[canBuy][trans]`.
//      - If `canBuy` is `0`:
//          - `sell`: Add price at `index`, increment `trans`, and reference `next[1][trans+1]`.
//          - `notSell`: Continue without selling, referencing `next[0][trans]`.
//          - Store max of `sell` and `notSell` in `curr[canBuy][trans]`.
// 5. Copy `curr` to `next` after each day's computation to simulate day-wise transition.
// 6. Return `next[1][0]` from `solveUsingSO` for the maximum profit beginning at day 0 with option to buy.

int solveUsingSO(vector<int> &prices)
{
    int n = prices.size();
    vector<vector<int>> curr(2, vector<int>(3, 0));
    vector<vector<int>> next(2, vector<int>(3, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int canBuy = 0; canBuy <= 1; canBuy++)
        {
            for (int trans = 0; trans < 2; trans++)
            {
                int ans = INT_MIN;
                if (canBuy == 1)
                {
                    int buy = -prices[index] + next[0][trans];
                    int notBuy = 0 + next[1][trans];
                    ans = max(buy, notBuy);
                }
                else
                {
                    int sell = prices[index] + next[1][trans + 1];
                    int notSell = 0 + next[0][trans];
                    ans = max(sell, notSell);
                }
                curr[canBuy][trans] = ans;
            }
        }
        next = curr;
    }
    return next[1][0];
}
int maxProfit(vector<int> &prices)
{
    return solveUsingSO(prices);
}