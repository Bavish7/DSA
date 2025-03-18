#include<iostream>
using namespace std;

// LONGEST COMMON SUBSEQUENCE (LEETCODE 1143)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. Base cases:
//    a. If i reaches or exceeds the length of text1 or j reaches or exceeds the length of text2, return 0.
//    b. If dp[i][j] has already been computed and stored (not equal to -1), return dp[i][j].
// 2. Recursive cases:
//    a. If text1[i] equals text2[j], include this character in the LCS:
//       - Recur for the next characters (i+1, j+1) and add 1 to the result.
//    b. If text1[i] does not equal text2[j], explore both options to find the maximum length:
//       - Exclude text1[i]: recur for (i+1, j)
//       - Exclude text2[j]: recur for (i, j+1)
//    c. Store the computed result in dp[i][j].
// 3. Return dp[i][j], which contains the length of the longest common subsequence between text1[0...i-1] and text2[0...j-1].

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
int longestCommonSubsequence(string text1, string text2)
{
    int i = 0;
    int j = 0;
    int m = text1.length();
    int n = text2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int ans = solveUsingMem(text1, text2, i, j, dp);
    return ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(M*N), SC=O(M*N)
// Steps:
// 1. Initialize a 2D dp array, dp[m+1][n+1], where m and n are lengths of text1 and text2 respectively.
//    - dp[i][j] will store the length of LCS between text1[0...i-1] and text2[0...j-1].
// 2. Iterate through dp from bottom-right to top-left:
//    a. If text1[i] equals text2[j], dp[i][j] = 1 + dp[i+1][j+1].
//    b. Otherwise, dp[i][j] = max(dp[i+1][j], dp[i][j+1]).
// 3. Return dp[0][0], which contains the length of the longest common subsequence between text1 and text2.

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
int longestCommonSubsequence(string text1, string text2)
{
    int ans = solveUsingTab(text1, text2);
    return ans;
}

// SPACE OPTIMIZATION APPROACH - TC=O(M*N), SC=O(N)
// Steps:
// 1. Initialize two vectors, curr and next, each of size n+1 (where n is the length of text2).
//    - curr[j] will store the LCS length considering text1[i...m-1] and text2[j...n-1] in the current iteration.
//    - next[j] will store the LCS length considering text1[i...m-1] and text2[j...n-1] in the next iteration.
// 2. Iterate through text1 from end to start (i = m-1 to 0):
//    a. Reset curr[n] to 0 for each iteration of text1 (corresponding to the end of text2).
//    b. Iterate through text2 from end to start (j = n-1 to 0):
//       - If text1[i] equals text2[j], set ans = 1 + next[j + 1].
//       - Otherwise, set ans = max(curr[j + 1], next[j]).
//    c. Store ans in curr[j] and move next = curr.
// 3. Return curr[0], which contains the length of the longest common subsequence between text1 and text2.

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
int longestCommonSubsequence(string text1, string text2)
{
    int ans = solveUsingSO(text1, text2);
    return ans;
}

