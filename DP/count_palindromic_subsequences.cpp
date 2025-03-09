#include<iostream>
using namespace std;

// COUNT PALINDROMIC SUBSEQUENCES
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(N^2)

// Steps:
// 1. Use memoization to count distinct palindromic subsequences in a given string.
// 2. If i == j, a single-character palindrome is counted.
// 3. If characters at i and j are equal, count palindromic subsequences within (i+1, j) and (i, j-1), adding 1 for the new palindrome formed.
// 4. If characters at i and j are different, subtract overlapping subsequences from (i+1, j-1).
// 5. Use modulo (1e9 + 7) to handle large results.

int mod = 1e9 + 7;
int solveUsingMem(string &s, vector<vector<int>> &dp, int i, int j)
{
    if (i == j)
        return 1;
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == s[j])
    {
        dp[i][j] = (1 + solveUsingMem(s, dp, i + 1, j) + solveUsingMem(s, dp, i, j - 1)) % mod;
    }
    else
    {
        dp[i][j] = ((solveUsingMem(s, dp, i + 1, j) + solveUsingMem(s, dp, i, j - 1) - solveUsingMem(s, dp, i + 1, j - 1)) % mod + mod) % mod;
    }
    return dp[i][j];
}
int countPalindromicSubsequences(string &s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solveUsingMem(s, dp, 0, n - 1);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^2), SC=O(N^2)
// Steps:
// 1. Use bottom-up DP to count distinct palindromic subsequences in a string.
// 2. Initialize a 2D DP table where dp[i][j] stores the count of palindromic subsequences in substring s[i...j].
// 3. Single-character substrings are palindromes, so dp[i][i] = 1.
// 4. If s[i] == s[j], count subsequences from (i+1, j) and (i, j-1) and add 1 for the new palindrome.
// 5. If s[i] != s[j], subtract overlapping subsequences from (i+1, j-1).
// 6. Use modulo (1e9 + 7) to handle large results.

int solveUsingTab(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                dp[i][j] = 1;
            if (s[i] == s[j])
            {
                dp[i][j] = (1 + dp[i + 1][j] + dp[i][j - 1]) % mod;
            }
            else
            {
                dp[i][j] = (dp[i + 1][j] + dp[i][j - 1] - dp[i + 1][j - 1] % mod + mod) % mod;
            }
        }
    }
    return dp[0][n - 1];
}
int countPalindromicSubsequences(string &s)
{
    return solveUsingTab(s);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N^2), SC=O(N)
// Steps:
// 1. Use space-optimized DP to count distinct palindromic subsequences in a string.
// 2. Maintain two 1D arrays: `curr` for the current row and `next` for the previous row.
// 3. Single-character substrings are palindromes, so `curr[i] = 1`.
// 4. If s[i] == s[j], count subsequences from `next[j]` and `curr[j-1]`, and add 1 for the new palindrome.
// 5. If s[i] != s[j], subtract overlapping subsequences from `next[j-1]`.
// 6. Use modulo (1e9 + 7) to handle large results.
// 7. Swap `next` and `curr` after processing each row to save space.

int solveUsingSO(string &s)
{
    int n = s.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if (i == j)
                curr[j] = 1;
            if (s[i] == s[j])
            {
                curr[j] = (1 + next[j] + curr[j - 1]) % mod;
            }
            else
            {
                curr[j] = (next[j] + curr[j - 1] - next[j - 1] % mod + mod) % mod;
            }
        }
        next = curr;
    }
    return next[n - 1];
}
int countPalindromicSubsequences(string &s)
{
    return solveUsingSO(s);
}