#include<iostream>
using namespace std;

// PAINT FENCE OF N POSTS AND K COLORS
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(N)

// Steps:
// 1. If n equals 1, return k.
// 2. If n equals 2, return add(k, multi(k, k - 1)), where add and multi are presumably functions for addition and multiplication respectively.
// 3. If dp[n] is not equal to -1, return dp[n].
// 4. Calculate dp[n] using the formula:
//      dp[n] = add(multi(solveUsingMem(dp, n - 2, k), k - 1), multi(solveUsingMem(dp, n - 1, k), k - 1))
//    - This formula recursively computes dp[n] based on the values of dp[n-2] and dp[n-1].
// 5. Return dp[n], which contains the computed value for the given n and k.

int add(int a, int b)
{
    return (a % mod + b % mod) % mod;
}
int multi(int a, int b)
{
    return ((a % mod) * 1LL * (b % mod)) % mod;
}
int solveUsingMem(vector<int> &dp, int n, int k)
{
    if (n == 1)
    {
        return k;
    }
    if (n == 2)
    {
        return add(k, multi(k, k - 1));
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    dp[n] = add(multi(solveUsingMem(dp, n - 2, k), k - 1), multi(solveUsingMem(dp, n - 1, k), k - 1));
    return dp[n];
}
int numberOfWays(int n, int k)
{
    vector<int> dp(n + 1, -1);
    return solve(dp, n, k);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION
// Steps:
// 1. Initialize dp[] array with size n+1 and set dp[1] = k, dp[2] = add(k, multi(k, k - 1)).
//    - dp[i] will store the computed value for index i using the recurrence relation.
// 2. Iterate from i = 3 to n:
//    - Compute dp[i] using the formula:
//        dp[i] = add(multi(dp[i - 2], k - 1), multi(dp[i - 1], k - 1))
//      - This formula calculates dp[i] based on previously computed values dp[i-2] and dp[i-1].
// 3. Return dp[n], which contains the computed value for the given n and k.

int add(int a, int b)
{
    return (a % mod + b % mod) % mod;
}
int multi(int a, int b)
{
    return ((a % mod) * 1LL * (b % mod)) % mod;
}
int solveUsingTab(int n, int k)
{

    vector<int> dp(n + 1, 0);
    dp[1] = k;
    dp[2] = add(k, multi(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        dp[i] = add(multi(dp[i - 2], k - 1), multi(dp[i - 1], k - 1));
    }
    return dp[n];
}
int numberOfWays(int n, int k)
{
    return solveUsingTab(n, k);
}

// SPACE OPTIMIZATION APPROACH
// Steps:
// 1. Initialize prev1 with dp[2] = add(k, multi(k, k - 1)) and prev2 with dp[1] = k.
//    - prev1 and prev2 store the computed values for the last two elements in the sequence.
// 2. Iterate from i = 3 to n:
//    - Compute curr using the formula:
//        curr = add(multi(prev1, k - 1), multi(prev2, k - 1))
//      - Update prev2 to prev1 and prev1 to curr for the next iteration.
// 3. Return prev1, which contains the computed value for dp[n].

int add(int a, int b)
{
    return (a % mod + b % mod) % mod;
}
int multi(int a, int b)
{
    return ((a % mod) * 1LL * (b % mod)) % mod;
}
int solveUsingSO(int n, int k)
{
    int prev1 = add(k, multi(k, k - 1));
    int prev2 = k;

    for (int i = 3; i <= n; i++)
    {
        int curr = add(multi(prev1, k - 1), multi(prev2, k - 1));
        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}
int numberOfWays(int n, int k)
{
    return solveUsingSO(n, k);
}