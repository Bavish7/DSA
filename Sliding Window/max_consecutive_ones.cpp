#include<iostream>
using namespace std;

// MAX CONSECUTIVE ONES III (LEETCODE 1004)
// USING VARIABLE SIZE WINDOW - TC=O(2N), SC=O(1)

// Steps:
// 1. Initialize `l` (left pointer), `r` (right pointer), `len` (current window length), and `maxLen` (maximum length of valid window) to track the sliding window.
// 2. Traverse the array with the right pointer `r`:
//    - If `nums[r] == 0`, decrement `k` (remaining flips allowed).
//    - When `k < 0` (too many zeros in the window), shrink the window by incrementing `l`. If `nums[l] == 0`, increment `k` to restore balance.
// 3. Update `len` as `r - l + 1` and track the maximum length using `maxLen`.
// 4. Return `maxLen` as the length of the longest subarray with at most `k` zero flips.

int longestOnes(vector<int> &nums, int k)
{
    int len = 0, maxLen = 0;
    int l = 0, r = 0;
    while (r < nums.size())
    {
        if (nums[r] == 0)
        {
            k--;
            while (k < 0)
            {
                if (nums[l] == 0)
                {
                    k++;
                }
                l++;
            }
        }
        len = r - l + 1;
        maxLen = max(maxLen, len);
        r++;
    }
    return maxLen;
}

// USING VARIABLE SIZE WINDOW - TC=O(N), SC=O(1)
// Steps:
// 1. Initialize `l` (left pointer), `r` (right pointer), `len` (current window length), `maxLen` (maximum valid length), and `zeroes` (number of zeros in the current window).
// 2. Traverse the array with the right pointer `r`:
//    - Increment `zeroes` if `nums[r] == 0`.
//    - If `zeroes > k` (too many zeros to flip), increment the left pointer `l` until the window becomes valid (`zeroes <= k`). Decrement `zeroes` when sliding past a zero.
// 3. For valid windows (`zeroes <= k`), calculate the window size as `r - l + 1` and update `maxLen`.
// 4. Return `maxLen` as the length of the longest subarray with at most `k` zero flips.

int longestOnes(vector<int> &nums, int k)
{
    int len = 0, maxLen = 0;
    int l = 0, r = 0, zeroes = 0;
    while (r < nums.size())
    {
        if (nums[r] == 0)
        {
            zeroes++;
        }
        if (zeroes > k)
        {
            if (nums[l] == 0)
            {
                zeroes--;
            }
            l++;
        }
        if (zeroes <= k)
        {
            len = r - l + 1;
            maxLen = max(maxLen, len);
        }
        r++;
    }
    return maxLen;
}