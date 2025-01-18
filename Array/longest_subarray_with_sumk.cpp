#include<iostream>
using namespace std;

// LONGEST SUBARRAY WITH SUM K
// USING PREFIX SUM AND UNORDERED MAP - TC=O(N), SC=O(N)

// Steps:
// 1. Use a hash map (`prefixSum`) to store the first occurrence of each prefix sum.
// 2. Traverse the array while maintaining a running sum (`sum`).
// 3. If the running sum equals `k`, update `maxLen` to the current index + 1.
// 4. Calculate the remaining sum (`rem = sum - k`). If `rem` exists in the hash map, compute the subarray length and update `maxLen` if the length is larger.
// 5. Store the current prefix sum in the hash map if it doesn't already exist.
// 6. Return `maxLen` as the result.

int getLongestSubarray(vector<int> &nums, int k)
{
    unordered_map<int, int> prefixSum;
    int sum = 0;
    int maxLen = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
        if (sum == k)
        {
            maxLen = max(maxLen, i + 1);
        }
        int rem = sum - k;
        if (prefixSum.find(rem) != prefixSum.end())
        {
            int len = i - prefixSum[rem];
            maxLen = max(maxLen, len);
        }
        if (prefixSum.find(sum) == prefixSum.end())
        {
            prefixSum[sum] = i;
        }
    }
    return maxLen;
}