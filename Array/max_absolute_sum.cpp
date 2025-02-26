#include<iostream>
using namespace std;

// MAXIMUM ABSOLUTE SUM OF ANY SUBARRAY (LEETCODE 1749)
// USING KADANE'S ALGORITHM - TC=O(N), SC=O(1)

// Steps:
// 1. Find the maximum subarray sum using Kadane’s algorithm (`maxSubSum`).
// 2. Find the minimum subarray sum using a modified Kadane’s algorithm (`minSubSum`).
// 3. The absolute max subarray sum is the maximum of `maxSubSum` and the absolute value of `minSubSum`.

int maxSubSum(vector<int> &nums)
{
    int currSum = nums[0];
    int maxSum = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        currSum = max(nums[i], currSum + nums[i]);
        maxSum = max(maxSum, currSum);
    }
    return maxSum;
}
int minSubSum(vector<int> &nums)
{
    int currSum = nums[0];
    int minSum = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        currSum = min(nums[i], currSum + nums[i]);
        minSum = min(minSum, currSum);
    }
    return minSum;
}
int maxAbsoluteSum(vector<int> &nums)
{
    int ans = INT_MIN;
    int maxSum = maxSubSum(nums);
    int minSum = minSubSum(nums);
    ans = max(maxSum, abs(minSum));
    return ans;
}