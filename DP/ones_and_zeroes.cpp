#include<iostream>
using namespace std;

// ONES AND ZEROES (LEETCODE 474)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(S*M*N), SC=O(S*M*N)

// Steps:
// 1. Define `solveUsingMem` with memoization to maximize the number of strings used within limits `m` (0's) and `n` (1's):
//    - Base case: If `i` equals the size of `nums`, return 0 (end of list).
//    - If value is memoized at `dp[i][m][n]`, return it.
// 2. Calculate `zeroes` and `ones` for `nums[i]` (current string's 0's and 1's).
// 3. Define two choices:
//    - `include`: If enough 0's and 1's are left, include the current string and recurse with updated `m` and `n`.
//    - `exclude`: Skip the current string and recurse without changing `m` or `n`.
// 4. Store the maximum of `include` and `exclude` in `dp[i][m][n]`.
// 5. In `findMaxForm`:
//    - Convert each string in `strs` to a pair of counts of 0's and 1's, and store in `nums`.
//    - Initialize 3D vector `dp` for memoization.
//    - Call `solveUsingMem` starting from index 0 and constraints `m` and `n`.

int solveUsingMem(vector<pair<int, int>> &nums, int i, int m, int n, vector<vector<vector<int>>> &dp)
{
    if (i == nums.size())
        return 0;
    if (dp[i][m][n] != -1)
    {
        return dp[i][m][n];
    }
    int zeroes = nums[i].first;
    int ones = nums[i].second;
    int include = 0, exclude = 0;
    if (m - zeroes >= 0 && n - ones >= 0)
    {
        include = 1 + solveUsingMem(nums, i + 1, m - zeroes, n - ones, dp);
    }
    exclude = 0 + solveUsingMem(nums, i + 1, m, n, dp);
    return dp[i][m][n] = max(include, exclude);
}
int findMaxForm(vector<string> &strs, int m, int n)
{
    vector<pair<int, int>> nums;
    for (auto str : strs)
    {
        int zeroes = 0, ones = 0;
        for (auto ch : str)
        {
            if (ch == '0')
                zeroes++;
            else
                ones++;
        }
        nums.push_back({zeroes, ones});
    }
    vector<vector<vector<int>>> dp(nums.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, -1)));
    return solveUsingMem(nums, 0, m, n, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(S*M*N), SC=O(S*M*N)
// Steps:
// 1. Define `solveUsingTab` to compute the maximum number of strings that can be formed within constraints `m` (0's) and `n` (1's) using tabulation:
//    - Initialize a 3D `dp` array with dimensions (num of strings + 1) x (m + 1) x (n + 1), set to 0.
//    - Traverse `nums` array in reverse to simulate choices for each string in decreasing order.
// 2. For each string in `nums`, calculate:
//    - `zeroes` and `ones` representing counts of '0' and '1' for the current string.
//    - `include` choice: If enough 0's and 1's are left, add the current string and retrieve previous best count from `dp`.
//    - `exclude` choice: Skip the current string, leaving `m` and `n` unchanged.
//    - Store the maximum of `include` and `exclude` in `dp[i][j][k]`.
// 3. In `findMaxForm`:
//    - Convert each string in `strs` into a pair of 0's and 1's counts and store in `nums`.
//    - Call `solveUsingTab` with constraints `m` and `n`.

int solveUsingTab(vector<pair<int, int>> &nums, int m, int n)
{
    vector<vector<vector<int>>> dp(nums.size() + 1, vector<vector<int>>(m + 1, vector<int>(n + 1, 0)));
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        for (int j = 0; j <= m; j++)
        {
            for (int k = 0; k <= n; k++)
            {
                int zeroes = nums[i].first;
                int ones = nums[i].second;
                int include = 0, exclude = 0;
                if (j - zeroes >= 0 && k - ones >= 0)
                {
                    include = 1 + dp[i + 1][j - zeroes][k - ones];
                }
                exclude = 0 + dp[i + 1][j][k];
                dp[i][j][k] = max(include, exclude);
            }
        }
    }
    return dp[0][m][n];
}
int findMaxForm(vector<string> &strs, int m, int n)
{
    vector<pair<int, int>> nums;
    for (auto str : strs)
    {
        int zeroes = 0, ones = 0;
        for (auto ch : str)
        {
            if (ch == '0')
                zeroes++;
            else
                ones++;
        }
        nums.push_back({zeroes, ones});
    }
    return solveUsingTab(nums, m, n);
}

// SPACE OPTIMIZATION APPROACH - TC=O(S*M*N), SC=O(M*N)
// Steps:
// 1. Count '0's and '1's in each string and store as pairs in `nums`.
// 2. Initialize a 2D dp array `dp` of size (m+1) x (n+1), where `dp[j][k]` represents the maximum number
//    of strings we can form with up to `j` zeroes and `k` ones.
// 3. For each `(zeroes, ones)` in `nums`:
//    a. Traverse `dp` in reverse from `m` to `zeroes` and `n` to `ones` to avoid overwriting current state.
//    b. Update `dp[j][k]` by choosing the max of:
//       - Including the string: 1 + `dp[j - zeroes][k - ones]`
//       - Excluding the string: `dp[j][k]` remains the same
// 4. The answer is stored in `dp[m][n]`, representing the maximum strings that fit the constraints.

int solveUsingSO(vector<pair<int, int>> &nums, int m, int n)
{
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = m; j >= 0; j--)
        {
            for (int k = n; k >= 0; k--)
            {
                int zeroes = nums[i].first;
                int ones = nums[i].second;
                int include = 0, exclude = 0;
                if (j - zeroes >= 0 && k - ones >= 0)
                {
                    include = 1 + dp[j - zeroes][k - ones];
                }
                exclude = 0 + dp[j][k];
                dp[j][k] = max(include, exclude);
            }
        }
    }
    return dp[m][n];
}
int findMaxForm(vector<string> &strs, int m, int n)
{
    vector<pair<int, int>> nums;
    for (auto str : strs)
    {
        int zeroes = 0, ones = 0;
        for (auto ch : str)
        {
            if (ch == '0')
                zeroes++;
            else
                ones++;
        }
        nums.push_back({zeroes, ones});
    }
    return solveUsingSO(nums, m, n);
}