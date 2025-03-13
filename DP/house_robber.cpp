#include<iostream>
using namespace std;

// HOUSE ROBBER (LEETCODE 198)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N), SC=O(N)

// Steps:
// 1. Base case: If index >= n, return 0 as there are no more houses to rob.
//                If dp[index] != -1, return dp[index] which has already been computed.
// 2. Recursive case:
//    a. Calculate include = nums[index] + solveUsingMem(index + 2, n, dp, nums).
//       This represents robbing the current house and adding the maximum from index + 2.
//    b. Calculate exclude = solveUsingMem(index + 1, n, dp, nums).
//       This represents skipping the current house and adding the maximum from index + 1.
// 3. Memoize the result by storing dp[index] = max(include, exclude).
// 4. Return dp[index] which contains the maximum amount that can be robbed starting from 'index'.

int solveUsingMem(int index, int n, vector<int> &dp, vector<int> &nums)
{
    if (index >= n)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int include = nums[index] + solveUsingMem(index + 2, n, dp, nums);
    int exclude = 0 + solveUsingMem(index + 1, n, dp, nums);
    dp[index] = max(include, exclude);
    return dp[index];
}
int rob(vector<int> &nums)
{
    int index = 0;
    int n = nums.size();
    vector<int> dp(n, -1);
    int ans = solveUsingMem(index, n, dp, nums);
    return ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N), SC=O(N)
// Steps:
// 1. Initialize dp array of size n with -1.
// 2. Set base case dp[n-1] = nums[n-1], which is the value of the last house.
// 3. Iterate backwards from n-2 to 0:
//    a. Calculate tempAns as dp[i+2] if i+2 is within bounds, else 0.
//    b. Calculate include = nums[i] + tempAns, which includes robbing current house i.
//    c. Calculate exclude = dp[i+1], which excludes robbing current house i.
//    d. Store dp[i] as the maximum of include and exclude.
// 4. Return dp[0], which contains the maximum amount that can be robbed starting from the first house.

int solveUsingTab(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, -1);
    dp[n - 1] = nums[n - 1];
    for (int i = n - 2; i >= 0; i--)
    {
        int tempAns = 0;
        if (i + 2 < n)
        {
            tempAns = dp[i + 2];
        }
        int include = nums[i] + tempAns;
        int exclude = 0 + dp[i + 1];
        dp[i] = max(include, exclude);
    }
    return dp[0];
}
int rob(vector<int> &nums)
{
    int ans = solveUsingTab(nums);
    return ans;
}

// SPACE OPTIMIZATION APPROACH - TC=O(N), SC=O(1)
// Steps:
// 1. Initialize prev as the value of the last house (nums[n-1]).
// 2. Initialize next as 0, representing the value after considering skipping the last house.
// 3. Initialize curr as 0, which will store the maximum amount that can be robbed.
// 4. Iterate backwards from n-2 to 0:
//    a. Calculate tempAns as next if i+2 is within bounds, else 0.
//    b. Calculate include = nums[i] + tempAns, which includes robbing current house i.
//    c. Calculate exclude = prev, which excludes robbing current house i.
//    d. Update curr as the maximum of include and exclude.
//    e. Update next to prev (move forward in the array).
//    f. Update prev to curr (move forward in the array).
// 5. Return prev, which contains the maximum amount that can be robbed starting from the first house.

int solveUsingSO(vector<int> &nums)
{
    int n = nums.size();
    int prev = nums[n - 1];
    int next = 0;
    int curr = 0;
    for (int i = n - 2; i >= 0; i--)
    {
        int tempAns = 0;
        if (i + 2 < n)
        {
            tempAns = next;
        }
        int include = nums[i] + tempAns;
        int exclude = 0 + prev;
        curr = max(include, exclude);
        next = prev;
        prev = curr;
    }
    return prev;
}
int rob(vector<int> &nums)
{
    int ans = solveUsingSO(nums);
    return ans;
}