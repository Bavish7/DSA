#include<iostream>
using namespace std;

// DECODE WAYS (LEETCODE 91)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N), SC=O(N)

// Steps:
// 1. Define a recursive function `solveUsingMem` with memoization to count decoding ways starting from `index`.
// 2. Base case: If `index` reaches the end of the string, return 1 (valid decoding).
// 3. If the current character is '0', return 0 (invalid encoding).
// 4. If the result for `index` is already computed (stored in `dp`), return it.
// 5. Recur for the next character (`index + 1`) to decode it individually.
// 6. If the next character forms a valid two-digit number (10-26), also recurse for `index + 2`.
// 7. Store the computed result in `dp[index]` to avoid redundant calculations.
// 8. In `numDecodings`, initialize `dp` with `-1` and call `solveUsingMem` starting from index `0`.

int solveUsingMem(string &s, int index, vector<int> &dp)
{
    if (index == s.length())
    {
        return 1;
    }
    if (s[index] == '0')
    {
        return 0;
    }
    if (dp[index] != -1)
        return dp[index];
    int ways = solveUsingMem(s, index + 1, dp);
    if (index + 1 < s.length() && (s[index] == '1' || (s[index] == '2' && s[index + 1] <= '6')))
    {
        ways += solveUsingMem(s, index + 2, dp);
    }
    return dp[index] = ways;
}
int numDecodings(string s)
{
    int n = s.length();
    vector<int> dp(n, -1);
    return solveUsingMem(s, 0, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N), SC=O(N)
// Steps:
// 1. Initialize a DP array `dp` of size `n+1` where `dp[i]` stores the number of ways to decode the substring starting from index `i`.
// 2. Set `dp[n] = 1` as the base case (empty string has one valid decoding).
// 3. Iterate from the end of the string (`n-1` to `0`):
//    - If `s[i]` is '0', set `dp[i] = 0` (invalid decoding).
//    - Otherwise, set `dp[i] = dp[i+1]` (consider single-character decoding).
//    - If `s[i]` forms a valid two-digit number (10-26) with `s[i+1]`, add `dp[i+2]` to `dp[i]`.
// 4. Return `dp[0]`, which stores the total number of decodings for the entire string.

int solveUsingTab(string s)
{
    int n = s.length();
    vector<int> dp(n + 1, 0);
    dp[n] = 1;
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == '0')
        {
            dp[i] = 0;
        }
        else
        {
            dp[i] = dp[i + 1];
            if (i + 1 < n && (s[i] == '1' || (s[i] == '2' && s[i + 1] <= '6')))
            {
                dp[i] += dp[i + 2];
            }
        }
    }
    return dp[0];
}
int numDecodings(string s)
{
    return solveUsingTab(s);
}

