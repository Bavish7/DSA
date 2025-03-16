#include<iostream>
using namespace std;

// LONGEST ARITHMETIC SUBSEQUENCE (LEETCODE 1027)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(N^2) - TLE

// Steps:
// 1. Initialize an array of hashmaps `dp[]` to store the length of the longest arithmetic subsequence
//    ending at each index with a given difference `diff`.
// 2. Define the recursive function `solve(index, diff)` to find the maximum length of the arithmetic subsequence ending at `index` with the given difference `diff`.
//      - Base case: If `index` is out of bounds (< 0), return 0.
//      - Memoization: If `dp[index][diff]` already contains a value, return it to avoid recomputation.
// 3. For each `j` from `index-1` to 0, check if `nums[index] - nums[j] == diff`:
//      - If true, calculate `1 + solve(j, diff)` to include this pair in the sequence.
//      - Track the maximum length obtained and store it in `dp[index][diff]`.
// 4. In the main function, iterate over all pairs `(i, j)` in `nums` where `j > i`.
//      - Calculate `diff = nums[j] - nums[i]` and get the maximum length of the sequence
//        ending at `j` with `diff` by calling `solve(i, diff)`.
//      - Update `ans` with `2 + solve(i, diff)` for each pair since a sequence of length 2 starts with `(i, j)`.
// 5. Return `ans` as the final result, representing the longest arithmetic subsequence length.

int solve(int index, int diff, vector<int> &nums, unordered_map<int, int> dp[])
{
    if (index < 0)
    {
        return 0;
    }
    if (dp[index].count(diff))
    {
        return dp[index][diff];
    }
    int len = 0;
    for (int j = index - 1; j >= 0; j--)
    {
        if (nums[index] - nums[j] == diff)
        {
            len = max(len, 1 + solve(j, diff, nums, dp));
        }
    }
    dp[index][diff] = len;
    return dp[index][diff];
}
int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 2)
    {
        return n;
    }
    unordered_map<int, int> dp[n + 1];
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ans = max(ans, 2 + solve(i, nums[j] - nums[i], nums, dp));
        }
    }
    return ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^2), SC=O(N^2)
// Steps:
// 1. Initialize an array of hashmaps `dp[]`, where `dp[i][diff]` holds the length of the longest arithmetic subsequence ending at index `i` with difference `diff`.
// 2. Set `maxLen` to 2, as the minimum length of any arithmetic subsequence with two elements is 2.
// 3. For each element `i` starting from the second position:
//      - For each previous element `j`, calculate the difference `diff = nums[i] - nums[j]`.
//      - Check if `dp[j]` already contains `diff`:
//          - If yes, set `dp[i][diff]` to `dp[j][diff] + 1` to extend the sequence ending at `j`.
//          - If no, initialize `dp[i][diff]` to 2, as `(j, i)` forms a new arithmetic subsequence.
//      - Update `maxLen` with the maximum length found for any `dp[i][diff]`.
// 4. Return `maxLen` as the longest arithmetic subsequence length.

int longestArithSeqLength(vector<int> &nums)
{
    int n = nums.size();
    if (n <= 2)
    {
        return n;
    }
    unordered_map<int, int> dp[n + 1];
    int maxLen = 2;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            int diff = nums[i] - nums[j];
            if (dp[j].count(diff))
            {
                dp[i][diff] = dp[j][diff] + 1;
            }
            else
            {
                dp[i][diff] = 2;
            }
            maxLen = max(maxLen, dp[i][diff]);
        }
    }
    return maxLen;
}