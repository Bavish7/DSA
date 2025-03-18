#include<iostream>
using namespace std;

// LONGEST PALINDROMIC SUBSEQUENCE (LEETCODE 516)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. If either i >= text1.length() or j >= text2.length(), return 0.
// 2. If dp[i][j] is not -1 (indicating already computed), return dp[i][j].
// 3. If text1[i] == text2[j], include both characters in the LPS:
//    a. Increment ans by 1 and recursively call solveUsingMem(text1, text2, i+1, j+1, dp).
// 4. If text1[i] != text2[j], explore two possibilities:
//    a. Exclude text1[i] and find LPS from (i+1, j).
//    b. Exclude text2[j] and find LPS from (i, j+1).
//    c. Take the maximum of these two possibilities.
// 5. Store the computed ans in dp[i][j] and return dp[i][j].

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
int longestPalindromeSubseq(string s)
{
    string a = s;
    reverse(a.begin(), a.end());
    int i = 0;
    int j = 0;
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    int ans = solveUsingMem(s, a, i, j, dp);
    return ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(M*N), SC=O(M*N)
// Steps:
// 1. Initialize dp[m+1][n+1] where m and n are lengths of text1 and text2 respectively.
// 2. Iterate from m-1 to 0 and n-1 to 0:
//    a. If text1[i] == text2[j], dp[i][j] = 1 + dp[i+1][j+1] (include both characters in LPS).
//    b. Otherwise, dp[i][j] = max(dp[i+1][j], dp[i][j+1]) (take maximum by excluding one character).
// 3. Return dp[0][0] as the length of the Longest Palindromic Subsequence between text1 and text2.

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
int longestPalindromeSubseq(string s)
{
    string a = s;
    reverse(a.begin(), a.end());
    int ans = solveUsingTab(s, a);
    return ans;
}

// SPACE OPTIMIZATION APPROACH - TC=O(M*N), SC=O(N)
// Steps:
// 1. Initialize two vectors, curr and next, of size n+1 (where n is the length of text2).
//    - curr will be used to store results for the current row of the dp table.
//    - next will be used to store results for the next row of the dp table.
// 2. Iterate through text1 from the end to the beginning:
//    a. Iterate through text2 from the end to the beginning:
//       - If text1[i] matches text2[j], ans = 1 + next[j+1] (include both characters in LPS).
//       - Otherwise, ans = max(curr[j+1], next[j]) (take maximum by excluding one character).
//    b. Update curr[j] with the computed ans.
// 3. After completing the inner loop for text2, update next to curr for the next iteration of text1.
// 4. Return curr[0], which contains the length of the Longest Palindromic Subsequence between text1 and text2.
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
int longestPalindromeSubseq(string s)
{
    string a = s;
    reverse(a.begin(), a.end());
    int ans = solveUsingSO(s, a);
    return ans;
}