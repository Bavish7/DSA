#include<iostream>
using namespace std;

// LONGEST NICE SUBARRAY (LEETCODE 2401)
// USING SLIDING WINDOW AND BIT MANIPULATION - TC=O(N), SC=O(1)

// Steps:
// 1. Use a sliding window approach with two pointers `i` and `j`.
// 2. Maintain a bitwise OR `ans` of the current subarray.
// 3. Expand `j` while ensuring all numbers have unique bits (`(ans & nums[j]) == 0`).
// 4. If a conflict arises (`(ans & nums[j]) != 0`), shrink the window from `i` by removing `nums[i]` using XOR.
// 5. Update `maxLen` to store the longest valid subarray length.
// 6. Continue until `j` reaches the end.

int longestNiceSubarray(vector<int> &nums)
{
    int n = nums.size();
    int i = 0, j = i + 1;
    int ans = nums[0], maxLen = 1;
    while (j < n)
    {
        while ((ans & nums[j]) != 0)
        {
            ans = ans ^ nums[i];
            i++;
        }
        ans = ans | nums[j];
        maxLen = max(maxLen, j - i + 1);
        j++;
    }
    return maxLen;
}