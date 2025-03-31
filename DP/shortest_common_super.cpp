#include<iostream>
using namespace std;

// SHORTEST COMMON SUPERSEQUENCE (LEETCODE 1092)
// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. Initialize a 2D DP table `dp[n+1][m+1]` where `dp[i][j]` stores the length of the longest common subsequence (LCS) between the first `i` characters of `s1` and first `j` characters of `s2`.
// 2. Fill the DP table by comparing characters from `s1` and `s2`:
//    - If characters match, `dp[i][j] = 1 + dp[i-1][j-1]`.
//    - Else, take the maximum of ignoring one character from either string: `dp[i][j] = max(dp[i-1][j], dp[i][j-1])`.
// 3. Trace back from `dp[n][m]` to reconstruct the shortest common supersequence by adding characters to `ans`:
//    - If characters match, add it to the result and move diagonally up.
//    - If characters do not match, move toward the larger value between `dp[i-1][j]` or `dp[i][j-1]` and append the respective character.
// 4. Append remaining characters of `s1` or `s2` if any, as part of the supersequence.
// 5. Reverse the result string to get the correct order.
// 6. Return the final result.

string shortestCommonSupersequence(string s1, string s2)
{
    int n = s1.size();
    int m = s2.size();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    for (int ind1 = 1; ind1 <= n; ind1++)
    {
        for (int ind2 = 1; ind2 <= m; ind2++)
        {
            if (s1[ind1 - 1] == s2[ind2 - 1])
                dp[ind1][ind2] = 1 + dp[ind1 - 1][ind2 - 1];
            else
                dp[ind1][ind2] = 0 + max(dp[ind1 - 1][ind2], dp[ind1][ind2 - 1]);
        }
    }
    int i = n;
    int j = m;
    string ans = "";
    while (i > 0 && j > 0)
    {
        if (s1[i - 1] == s2[j - 1])
        {
            ans += s1[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] > dp[i][j - 1])
        {
            ans += s1[i - 1];
            i--;
        }
        else
        {
            ans += s2[j - 1];
            j--;
        }
    }
    while (i > 0)
    {
        ans += s1[i - 1];
        i--;
    }
    while (j > 0)
    {
        ans += s2[j - 1];
        j--;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}


