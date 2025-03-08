#include<iostream>
using namespace std;

// COIN CHANGE (LEETCODE 322)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(AMOUNT * COINS.SIZE), SC=O(AMOUNT)

// Steps:
// 1. If amount is 0, return 0 (no coins needed).
// 2. If dp[amount] has a precomputed value, return it.
// 3. Initialize minCoins to INT_MAX.
// 4. Iterate through each coin:
//    a. If the current coin value is less than or equal to amount:
//       - Recursively calculate the minimum coins needed for (amount - coin value).
//       - Update minCoins if recursionAns is not INT_MAX.
// 5. Memoize dp[amount] with minCoins and return it.

int solveUsingMem(vector<int> &coins, int amount, vector<int> &dp)
{
    if (amount == 0)
    {
        return 0;
    }
    if (dp[amount] != -1)
    {
        return dp[amount];
    }
    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        if (amount >= coins[i])
        {
            int recursionAns = solveUsingMem(coins, amount - coins[i], dp);
            if (recursionAns != INT_MAX)
            {
                int ans = 1 + recursionAns;
                mini = min(mini, ans);
            }
        }
    }
    dp[amount] = mini;
    return dp[amount];
}
int coinChange(vector<int> &coins, int amount)
{
    int n = amount;
    vector<int> dp(n + 1, -1);
    int ans = solveUsingMem(coins, amount, dp);
    if (ans == INT_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(AMOUNT * COINS.SIZE), SC=O(AMOUNT)
// Steps:
// 1. Initialize a dp array with size amount + 1, filled with INT_MAX (indicating unreachable).
// 2. Set dp[0] to 0 (no coins needed for amount 0).
// 3. Iterate through each value from 1 to amount:
//    a. Initialize minCoins to INT_MAX.
//    b. Iterate through each coin:
//       - If the current coin value is less than or equal to the current value:
//         - Calculate the minimum coins needed as 1 + dp[value - coin].
//         - Update minCoins if recursionAns is not INT_MAX.
//    c. Memoize dp[value] with minCoins.
// 4. Return dp[amount], which contains the minimum number of coins needed to make up amount.

int solveUsingTab(vector<int> &coins, int amount)
{
    int n = amount;
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    for (int value = 1; value <= n; value++)
    {
        int mini = INT_MAX;
        for (int i = 0; i < coins.size(); i++)
        {
            if (value - coins[i] >= 0)
            {
                int recursionAns = dp[value - coins[i]];
                if (recursionAns != INT_MAX)
                {
                    int ans = 1 + recursionAns;
                    mini = min(mini, ans);
                }
            }
        }
        dp[value] = mini;
    }
    return dp[n];
}
int coinChange(vector<int> &coins, int amount)
{
    int ans = solveUsingTab(coins, amount);
    if (ans == INT_MAX)
    {
        return -1;
    }
    else
    {
        return ans;
    }
}