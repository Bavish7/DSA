#include<iostream>
using namespace std;

// FIND THE SMALLEST DIVISOR GIVEN A THRESHOLD (LEETCODE 1283)
// USING FOR LOOP - TC=O(N*MAXI), SC=O(1) - TLE

// Steps:
// 1. Define `solve` to check if dividing all `nums[i]` by `div` (rounded up) keeps the sum ≤ `threshold`.
// 2. Find the maximum element `maxi` in `nums` as the largest possible divisor.
// 3. Iterate from 1 to `maxi` and return the smallest divisor for which `solve` returns true.
// 4. If no valid divisor is found, return -1 (though this won't occur for valid inputs).

bool solve(vector<int> &nums, int div, int threshold)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += ceil((double)nums[i] / (double)div);
    }
    return sum <= threshold;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, nums[i]);
    }
    for (int i = 1; i <= maxi; i++)
    {
        if (solve(nums, i, threshold))
        {
            return i;
        }
    }
    return -1;
}

// USING BINARY SEARCH - TC=O(N*LOG(MAXI)), SC=O(1)
// Steps:
// 1. Define `solve` to check if dividing each `nums[i]` by `div` (rounded up) keeps the sum ≤ `threshold`.
// 2. Find the largest element `maxi` in `nums` to set the upper bound for binary search.
// 3. Perform binary search on possible divisors (1 to `maxi`):
//    - If `solve` returns true for `mid`, move the search to smaller divisors (`high = mid - 1`).
//    - Otherwise, move to larger divisors (`low = mid + 1`).
// 4. Return `low` as the smallest divisor that satisfies the condition.

bool solve(vector<int> &nums, int div, int threshold)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += ceil((double)nums[i] / (double)div);
    }
    return sum <= threshold;
}
int smallestDivisor(vector<int> &nums, int threshold)
{
    int n = nums.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, nums[i]);
    }
    int low = 1, high = maxi;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (solve(nums, mid, threshold))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}