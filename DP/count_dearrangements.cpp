#include<iostream>
using namespace std;

// COUNT DEARRANGEMENTS
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N), SC=O(N)

// Steps:
// 1. Define `solveUsingMem` to compute derangements recursively for `n` items.
// 2. Base Cases:
//    - If `n == 1`, return 0 (no derangements possible).
//    - If `n == 2`, return 1 (one possible derangement).
// 3. Check if `dp[n]` is already computed. If yes, return it.
// 4. Otherwise, calculate `ans` as:
//    - `ans = (n - 1) * (solveUsingMem(n - 1, dp) + solveUsingMem(n - 2, dp)) % 1000000007`.
// 5. Store result in `dp[n]` and return it.
// 6. `countDerangements` initializes `dp` and calls `solveUsingMem` for the result.

long long int solveUsingMem(int n, vector<long long> &dp)
{
    if (n == 1)
    {
        return 0;
    }
    if (n == 2)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    long long int ans = ((n - 1) * (solveUsingMem(n - 1, dp) + solveUsingMem(n - 2, dp))) % 1000000007;
    dp[n] = ans;
    return dp[n];
}
long long int countDerangements(int n)
{
    vector<long long int> dp(n + 1, -1);
    long long int ans = solveUsingMem(n, dp);
    return ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N), SC=O(N)
// Steps:
// 1. Define `solveUsingTab` to calculate derangements iteratively.
// 2. Initialize `dp` array with base cases:
//    - `dp[1] = 0` (no derangements for one item).
//    - `dp[2] = 1` (one derangement for two items).
// 3. For each `i` from 3 to `n`, calculate `dp[i]` as:
//    - `dp[i] = (i - 1) * (dp[i - 1] + dp[i - 2]) % 1000000007`.
//    - Store result in `dp[i]`.
// 4. Return `dp[n]` which contains the count of derangements for `n` items.
// 5. `countDerangements` initializes `dp` using `solveUsingTab` and returns the result.

long long int solveUsingTab(int n)
{
    vector<long long int> dp(n + 1, -1);
    dp[1] = 0, dp[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        dp[i] = ((i - 1) * (dp[i - 1] + dp[i - 2])) % 1000000007;
    }
    return dp[n];
}
long long int countDerangements(int n)
{
    long long int ans = solveUsingTab(n);
    return ans;
}

// SPACE OPTIMIZATION APPROACH - TC=O(N), SC=O(1)
// Steps:
// 1. Define `solveUsingSO` to compute derangements using space optimization.
// 2. Initialize base cases:
//    - `prev = 0` for `dp[1]` (no derangements for one item).
//    - `curr = 1` for `dp[2]` (one derangement for two items).
// 3. Loop from `i = 3` to `n`:
//    - Calculate `next = (i - 1) * (curr + prev) % 1000000007`.
//    - Update `prev` to `curr` and `curr` to `next`.
// 4. Return `curr`, which holds the derangement count for `n` items.
// 5. `countDerangements` calls `solveUsingSO` and returns the result.

long long int solveUsingSO(int n)
{
    long long int next;
    long long int curr;
    long long int prev;
    prev = 0, curr = 1;
    for (int i = 3; i <= n; i++)
    {
        next = ((i - 1) * (curr + prev)) % 1000000007;
        prev = curr;
        curr = next;
    }
    return curr;
}
long long int countDerangements(int n)
{
    long long int ans = solveUsingSO(n);
    return ans;
}