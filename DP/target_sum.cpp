#include<iostream>
using namespace std;

// TARGET SUM (LEETCODE 494)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*T), SC=O(N*T)

// Steps:
// 1. Define a recursive `solveUsingMem` function with memoization to find ways to achieve `target` sum:
//    - If `i` reaches `nums.size()`, check if `target` is 0. If so, count as a valid way, otherwise return 0.
//    - Check memoization map `dp` to avoid redundant calculations.
// 2. Explore two options for each `nums[i]`:
//    - `plus`: Add `nums[i]` to the target sum and move to the next index.
//    - `minus`: Subtract `nums[i]` from the target sum and move to the next index.
// 3. Store the total ways (sum of `plus` and `minus`) in `dp[{target, i}]` for future use.
// 4. In `findTargetSumWays`, initialize `dp` and call `solveUsingMem` with `target` and starting index 0.

int solveUsingMem(vector<int> &nums, int target, int i, map<pair<int, int>, int> &dp)
{
    if (i == nums.size())
        return target == 0 ? 1 : 0;
    if (dp.find({target, i}) != dp.end())
    {
        return dp[{target, i}];
    }
    int plus = solveUsingMem(nums, target + nums[i], i + 1, dp);
    int minus = solveUsingMem(nums, target - nums[i], i + 1, dp);
    dp[{target, i}] = plus + minus;
    return dp[{target, i}];
}
int findTargetSumWays(vector<int> &nums, int target)
{
    map<pair<int, int>, int> dp;
    return solveUsingMem(nums, target, 0, dp);
}