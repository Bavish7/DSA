#include<iostream>
using namespace std;

// SUBSET SUM EQUAL TO K
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*K), SC=O(N*K)

// Steps:
// 1. The base case is when the target sum becomes 0, in which case the answer is true (since an empty subset can form the sum 0).
// 2. If we've processed all elements and haven't found a valid subset, return false.
// 3. For each index, either include or exclude the current element:
//     - Exclude: Check if the subset sum can be formed by excluding the current element.
//     - Include: Check if the subset sum can be formed by including the current element (only if it does not exceed the target).
// 4. Use memoization to store results of previously computed states to avoid redundant calculations.
// 5. The final result is stored in dp[n-1][k], indicating whether it's possible to form a subset with sum k using all elements.

bool solveUsingMem(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return true;
    if (index == 0)
        return (arr[0] == target);
    if (dp[index][target] != -1)
        return dp[index][target];
    bool exclude = solveUsingMem(index - 1, target, arr, dp);
    bool include = false;
    if (target >= arr[index])
    {
        include = solveUsingMem(index - 1, target - arr[index], arr, dp);
    }
    return dp[index][target] = include || exclude;
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solveUsingMem(n - 1, k, arr, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*K), SC=O(N*K)
// Steps:
// 1. Initialize the DP table with dimensions [n][k+1], where n is the number of elements in the array and k is the target sum.
// 2. Set dp[i][0] to true for all i, since a sum of 0 can always be formed by taking no elements.
// 3. Set dp[0][arr[0]] to true if the first element is less than or equal to the target sum k.
// 4. Iterate through the array, for each element and for each target sum from 1 to k:
//     - Exclude: Check the previous row (excluding the current element).
//     - Include: If the target is greater than or equal to the current element, check if the sum can be formed by including the current element.
// 5. The result is stored in dp[n-1][k], indicating whether it's possible to form a subset with sum k.

bool solveUsingTab(int n, int k, vector<int> &arr)
{
    vector<vector<bool>> dp(n, vector<bool>(k + 1, 0));
    for (int index = 0; index < n; index++)
    {
        dp[index][0] = 1;
    }
    dp[0][arr[0]] = 1;
    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool exclude = dp[index - 1][target];
            bool include = false;
            if (target >= arr[index])
            {
                include = dp[index - 1][target - arr[index]];
            }
            dp[index][target] = include || exclude;
        }
    }
    return dp[n - 1][k];
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return solveUsingTab(n, k, arr);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N*K), SC=O(K)
// Steps:
// 1. Initialize two arrays: prev and curr, both of size k+1, to store the DP results of previous and current rows.
// 2. Set prev[0] and curr[0] to true, since a sum of 0 can always be formed by taking no elements.
// 3. Set prev[arr[0]] to true if the first element is less than or equal to the target sum k.
// 4. Iterate through the array, for each element, and for each target sum from 1 to k:
//     - Exclude: Check if the sum can be formed without the current element (using prev).
//     - Include: If the target is greater than or equal to the current element, check if the sum can be formed by including the current element (using prev).
// 5. After each iteration, update prev to curr, as curr holds the results for the current element.
// 6. The result is stored in prev[k], indicating whether it's possible to form a subset with sum k.

bool solveUsingSO(int n, int k, vector<int> &arr)
{
    vector<bool> prev(k + 1, 0), curr(k + 1, 0);
    prev[0] = curr[0] = true;
    prev[arr[0]] = 1;
    for (int index = 1; index < n; index++)
    {
        for (int target = 1; target <= k; target++)
        {
            bool exclude = prev[target];
            bool include = false;
            if (target >= arr[index])
            {
                include = prev[target - arr[index]];
            }
            curr[target] = include || exclude;
        }
        prev = curr;
    }
    return prev[k];
}
bool subsetSumToK(int n, int k, vector<int> &arr)
{
    return solveUsingSO(n, k, arr);
}