#include<iostream>
using namespace std;

// LONGEST COMMON SUBSTRING
// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. Create a 2D DP table where dp[i][j] stores the length of the longest common suffix of str1[0..i-1] and str2[0..j-1].
// 2. Initialize dp[i][0] and dp[0][j] to 0 since substrings of length 0 contribute nothing.
// 3. Iterate over both strings using indices i and j.
// 4. If characters match (str1[i - 1] == str2[j - 1]), update dp[i][j] = 1 + dp[i - 1][j - 1] and track the max length.
// 5. If characters don't match, dp[i][j] remains 0 (no suffix continuation possible).
// 6. Return the tracked maximum length as the result.

int solveUsingTab(string &str1, string &str2)
{
    int m = str1.size();
    int n = str2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    int maxLen = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
                maxLen = max(maxLen, dp[i][j]);
            }
        }
    }
    return maxLen;
}
int lcs(string &str1, string &str2)
{
    return solveUsingTab(str1, str2);
}

// SPACE OPTIMIZATION APPROACH - TC=O(M*N), SC=O(N)
// Steps:
// 1. Create two 1D vectors `prev` and `curr` to store DP states for the previous and current rows, respectively.
// 2. Initialize both vectors to 0 as base cases for substrings of length 0.
// 3. Iterate over both strings using indices i and j.
// 4. If characters match (str1[i - 1] == str2[j - 1]), update curr[j] = 1 + prev[j - 1] and track the max length.
// 5. If characters don't match, reset curr[j] to 0 (no suffix continuation).
// 6. Copy curr to prev after each row to prepare for the next iteration.
// 7. Return the tracked maximum length as the result.

int solveUsingSO(string &str1, string &str2)
{
    int m = str1.size();
    int n = str2.size();
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    int maxLen = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (str1[i - 1] == str2[j - 1])
            {
                curr[j] = 1 + prev[j - 1];
                maxLen = max(maxLen, curr[j]);
            }
            else
                curr[j] = 0;
        }
        prev = curr;
    }
    return maxLen;
}
int lcs(string &str1, string &str2)
{
    return solveUsingSO(str1, str2);
}
