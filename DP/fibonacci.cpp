#include<iostream>
using namespace std;

// TOP-DOWN APPROACH - RECURSION + MEMOIZATION
int solveUsingMem(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return n;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = solveUsingMem(n - 1, dp) + solveUsingMem(n - 2, dp);
    return dp[n];
}
int fib(int n)
{
    vector<int> dp(n + 1, -1);
    int ans = solveUsingMem(n, dp);
    return ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION
int solveUsingTabulation(int n)
{
    vector<int> dp(n + 1, -1);
    dp[0] = 0;
    if (n == 0)
    {
        return dp[0];
    }
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}
int fib(int n)
{
    int ans = solveUsingTabulation(n);
    return ans;
}

// SPACE OPTIMIZATION APPROACH
int solveUsingSpaceOptimisation(int n)
{
    int prev = 0;
    int curr = 1;
    if (n <= 1)
    {
        return n;
    }
    int ans;
    for (int i = 2; i <= n; i++)
    {
        ans = prev + curr;
        prev = curr;
        curr = ans;
    }
    return ans;
}
int fib(int n)
{
    int ans = solveUsingSpaceOptimisation(n);
    return ans;
}
