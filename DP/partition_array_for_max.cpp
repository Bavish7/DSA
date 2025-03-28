#include<iostream>
using namespace std;

// PARTITION ARRAY FOR MAXIMUM SUM (LEETCODE 1043)
// TOP-DOWN MEMOIZATION - TC=O(N*K), SC=O(N)

// Steps:
// 1. Define `solveUsingMem()` as a recursive function with memoization to compute the maximum sum after partitioning.
// 2. Base case: If the current index `ind` reaches the array length `n`, return 0.
// 3. Check if the solution for `dp[ind]` is already computed, and if so, return it.
// 4. Initialize variables:
//    - `maxAns` to store the maximum sum result.
//    - `len` to track partition length.
//    - `maxEle` to store the maximum element in the current partition.
// 5. Iterate from index `ind` to `min(n, ind + k)`:
//    - Update partition length `len`.
//    - Track the maximum element in the current partition.
//    - Calculate the partition sum as `len * maxEle + solveUsingMem(j + 1, n, arr, k, dp)`.
//    - Update `maxAns` by comparing it with the current partition result.
// 6. Store and return the result in `dp[ind]`.

int solveUsingMem(int ind, int n, vector<int> &arr, int k, vector<int> &dp)
{
    if (ind == n)
        return 0;
    if (dp[ind] != -1)
        return dp[ind];
    int maxAns = INT_MIN;
    int len = 0;
    int maxEle = INT_MIN;
    for (int j = ind; j < min(n, ind + k); j++)
    {
        len++;
        maxEle = max(maxEle, arr[j]);
        int sum = (len * maxEle) + solveUsingMem(j + 1, n, arr, k, dp);
        maxAns = max(maxAns, sum);
    }
    return dp[ind] = maxAns;
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n, -1);
    return solveUsingMem(0, n, arr, k, dp);
}

// BOTTOM-UP TABULATION - TC=O(N*K), SC=O(N)
int solveUsingTab(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> dp(n + 1, 0);
    for (int ind = n - 1; ind >= 0; ind--)
    {
        int maxAns = INT_MIN;
        int len = 0;
        int maxEle = INT_MIN;
        for (int j = ind; j < min(n, ind + k); j++)
        {
            len++;
            maxEle = max(maxEle, arr[j]);
            int sum = (len * maxEle) + dp[j + 1];
            maxAns = max(maxAns, sum);
        }
        dp[ind] = maxAns;
    }
    return dp[0];
}
int maxSumAfterPartitioning(vector<int> &arr, int k)
{
    return solveUsingTab(arr, k);
}