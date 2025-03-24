#include<iostream>
using namespace std;

// MINIMUM INSERTION STEPS TO MAKE A STRING PALINDROMIC (LEETCODE 1312)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(N^2)

// Steps:
// 1. Initialize two 1D vectors `curr` and `next` to store the current and next row of the dynamic programming table.
// 2. Traverse the strings `text1` and `text2` from the last characters towards the first (bottom-up approach).
// 3. If characters `text1[i]` and `text2[j]` match, set `curr[j] = 1 + next[j + 1]` (include the match).
//    Otherwise, set `curr[j] = max(curr[j + 1], next[j])` to store the best possible match.
// 4. After processing each row, update `next` to be equal to `curr`.
// 5. Return `curr[0]` as the length of the longest common subsequence (LCS) between `word1` and `word2`.
// 6. Use the formula `word1.size() + word2.size() - 2 * LCS` to compute the minimum number of operations required to convert `word1` to `word2`.

int solveUsingMem(string &text1, string &text2, int i, int j, vector<vector<int>> &dp)
{
    if (i >= text1.length())
    {
        return 0;
    }
    if (j >= text2.length())
    {
        return 0;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = 0;
    if (text1[i] == text2[j])
    {
        ans = 1 + solveUsingMem(text1, text2, i + 1, j + 1, dp);
    }
    else
    {
        ans = 0 + max(solveUsingMem(text1, text2, i + 1, j, dp), solveUsingMem(text1, text2, i, j + 1, dp));
    }
    dp[i][j] = ans;
    return dp[i][j];
}
int minInsertions(string s)
{
    string a = s;
    reverse(a.begin(), a.end());
    int i = 0;
    int j = 0;
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = solveUsingMem(s, a, i, j, dp);
    return n - ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^2), SC=O(N^2)
// Steps:
// 1. Reverse the string `s` to get `a`. The Longest Common Subsequence (LCS) of `s` and `a` represents the Longest Palindromic Subsequence (LPS) of `s`.
// 2. Use dynamic programming with a bottom-up approach to calculate the LCS of `s` and `a`.
// 3. Initialize a DP table `dp` where `dp[i][j]` represents the length of the LCS of substrings `s[0..i-1]` and `a[0..j-1]`.
// 4. For each pair of indices `(i, j)`:
//    - If `s[i] == a[j]`, increment the LCS length by 1 from `dp[i+1][j+1]`.
//    - If they don't match, take the maximum of the two options: `dp[i+1][j]` or `dp[i][j+1]`.
// 5. The LCS length gives the Longest Palindromic Subsequence (LPS) of `s`.
// 6. To compute the minimum insertions needed to make `s` a palindrome, subtract the LPS length from `s.size()`.

int solveUsingTab(string text1, string text2)
{
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int ans = 0;
            if (text1[i] == text2[j])
            {
                ans = 1 + dp[i + 1][j + 1];
            }
            else
            {
                ans = 0 + max(dp[i + 1][j], dp[i][j + 1]);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int minInsertions(string s)
{
    string a = s;
    reverse(a.begin(), a.end());
    int ans = solveUsingTab(s, a);
    return s.size() - ans;
}

// SPACE OPTIMIZATION APPROACH - TC=O(N^2), SC=O(N)
// Steps:
// 1. Reverse the string `s` to get `a`. The Longest Common Subsequence (LCS) of `s` and `a` represents the Longest Palindromic Subsequence (LPS) of `s`.
// 2. Use dynamic programming with a space-optimized approach to calculate the LCS of `s` and `a`.
// 3. Use two arrays `curr` and `next` to store the results of the current and previous rows, respectively.
// 4. Iterate through the string in reverse order:
//    - If `s[i] == a[j]`, increment the LCS length by 1 from `next[j+1]`.
//    - If they don't match, take the maximum value between `curr[j+1]` and `next[j]`.
// 5. The LCS length gives the Longest Palindromic Subsequence (LPS) of `s`.
// 6. To compute the minimum insertions needed to make `s` a palindrome, subtract the LPS length from `s.size()`.

int solveUsingSO(string text1, string text2)
{
    int m = text1.length();
    int n = text2.length();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int ans = 0;
            if (text1[i] == text2[j])
            {
                ans = 1 + next[j + 1];
            }
            else
            {
                ans = 0 + max(curr[j + 1], next[j]);
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return curr[0];
}
int minInsertions(string s)
{
    string a = s;
    reverse(a.begin(), a.end());
    int ans = solveUsingSO(s, a);
    return s.size() - ans;
}