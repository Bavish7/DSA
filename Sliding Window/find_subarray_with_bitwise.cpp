#include<iostream>
using namespace std;

// FIND SUBARRAY WITH BITWISE OR CLOSEST TO K (LEETCODE 3171)
// USING SLIDING WINDOW AND BIT MANIPULATION - TC=O(N), SC=O(1)

// Steps:
// 1. Maintain a sliding window [left, right] and a frequency array bitsFreq[32] to track bit counts.
// 2. For each right index, call update() with operation=1 to add nums[right]'s bits to bitsFreq.
// 3. `update()` recomputes the OR of all bits currently in the window using bitsFreq.
// 4. Track minDiff = min(minDiff, |curr - k|).
// 5. If OR value > k, shrink the window from the left using update() with operation=-1.
// 6. If OR == k, return 0 immediately (minimum possible difference).
// 7. Repeat until the window reaches the end of the array.

int update(int num, int operation, vector<int> &bitsFreq)
{
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        if ((num >> i) & 1)
        {
            bitsFreq[i] += operation;
        }
        if (bitsFreq[i])
            ans |= (1 << i);
    }
    return ans;
}
int minimumDifference(vector<int> &nums, int k)
{
    int n = nums.size(), minDiff = INT_MAX;
    vector<int> bitsFreq(32, 0);
    int left = 0, right = 0;
    while (right < n)
    {
        int curr = update(nums[right], 1, bitsFreq);
        minDiff = min(minDiff, abs(curr - k));
        if (curr < k)
        {
            right++;
        }
        else if (curr > k)
        {
            while (left < right && curr > k)
            {
                curr = update(nums[left], -1, bitsFreq);
                minDiff = min(minDiff, abs(curr - k));
                left++;
            }
            right++;
        }
        else
        {
            return 0;
        }
    }
    return minDiff;
}