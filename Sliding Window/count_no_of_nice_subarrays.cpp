#include<iostream>
using namespace std;

// COUNT NUMBER OF NICE SUBARRAYS (LEETCODE 1248)
// USING VARIABLE SIZE WINDOW - TC=O(4N), SC=O(1)

// Steps:
// 1. Modify the `solve` function to count subarrays with at most `k` odd numbers.
//    - Increment `sum` by `nums[r] % 2` (1 if odd, 0 if even) for each element in the array.
//    - If `sum > k`, shrink the window from the left by subtracting `nums[l] % 2` and moving `l`.
//    - Count valid subarrays in the current window using `(r - l + 1)` and update `count`.
// 2. In `numberOfSubarrays`, compute the exact number of subarrays with `k` odd numbers using the difference:
//    - `solve(nums, k)` - `solve(nums, k - 1)`.
// 3. Return the result.

int solve(vector<int> &nums, int k)
{
    if (k < 0)
        return 0;
    int l = 0, r = 0, sum = 0, count = 0;
    while (r < nums.size())
    {
        sum += nums[r] % 2;
        while (sum > k)
        {
            sum -= nums[l] % 2;
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}
int numberOfSubarrays(vector<int> &nums, int k)
{
    return solve(nums, k) - solve(nums, k - 1);
}