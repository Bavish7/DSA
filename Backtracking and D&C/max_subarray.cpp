#include<iostream>
using namespace std;

// MAX SUBARRAY (LEETCODE 53)
// USING DIVIDE AND CONQUER APPROACH - TC=O(N*LOGN), SC=O(LOGN)

// Steps:
// 1. Base case: If the subarray has only one element (start == end), return that element as the max sum.
// 2. Calculate the midpoint (mid) of the current subarray.
// 3. Recursively find the maximum subarray sum in the left half (start to mid) and in the right half (mid+1 to end).
// 4. Calculate the maximum subarray sum that crosses the midpoint:
//    a. Start from the midpoint and move left to find the maximum left border sum.
//    b. Start from the midpoint+1 and move right to find the maximum right border sum.
//    c. The cross-border sum is the sum of maxLeftBorderSum and maxRightBorderSum.
// 5. The result is the maximum of the left half, right half, and the cross-border sum.
// 6. Return the maximum sum for the current subarray.

int maxArrayHelper(vector<int> &nums, int start, int end)
{
    if (start == end)
    {
        return nums[start];
    }
    int maxLeftBorderSum = INT_MIN, maxRightBorderSum = INT_MIN;
    int mid = (start + end) / 2;
    int maxLeftSum = maxArrayHelper(nums, start, mid);
    int maxRightSum = maxArrayHelper(nums, mid + 1, end);
    int leftBorderSum = 0, rightBorderSum = 0;
    for (int i = mid; i >= start; i--)
    {
        leftBorderSum += nums[i];
        if (leftBorderSum > maxLeftBorderSum)
        {
            maxLeftBorderSum = leftBorderSum;
        }
    }
    for (int i = mid + 1; i <= end; i++)
    {
        rightBorderSum += nums[i];
        if (rightBorderSum > maxRightBorderSum)
        {
            maxRightBorderSum = rightBorderSum;
        }
    }
    int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
    return max(crossBorderSum, max(maxLeftSum, maxRightSum));
}
int maxSubArray(vector<int> &nums)
{
    return maxArrayHelper(nums, 0, nums.size() - 1);
}

// USING KADANE'S ALGORITHM - TC=O(N), SC=O(1)
// Steps:
// 1. Initialize `maxi` to the smallest possible integer (`INT_MIN`) to keep track of the maximum sum.
// 2. Use a variable `sum` to store the current sum of the subarray being evaluated.
// 3. Traverse the array:
//    - Add the current element to `sum`.
//    - Update `maxi` if `sum` exceeds the current `maxi`.
//    - If `sum` becomes negative, reset it to 0 (start a new subarray).
// 4. Return `maxi` as the result.

int maxSubArray(vector<int> &nums)
{
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum > maxi)
        {
            maxi = sum;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }
    return maxi;
}