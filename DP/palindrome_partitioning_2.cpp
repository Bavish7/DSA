#include<iostream>
using namespace std;

// PALINDROME PARTITIONING II (LEETCODE 132)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(N)

// Steps:
// 1. Use the `isPalindrome()` helper function to check if a substring `s[i...j]` is a palindrome.
//    - Compare characters at `i` and `j`, increment `i`, decrement `j`, and return false if they don't match.
// 2. Define `solveUsingMem(i, n, s, dp)` to compute the minimum cuts required to partition `s[i...n-1]`.
// 3. Base case: If `i == n`, return 0 (no cuts needed).
// 4. Memoization: Check if the result for `dp[i]` is already computed to avoid redundant work.
// 5. For each possible partition `j`, if `s[i...j]` is a palindrome, calculate partitioning cost recursively.
// 6. Use `1 + solveUsingMem(j + 1, n, s, dp)` to compute the cost of cutting after `j`.
// 7. Update `minCost` and store it in `dp[i]`.
// 8. Return `solveUsingMem(0, n, s, dp) - 1` to account for the extra cut counted in recursion.

bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
        {
            return false;
        }
    }
    return true;
}
int solveUsingMem(int i, int n, string &s, vector<int> &dp)
{
    if (i == n)
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int minCost = INT_MAX;
    for (int j = i; j < n; j++)
    {
        if (isPalindrome(i, j, s))
        {
            int cost = 1 + solveUsingMem(j + 1, n, s, dp);
            minCost = min(minCost, cost);
        }
    }
    return dp[i] = minCost;
}
int minCut(string s)
{
    int n = s.size();
    vector<int> dp(n, -1);
    return solveUsingMem(0, n, s, dp) - 1;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^2), SC=O(N)
// Steps:
// 1. Use the `isPalindrome()` helper function to check if a substring `s[i...j]` is a palindrome.
//    - Compare characters at `i` and `j`, increment `i`, decrement `j`, and return false if they don't match.
// 2. Define `solveUsingTab()` to compute the minimum cuts required using bottom-up dynamic programming.
// 3. Initialize `dp[n]` with 0, representing no cuts required for an empty string.
// 4. Iterate from the last index `i` towards the beginning of the string:
//    - For each possible partition `j`, check if `s[i...j]` is a palindrome.
//    - If yes, compute the partitioning cost as `1 + dp[j + 1]` and update `minCost`.
// 5. Store the result in `dp[i]`.
// 6. Return `dp[0] - 1` to account for the extra cut counted during computation.

bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
        {
            return false;
        }
    }
    return true;
}
int solveUsingTab(string &s)
{
    int n = s.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int minCost = INT_MAX;
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
            {
                int cost = 1 + dp[j + 1];
                minCost = min(minCost, cost);
            }
        }
        dp[i] = minCost;
    }
    return dp[0];
}
int minCut(string s)
{
    return solveUsingTab(s) - 1;
}
