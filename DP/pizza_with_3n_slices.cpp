#include<iostream>
using namespace std;

// PIZZA WITH 3N SLICES (LEETCODE 1388)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(N^2)

// Steps:
// 1. Define `solveUsingMem` to maximize the sum of selected slice values.
// 2. Base Cases:
//    - If `k` slices are selected, return 0 as no more slices can be chosen.
//    - If `index > endIndex`, return 0 as we have reached beyond the allowed range.
// 3. Check if `dp[index][k]` is already computed; if so, return it to avoid recomputation.
// 4. Recursive Choices:
//      - `include`: Add `slices[index]` and call `solveUsingMem` on `index+2` with `k-1` slices remaining.
//      - `exclude`: Skip the current slice, call `solveUsingMem` on `index+1` with `k` slices remaining.
//      - Store the maximum of `include` and `exclude` in `dp[index][k]`.
// 5. In `maxSizeSlices`, solve the problem in two cases (to handle circular condition):
//      - Case 1: Select from slices `[0, n-2]`.
//      - Case 2: Select from slices `[1, n-1]`.
// 6. Return the maximum of these two cases as the answer.

int solveUsingMem(int index, int endIndex, vector<int> &slices, int k, vector<vector<int>> &dp)
{
    if (k == 0 || index > endIndex)
    {
        return 0;
    }
    if (dp[index][k] != -1)
    {
        return dp[index][k];
    }
    int include = slices[index] + solveUsingMem(index + 2, endIndex, slices, k - 1, dp);
    int exclude = 0 + solveUsingMem(index + 1, endIndex, slices, k, dp);
    dp[index][k] = max(include, exclude);
    return dp[index][k];
}
int maxSizeSlices(vector<int> &slices)
{
    int n = slices.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int case1 = solveUsingMem(0, n - 2, slices, n / 3, dp);
    vector<vector<int>> dp2(n, vector<int>(n, -1));
    int case2 = solveUsingMem(1, n - 1, slices, n / 3, dp2);
    return max(case1, case2);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^2), SC=O(N^2)
// Steps:
// 1. Initialize two DP tables, `dp1` and `dp2`, where:
//      - `dp1[i][k]` holds the maximum sum of selected slices when considering slices from [0, n-2].
//      - `dp2[i][k]` holds the maximum sum when considering slices from [1, n-1].
// 2. Populate `dp1` and `dp2` bottom-up, starting from the last valid slice index for each case.
// 3. For each slice `index`, compute:
//      - `include`: Add `slices[index]` and move to `index+2` with `k-1` slices left to pick.
//      - `exclude`: Skip `slices[index]` and move to `index+1` with `k` slices left.
// 4. Set `dp1[index][k]` and `dp2[index][k]` as the maximum of `include` and `exclude`.
// 5. Retrieve results for each case:
//      - `case1` as `dp1[0][n/3]` when picking from `[0, n-2]`.
//      - `case2` as `dp2[1][n/3]` when picking from `[1, n-1]`.
// 6. Return the maximum of `case1` and `case2` as the answer.

int solveUsingTab(vector<int> &slices)
{
    int n = slices.size();
    vector<vector<int>> dp1(n + 2, vector<int>(n, 0));
    vector<vector<int>> dp2(n + 2, vector<int>(n, 0));
    for (int index = n - 2; index >= 0; index--)
    {
        for (int k = 1; k <= n / 3; k++)
        {
            int include = slices[index] + dp1[index + 2][k - 1];
            int exclude = 0 + dp1[index + 1][k];
            dp1[index][k] = max(include, exclude);
        }
    }
    int case1 = dp1[0][n / 3];
    for (int index = n - 1; index >= 1; index--)
    {
        for (int k = 1; k <= n / 3; k++)
        {
            int include = slices[index] + dp2[index + 2][k - 1];
            int exclude = 0 + dp2[index + 1][k];
            dp2[index][k] = max(include, exclude);
        }
    }
    int case2 = dp2[1][n / 3];
    return max(case1, case2);
}
int maxSizeSlices(vector<int> &slices)
{
    return solveUsingTab(slices);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N^2), SC=O(N)
// Steps:
// 1. Initialize vectors `prev1`, `curr1`, `next1` for Case 1 (slices [0, n-2]) and `prev2`, `curr2`, `next2` for Case 2 (slices [1, n-1]).
// 2. For Case 1 (from `index = n-2` down to `0`):
//      - For each `k` (1 to n/3), calculate:
//          - `include`: Add `slices[index]` and move to `next1[k-1]`.
//          - `exclude`: Skip `slices[index]` and use `curr1[k]`.
//          - Store max of `include` and `exclude` in `prev1[k]`.
//      - Shift states by setting `next1 = curr1` and `curr1 = prev1`.
// 3. Set `case1` to `curr1[n/3]`.
// 4. Repeat step 2 for Case 2 (from `index = n-1` down to `1`) using `prev2`, `curr2`, `next2`.
// 5. Set `case2` to `curr2[n/3]`.
// 6. Return `max(case1, case2)`.

int solveUsingSO(vector<int> &slices)
{
    int n = slices.size();
    vector<int> prev1(n + 2, 0);
    vector<int> curr1(n + 2, 0);
    vector<int> next1(n + 2, 0);
    vector<int> prev2(n + 2, 0);
    vector<int> curr2(n + 2, 0);
    vector<int> next2(n + 2, 0);
    for (int index = n - 2; index >= 0; index--)
    {
        for (int k = 1; k <= n / 3; k++)
        {
            int include = slices[index] + next1[k - 1];
            int exclude = 0 + curr1[k];
            prev1[k] = max(include, exclude);
        }
        next1 = curr1;
        curr1 = prev1;
    }
    int case1 = curr1[n / 3];
    for (int index = n - 1; index >= 1; index--)
    {
        for (int k = 1; k <= n / 3; k++)
        {
            int include = slices[index] + next2[k - 1];
            int exclude = 0 + curr2[k];
            prev2[k] = max(include, exclude);
        }
        next2 = curr2;
        curr2 = prev2;
    }
    int case2 = curr2[n / 3];
    return max(case1, case2);
}
int maxSizeSlices(vector<int> &slices)
{
    return solveUsingSO(slices);
}