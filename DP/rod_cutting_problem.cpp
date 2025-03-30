#include<iostream>
using namespace std;

// ROD CUTTING PROBLEM
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*N), SC=O(N*N)

// Steps:
// 1. Base case: When `index == 0`, return `n * price[0]` as only 1-length rods are available.  
// 2. Use memoization to avoid redundant computations by storing results in `dp[index][n]`.  
// 3. Compute `exclude` by skipping the current rod length (`index`).  
// 4. Compute `include` if the current rod length fits (`index + 1 <= n`), adding its price and recursively solving for the reduced length.  
// 5. Return the maximum of `include` and `exclude` as the result.  
// 6. Initialize the `dp` table and solve for the maximum price using the recursive function.

int solveUsingMem(int index, int n, vector<int> &price, vector<vector<int>> &dp)
{
    if (index == 0)
        return n * price[0];
    if (dp[index][n] != -1)
        return dp[index][n];
    int exclude = solveUsingMem(index - 1, n, price, dp);
    int include = INT_MIN;
    int rodLen = index + 1;
    if (rodLen <= n)
    {
        include = price[index] + solveUsingMem(index, n - rodLen, price, dp);
    }
    return dp[index][n] = max(include, exclude);
}
int cutRod(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    return solveUsingMem(n - 1, n, price, dp);
}

// BOTTOM UP APPROACH - ITERATIVE + TABULATION - TC=O(N*N), SC=O(N*N)
// Steps:
// 1. Initialize `dp[0][N]` for all capacities `N` by calculating `N * price[0]` when only 1-length rods are available.  
// 2. Traverse through possible rod lengths (`index`) and capacities (`N`).  
// 3. Compute `exclude` by skipping the current rod length (`index`).  
// 4. Compute `include` if the current rod length fits (`index + 1 <= N`), adding its price and solving for the reduced length using `dp[index][N - rodLen]`.  
// 5. Store the maximum of `include` and `exclude` in `dp[index][N]`.  
// 6. Return the result stored in `dp[n - 1][n]`.

int solveUsingTab(vector<int> &price, int n)
{
    vector<vector<int>> dp(n, vector<int>(n + 1, 0));
    for (int N = 0; N <= n; N++)
    {
        dp[0][N] = N * price[0];
    }
    for (int index = 1; index < n; index++)
    {
        for (int N = 0; N <= n; N++)
        {
            int exclude = dp[index - 1][N];
            int include = INT_MIN;
            int rodLen = index + 1;
            if (rodLen <= N)
            {
                include = price[index] + dp[index][N - rodLen];
            }
            dp[index][N] = max(include, exclude);
        }
    }
    return dp[n - 1][n];
}
int cutRod(vector<int> &price, int n)
{
    return solveUsingTab(price, n);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N*N), SC=O(N)
// Steps:
// 1. Use two 1D vectors `prev` and `curr` to reduce space complexity compared to the 2D table.  
// 2. Initialize `prev[N]` by calculating `N * price[0]` when only 1-length rods are available.  
// 3. Iterate through possible rod lengths (`index`) and capacities (`N`).  
// 4. Compute `exclude` by skipping the current rod length (`index`).  
// 5. Compute `include` if the current rod length fits (`index + 1 <= N`), adding its price and using `curr[N - rodLen]`.  
// 6. Store the maximum of `include` and `exclude` in `curr[N]`.  
// 7. After each rod length iteration, assign `curr` to `prev` for the next iteration.  
// 8. Return the final result stored in `prev[n]`.

int solveUsingSO(vector<int> &price, int n)
{
    vector<int> prev(n + 1, 0), curr(n + 1, 0);
    for (int N = 0; N <= n; N++)
    {
        prev[N] = N * price[0];
    }
    for (int index = 1; index < n; index++)
    {
        for (int N = 0; N <= n; N++)
        {
            int exclude = prev[N];
            int include = INT_MIN;
            int rodLen = index + 1;
            if (rodLen <= N)
            {
                include = price[index] + curr[N - rodLen];
            }
            curr[N] = max(include, exclude);
        }
        prev = curr;
    }
    return prev[n];
}
int cutRod(vector<int> &price, int n)
{
    return solveUsingSO(price, n);
}