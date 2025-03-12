#include<iostream>
using namespace std;

// EDIT DISTANCE (LEETCODE 72)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. If i reaches the end of string a, return the remaining length of string b from j.
// 2. If j reaches the end of string b, return the remaining length of string a from i.
// 3. If dp[i][j] is already calculated, return dp[i][j].
// 4. If characters a[i] and b[j] are the same, recursively calculate for i+1 and j+1 without any cost increment.
// 5. If characters are different, calculate costs for insert, replace, and remove operations, taking minimum of these costs.
// 6. Store the minimum cost in dp[i][j] and return dp[i][j].

int solveUsingMem(string a, string b, int i, int j, vector<vector<int>> &dp)
{
    if (i == a.length())
    {
        return b.length() - j;
    }
    if (j == b.length())
    {
        return a.length() - i;
    }
    if (dp[i][j] != -1)
    {
        return dp[i][j];
    }
    int ans = 0;
    if (a[i] == b[j])
    {
        ans = 0 + solveUsingMem(a, b, i + 1, j + 1, dp);
    }
    else
    {
        int insert = 1 + solveUsingMem(a, b, i, j + 1, dp);
        int replace = 1 + solveUsingMem(a, b, i + 1, j + 1, dp);
        int remove = 1 + solveUsingMem(a, b, i + 1, j, dp);
        ans = min(insert, min(replace, remove));
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
    return ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(M*N), SC=O(M*N)
// Steps:
// solveUsingTab(a, b):
// 1. Initialize dp[m+1][n+1] where m and n are lengths of strings a and b respectively.
// 2. Base cases: dp[i][n] = a.length() - i for i from 0 to m (if i reaches the end of string a).
//                dp[m][j] = b.length() - j for j from 0 to n (if j reaches the end of string b).
// 3. Iterate from m-1 to 0 and n-1 to 0:
//    a. If characters a[i] and b[j] are the same, set dp[i][j] = dp[i+1][j+1].
//    b. Otherwise, calculate costs for insert, replace, and remove operations, taking minimum of these costs.
//    c. Store the minimum cost in dp[i][j].
// 4. Return dp[0][0] as the minimum edit distance between strings a and b.

int solveUsingTab(string a, string b)
{
    int m = a.length();
    int n = b.length();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
    for (int i = 0; i <= m; i++)
    {
        dp[i][n] = a.length() - i;
    }
    for (int j = 0; j <= n; j++)
    {
        dp[m][j] = b.length() - j;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
            {
                ans = 0 + dp[i + 1][j + 1];
            }
            else
            {
                int insert = 1 + dp[i][j + 1];
                int replace = 1 + dp[i + 1][j + 1];
                int remove = 1 + dp[i + 1][j];
                ans = min(insert, min(replace, remove));
            }
            dp[i][j] = ans;
        }
    }
    return dp[0][0];
}
int minDistance(string word1, string word2)
{
    int ans = solveUsingTab(word1, word2);
    return ans;
}

// SPACE OPTIMIZATION APPROACH - TC=O(M*N), SC=O(N)
// Steps:
// 1. Initialize vectors curr and next with size n+1, where n is the length of string b.
//    - curr[j] represents the cost to transform the prefix a[i...m-1] to b[j...n-1].
//    - next[j] stores the values of curr[j] after each iteration.
// 2. Initialize base cases: next[j] = n - j for j from 0 to n.
// 3. Iterate from m-1 to 0 and n-1 to 0:
//    a. Set curr[n] = m - i as the base case for the current row.
//    b. Iterate from n-1 to 0:
//       - If a[i] == b[j], set ans = next[j+1].
//       - Otherwise, calculate costs for insert, replace, and remove operations, taking the minimum of these costs.
//    c. Update curr[j] with ans.
//    d. Update next with curr for the next iteration.
// 4. Return next[0] as the minimum edit distance between strings a and b.

int solveUsingSO(string a, string b)
{
    int m = a.length();
    int n = b.length();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int j = 0; j < n; j++)
    {
        next[j] = n - j;
    }
    for (int i = m - 1; i >= 0; i--)
    {
        curr[n] = m - i;
        for (int j = n - 1; j >= 0; j--)
        {
            int ans = 0;
            if (a[i] == b[j])
            {
                ans = 0 + next[j + 1];
            }
            else
            {
                int insert = 1 + curr[j + 1];
                int replace = 1 + next[j + 1];
                int remove = 1 + next[j];
                ans = min(insert, min(replace, remove));
            }
            curr[j] = ans;
        }
        next = curr;
    }
    return next[0];
}
int minDistance(string word1, string word2)
{
    int ans = solveUsingSO(word1, word2);
    return ans;
}