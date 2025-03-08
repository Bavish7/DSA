#include<iostream>
using namespace std;

// COIN CHANGE II (LEETCODE 518)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*AMOUNT), SC=O(N*AMOUNT)

// Steps:
// 1. Base case handles single coin usage by checking divisibility with `sum`.
// 2. Use recursion with memoization to explore two options for each index and sum:
//    a) Exclude the current coin and move to the next index.
//    b) Include the current coin if the remaining sum allows, staying on the same index.
// 3. Store computed results in the dp table to avoid redundant recursive calls.
// 4. Return the sum of include and exclude results as the total number of ways.

int solveUsingMem(int index, int sum, vector<int> &coins, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        return (sum % coins[index] == 0);
    }
    if (dp[index][sum] != -1)
        return dp[index][sum];
    int exclude = solveUsingMem(index - 1, sum, coins, dp);
    int include = 0;
    if (sum >= coins[index])
    {
        include = solveUsingMem(index, sum - coins[index], coins, dp);
    }
    return dp[index][sum] = include + exclude;
}
int change(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, -1));
    return solveUsingMem(n - 1, amount, coins, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*AMOUNT), SC=O(N*AMOUNT)
// Steps:
// 1. Initialize a DP table `dp` where `dp[i][j]` represents the number of ways to make sum `j` using coins up to index `i`.
// 2. Base case: For the first row (`index == 0`), fill values based on whether the current sum `j` is divisible by `coins[0]`.
// 3. Iterate through the coins and possible sums:
//    a) Exclude the current coin (`dp[index - 1][sum]`).
//    b) Include the current coin if valid (`dp[index][sum - coins[index]]`).
// 4. Update `dp[index][sum]` by adding the results from include and exclude cases.
// 5. Return the final answer stored in `dp[n - 1][amount]`.

int solveUsingTab(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<vector<int>> dp(n, vector<int>(amount + 1, 0));
    for (int sum = 0; sum <= amount; sum++)
    {
        dp[0][sum] = (sum % coins[0] == 0);
    }
    for (int index = 1; index < n; index++)
    {
        for (int sum = 0; sum <= amount; sum++)
        {
            int exclude = dp[index - 1][sum];
            int include = 0;
            if (sum >= coins[index])
            {
                include = dp[index][sum - coins[index]];
            }
            dp[index][sum] = (long)include + exclude;
        }
    }
    return dp[n - 1][amount];
}
int change(int amount, vector<int> &coins)
{
    return solveUsingTab(amount, coins);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N*AMOUNT), SC=O(AMOUNT)
// Steps:
// 1. Initialize two vectors `prev` and `curr` to store results for the previous and current row, respectively.
// 2. Base case: For the first row, fill `prev` based on whether `sum` is divisible by `coins[0]`.
// 3. Iterate through the coins and possible sums:
//    a) Exclude the current coin (`prev[sum]`).
//    b) Include the current coin if valid (`curr[sum - coins[index]]`).
// 4. Update `curr[sum]` by adding the results from include and exclude cases.
// 5. Copy `curr` to `prev` at the end of each row iteration.
// 6. Return the final result stored in `prev[amount]`.

int solveUsingSO(int amount, vector<int> &coins)
{
    int n = coins.size();
    vector<int> prev(amount + 1, 0), curr(amount + 1, 0);
    for (int sum = 0; sum <= amount; sum++)
    {
        prev[sum] = (sum % coins[0] == 0);
    }
    for (int index = 1; index < n; index++)
    {
        for (int sum = 0; sum <= amount; sum++)
        {
            int exclude = prev[sum];
            int include = 0;
            if (sum >= coins[index])
            {
                include = curr[sum - coins[index]];
            }
            curr[sum] = (long)include + exclude;
        }
        prev = curr;
    }
    return prev[amount];
}
int change(int amount, vector<int> &coins)
{
    return solveUsingSO(amount, coins);
}