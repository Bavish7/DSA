#include<iostream>
using namespace std;

// BUILD ARRAY WHERE YOU CAN FIND THE MAXIMUM EXACTLY K COMPARISONS (LEETCODE 1420)
// TOP-DOWN APPRACH - RECURSION + MEMOIZATION - TC=O(M^2*N*K), SC=O(M*N*K)

// Steps:
// 1. Define a recursive function with memoization: solve(index, cost, maxEle)
//    - index = current position in the array (0 to n-1)
//    - cost = number of times maximum has increased so far (must be exactly k)
//    - maxEle = current maximum value in the array
// 2. Base Case: If index == n, return 1 if cost == k (valid array), else 0.
// 3. Use memoization to avoid recomputation (dp[index][maxEle][cost]).
// 4. For every number from 1 to m:
//    - If number > maxEle → max increases, so increment cost.
//    - Else keep cost same (no new maximum).
// 5. Recur for the next index and accumulate results modulo 1e9+7.
// 6. Initial call starts with index = 0, cost = 0, maxEle = 0.
// 7. The final answer is the number of valid arrays with length n and search cost k.

int mod = 1e9 + 7;
int solveUsingMem(int index, int cost, int maxEle, int n, int m, int k, vector<vector<vector<int>>> &dp)
{
    if (index == n)
    {
        return (cost == k);
    }
    if (cost > k)
        return 0;
    if (dp[index][maxEle][cost] != -1)
        return dp[index][maxEle][cost];
    int ans = 0;
    for (int i = 1; i <= m; i++)
    {
        if (i > maxEle)
        {
            ans = (ans + solveUsingMem(index + 1, cost + 1, i, n, m, k, dp)) % mod;
        }
        else
        {
            ans = (ans + solveUsingMem(index + 1, cost, maxEle, n, m, k, dp)) % mod;
        }
    }
    return dp[index][maxEle][cost] = ans % mod;
}
int numOfArrays(int n, int m, int k)
{
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(k + 1, -1)));
    return solveUsingMem(0, 0, 0, n, m, k, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(M^2*N*K), SC=O(M*N*K)
// Steps:
// 1. Create a 3D dp array dp[index][maxEle][cost] where:
//    - index = current position in the array
//    - maxEle = current maximum value in the array
//    - cost = how many times the maximum value has increased so far
// 2. Initialize base case: when index == n and cost == k → dp[n][i][k] = 1 for all valid i (array is complete and valid).
// 3. Iterate backwards from index = n-1 to 0.
// 4. For each index, maxEle, and cost:
//    - Try all numbers from 1 to m:
//      - If current number i > maxEle → it's a new max → cost increases → dp[index+1][i][cost+1]
//      - Else → no new max → dp[index+1][maxEle][cost]
// 5. Store the accumulated answer for each state in dp[index][maxEle][cost].
// 6. Return dp[0][0][0] as it represents the number of valid arrays starting from scratch.

int mod = 1e9 + 7;
int solveUsingTab(int n, int m, int k)
{
    vector<vector<vector<int>>> dp(n + 2, vector<vector<int>>(m + 2, vector<int>(k + 2, 0)));
    for (int i = 1; i <= m; i++)
    {
        dp[n][i][k] = 1;
    }
    for (int index = n - 1; index >= 0; index--)
    {
        for (int maxEle = m; maxEle >= 0; maxEle--)
        {
            for (int cost = k; cost >= 0; cost--)
            {
                int ans = 0;
                for (int i = 1; i <= m; i++)
                {
                    if (i > maxEle)
                    {
                        ans = (ans + dp[index + 1][i][cost + 1]) % mod;
                    }
                    else
                    {
                        ans = (ans + dp[index + 1][maxEle][cost]) % mod;
                    }
                }
                dp[index][maxEle][cost] = ans % mod;
            }
        }
    }
    return dp[0][0][0];
}
int numOfArrays(int n, int m, int k)
{
    return solveUsingTab(n, m, k);
}

// SPACE OPTIMIZATION APPROACH - TC=O(M^2*N*K), SC=O(M*K)
// Steps:
// 1. This version optimizes space by reducing 3D DP to 2 layers: `curr` and `next`, each of size [m+2][k+2].
// 2. Initialize base case: when index == n and cost == k, set next[i][k] = 1 for all i in 1 to m.
// 3. Iterate index backward from n-1 to 0.
// 4. For each (maxEle, cost) pair:
//    - Try placing numbers 1 to m:
//      - If i > maxEle: new max, increase cost → next[i][cost+1]
//      - Else: keep cost same → next[maxEle][cost]
// 5. Sum all valid ways and assign to curr[maxEle][cost].
// 6. After processing an index, set next = curr for next iteration.
// 7. Final result is stored in next[0][0], representing all ways to build a valid array from scratch.

int mod = 1e9 + 7;
int solveUsingSO(int n, int m, int k)
{
    vector<vector<int>> curr(m + 2, vector<int>(k + 2, 0));
    vector<vector<int>> next(m + 2, vector<int>(k + 2, 0));
    for (int i = 1; i <= m; i++)
    {
        next[i][k] = 1;
    }
    for (int index = n - 1; index >= 0; index--)
    {
        for (int maxEle = m; maxEle >= 0; maxEle--)
        {
            for (int cost = k; cost >= 0; cost--)
            {
                int ans = 0;
                for (int i = 1; i <= m; i++)
                {
                    if (i > maxEle)
                    {
                        ans = (ans + next[i][cost + 1]) % mod;
                    }
                    else
                    {
                        ans = (ans + next[maxEle][cost]) % mod;
                    }
                }
                curr[maxEle][cost] = ans % mod;
            }
        }
        next = curr;
    }
    return next[0][0];
}
int numOfArrays(int n, int m, int k)
{
    return solveUsingSO(n, m, k);
}