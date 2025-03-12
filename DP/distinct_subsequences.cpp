#include<iostream>
using namespace std;

// DISTINCT SUBSEQUENCES (LEETCODE 115)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. Define a recursive function `solveUsingMem` that takes strings `s`, `t`, indices `i` and `j`, and a DP table `dp`.
// 2. Check the base case: if `j` equals the length of `t`, return 1 (indicating a valid subsequence found).
// 3. Check the base case: if `i` equals the length of `s`, return 0 (no more characters left in `s`).
// 4. If the value in `dp[i][j]` is not -1, return the stored value (memoization).
// 5. Initialize `ans` to 0.
// 6. If the current characters match (`s[i] == t[j]`), add the result of moving to the next characters in both strings (`i+1`, `j+1`) to `ans`.
// 7. Regardless of the match, call the function recursively to skip the current character in `s` (`i+1`) while keeping `j` the same, and add this result to `ans`.
// 8. Store the computed `ans` in `dp[i][j]` for future reference.
// 9. Return `dp[i][j]` which represents the number of distinct subsequences of `t` in `s`.

int solveUsingMem(string &s, string &t, int i, int j, vector<vector<int>> &dp)
{
    if (j == t.size())
    {
        return 1;
    }
    if (i == s.size())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = 0;
    if (s[i] == t[j])
    {
        ans += solveUsingMem(s, t, i + 1, j + 1, dp);
    }
    ans += solveUsingMem(s, t, i + 1, j, dp);
    dp[i][j] = ans;
    return dp[i][j];
}
int numDistinct(string s, string t)
{
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return solveUsingMem(s, t, 0, 0, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(M*N), SC=O(M*N)
// Steps:
// 1. Define the function `solveUsingTab` that takes strings `s` and `t` as input.
// 2. Initialize variables `m` and `n` as the lengths of `s` and `t`, respectively.
// 3. Create a DP table `dp` of size (m+1) x (n+1) initialized to 0.
// 4. Fill the base case: set `dp[i][n]` to 1 for all `i` (indicating that an empty `t` can always be formed from `s`).
// 5. Iterate backwards through `s` (from `m-1` to `0`) and `t` (from `n-1` to `0`):
//    - Initialize `ans` to 0 for each pair of indices `i` and `j`.
//    - If `s[i]` matches `t[j]`, add `dp[i+1][j+1]` to `ans` (counting the subsequences with this matching character).
//    - Always add `dp[i+1][j]` to `ans` (counting subsequences without using `s[i]`).
// 6. Store the computed `ans` in `dp[i][j]`.
// 7. The result of distinct subsequences of `t` in `s` will be found in `dp[0][0]`.
// 8. Return `dp[0][0]` as the final result of the `numDistinct` function.

int solveUsingTab(string &s, string &t)
{
    int m = s.size(), n = t.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i <= m; i++)
    {
        dp[i][n] = 1;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            long long ans = 0;
            if (s[i] == t[j])
            {
                ans += dp[i + 1][j + 1];
            }
            ans += dp[i + 1][j];
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int numDistinct(string s, string t)
{
    return solveUsingTab(s, t);
}

// SPACE OPTIMIZATION APPROACH - TC=O(M*N), SC=O(N)
// Steps:
// 1. Define the function `solveUsingSO` that takes two strings, `s` and `t`.
// 2. Initialize `m` and `n` as the lengths of `s` and `t`, respectively.
// 3. Create two vectors `curr` and `next` of size (n+1), initialized to 0, to store the number of distinct subsequences.
// 4. Set `next[n]` and `curr[n]` to 1, as there is one way to match an empty string `t` with any prefix of `s`.
// 5. Iterate backwards through the characters of `s` (from `m-1` to `0`):
//    - For each character in `s`, iterate backwards through `t` (from `n-1` to `0`):
//      - Initialize `ans` to 0 for the current indices `i` and `j`.
//      - If `s[i]` matches `t[j]`, add `next[j+1]` to `ans` (counting subsequences that include this character).
//      - Always add `next[j]` to `ans` (counting subsequences that do not include `s[i]`).
//      - Store the computed `ans` in `curr[j]`.
// 6. After processing all characters in `s`, update `next` to be the same as `curr` for the next iteration.
// 7. The result of distinct subsequences of `t` in `s` will be found in `next[0]`.
// 8. Return `next[0]` as the final result of the `numDistinct` function.

int solveUsingSO(string &s, string &t)
{
    int m = s.size(), n = t.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    next[n] = curr[n] = 1;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            long long ans = 0;
            if (s[i] == t[j])
            {
                ans += next[j + 1];
            }
            ans += next[j];
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}
int numDistinct(string s, string t)
{
    return solveUsingSO(s, t);
}
