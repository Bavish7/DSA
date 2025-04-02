#include<iostream>
using namespace std;

// UNIQUE BINARY SEARCH TREES (LEETCODE 96)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(N) 

// Steps:
// 1. Define `solve(n, dp)` to recursively compute the number of unique BSTs for `n` nodes.
// 2. Base case: Return `1` if `n <= 1`, as there's only one way to arrange zero or one node.
// 3. If `dp[n]` is already computed, return `dp[n]` to avoid redundant calculations.
// 4. For each root node from `1` to `n`:
//      - Calculate the number of unique BSTs for the left subtree with `i-1` nodes.
//      - Calculate the number of unique BSTs for the right subtree with `n-i` nodes.
//      - Multiply the two values to get unique BSTs for this root and add to `ans`.
// 5. Store `ans` in `dp[n]` and return it.
// 6. Call `solve(n, dp)` from `numTrees(n)` to get the final result.

int solveUsingMem(int n, vector<int> &dp)
{
    if (n <= 1)
    {
        return 1;
    }
    if (dp[n] != -1)
    {
        return dp[n];
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ans += solveUsingMem(i - 1, dp) * solveUsingMem(n - i, dp);
    }
    dp[n] = ans;
    return dp[n];
}
int numTrees(int n)
{
    vector<int> dp(n + 1, -1);
    return solveUsingMem(n, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^2), SC=O(N)
// Steps:
// 1. Initialize a DP array `dp` where `dp[i]` stores the number of unique BSTs for `i` nodes.
//      - Set base cases: `dp[0] = 1` and `dp[1] = 1`, as there's only one BST for zero or one node.
// 2. Populate `dp` from `2` to `n` (for each number of nodes):
//      - For each possible root node `i` from `1` to `index`:
//          - Compute the number of unique BSTs as `dp[i-1] * dp[index-i]` for left and right subtrees.
//          - Sum these results to get `dp[index]`.
// 3. Return `dp[n]`, which holds the final count of unique BSTs for `n` nodes.

int solveUsingTab(int n)
{
    vector<int> dp(n + 1, 0);
    dp[0] = 1;
    dp[1] = 1;
    for (int index = 2; index <= n; index++)
    {
        int ans = 0;
        for (int i = 1; i <= index; i++)
        {
            ans += dp[i - 1] * dp[index - i];
        }
        dp[index] = ans;
    }
    return dp[n];
}
int numTrees(int n)
{
    return solveUsingTab(n);
}

// USING CATALAN NUMBER - TC=O(N), SC=O(1)
int numTrees(int n)
{
    long long catalan = 1;
    for (int i = 0; i < n; i++)
    {
        catalan = catalan * 2 * (2 * i + 1) / (i + 2);
    }
    return static_cast<int>(catalan);
}