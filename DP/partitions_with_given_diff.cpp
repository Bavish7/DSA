#include<iostream>
using namespace std;

// PARTITIONS WITH GIVEN DIFFERENCE
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*SUM), SC=O(N*SUM)

// Steps:
// 1. Calculate the `totalSum` of the array `arr`.  
// 2. If the target difference `d` is greater than `totalSum` or if `(totalSum - d)` is odd, return `false` since it's not possible to partition the array into two subsets with the given difference.  
// 3. The problem can be reduced to finding the number of subsets with sum `(totalSum - d) / 2`.  
// 4. Use `findWays` function to count the number of subsets with the sum `(totalSum - d) / 2` using dynamic programming.  
// 5. The base case of `solveUsingMem` handles cases where no elements are left to include or the target is zero. It returns `2` for a target of `0` and array element `0`, otherwise `1` or `0` based on the target matching the current element.  
// 6. Recursively calculate the number of ways to include or exclude the current element to reach the target sum.  
// 7. Return the result of `findWays` for the reduced target.

#include <bits/stdc++.h>
int mod = 1e9 + 7;
int solveUsingMem(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == arr[index] || target == 0)
            return 1;
        else
            return 0;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    int include = 0;
    if (target >= arr[index])
    {
        include = solveUsingMem(index - 1, target - arr[index], arr, dp);
    }
    int exclude = solveUsingMem(index - 1, target, arr, dp);
    return dp[index][target] = (include + exclude) % mod;
}
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solveUsingMem(n - 1, k, arr, dp);
}
int countPartitions(int n, int d, vector<int> &arr)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += arr[i];
    if (totalSum - d < 0 || (totalSum - d) % 2)
        return false;
    return findWays(arr, (totalSum - d) / 2);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*SUM), SC=O(N*SUM)
// Steps:
// 1. Calculate the `totalSum` of the array `arr`.  
// 2. If the target difference `d` is greater than `totalSum` or if `(totalSum - d)` is odd, return `false` as it's not possible to partition the array into two subsets with the given difference.  
// 3. The problem is reduced to finding the number of subsets with sum `(totalSum - d) / 2`.  
// 4. Initialize the base case for the first element:  
//    - If the first element is `0`, it can either be included or excluded, hence `dp[0][0] = 2`.  
//    - If the first element is not `0` but is less than or equal to `k`, set `dp[0][arr[0]] = 1`.  
// 5. For subsequent elements, iterate over each possible target sum and calculate the number of ways to include or exclude the current element to form that sum:  
//    - `exclude = dp[index - 1][target]` (ways without including the current element)  
//    - `include = dp[index - 1][target - arr[index]]` (ways including the current element, if the target is greater than or equal to `arr[index]`)  
//    - Store the result in `dp[index][target] = (include + exclude) % mod`.  
// 6. Return `dp[n - 1][k]`, the number of ways to form the target sum.

int mod = 1e9 + 7;
int solveUsingTab(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    if (arr[0] == 0)
        dp[0][0] = 2;
    else
        dp[0][0] = 1;
    if (arr[0] != 0 && arr[0] <= k)
        dp[0][arr[0]] = 1;
    for (int index = 1; index < n; index++)
    {
        for (int target = 0; target <= k; target++)
        {
            int exclude = dp[index - 1][target];
            int include = 0;
            if (target >= arr[index])
            {
                include = dp[index - 1][target - arr[index]];
            }
            dp[index][target] = (include + exclude) % mod;
        }
    }
    return dp[n - 1][k];
}
int findWays(vector<int> &arr, int k)
{
    return solveUsingTab(arr, k);
}
int countPartitions(int n, int d, vector<int> &arr)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += arr[i];
    if (totalSum - d < 0 || (totalSum - d) % 2)
        return false;
    return findWays(arr, (totalSum - d) / 2);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N*SUM), SC=O(SUM)
// Steps:
// 1. Calculate the `totalSum` of the array `arr`.  
// 2. If the target difference `d` is greater than `totalSum` or if `(totalSum - d)` is odd, return `false` as it's not possible to partition the array into two subsets with the given difference.  
// 3. The problem is reduced to finding the number of subsets with sum `(totalSum - d) / 2`.  
// 4. Initialize a space-efficient DP approach using two arrays `prev` and `curr` to track the number of ways to form sums.  
// 5. Set the base case:  
//    - If the first element is `0`, it can either be included or excluded, hence `prev[0] = 2`.  
//    - If the first element is non-zero but less than or equal to `k`, set `prev[arr[0]] = 1`.  
// 6. For each subsequent element in `arr`, calculate the number of ways to form a sum using a rolling array approach:  
//    - `exclude = prev[target]` (ways without including the current element)  
//    - `include = prev[target - arr[index]]` (ways including the current element, if the target is greater than or equal to `arr[index]`)  
//    - Store the result in `curr[target] = (include + exclude) % mod`.  
// 7. After processing all elements, the result is stored in `prev[k]`, which is the number of ways to form the target sum.

int mod = 1e9 + 7;
int solveUsingSO(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> prev(k + 1, 0), curr(k + 1, 0);
    if (arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    if (arr[0] != 0 && arr[0] <= k)
        prev[arr[0]] = 1;
    for (int index = 1; index < n; index++)
    {
        for (int target = 0; target <= k; target++)
        {
            int exclude = prev[target];
            int include = 0;
            if (target >= arr[index])
            {
                include = prev[target - arr[index]];
            }
            curr[target] = (include + exclude) % mod;
        }
        prev = curr;
    }
    return prev[k];
}
int findWays(vector<int> &arr, int k)
{
    return solveUsingSO(arr, k);
}
int countPartitions(int n, int d, vector<int> &arr)
{
    int totalSum = 0;
    for (int i = 0; i < n; i++)
        totalSum += arr[i];
    if (totalSum - d < 0 || (totalSum - d) % 2)
        return false;
    return findWays(arr, (totalSum - d) / 2);
}