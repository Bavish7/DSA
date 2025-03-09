#include<iostream>
using namespace std;

// COMBINATION SUM IV (LEETCODE 377)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*TARGET), SC=O(TARGET)

// Steps:
// 1. Define `solveUsingMem` to calculate the number of combinations that sum up to `target`.
//    - Base Cases:
//        - If `target == 0`, return 1 (one valid combination found).
//        - If `target < 0`, return 0 (no valid combination).
// 2. If `dp[target]` is already computed, return it to avoid redundant calculations.
// 3. Initialize `ans = 0` and iterate over each number in `nums`:
//    - For each `nums[i]`, recursively call `solveUsingMem` with `target - nums[i]`.
//    - Accumulate results in `ans`.
// 4. Store `ans` in `dp[target]` to memoize the result, and return `ans`.
// 5. `combinationSum4` initializes the DP array and calls `solveUsingMem`.

int solveUsingMem(vector<int> &nums, int target, vector<int> &dp)
{
    if (target == 0)
    {
        return 1;
    }
    if (target < 0)
    {
        return 0;
    }
    if (dp[target] != -1)
    {
        return dp[target];
    }
    int ans = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        ans += solveUsingMem(nums, target - nums[i], dp);
    }
    dp[target] = ans;
    return dp[target];
}
int combinationSum4(vector<int> &nums, int target)
{
    vector<int> dp(target + 1, -1);
    return solveUsingMem(nums, target, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*TARGET), SC=O(TARGET)
// 1. Define `solveUsingTab` to calculate the number of ways to achieve each `sum` up to `target`.
// 2. Initialize `dp[0] = 1` (base case: there's one way to reach a sum of zero, by selecting no elements).
// 3. For each `sum` from 1 to `target`:
//      - Iterate over each number in `nums`.
//      - If `sum - nums[i] >= 0`, add `dp[sum - nums[i]]` to `dp[sum]`.
//        This represents adding ways to reach `sum - nums[i]` to the ways to reach `sum`.
// 4. Return `dp[target]` as the total number of combinations to reach the target.

int solveUsingTab(vector<int> &nums, int target)
{
    vector<unsigned long long> dp(target + 1, 0);
    dp[0] = 1;
    for (int sum = 1; sum <= target; sum++)
    {
        int ans = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            if (sum - nums[i] >= 0)
            {
                dp[sum] += dp[sum - nums[i]];
            }
        }
    }
    return dp[target];
}
int combinationSum4(vector<int> &nums, int target)
{
    return solveUsingTab(nums, target);
}