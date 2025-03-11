#include<iostream>
using namespace std;

// DELETE OPERATION FOR TWO STRINGS (LEETCODE 583)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. Define `solveUsingMem()` to recursively find the length of the longest common subsequence (LCS) between `text1` and `text2` starting from indices `i` and `j`.
// 2. Base case:
//    - If either string is completely traversed, return 0 since no further matches are possible.
// 3. Check if the result is already computed in `dp[i][j]`. If yes, return the stored value.
// 4. If the current characters match, include them in the LCS and move diagonally (`i + 1, j + 1`).
//    Otherwise, take the maximum result by either skipping the current character in `text1` or `text2`.
// 5. Store the result in `dp[i][j]` to avoid redundant computations.
// 6. The function `minDistance()` calculates the minimum number of operations required to convert `word1` to `word2` using the formula `m + n - 2 * LCS(word1, word2)`.

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
int minDistance(string word1, string word2)
{
    int i = 0;
    int j = 0;
    int m = word1.length();
    int n = word2.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    int ans = solveUsingMem(word1, word2, i, j, dp);
    return m + n - 2 * ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(M*N), SC=O(M*N)
// Steps:
// 1. Initialize a 2D vector `dp` where `dp[i][j]` represents the length of the longest common subsequence (LCS) starting from indices `i` in `text1` and `j` in `text2`.
// 2. Traverse `dp` from the last row and last column to the first (bottom-up approach).
// 3. If characters `text1[i]` and `text2[j]` match, set `dp[i][j] = 1 + dp[i + 1][j + 1]` (include the match).
//    Otherwise, set `dp[i][j] = max(dp[i + 1][j], dp[i][j + 1])` to account for the best possible match.
// 4. Return `dp[0][0]` as the length of the LCS between `word1` and `word2`.
// 5. Use the formula `word1.size() + word2.size() - 2 * LCS` to compute the minimum number of operations required to convert `word1` to `word2`.

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
int minDistance(string word1, string word2)
{
    int ans = solveUsingTab(word1, word2);
    return word1.size() + word2.size() - 2 * ans;
}

// SPACE OPTIMIZATION APPROACH - TC=O(N^2), SC=O(N)
// Steps:
// 1. Initialize two 1D vectors `curr` and `next` to store the current and next row of the dynamic programming table.
// 2. Traverse the strings `text1` and `text2` from the last characters towards the first (bottom-up approach).
// 3. If characters `text1[i]` and `text2[j]` match, set `curr[j] = 1 + next[j + 1]` (include the match).
//    Otherwise, set `curr[j] = max(curr[j + 1], next[j])` to store the best possible match.
// 4. After processing each row, update `next` to be equal to `curr`.
// 5. Return `curr[0]` as the length of the longest common subsequence (LCS) between `word1` and `word2`.
// 6. Use the formula `word1.size() + word2.size() - 2 * LCS` to compute the minimum number of operations required to convert `word1` to `word2`.

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
int minDistance(string word1, string word2)
{
    int ans = solveUsingSO(word1, word2);
    return word1.size() + word2.size() - 2 * ans;
}
