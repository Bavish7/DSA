#include<iostream>
using namespace std;

// SHORTEST SUBARRAY WITH OR AT LEAST K II (LEETCODE 3097)
// USING SLIDING WINDOW AND BIT MANIPULATION - TC=O(N), SC=O(1)

// Steps:
// 1. Maintain a sliding window [left, right] and a bit frequency array `bitsFreq`.
// 2. Expand right → add nums[right]’s bits into `bitsFreq`.
// 3. After each expansion, compute current OR using `getNumber(bitsFreq)`.
// 4. While OR ≥ k, shrink from left:
//    - Update minLen with window size.
//    - Remove nums[left]’s bits from `bitsFreq`, then move left.
// 5. Continue until right reaches end.
// 6. Return minLen if found, else -1.

void updateWindow(int num, vector<int> &freq, int val)
{
    for (int i = 0; i < 32; i++)
    {
        if ((num >> i) & 1)
        {
            freq[i] += val;
        }
    }
}
int getNumber(vector<int> &freq)
{
    int ans = 0;
    for (int i = 0; i < 32; i++)
    {
        if (freq[i] > 0)
        {
            ans |= (1 << i);
        }
    }
    return ans;
}
int minimumSubarrayLength(vector<int> &nums, int k)
{
    int n = nums.size();
    int minLen = INT_MAX;
    int left = 0, right = 0;
    vector<int> bitsFreq(32, 0);
    while (right < n)
    {
        updateWindow(nums[right], bitsFreq, 1);
        while (left <= right && getNumber(bitsFreq) >= k)
        {
            minLen = min(minLen, right - left + 1);
            updateWindow(nums[left], bitsFreq, -1);
            left++;
        }
        right++;
    }
    return minLen == INT_MAX ? -1 : minLen;
}