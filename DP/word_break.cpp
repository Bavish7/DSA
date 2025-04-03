#include<iostream>
using namespace std;

// WORD BREAK (LEETCODE 139)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(M+N)

// Steps:
// 1. Convert `wordDict` to an unordered_set `dict` for O(1) average lookup time.
// 2. Define a recursive function with memoization (`dp`) to avoid recalculating results for the same start index.
//    - Base case: If `start == s.size()`, return true (all parts of the string matched).
// 3. For each substring starting at `start`, check if it exists in `dict`.
//    - If found, make a recursive call with `start = i + 1` to check the remaining part of the string.
// 4. Memoize and return the result of each call to avoid redundant computations.

bool solveUsingMem(string &s, unordered_set<string>&dict, int start, vector<int> &dp)
{
    if (start == s.size())
    {
        return true;
    }
    if (dp[start] != -1)
    {
        return dp[start];
    }
    bool flag = false;
    string word = "";
    for (int i = start; i < s.size(); i++)
    {
        word += s[i];
        if (dict.find(word)!=dict.end())
        {
            flag = flag || solveUsingMem(s, dict, i + 1, dp);
        }
    }
    dp[start] = flag;
    return dp[start];
}
bool wordBreak(string s, vector<string> &wordDict)
{
    int n = s.size();
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    vector<int> dp(n + 1, -1);
    return solveUsingMem(s, dict, 0, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^2), SC=O(M+N)
// Steps:
// 1. Initialize a DP array `dp` of size `n+1` where `dp[i]` indicates if the substring `s[i:]` can be segmented.
// 2. Set `dp[n] = true` because an empty suffix can always be segmented (base case).
// 3. Iterate from the end of the string `s` to the start:
//    - For each `start` position, initialize `word` as an empty string.
//    - Expand `word` by adding one character at a time from `start` to `i`.
//    - If `word` exists in `dict`, update `dp[start]` by checking `dp[i+1]`.
// 4. The final result is stored in `dp[0]`, indicating whether the entire string can be segmented.

bool solveUsingTab(string s, unordered_set<string> &dict)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[n] = true;
    for (int start = n - 1; start >= 0; start--)
    {
        bool flag = false;
        string word = "";
        for (int i = start; i < n; i++)
        {
            word += s[i];
            if (dict.find(word) != dict.end())
            {
                flag = flag || dp[i + 1];
            }
        }
        dp[start] = flag;
    }
    return dp[0];
}
bool wordBreak(string s, vector<string> &wordDict)
{
    unordered_set<string> dict(wordDict.begin(), wordDict.end());
    return solveUsingTab(s, dict);
}