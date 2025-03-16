#include<iostream>
using namespace std;

// LONGEST ARITHMETIC SUBSEQUENCE OF GIVEN DIFFERENCE (LEETCODE 1218)
// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize `dp`, a hashmap where `dp[x]` stores the length of the longest subsequence ending with element `x` that has a difference of `difference` between consecutive elements.
// 2. Iterate over each element `arr[i]` in the array:
//      - Calculate `temp` as `arr[i] - difference`, representing the previous element needed to maintain the difference.
//      - If `temp` exists in `dp`, set `tempAns` as `dp[temp]` to extend that subsequence by 1; otherwise, initialize `tempAns` to 0.
//      - Set `dp[arr[i]] = 1 + tempAns` to update the subsequence length ending at `arr[i]`.
//      - Update `ans` with the maximum length found in `dp[arr[i]]`.
// 3. Return `ans` as the length of the longest arithmetic subsequence with the given difference.

int longestSubsequence(vector<int> &arr, int difference)
{
    int ans = 0;
    unordered_map<int, int> dp;
    for (int i = 0; i < arr.size(); i++)
    {
        int temp = arr[i] - difference;
        int tempAns = 0;
        if (dp.count(temp))
        {
            tempAns = dp[temp];
        }
        dp[arr[i]] = 1 + tempAns;
        ans = max(ans, dp[arr[i]]);
    }
    return ans;
}