#include<iostream>
using namespace std;

// STONE GAME II (LEETCODE 1140)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^3), SC=O(N^2)

// Steps:
// 1. Base case: If the index `i` reaches the end of the piles array, return 0, as there are no more stones to take.
// 2. Check if the result for the current state (i, m, alice) has been computed before in `dp`. If so, return it.
// 3. Initialize `ans` to `INT_MIN` if it’s Alice’s turn (maximize stones) and `INT_MAX` if it’s Bob’s turn (minimize stones).
// 4. Iterate over possible choices `x`, where Alice/Bob can pick between 1 and 2 * M stones, accumulating the total stones for each choice.
//    - If `i + x - 1` exceeds the array size, break out of the loop.
//    - Update the total number of stones picked so far in the current turn.
//    - If it's Alice's turn, calculate the maximum by choosing the current `total + solveUsingMem(...)` recursively.
//    - If it's Bob's turn, calculate the minimum by choosing `solveUsingMem(...)` recursively.
// 5. Memoize the result for the current state (i, m, alice) in `dp`.
// 6. Return the result of `dp[i][m][alice]`.

int solveUsingMem(vector<int> &piles, int i, int m, bool alice, vector<vector<vector<int>>> &dp)
{
    if (i == piles.size())
    {
        return 0;
    }
    if (dp[i][m][alice] != -1)
    {
        return dp[i][m][alice];
    }
    int ans = alice ? INT_MIN : INT_MAX;
    int total = 0;
    for (int x = 1; x <= 2 * m; x++)
    {
        if (i + x - 1 >= piles.size())
            break;
        total += piles[i + x - 1];
        if (alice)
        {
            ans = max(ans, total + solveUsingMem(piles, i + x, max(x, m), !alice, dp));
        }
        else
        {
            ans = min(ans, solveUsingMem(piles, i + x, max(x, m), !alice, dp));
        }
    }
    dp[i][m][alice] = ans;
    return dp[i][m][alice];
}
int stoneGameII(vector<int> &piles)
{
    int n = piles.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, -1)));
    return solveUsingMem(piles, 0, 1, 1, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^3), SC=O(N^2)
// Steps:
// 1. Initialize a 3D dp array `dp[i][m][alice]` where:
//    - `i` is the starting index in piles.
//    - `m` is the current M value, dictating how many piles can be picked.
//    - `alice` is a boolean indicating if it's Alice's (1) or Bob's (0) turn.
// 2. Populate the dp table from bottom to top:
//    - Traverse `i` from `n-1` to `0` (backwards through piles).
//    - Traverse `m` from `n` to `1` (possible values of M, bounded by `n`).
//    - For each state, set `ans` to `INT_MIN` if it's Alice's turn or `INT_MAX` if it's Bob's turn.
// 3. For each `x` (from 1 to 2*m), calculate total stones up to `i + x - 1` and use the dp table:
//    - If it's Alice's turn, update `ans` to maximize stones.
//    - If it's Bob's turn, update `ans` to minimize stones.
// 4. Store the computed value for dp[i][m][alice].
// 5. Return the answer from dp[0][1][1], which represents Alice starting at index 0 with M=1.

int solveUsingTab(vector<int> &piles)
{
    int n = piles.size();
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(n + 1, vector<int>(2, 0)));
    for (int i = n - 1; i >= 0; i--)
    {
        for (int m = n; m >= 1; m--)
        {
            for (int alice = 0; alice <= 1; alice++)
            {
                int ans = alice ? INT_MIN : INT_MAX;
                int total = 0;
                for (int x = 1; x <= 2 * m; x++)
                {
                    if (i + x - 1 >= piles.size())
                        break;
                    total += piles[i + x - 1];
                    if (alice)
                    {
                        ans = max(ans, total + dp[i + x][max(m, x)][!alice]);
                    }
                    else
                    {
                        ans = min(ans, dp[i + x][max(m, x)][!alice]);
                    }
                }
                dp[i][m][alice] = ans;
            }
        }
    }
    return dp[0][1][1];
}
int stoneGameII(vector<int> &piles)
{
    return solveUsingTab(piles);
}

// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(N^2)
// Steps:
// 1. Calculate the suffix sum array `suffixSum` such that `suffixSum[i]` represents the total stones from index `i` to the end of `piles`.
// 2. Define a recursive helper function `solveUsingMem` with memoization to compute the maximum stones Alice can collect starting from index `i` with a current M value `M`.
//    - If all remaining stones can be taken, return `suffixSum[i]`.
//    - Otherwise, try taking `x` stones (from 1 to 2 * M) and recursively calculate the maximum stones Alice can collect based on the opponent’s response.
//    - Store the result in `dp[i][M]` to avoid recomputation.
// 3. Return the result from `solveUsingMem(0, 1)` as the answer.

int solveUsingMem(vector<int> &piles, vector<vector<int>> &dp, const vector<int> &suffixSum, int i, int M)
{
    if (i == piles.size())
        return 0;
    if (i + 2 * M >= piles.size())
        return suffixSum[i];
    if (dp[i][M] != 0)
    {
        return dp[i][M];
    }
    int result = 0;
    for (int x = 1; x <= 2 * M; ++x)
    {
        result = max(result, suffixSum[i] - solveUsingMem(piles, dp, suffixSum, i + x, max(M, x)));
    }
    dp[i][M] = result;
    return result;
}
int stoneGameII(vector<int> &piles)
{
    int n = piles.size();
    if (n == 0)
        return 0;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    vector<int> suffixSum(n);
    suffixSum[n - 1] = piles[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        suffixSum[i] = piles[i] + suffixSum[i + 1];
    }
    return solveUsingMem(piles, dp, suffixSum, 0, 1);
}
// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^2), SC=O(N^2)
// Steps:
// 1. Calculate the suffix sum array `suffixSum` such that `suffixSum[i]` represents the total stones from index `i` to the end of `piles`.
// 2. Initialize a 2D dp array `dp[i][m]` to store the maximum stones Alice can collect starting from index `i` with M as `m`.
// 3. Populate the dp table from bottom to top and from right to left to ensure dependencies are filled in advance.
//    - If `i + 2 * m >= n`, Alice can take all remaining stones, so set `dp[i][m] = suffixSum[i]`.
//    - Otherwise, for each possible number of stones `x` (from 1 to 2 * m):
//      - Calculate the maximum score by considering Alice's best choice to maximize her stones collected.
// 4. Return `dp[0][1]` as the result, representing the maximum stones Alice can collect starting from index 0 with M = 1.

int stoneGameII(vector<int> &piles)
{
    int n = piles.size();
    if (n == 0)
        return 0;
    if (n == 1)
        return piles[0];
    vector<int> suffixSum(n);
    suffixSum[n - 1] = piles[n - 1];
    for (int i = n - 2; i >= 0; --i)
    {
        suffixSum[i] = piles[i] + suffixSum[i + 1];
    }
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int i = n - 1; i >= 0; --i)
    {
        for (int m = n - 1; m >= 1; m--)
        {
            if (i + 2 * m >= n)
            {
                dp[i][m] = suffixSum[i];
            }
            else
            {
                int maxScore = 0;
                for (int x = 1; x <= 2 * m; ++x)
                {
                    if (i + x - 1 < n)
                    {
                        maxScore = max(maxScore, suffixSum[i] - dp[i + x][max(m, x)]);
                    }
                }
                dp[i][m] = maxScore;
            }
        }
    }
    return dp[0][1];
}