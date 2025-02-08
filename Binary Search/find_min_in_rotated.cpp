#include<iostream>
using namespace std;

// FIND MINIMUM IN ROTATED SORTED ARRAY (LEETCODE 153)
// USING BINARY SEARCH - TC=O(LOGN), SC=O(1)

// Steps:
// 1. Initialize `start` to 0, `end` to the last index of the array, and `ans` to INT_MAX.
// 2. Use a loop while `start <= end` to perform binary search:
//    - Calculate `mid` as the middle index.
//    - If the left half (`nums[start]` to `nums[mid]`) is sorted:
//        - Update `ans` with the smaller value between `ans` and `nums[start]`.
//        - Move `start` to `mid + 1` to search the unsorted half.
//    - If the right half (`nums[mid]` to `nums[end]`) is sorted:
//        - Update `ans` with the smaller value between `ans` and `nums[mid]`.
//        - Move `end` to `mid - 1` to search the unsorted half.
// 3. Return `ans` after the loop ends, as it holds the minimum value.

int findMin(vector<int> &nums)
{
    int start = 0, end = nums.size() - 1;
    int ans = INT_MAX;
    while (start <= end)
    {
        int mid = (start + end) / 2;
        if (nums[start] <= nums[mid])
        {
            ans = min(ans, nums[start]);
            start = mid + 1;
        }
        else if (nums[mid] <= nums[end])
        {
            ans = min(ans, nums[mid]);
            end = mid - 1;
        }
    }
    return ans;
}