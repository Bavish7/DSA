#include<iostream>
using namespace std;

// REGULAR EXPRESSION MATCHING (LEETCODE 10)
// USING RECURSION - TC=O(2^N), SC=O(N)

// Steps:
// 1. Define a recursive function solve(i, j) to match s[i:] with p[j:].
// 2. Base case: if j reaches end of pattern, return true only if i also reaches end of string.
// 3. Check if s[i] matches p[j] or p[j] is '.' → set `firstChar = true`.
// 4. If next pattern char is '*':
//    - Option 1: Exclude `*` pattern → move j by 2.
//    - Option 2: Include `*` → if firstChar is true, move i by 1 (keep j).
//    - Return true if either include or exclude is true.
// 5. Else: return true only if firstChar is true and the rest of strings also match (i+1, j+1).

bool solve(int i, int j, string &s, string &p)
{
    if (j == p.size())
    {
        return (i == s.size());
    }
    bool firstChar = false;
    if (i < s.size() && (p[j] == s[i] || p[j] == '.'))
        firstChar = true;
    if (p[j + 1] == '*')
    {
        bool exclude = solve(i, j + 2, s, p);
        bool include = (firstChar && solve(i + 1, j, s, p));
        return include || exclude;
    }
    return (firstChar && solve(i + 1, j + 1, s, p));
}
bool isMatch(string s, string p)
{
    return solve(0, 0, s, p);
}

// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*M), SC=O(N*M)
// Steps:
// 1. Use recursion with memoization to avoid recomputation of overlapping subproblems.
// 2. Base case: if pattern is exhausted (j == m), string must also be exhausted (i == n).
// 3. Check memo table dp[i][j] to reuse result if already computed.
// 4. Determine if current chars match or if pattern has '.', which matches any char.
// 5. If next character in pattern is '*':
//    - Exclude case: skip '*' and its preceding char → solve(i, j+2).
//    - Include case: if firstChar matches → solve(i+1, j).
// 6. Else, just match current char and move both indices forward.
// 7. Store and return the result in dp[i][j].

bool solveUsingMem(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{
    if (j == p.size())
    {
        return (i == s.size());
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    bool firstChar = false;
    if (i < s.size() && (p[j] == s[i] || p[j] == '.'))
        firstChar = true;
    if (p[j + 1] == '*')
    {
        bool exclude = solveUsingMem(i, j + 2, s, p, dp);
        bool include = (firstChar && solveUsingMem(i + 1, j, s, p, dp));
        return dp[i][j] = include || exclude;
    }
    return dp[i][j] = (firstChar && solveUsingMem(i + 1, j + 1, s, p, dp));
}
bool isMatch(string s, string p)
{
    int n = s.size(), m = p.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return solveUsingMem(0, 0, s, p, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*M), SC=O(N*M)
// Steps:
// 1. Create a 2D boolean DP table of size (n+1) x (m+1), where n = s.size(), m = p.size().
// 2. dp[i][j] stores whether s[i:] matches p[j:].
// 3. Base case: both string and pattern are fully matched → dp[n][m] = true.
// 4. Iterate i from n to 0 and j from m-1 to 0:
//    - If s[i] matches p[j] or p[j] is '.', set firstChar = true.
//    - If p[j+1] is '*':
//         - Exclude: consider '*' as matching 0 characters → dp[i][j+2]
//         - Include: match one character and stay at j → dp[i+1][j] (if firstChar)
//    - Else, just match current char → dp[i+1][j+1] (if firstChar).
// 5. Final result is stored in dp[0][0].

bool solveUsingTab(string &s, string &p)
{
    int n = s.size(), m = p.size();
    vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));
    dp[n][m] = true;
    for (int i = n; i >= 0; i--)
    {
        for (int j = m - 1; j >= 0; j--)
        {
            bool firstChar = false;
            if (i < n && (p[j] == s[i] || p[j] == '.'))
                firstChar = true;
            if (j + 1 < m && p[j + 1] == '*')
            {
                bool exclude = dp[i][j + 2];
                bool include = (firstChar && dp[i + 1][j]);
                dp[i][j] = include || exclude;
            }
            else
            {
                dp[i][j] = (firstChar && dp[i + 1][j + 1]);
            }
        }
    }
    return dp[0][0];
}
bool isMatch(string s, string p)
{
    return solveUsingTab(s, p);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N*M), SC=O(M)
// Steps:
// 1. Use space optimization to reduce 2D DP to two 1D arrays: `curr` and `next` of size (m+1).
// 2. `next` stores dp[i+1][j...m] and `curr` stores dp[i][j...m] for current i.
// 3. Base case: next[m] = true → both strings exhausted.
// 4. Iterate i from n to 0 (reverse) and j from m-1 to 0:
//    - Match current character if s[i] == p[j] or p[j] == '.'.
//    - If p[j+1] == '*':
//        - exclude = curr[j+2] (skip pattern segment)
//        - include = firstChar && next[j] (consume one char from s)
//    - Else, normal match: firstChar && next[j+1].
// 5. After each i, update `next = curr`.
// 6. Final result in curr[0].

bool solveUsingSO(string &s, string &p)
{
    int n = s.size(), m = p.size();
    vector<bool> curr(m + 1, false), next(m + 1, false);
    next[m] = true;
    for (int i = n; i >= 0; i--)
    {
        curr[m] = (i == n);
        for (int j = m - 1; j >= 0; j--)
        {
            bool firstChar = false;
            if (i < n && (p[j] == s[i] || p[j] == '.'))
                firstChar = true;
            if (j + 1 < m && p[j + 1] == '*')
            {
                bool exclude = curr[j + 2];
                bool include = (firstChar && next[j]);
                curr[j] = include || exclude;
            }
            else
            {
                curr[j] = (firstChar && next[j + 1]);
            }
        }
        next = curr;
    }
    return curr[0];
}
bool isMatch(string s, string p)
{
    return solveUsingSO(s, p);
}
