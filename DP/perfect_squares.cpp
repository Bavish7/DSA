#include<iostream>
using namespace std;

// PERFECT SQUARES (LEETCODE 279)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*SQRT(N)), SC=O(N)

// Steps:
// 1. Base case: If n <= 0, return 0 as no more perfect squares can be used.
// 2. If dp[n] already calculated, return stored value.
// 3. Initialize ans as maximum integer value.
// 4. Iterate through perfect squares up to sqrt(n):
//    - Calculate perfectSquare = i * i.
//    - Recursively calculate recAns = 1 + solveUsingMem(n - perfectSquare, dp).
//    - Update ans if recAns is smaller.
// 5. Store ans in dp[n] and return dp[n].

int solveUsingMem(int n, vector<int> &dp)
{
    if (n <= 0)
    {
        return 0;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = INT_MAX;
    for (int i = 1; i <= sqrt(n); i++)
    {
        int perfectSquare = i * i;
        int recAns = 1 + solveUsingMem(n - perfectSquare, dp);
        if (recAns < ans)
        {
            ans = recAns;
        }
    }
    dp[n] = ans;
    return dp[n];
}
int numSquares(int n)
{
    vector<int> dp(n + 1, -1);
    int ans = solveUsingMem(n, dp);
    return ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*SQRT(N)), SC=O(N)
// Steps:
// 1. Initialize dp array of size n+1, where dp[i] will store the minimum number of perfect squares summing up to i.
// 2. Iterate through each index from 1 to n:
//    a. Initialize ans to maximum integer value.
//    b. Iterate through perfect squares up to sqrt(index):
//       - Calculate perfectSquare = i * i.
//       - Calculate recAns = 1 + dp[index - perfectSquare].
//       - Update ans if recAns is smaller.
//    c. Store ans in dp[index].
// 3. Return dp[n], which contains the minimum number of perfect squares summing up to n.

int solveUsingTab(int n)
{
    vector<int> dp(n + 1, 0);
    for (int index = 1; index <= n; index++)
    {
        int ans = INT_MAX;
        for (int i = 1; i <= sqrt(index); i++)
        {
            int perfectSquare = i * i;
            int recAns = 1 + dp[index - perfectSquare];
            if (recAns < ans)
            {
                ans = recAns;
            }
        }
        dp[index] = ans;
    }
    return dp[n];
}
int numSquares(int n)
{
    int ans = solveUsingTab(n);
    return ans;
}