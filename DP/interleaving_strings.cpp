#include<iostream>
using namespace std;

// INTERLEAVING STRINGS (LEETCODE 97)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. If the combined length of `s1` and `s2` is not equal to `s3`'s length, return `false`.
// 2. Initialize a 2D DP array `dp` where `dp[i][j]` stores whether `s3` up to index `i + j` can be formed by interleaving `s1` up to `i` and `s2` up to `j`.
// 3. Define `solveUsingMem`:
//    - Base case: If `i + j` reaches the length of `s3`, return `true`.
//    - If `dp[i][j]` is already computed, return its value.
//    - Check characters from `s1` and `s2`:
//      - If `s1[i] == s3[i + j]`, attempt to include `s1[i]` by calling `solveUsingMem` with `i+1` and `j`.
//      - If `s2[j] == s3[i + j]`, attempt to include `s2[j]` by calling `solveUsingMem` with `i` and `j+1`.
//      - Use logical OR to accumulate results.
//    - Store and return the result in `dp[i][j]`.
// 4. Call `solveUsingMem` with initial indices `0, 0` to check if `s3` can be formed.

bool solveUsingMem(string &s1, string &s2, string &s3, int i, int j, vector<vector<int>> &dp)
{
    if (i + j >= s3.size())
        return true;
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    bool flag = false;
    if (i < s1.size() && s1[i] == s3[i + j])
    {
        flag = flag || solveUsingMem(s1, s2, s3, i + 1, j, dp);
    }
    if (j < s2.size() && s2[j] == s3[i + j])
    {
        flag = flag || solveUsingMem(s1, s2, s3, i, j + 1, dp);
    }
    dp[i][j] = flag;
    return dp[i][j];
}
bool isInterleave(string s1, string s2, string s3)
{
    if (s1.size() + s2.size() != s3.size())
    {
        return false;
    }
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, -1));
    return solveUsingMem(s1, s2, s3, 0, 0, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(M*N), SC=O(M*N)
// Steps:
// 1. Check if the combined length of `s1` and `s2` matches `s3`. If not, return `false`.
// 2. Initialize a DP table `dp` where `dp[i][j]` represents if `s3` up to index `i + j` can be formed by interleaving `s1` up to `i` and `s2` up to `j`.
// 3. Set the base case `dp[s1.size()][s2.size()] = true`.
// 4. Traverse `dp` in reverse:
//    - For each position `i` and `j`, determine if `s3[i + j]` matches the next character in `s1` or `s2`:
//      - If `s1[i] == s3[i + j]`, set `dp[i][j]` to `dp[i + 1][j]`.
//      - If `s2[j] == s3[i + j]`, set `dp[i][j]` to `dp[i][j + 1]`.
//    - Store `true` in `dp[i][j]` if any condition above is satisfied.
// 5. Return the result from `dp[0][0]`.

bool solveUsingTab(string &s1, string &s2, string &s3)
{
    if (s1.size() + s2.size() != s3.size())
    {
        return false;
    }
    vector<vector<int>> dp(s1.size() + 1, vector<int>(s2.size() + 1, 0));
    dp[s1.size()][s2.size()] = true;
    for (int i = s1.size(); i >= 0; i--)
    {
        for (int j = s2.size(); j >= 0; j--)
        {
            if (i == s1.size() && j == s2.size())
                continue;
            bool flag = false;
            if (i < s1.size() && s1[i] == s3[i + j])
            {
                flag = flag || dp[i + 1][j];
            }
            if (j < s2.size() && s2[j] == s3[i + j])
            {
                flag = flag || dp[i][j + 1];
            }
            dp[i][j] = flag;
        }
    }
    return dp[0][0];
}
bool isInterleave(string s1, string s2, string s3)
{
    return solveUsingTab(s1, s2, s3);
}

// SPACE OPTIMIZATION APPROACH - TC=O(M*N), SC=O(N)
// Steps:
// 1. Check if the combined length of `s1` and `s2` matches `s3`. If not, return `false`.
// 2. Initialize two 1D arrays, `curr` and `next`, to store results for the current and next rows, respectively.
// 3. Set the base case `curr[s2.size()] = true`, as both `s1` and `s2` are fully traversed here.
// 4. Traverse from the end of `s1` and `s2`:
//    - For each position `i` and `j`, set `flag` based on matches in `s1` and `s2`:
//      - If `s1[i] == s3[i + j]`, update `flag` with the value in `next[j]`.
//      - If `s2[j] == s3[i + j]`, update `flag` with the value in `curr[j + 1]`.
//    - Store `flag` in `curr[j]`.
// 5. Update `next` to `curr` after each row is processed.
// 6. Return the result from `next[0]`.

bool solveUsingSO(string &s1, string &s2, string &s3)
{
    if (s1.size() + s2.size() != s3.size())
    {
        return false;
    }
    vector<int> curr(s2.size() + 1, 0);
    vector<int> next(s2.size() + 1, 0);
    curr[s2.size()] = true;
    for (int i = s1.size(); i >= 0; i--)
    {
        for (int j = s2.size(); j >= 0; j--)
        {
            if (i == s1.size() && j == s2.size())
                continue;
            bool flag = false;
            if (i < s1.size() && s1[i] == s3[i + j])
            {
                flag = flag || next[j];
            }
            if (j < s2.size() && s2[j] == s3[i + j])
            {
                flag = flag || curr[j + 1];
            }
            curr[j] = flag;
        }
        next = curr;
    }
    return next[0];
}
bool isInterleave(string s1, string s2, string s3)
{
    return solveUsingSO(s1, s2, s3);
}