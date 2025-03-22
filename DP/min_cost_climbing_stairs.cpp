#include<iostream>
using namespace std;

// MIN COST CLIMBING STAIRS (LEETCODE 746)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N), SC=O(N)

// Steps:
// 1. Define a recursive function `solveUsingMem` that returns the minimum cost to climb stairs from a given index.
// 2. Base case: If the current index exceeds or equals `n` (the number of steps), return 0 (no further cost).
// 3. Use memoization to store results in `dp[]` for previously solved subproblems to avoid redundant calculations.
// 4. Recursively compute the cost for both taking one step and two steps ahead from the current index.
// 5. At each index, store the minimum cost in `dp[]` and return it.
// 6. In the main function, call `solveUsingMem` starting from both index 0 and index 1 (as you can start from either step).
// 7. Return the minimum of the two computed results.

int solveUsingMem(vector<int> &cost, int n, int index, vector<int> &dp)
{
    if (index >= n)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int step0 = cost[index] + solveUsingMem(cost, n, index + 1, dp);
    int step1 = cost[index] + solveUsingMem(cost, n, index + 2, dp);
    dp[index] = min(step0, step1);
    return dp[index];
}
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    vector<int> dp(n + 1, -1);
    int ans1 = solveUsingMem(cost, n, 0, dp);
    int ans2 = solveUsingMem(cost, n, 1, dp);
    return min(ans1, ans2);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N), SC=O(N)
// Steps:
// 1. Define a tabulation function `solveUsingTab` to compute the minimum cost to climb stairs.
// 2. Create a `dp[]` array of size `n+1` initialized to `INT_MAX`, with `dp[n]` set to 0 (reaching the top requires no cost).
// 3. Set `dp[n-1]` as the cost of the last step.
// 4. Iterate from `n-2` down to 0, calculating the minimum cost for taking either one step or two steps ahead from each index.
// 5. Store the minimum cost for each index in the `dp[]` array.
// 6. Return the minimum of `dp[0]` and `dp[1]`, representing starting from either the first or second step.

int solveUsingTab(vector<int> &cost, int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    dp[n - 1] = cost[n - 1];
    for (int index = n - 2; index >= 0; index--)
    {
        int step0 = cost[index] + dp[index + 1];
        int step1 = cost[index] + dp[index + 2];
        dp[index] = min(step0, step1);
    }
    return min(dp[0], dp[1]);
}
int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    return solveUsingTab(cost, n);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N), SC=O(1)
// Steps:
// 1. Initialize two variables, `curr` to 0 and `prev` to `cost[n-1]` (cost of the last step).
// 2. Iterate from `n-2` down to 0, for each index:
//    - Calculate the cost of taking one step ahead (`step0`) and two steps ahead (`step1`).
//    - Update `curr` to the previous `prev` value.
//    - Update `prev` to the minimum of `step0` and `step1`.
// 3. After the loop, return the minimum of `prev` and `curr`, which represents the minimum cost to reach the top.

int minCostClimbingStairs(vector<int> &cost)
{
    int n = cost.size();
    int curr = 0;
    int prev = cost[n - 1];
    for (int index = n - 2; index >= 0; index--)
    {
        int step0 = cost[index] + curr;
        int step1 = cost[index] + prev;
        curr = prev;
        prev = min(step0, step1);
    }
    return min(prev, curr);
}