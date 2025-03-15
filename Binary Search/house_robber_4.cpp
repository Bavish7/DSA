#include<iostream>
using namespace std;

// HOUSE ROBBER IV (LEETCODE 2560)
// USING BINARY SEARCH ON ANSWER - TC=O(N*LOG(MAX)), SC=O(1)

// Steps:
// 1. `isCapable` function checks if `k` elements can be selected such that no two are adjacent and all are ≤ `mid`:
//    - Iterate through `nums`, selecting elements ≤ `mid` while skipping the next index.
//    - If at least `k` elements are selected, return true; otherwise, return false.
// 2. `minCapability` finds the minimum possible maximum element among the chosen `k` elements:
//    - Initialize `left` as the smallest element and `right` as the largest element in `nums`.
//    - Perform binary search on `mid`, representing the possible maximum element in a valid selection.
//    - If `isCapable` returns true for `mid`, update `ans` and search for a smaller valid `mid`.
//    - Otherwise, increase `left` to find a feasible `mid`.
//    - Return `ans`, the minimum possible maximum element among `k` chosen elements.

bool isCapable(vector<int> &nums, int k, int mid)
{
    int count = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] <= mid)
        {
            count++;
            i++;
        }
    }
    return count >= k;
}
int minCapability(vector<int> &nums, int k)
{
    int n = nums.size();
    int left = INT_MAX, right = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] < left)
            left = nums[i];
        if (nums[i] > right)
            right = nums[i];
    }
    int ans = right;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (isCapable(nums, k, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}