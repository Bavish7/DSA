#include<iostream>
using namespace std;

// MAXIMUM XOR FOR EACH QUERY (LEETCODE 1829)
// USING BIT MANIPULATION AND PREFIX XOR - TC=O(N), SC=O(N)

// Steps:
// 1. Compute XOR of all elements (totalXor).
// 2. Prepare mask = (1 << maximumBit) - 1 (ensures result ≤ max possible k).
// 3. For each query (in reverse order):
//    - Find k = totalXor ^ mask (maximizes XOR result).
//    - Store k in ans[i].
//    - Remove last element’s contribution: totalXor ^= nums[n-i-1].
// 4. Return ans.

vector<int> getMaximumXor(vector<int> &nums, int maximumBit)
{
    int n = nums.size();
    vector<int> ans(n);
    int totalXor = 0;
    for (int i = 0; i < n; i++)
    {
        totalXor ^= nums[i];
    }
    int mask = (1 << maximumBit) - 1;
    for (int i = 0; i < n; i++)
    {
        int k = totalXor ^ mask;
        ans[i] = k;
        totalXor ^= nums[n - i - 1];
    }
    return ans;
}