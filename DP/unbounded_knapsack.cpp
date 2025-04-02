#include<iostream>
using namespace std;

// UNBOUNDED KNAPSACK
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*W), SC=O(N*W)

// Steps:
// 1. Base case: If index is 0, calculate maximum profit by taking as many items of this type as possible.
// 2. If already computed, return dp[w][index].
// 3. Initialize include to 0.
//    a. If weight[index] is less than or equal to w, calculate profit including current item.
// 4. Calculate profit excluding current item.
// 5. Store the maximum of include and exclude in dp[w][index].
// 6. Return dp[w][index].

int solveUsingMem(int n, int w, vector<int> &profit, vector<int> &weight, int index, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        return w / weight[0] * profit[index];
    }
    if (dp[w][index] != -1)
    {
        return dp[w][index];
    }
    int include = 0;
    if (weight[index] <= w)
    {
        include = profit[index] + solveUsingMem(n, w - weight[index], profit, weight, index, dp);
    }
    int exclude = solveUsingMem(n, w, profit, weight, index - 1, dp);
    dp[w][index] = max(include, exclude);
    return dp[w][index];
}

int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    int index = n - 1;
    vector<vector<int>> dp(w + 1, vector<int>(n + 1, -1));
    int ans = solveUsingMem(n, w, profit, weight, index, dp);
    return ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*W), SC=O(N*W)
// Steps:
// 1. Initialize a DP table `dp[w+1][n]` where `dp[sum][index]` stores the maximum profit achievable with capacity `sum` using the first `index + 1` items.  
// 2. For the first item (`index == 0`), fill in the table by calculating how many times the first item can be added to the knapsack (`sum / weight[0] * profit[0]`).  
// 3. Iterate through items (`index`) and possible capacities (`sum`).  
// 4. For each item, calculate two options:  
//     a) `include`: Adding the current item (`profit[index] + dp[sum - weight[index]][index]` if the item fits in the current capacity).  
//     b) `exclude`: Not adding the current item (`dp[sum][index - 1]` from the previous item).  
// 5. Store the maximum of `include` and `exclude` in `dp[sum][index]`.  
// 6. Return the result stored in `dp[w][n - 1]` as the maximum profit achievable with the given capacity and items.

int solveUsingTab(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<vector<int>> dp(w + 1, vector<int>(n, 0));
    for (int sum = 0; sum <= w; sum++)
    {
        dp[sum][0] = sum / weight[0] * profit[0];
    }
    for (int index = 1; index < n; index++)
    {
        for (int sum = 0; sum <= w; sum++)
        {
            int include = 0;
            if (weight[index] <= sum)
            {
                include = profit[index] + dp[sum - weight[index]][index];
            }
            int exclude = dp[sum][index - 1];
            dp[sum][index] = max(include, exclude);
        }
    }
    return dp[w][n - 1];
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return solveUsingTab(n, w, profit, weight);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N*W), SC=O(W)
// Steps:
// 1. Use two arrays `prev` and `curr` to optimize space instead of using a 2D DP table. `prev` stores the results of the previous row (previous item), and `curr` stores the current row (current item).  
// 2. Initialize the `prev` array where each element represents the maximum profit achievable with the first item and varying capacities (`sum / weight[0] * profit[0]`).  
// 3. For each item, iterate through possible capacities (`sum`).  
// 4. For each capacity, calculate two options:  
//     a) `include`: Add the current item if it fits in the capacity (`profit[index] + curr[sum - weight[index]]`).  
//     b) `exclude`: Don't add the current item (`prev[sum]` from the previous item).  
// 5. Store the maximum of `include` and `exclude` in `curr[sum]`.  
// 6. After processing all items, return the value stored in `prev[w]` (the maximum profit for the given capacity).

int solveUsingSO(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int> prev(w + 1, 0), curr(w + 1, 0);
    for (int sum = 0; sum <= w; sum++)
    {
        prev[sum] = sum / weight[0] * profit[0];
    }
    for (int index = 1; index < n; index++)
    {
        for (int sum = 0; sum <= w; sum++)
        {
            int include = 0;
            if (weight[index] <= sum)
            {
                include = profit[index] + curr[sum - weight[index]];
            }
            int exclude = prev[sum];
            curr[sum] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[w];
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    return solveUsingSO(n, w, profit, weight);
}