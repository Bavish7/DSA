#include<iostream>
using namespace std;

// MINIMUM ASCII DELETE SUM FOR TWO STRINGS (LEETCODE 712)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. Define a recursive function `solveUsingMem(s1, s2, i, j, dp)` to find the minimum delete sum from index `i` in `s1` and `j` in `s2`.
// 2. Base Case:
//    - If `i` or `j` reach the end of either string, add up the ASCII values of the remaining characters in the other string to ensure both are empty.
// 3. Memoization Check: If `dp[i][j] != -1`, return the stored result to avoid recalculations.
// 4. If `s1[i] == s2[j]` (characters match), no deletions are needed; move to the next characters in both strings by calling `solveUsingMem(s1, s2, i+1, j+1, dp)`.
// 5. If `s1[i] != s2[j]` (characters differ):
//    - Calculate the cost of deleting `s1[i]` (ASCII value `s1[i]` + recursive call for `i+1` and `j`).
//    - Calculate the cost of deleting `s2[j]` (ASCII value `s2[j]` + recursive call for `i` and `j+1`).
//    - Store the minimum of these two options in `dp[i][j]` to ensure minimal deletions are performed.
// 6. Return the computed result in `dp[0][0]`, which represents the minimum delete sum starting from the beginning of both strings.

int solveUsingMem(string &s1, string &s2, int i, int j, vector<vector<int>> &dp)
{
    int ans = 0;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    if (i == s1.size() || j == s2.size())
    {
        for (int x = i; x < s1.size(); x++)
        {
            ans += s1[x];
        }
        for (int x = j; x < s2.size(); x++)
        {
            ans += s2[x];
        }
    }
    else if (s1[i] == s2[j])
    {
        ans = solveUsingMem(s1, s2, i + 1, j + 1, dp);
    }
    else
    {
        int deleteS1 = s1[i] + solveUsingMem(s1, s2, i + 1, j, dp);
        int deleteS2 = s2[j] + solveUsingMem(s1, s2, i, j + 1, dp);
        ans = min(deleteS1, deleteS2);
    }
    dp[i][j] = ans;
    return dp[i][j];
}
int minimumDeleteSum(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return solveUsingMem(s1, s2, 0, 0, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(M*N), SC=O(M*N)
// Steps:
// 1. Initialize the DP table `dp`, where `dp[i][j]` represents the minimum delete sum needed to make `s1[i:]` and `s2[j:]` equal.
// 2. Fill the base cases:
//    - If `s2` is empty, fill `dp[i][n]` with the ASCII sum of the remaining characters in `s1[i:]`.
//    - If `s1` is empty, fill `dp[m][j]` with the ASCII sum of the remaining characters in `s2[j:]`.
// 3. Fill the DP table from the bottom-right corner up to the top-left:
//    - If `s1[i] == s2[j]`, carry over the value from `dp[i+1][j+1]` as no deletion is needed for these characters.
//    - If `s1[i] != s2[j]`, calculate the cost of deleting either `s1[i]` or `s2[j]` and take the minimum of these two choices.
// 4. Store the result in `dp[0][0]`, which gives the minimum delete sum starting from the beginning of both strings.

int solveUsingTab(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = m - 1; i >= 0; i--)
    {
        dp[i][n] = s1[i] + dp[i + 1][n];
    }
    for (int j = n - 1; j >= 0; j--)
    {
        dp[m][j] = s2[j] + dp[m][j + 1];
    }
    int ans = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            if (s1[i] == s2[j])
            {
                ans = dp[i + 1][j + 1];
            }
            else
            {
                int deleteS1 = s1[i] + dp[i + 1][j];
                int deleteS2 = s2[j] + dp[i][j + 1];
                ans = min(deleteS1, deleteS2);
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int minimumDeleteSum(string s1, string s2)
{
    return solveUsingTab(s1, s2);
}

// SPACE OPTIMIZATION APPROACH - TC=O(M*N), SC=O(N)
// Steps:
// 1. Initialize a 1D array `dp` of size `n + 1` to store the minimum ASCII delete sums for substrings of `s2`.
// 2. Fill `dp[j]` for the base case where `s1` is empty by setting `dp[j]` to the sum of ASCII values from `s2[j:]`.
// 3. For each character `s1[i]` from the end of `s1` to the start:
//    - Save `dp[n]` to `prev` and add `s1[i]` to `dp[n]` (handling cases where `s2` is empty).
//    - Traverse `s2` backwards:
//        - Backup `dp[j]` to `temp`.
//        - If `s1[i] == s2[j]`, set `dp[j] = prev`.
//        - Else, set `dp[j]` to `min(s1[i] + dp[j], s2[j] + dp[j + 1])`.
//        - Update `prev` to `temp` for the next iteration.
// 4. Return `dp[0]` as the minimum delete sum for making `s1` and `s2` equal.

int solveUsingSO(string s1, string s2)
{
    int m = s1.size();
    int n = s2.size();
    vector<int> dp(n + 1, 0);
    for (int j = n - 1; j >= 0; j--)
    {
        dp[j] = s2[j] + dp[j + 1];
    }
    for (int i = m - 1; i >= 0; i--)
    {
        int prev = dp[n];
        dp[n] += s1[i];
        for (int j = n - 1; j >= 0; j--)
        {
            int temp = dp[j];
            if (s1[i] == s2[j])
            {
                dp[j] = prev;
            }
            else
            {
                int deleteS1 = s1[i] + dp[j];
                int deleteS2 = s2[j] + dp[j + 1];
                dp[j] = min(deleteS1, deleteS2);
            }
            prev = temp;
        }
    }
    return dp[0];
}
int minimumDeleteSum(string s1, string s2)
{
    return solveUsingSO(s1, s2);
}