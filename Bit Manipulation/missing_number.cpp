#include<iostream>
using namespace std;

// MISSING NUMBER (LEETCODE 268)
// USING FOR LOOP - TC=O(N), SC=O(N)
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n + 1, -1);
    for (int i = 0; i < n; i++)
    {
        ans[nums[i]] = nums[i];
    }
    for (int i = 0; i <= n; i++)
    {
        if (ans[i] == -1)
        {
            return i;
        }
    }
    return -1;
}

// USING XOR - TC=O(N), SC=O(1)
int missingNumber(vector<int> &nums)
{
    int n = nums.size();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans ^= nums[i];
    }
    for (int i = 0; i <= n; i++)
    {
        ans ^= i;
    }
    return ans;
}