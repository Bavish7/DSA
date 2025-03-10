#include<iostream>
using namespace std;

// COUNT SUBSETS WITH SUM K
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*TARGET), SC=O(N*TARGET)

// Steps:
// 1. Define a DP table `dp[index][target]` to store the number of ways to achieve the `target` using elements up to `index`.
// 2. Base cases:
//    - If `index == 0`:
//      - Return 2 if both `target == 0` and `arr[0] == 0` to account for picking and not picking the zero.
//      - Return 1 if either `target == arr[0]` or `target == 0`, otherwise return 0.
// 3. For recursive calls:
//    - Include the current element if it does not exceed the target.
//    - Exclude the current element.
// 4. Store and return the result modulo `1e9 + 7` to avoid overflow issues.
// 5. Use memoization to store previously computed results for efficiency.

int mod = 1e9 + 7;
int solveUsingMem(int index, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (index == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == arr[index] || target == 0)
            return 1;
        else
            return 0;
    }
    if (dp[index][target] != -1)
        return dp[index][target];
    int include = 0;
    if (target >= arr[index])
    {
        include = solveUsingMem(index - 1, target - arr[index], arr, dp);
    }
    int exclude = solveUsingMem(index - 1, target, arr, dp);
    return dp[index][target] = (include + exclude) % mod;
}
int findWays(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    return solveUsingMem(n - 1, k, arr, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*TARGET), SC=O(N*TARGET)
// Steps:
// 1. Initialize a DP table `dp[index][target]` where `dp[i][j]` stores the number of ways to form the sum `j` using the first `i` elements.
// 2. Handle base cases:
//    - If `index == 0`:
//      - Set `dp[0][0] = 2` if both `target == 0` and `arr[0] == 0`, to count picking and not picking the zero.
//      - Set `dp[0][target] = 1` if `target == arr[0]` or `target == 0`, else set it to 0.
// 3. For each subsequent `index`:
//    - Compute `include` by considering the current element if `target >= arr[index]`.
//    - Compute `exclude` by ignoring the current element.
// 4. Store the result as `(include + exclude) % mod` to avoid overflow issues.
// 5. Return `dp[n - 1][k]` as the final answer.

int mod = 1e9 + 7;
int solveUsingTab(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(k + 1, -1));
    for (int index = 0; index < n; index++)
    {
        for (int target = 0; target <= k; target++)
        {
            if (index == 0)
            {
                if (target == 0 && arr[0] == 0)
                    dp[index][target] = 2;
                else if (target == arr[index] || target == 0)
                    dp[index][target] = 1;
                else
                    dp[index][target] = 0;
            }
            else
            {
                int include = 0;
                if (target >= arr[index])
                {
                    include = dp[index - 1][target - arr[index]];
                }
                int exclude = dp[index - 1][target];
                dp[index][target] = (include + exclude) % mod;
            }
        }
    }
    return dp[n - 1][k];
}
int findWays(vector<int> &arr, int k)
{
    return solveUsingTab(arr, k);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N*TARGET), SC=O(TARGET)
// Steps:
// 1. Use two vectors `prev` and `curr` of size `k + 1` to store the DP states.
// 2. For `index == 0`, handle:
//    - Base case: If `target == 0 && arr[0] == 0`, set `curr[0] = 2` (counting pick & non-pick).
//    - Set `curr[target] = 1` if `target == 0` or `target == arr[0]`, else set it to 0.
// 3. For subsequent indices:
//    - Compute `include` if `target >= arr[index]`, else skip.
//    - Compute `exclude` by referring to `prev[target]`.
//    - Store result as `(include + exclude) % mod`.
// 4. Update `prev = curr` to reuse space and reduce memory usage.
// 5. Return `prev[k]` as the final answer.

int mod = 1e9 + 7;
int solveUsingSO(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> prev(k + 1, 0), curr(k + 1, 0);
    for (int index = 0; index < n; index++)
    {
        for (int target = 0; target <= k; target++)
        {
            if (index == 0)
            {
                if (target == 0 && arr[0] == 0)
                    curr[target] = 2;
                else if (target == arr[index] || target == 0)
                    curr[target] = 1;
                else
                    curr[target] = 0;
            }
            else
            {
                int include = 0;
                if (target >= arr[index])
                {
                    include = prev[target - arr[index]];
                }
                int exclude = prev[target];
                curr[target] = (include + exclude) % mod;
            }
        }
        prev = curr;
    }
    return prev[k];
}
int findWays(vector<int> &arr, int k)
{
    return solveUsingSO(arr, k);
}