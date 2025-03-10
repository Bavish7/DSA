#include<iostream>
using namespace std;

// CUT INTO SEGMENTS
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N), SC=O(N)

// Steps:
// 1. Define a `solveUsingMem` function to compute the maximum number of segments for a given length `n` using memoization.
// 2. Base cases:
//    - If `n == 0`, return 0 because no segments can be cut.
//    - If `n < 0`, return `INT_MIN` as it's invalid to cut negative length segments.
// 3. Check if the result for the current length `n` is already computed (i.e., present in the `dp` array). If yes, return the stored value.
// 4. Recursively compute the maximum number of segments by cutting lengths of `x`, `y`, or `z` and adding 1 for each cut. Store the results for these cuts in `xLen`, `yLen`, and `zLen`.
// 5. Store the maximum value of these results in `dp[n]`.
// 6. In the `cutSegments` function, initialize a `dp` array to store results for each length from 0 to `n`.
// 7. Call the `solveUsingMem` function to get the result for the full length `n`.
// 8. If the result is negative, return 0 as it's not possible to cut the rod. Otherwise, return the result.

int solveUsingMem(int n, int x, int y, int z, vector<int> &dp)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return INT_MIN;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int xLen = 1 + solveUsingMem(n - x, x, y, z, dp);
    int yLen = 1 + solveUsingMem(n - y, x, y, z, dp);
    int zLen = 1 + solveUsingMem(n - z, x, y, z, dp);
    dp[n] = max(xLen, max(yLen, zLen));
    return dp[n];
}
int cutSegments(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, -1);
    int ans = solveUsingMem(n, x, y, z, dp);
    if (ans < 0)
        return 0;
    return ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N), SC=O(N)
// Steps:
// 1. Initialize a `dp` array of size `n+1` with `INT_MIN`, to store the maximum number of segments that can be cut for each length from 0 to n.
// 2. Set `dp[0] = 0` because no segments can be cut for a rod of length 0.
// 3. Loop through each length `i` from 1 to `n`:
//    - For each length, check if cutting a segment of length `x`, `y`, or `z` is possible.
//    - If possible, update `dp[i]` by taking the maximum of its current value and `1 + dp[i - x]`, `1 + dp[i - y]`, or `1 + dp[i - z]`.
// 4. After processing all lengths, return `dp[n]`, which holds the maximum number of segments that can be cut for the rod of length `n`.
// 5. If `dp[n]` is negative, return 0, as it means it's not possible to cut the rod into the given segment sizes.

int solveUsingTab(int n, int x, int y, int z)
{
    vector<int> dp(n + 1, INT_MIN);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        int xLen = 0, yLen = 0, zLen = 0;
        if (i - x >= 0)
        {
            dp[i] = max(dp[i], 1 + dp[i - x]);
        }
        if (i - y >= 0)
        {
            dp[i] = max(dp[i], 1 + dp[i - y]);
        }
        if (i - z >= 0)
        {
            dp[i] = max(dp[i], 1 + dp[i - z]);
        }
    }
    return dp[n];
}
int cutSegments(int n, int x, int y, int z)
{
    int ans = solveUsingTab(n, x, y, z);
    if (ans < 0)
        return 0;
    return ans;
}