#include<iostream>
using namespace std;

// MATRIX CHAIN MULTIPLICATION
// TOP-DOWN MEMOIZATION - TC=O(N^3), SC=O(N^2)

// Steps:
// 1. Define `dp[i][j]` as the minimum multiplication cost for matrices from index `i` to `j`.
// 2. Base case: If `i == j`, there's only one matrix, so no multiplication is required.
// 3. For each possible partition point `k` between `i` and `j`, recursively compute:
//    a. Cost of multiplying matrices from `i` to `k`.
//    b. Cost of multiplying matrices from `k + 1` to `j`.
//    c. Cost of merging the two results, given by `arr[i - 1] * arr[k] * arr[j]`.
// 4. Take the minimum of all possible partition costs and store it in `dp[i][j]`.
// 5. Return the minimum multiplication cost from `1` to `N - 1`.

int solveUsingMem(vector<int> &arr, int i, int j, vector<vector<int>> &dp)
{
    if (i == j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = INT_MAX;
    for (int k = i; k <= j - 1; k++)
    {
        int ans = solveUsingMem(arr, i, k, dp) + solveUsingMem(arr, k + 1, j, dp) + arr[i - 1] * arr[k] * arr[j];
        mini = min(ans, mini);
    }
    return dp[i][j] = mini;
}
int matrixMultiplication(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    return solveUsingMem(arr, 1, N - 1, dp);
}

// BOTTOM-UP TABULATION - TC=O(N^3), SC=O(N^2)
// Steps:
// 1. Initialize the diagonal elements of `dp` to `0` since multiplying a single matrix requires no cost.
// 2. Iterate over the matrix chain in reverse for the starting index `i` and forward for the ending index `j`.
// 3. For each subproblem defined by `dp[i][j]`, evaluate all possible partitions between `i` and `j` using index `k`.
// 4. Compute the cost for each partition as `dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j]`.
// 5. Store the minimum cost of these partitions in `dp[i][j]`.
// 6. Return the value of `dp[1][N - 1]`, representing the minimum cost of multiplying matrices from `1` to `N - 1`.

int solveUsingTab(vector<int> &arr, int N)
{
    vector<vector<int>> dp(N, vector<int>(N, -1));
    for (int i = 0; i < N; i++)
    {
        dp[i][i] = 0;
    }
    for (int i = N - 1; i >= 1; i--)
    {
        for (int j = i + 1; j < N; j++)
        {
            int mini = INT_MAX;
            for (int k = i; k <= j - 1; k++)
            {
                int ans = dp[i][k] + dp[k + 1][j] + arr[i - 1] * arr[k] * arr[j];
                mini = min(ans, mini);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][N - 1];
}
int matrixMultiplication(vector<int> &arr, int N)
{
    return solveUsingTab(arr, N);
}