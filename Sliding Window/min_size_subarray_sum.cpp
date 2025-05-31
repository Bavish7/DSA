#include<iostream>
using namespace std;

// MINIMUM SIZE SUBARRAY SUM (LEETCODE 209)
// USING VARIABLE SIZE WINDOW - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize two pointers, `start` and `end`, to the beginning of the array. Also, initialize `sum` to 0 and `ans` to a very large value.
// 2. Expand the window by moving the `end` pointer and adding `nums[end]` to `sum`.
// 3. While the `sum` is greater than or equal to the `target`, update `ans` with the minimum length of the window and shrink the window from the left by moving the `start` pointer and subtracting `nums[start]` from `sum`.
// 4. Continue expanding and contracting the window until the `end` pointer reaches the end of the array.
// 5. If `ans` remains unchanged from its initial value, it means no valid subarray was found, so return 0. Otherwise, return the minimum length found.

int minSubArrayLen(int target, vector<int> &nums)
{
    int start = 0;
    int end = 0;
    int n = nums.size();
    int ans = INT_MAX;
    int sum = 0;
    while (end < n)
    {
        sum = sum + nums[end];
        while (sum >= target)
        {
            ans = min(ans, end - start + 1);
            sum = sum - nums[start];
            start++;
        }
        end++;
    }
    if (ans == INT_MAX)
    {
        return 0;
    }
    else
    {
        return ans;
    }
}