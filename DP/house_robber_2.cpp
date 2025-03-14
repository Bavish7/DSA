#include<iostream>
using namespace std;

// HOUSE ROBBER II (LEETCODE 213)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N), SC=O(N)

// Steps:
// 1. Define a recursive function `solveUsingMem` that takes the current index, size of the `nums` array, a memoization array `dp`, and the `nums` array as parameters.
// 2. If the `index` is greater than or equal to `n`, return 0 (base case).
// 3. If `dp[index]` is not -1, return the cached value to avoid redundant calculations.
// 4. Calculate the maximum amount of money that can be robbed if the current house (index) is included:
//    - Include the current house: `nums[index] + solveUsingMem(index + 2, n, dp, nums)`.
// 5. Calculate the maximum amount if the current house is excluded: `solveUsingMem(index + 1, n, dp, nums)`.
// 6. Store the maximum of the two choices in `dp[index]`.
// 7. In the `rob` function:
//    - Handle the special case where the array has only one element.
//    - Create two separate DP arrays to represent two scenarios (robbing from the first house or the last house).
//    - Call the `solveUsingMem` function for both cases and return the maximum value.

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
    int n = nums.size();
    if (n == 1)
        return nums[0];
    vector<int> dp1(n, -1);
    int ans1 = solveUsingMem(0, n - 1, dp1, nums);
    vector<int> dp2(n, -1);
    int ans2 = solveUsingMem(1, n, dp2, nums);
    return max(ans1, ans2);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N), SC=O(N)
// Steps:
// 1. Define a helper function `solveUsingTab` that uses tabulation to solve the problem for a given range (`start` to `end`) within the `nums` array.
// 2. Initialize a DP array `dp` of size `n`, where `n` is the number of houses within the given range.
// 3. Set base cases by initializing `dp[n - 1]` to `nums[end]` (the last house in the range). If there are at least two houses, set `dp[n - 2]` as the maximum between `nums[end]` and `nums[end - 1]` (the last two houses).
// 4. Fill the DP array backwards. For each house at index `i` (from `n - 3` to `0`), calculate the maximum money by either including or excluding the house. To include the house, add `nums[start + i]` to `dp[i + 2]`. To exclude it, take `dp[i + 1]`. Set `dp[i]` to the maximum of the two values.
// 5. Return `dp[0]` as it holds the maximum money that can be robbed from the given range.
// 6. In the main function `rob`, handle edge cases where the `nums` array is empty by returning 0, and where it has only one house by returning `nums[0]`.
// 7. For the general case, call `solveUsingTab` twice: once for houses excluding the last house (`0` to `n - 2`) and once excluding the first house (`1` to `n - 1`).
// 8. Return the maximum of the two results.

int solveUsingTab(vector<int> &nums, int start, int end)
{
    int n = end - start + 1;
    vector<int> dp(n, 0);
    dp[n - 1] = nums[end];
    if (n > 1)
    {
        dp[n - 2] = max(nums[end], nums[end - 1]);
    }
    for (int i = n - 3; i >= 0; --i)
    {
        int include = nums[start + i] + dp[i + 2];
        int exclude = dp[i + 1];
        dp[i] = max(include, exclude);
    }
    return dp[0];
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    int ans1 = solveUsingTab(nums, 0, n - 2);
    int ans2 = solveUsingTab(nums, 1, n - 1);
    return max(ans1, ans2);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N), SC=O(1)
// Steps:
// 1. Define a helper function `solveUsingSpaceOpt` that uses space optimization to solve the problem for a given range (`start` to `end`) within the `nums` array.
// 2. Initialize two variables, `prev2` and `prev1`, to store results of the last two states. Set `prev2` to 0 and `prev1` to `nums[end]`, representing the maximum amount robable when starting from the last house.
// 3. Iterate backwards through the houses in the range from `end - 1` to `start`.
// 4. For each house, calculate the maximum money by either including or excluding the current house:
//    - To include, add `nums[i]` to `prev2`.
//    - To exclude, take `prev1`.
//    - Update `prev2` and `prev1` for the next iteration.
// 5. After finishing the loop, `prev1` holds the maximum robable amount for the given range.
// 6. In the main function `rob`, handle cases for empty `nums` array by returning 0 and single-house array by returning `nums[0]`.
// 7. For the general case, call `solveUsingSpaceOpt` twice: once for houses excluding the last house (`0` to `n - 2`) and once excluding the first house (`1` to `n - 1`).
// 8. Return the maximum of the two results.

int solveUsingSO(vector<int> &nums, int start, int end)
{
    int prev2 = 0;
    int prev1 = nums[end];
    for (int i = end - 1; i >= start; i--)
    {
        int include = nums[i] + prev2;
        int exclude = prev1;
        int curr = max(include, exclude);
        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int rob(vector<int> &nums)
{
    int n = nums.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return nums[0];
    int case1 = solveUsingSO(nums, 0, n - 2);
    int case2 = solveUsingSO(nums, 1, n - 1);
    return max(case1, case2);
}