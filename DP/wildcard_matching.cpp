#include<iostream>
using namespace std;

// WILDCARD MATCHING (LEETCODE 44)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. Base Case 1: If both strings are empty (i == 0 && j == 0), return true.
// 2. Base Case 2: If `s` is not empty but `p` is empty (i > 0 && j == 0), return false.
// 3. Base Case 3: If `s` is empty but `p` is not (i == 0 && j > 0), check if all characters in `p` are '*'.
//    If any character is not '*', return false; otherwise, return true.
// 4. Check memoization table for previously computed results.
// 5. If characters match or pattern has '?' (wildcard), recursively solve for `i - 1` and `j - 1`.
// 6. If pattern has '*' (wildcard):
//    - `include`: Treat '*' as part of the current match and solve for `i - 1, j`.
//    - `exclude`: Ignore '*' and solve for `i, j - 1`.
//    - Store the result as `include || exclude`.
// 7. If none of the above conditions match, return false.
// 8. Use memoized results for efficiency and return final result.

bool solveUsingMem(int i, int j, string &s, string &p, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return true;
    if (i > 0 && j == 0)
        return false;
    if (i == 0 && j > 0)
    {
        for (int temp = 1; temp <= j; temp++)
        {
            if (p[temp - 1] != '*')
                return false;
        }
        return true;
    }
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
    {
        return dp[i][j] = solveUsingMem(i - 1, j - 1, s, p, dp);
    }
    if (p[j - 1] == '*')
    {
        bool exclude = solveUsingMem(i - 1, j, s, p, dp);
        bool include = solveUsingMem(i, j - 1, s, p, dp);
        return dp[i][j] = include || exclude;
    }
    return dp[i][j] = false;
}
bool isMatch(string s, string p)
{
    int m = s.size();
    int n = p.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    return solveUsingMem(m, n, s, p, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(M*N), SC=O(M*N)
// Steps:
// 1. Create a DP table `dp[m + 1][n + 1]`, where `dp[i][j]` stores whether `s[0...i-1]` matches `p[0...j-1]`.
// 2. Base case: `dp[0][0] = true`, indicating that empty strings match.
// 3. Fill the first column `dp[i][0]` with `false`, as an empty pattern cannot match a non-empty string.
// 4. Fill the first row `dp[0][j]`, checking if all characters up to `j - 1` in `p` are `*`. Set `true` if they are, otherwise `false`.
// 5. Iterate through both strings `s` and `p` for all indices `i` and `j`.
//    - If characters match or pattern has '?', set `dp[i][j] = dp[i - 1][j - 1]`.
//    - If pattern has '*', evaluate two cases:
//      - `exclude`: Treat '*' as empty (`dp[i - 1][j]`).
//      - `include`: Treat '*' as matching the current character (`dp[i][j - 1]`).
//      - Set `dp[i][j] = include || exclude`.
// 6. Return the result in `dp[m][n]` as the final answer.

bool solveUsingTab(string &s, string &p)
{
    int m = s.size();
    int n = p.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, false));
    dp[0][0] = true;
    for (int i = 1; i <= m; i++)
    {
        dp[i][0] = false;
    }
    for (int j = 1; j <= n; j++)
    {
        bool flag = true;
        for (int temp = 1; temp <= j; temp++)
        {
            if (p[temp - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        dp[0][j] = flag;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else if (p[j - 1] == '*')
            {
                bool exclude = dp[i - 1][j];
                bool include = dp[i][j - 1];
                dp[i][j] = include || exclude;
            }
        }
    }
    return dp[m][n];
}
bool isMatch(string s, string p)
{
    return solveUsingTab(s, p);
}

// SPACE OPTIMIZATION APPROACH - TC=O(M*N), SC=O(M)
// Steps:
// 1. Create two 1D vectors `prev` and `curr` for space optimization, where `prev[j]` stores the result for the previous pattern character.
// 2. Initialize base cases:
//    - `prev[0] = true`, indicating that empty strings match.
//    - Set all `prev[j] = false` for non-zero `j` as an empty pattern can't match a non-empty string.
// 3. Iterate over pattern characters `p[i - 1]` for all indices `i`:
//    - Handle the base case for row `curr[0]`: Check if all characters up to `i - 1` are `*`. Set `true` if so.
//    - For each string character `s[j - 1]`, update `curr[j]`:
//      - If characters match or the pattern has '?', set `curr[j] = prev[j - 1]`.
//      - If pattern has '*', evaluate two cases:
//        - `exclude`: Treat '*' as empty (`prev[j]`).
//        - `include`: Treat '*' as matching the current character (`curr[j - 1]`).
//        - Set `curr[j] = include || exclude`.
//      - Else set `curr[j] = false` for no match.
// 4. Update `prev = curr` after processing each pattern character.
// 5. Return `prev[m]` as the final result.

bool solveUsingSO(string s, string p)
{
    int m = s.size();
    int n = p.size();
    vector<bool> prev(m + 1, false), curr(m + 1, false);
    prev[0] = true;
    for (int j = 1; j <= m; j++)
    {
        prev[j] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int temp = 1; temp <= i; temp++)
        {
            if (p[temp - 1] != '*')
            {
                flag = false;
                break;
            }
        }
        curr[0] = flag;
        for (int j = 1; j <= m; j++)
        {
            if (s[j - 1] == p[i - 1] || p[i - 1] == '?')
            {
                curr[j] = prev[j - 1];
            }
            else if (p[i - 1] == '*')
            {
                bool exclude = prev[j];
                bool include = curr[j - 1];
                curr[j] = include || exclude;
            }
            else
            {
                curr[j] = false;
            }
        }
        prev = curr;
    }
    return prev[m];
}
bool isMatch(string s, string p)
{
    return solveUsingSO(s, p);
}