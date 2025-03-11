#include<iostream>
using namespace std;

// NUMBER OF DICE ROLLS WITH TARGET SUM (LEETCODE 1155)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*TARGET*K), SC=O(N*TARGET)

// Steps:
// 1. Base cases:
//    - If target is 0 and n is 0, return 1 (one way to achieve the target with n dice rolls).
//    - If target is not 0 and n is 0, return 0 (no way to achieve the target with n dice rolls).
//    - If target is 0 and n is not 0, return 0 (no way to achieve the target with n dice rolls).
//    - If dp[n][target] is already computed, return dp[n][target].
// 2. Initialize ans to 0.
// 3. Iterate from 1 to k (possible dice faces):
//    a. If target - i >= 0, recursively calculate recAns as solveUsingMem(n - 1, k, target - i, dp).
//    b. Update ans as (ans + recAns) % MOD.
// 4. Memoize dp[n][target] with ans.
// 5. Return dp[n][target].

long long int MOD = 1000000007;
int solveUsingMem(int n, int k, int target, vector<vector<int>> &dp)
{
    if (target == 0 && n == 0)
    {
        return 1;
    }
    if (target != 0 && n == 0)
    {
        return 0;
    }
    if (target == 0 && n != 0)
    {
        return 0;
    }
    if (dp[n][target] != -1)
    {
        return dp[n][target];
    }
    int ans = 0;
    for (int i = 1; i <= k; i++)
    {
        int recAns = 0;
        if (target - i >= 0)
        {
            recAns = (solveUsingMem(n - 1, k, target - i, dp)) % MOD;
        }
        ans = (ans % MOD + recAns % MOD) % MOD;
    }
    dp[n][target] = ans;
    return dp[n][target];
}
int numRollsToTarget(int n, int k, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
    int ans = solveUsingMem(n, k, target, dp);
    return ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*TARGET*K), SC=O(N*TARGET)
// Steps:
// 1. Initialize a 2D dp array dp[n+1][target+1] with all values set to 0.
// 2. Set dp[0][0] = 1, because there's one way to achieve sum 0 with 0 dice.
// 3. Iterate over the number of dice from 1 to n:
//    a. Iterate over the current sum from 1 to target:
//       i. Initialize ans to 0.
//       ii. Iterate over possible dice faces from 1 to k:
//           - If current sum - face is non-negative, update ans as dp[dice-1][current sum-face] % MOD.
//       iii. Update dp[dice][current sum] to ans % MOD.
// 4. Return dp[n][target], which contains the number of ways to achieve the target sum with n dice.

long long int MOD = 1000000007;
int solveUsingTab(int n, int k, int target)
{
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int dice = 1; dice <= n; dice++)
    {
        for (int currSum = 1; currSum <= target; currSum++)
        {
            int ans = 0;
            for (int face = 1; face <= k; face++)
            {
                int recAns = 0;
                if (currSum - face >= 0)
                {
                    recAns = (dp[dice - 1][currSum - face]) % MOD;
                }
                ans = (ans % MOD + recAns % MOD) % MOD;
            }
            dp[dice][currSum] = ans;
        }
    }
    return dp[n][target];
}
int numRollsToTarget(int n, int k, int target)
{
    int ans = solveUsingTab(n, k, target);
    return ans;
}

// SPACE OPTIMIZATION APPROACH - TC=O(N*TARGET*K), SC=O(TARGET)
// Steps:
// 1. Define `solveUsingSO` to compute the number of ways to reach a target sum using `n` dice with `k` faces using space optimization.
// 2. Initialize two vectors `curr` and `prev` to hold intermediate results for each dice roll.
//    - Set `prev[0] = 1` to represent reaching a sum of 0 with no dice.
// 3. Loop over each dice (from 1 to `n`):
//    - For each possible sum `currSum` from 0 to `target`:
//        - Initialize `ans = 0` to store the count of ways to reach `currSum`.
//        - Iterate over each face (from 1 to `k`):
//            - If `currSum - face >= 0`, add ways to reach `currSum - face` from `prev` to `ans`.
//            - Use `MOD` to keep results within bounds of large numbers.
//        - Set `curr[currSum]` to `ans` after iterating over faces.
//    - Set `prev` to `curr` for the next iteration.
// 4. Return `prev[target]`, which holds the number of ways to reach `target` with `n` dice.
// 5. `numRollsToTarget` calls `solveUsingSO` and returns the result.

long long int MOD = 1000000007;
int solveUsingSO(int n, int k, int target)
{
    vector<int> curr(target + 1, 0);
    vector<int> prev(target + 1, 0);
    prev[0] = 1;
    for (int dice = 1; dice <= n; dice++)
    {
        for (int currSum = 0; currSum <= target; currSum++)
        {
            int ans = 0;
            for (int face = 1; face <= k; face++)
            {
                int recAns = 0;
                if (currSum - face >= 0)
                {
                    recAns = (prev[currSum - face]) % MOD;
                }
                ans = (ans % MOD + recAns % MOD) % MOD;
            }
            curr[currSum] = ans;
        }
        prev = curr;
    }
    return prev[target];
}
int numRollsToTarget(int n, int k, int target)
{
    int ans = solveUsingSO(n, k, target);
    return ans;
}