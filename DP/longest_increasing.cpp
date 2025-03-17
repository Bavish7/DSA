#include<iostream>
using namespace std;

// LONGEST INCREASING SUBSEQUENCE (LEETCODE 300)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(N^2)

// Steps:
// 1. If curr reaches the end of nums, return 0 because no more elements can be included.
// 2. If dp[curr][prev + 1] is already computed (not -1), return its value from dp to avoid recomputation.
// 3. Calculate include:
//    a. If prev is -1 (starting case) or nums[curr] is greater than nums[prev], include curr in the sequence.
//    b. Recursively call solveUsingMem with curr as prev and curr + 1 as curr to include curr.
// 4. Calculate exclude:
//    a. Exclude curr from the sequence, keeping prev unchanged.
//    b. Recursively call solveUsingMem with prev and curr + 1.
// 5. Store the maximum of include and exclude in dp[curr][prev + 1].
// 6. Return dp[curr][prev + 1] as the length of the longest increasing subsequence from curr to the end of nums.

int solveUsingMem(int prev, int curr, vector<int> &nums, vector<vector<int>> &dp)
{
    if (curr == nums.size())
    {
        return 0;
    }
    if (dp[curr][prev + 1] != -1)
    {
        return dp[curr][prev + 1];
    }
    int include = 0;
    if (prev == -1 || nums[curr] > nums[prev])
    {
        include = 1 + solveUsingMem(curr, curr + 1, nums, dp);
    }
    int exclude = 0 + solveUsingMem(prev, curr + 1, nums, dp);
    dp[curr][prev + 1] = max(include, exclude);
    return dp[curr][prev + 1];
}
int lengthOfLIS(vector<int> &nums)
{
    int prev = -1;
    int curr = 0;
    vector<vector<int>> dp(nums.size() + 1, vector<int>(nums.size() + 1, -1));
    int ans = solveUsingMem(prev, curr, nums, dp);
    return ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^2), SC=O(N^2)
// Steps:
// 1. Initialize dp[n+1][n+1] where n is the size of nums.
// 2. Iterate from end to start of nums:
//    a. Iterate from curr = n-1 to 0:
//       i. Iterate from prev = curr-1 to -1:
//          - Calculate include:
//            * If prev is -1 (starting case) or nums[curr] > nums[prev], include curr in the sequence.
//            * Set include to 1 + dp[curr + 1][curr + 1] (length of subsequence starting from curr + 1).
//          - Calculate exclude:
//            * Exclude curr from the sequence, keeping prev unchanged.
//            * Set exclude to dp[curr + 1][prev + 1] (length of subsequence starting from curr + 1 with prev).
//          - Store the maximum of include and exclude in dp[curr][prev + 1].
// 3. Return dp[0][0] as the length of the longest increasing subsequence from the start of nums.

int solveUsingTab(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int curr = n - 1; curr >= 0; curr--)
    {
        for (int prev = curr - 1; prev >= -1; prev--)
        {
            int include = 0;
            if (prev == -1 || nums[curr] > nums[prev])
            {
                include = 1 + dp[curr + 1][curr + 1];
            }
            int exclude = 0 + dp[curr + 1][prev + 1];
            dp[curr][prev + 1] = max(include, exclude);
        }
    }
    return dp[0][0];
}
int lengthOfLIS(vector<int> &nums)
{
    int ans = solveUsingTab(nums);
    return ans;
}

// SPACE OPTIMIZATION APPROACH - TC=O(N^2), SC=O(2*N)
// Steps:
// 1. Initialize curr[n+1] and next[n+1] arrays where n is the size of nums.
//    - curr array stores the current maximum lengths of subsequences ending at each index.
//    - next array helps in swapping and storing results for the next iteration.
// 2. Iterate from end to start of nums:
//    a. Iterate from i = n-1 to 0:
//       i. Iterate from j = i-1 to -1:
//          - Calculate include:
//            * If j is -1 (starting case) or nums[i] > nums[j], include nums[i] in the subsequence.
//            * Set include to 1 + next[i + 1] (length of subsequence starting from i + 1).
//          - Calculate exclude:
//            * Exclude nums[i] and keep the previous subsequence length.
//            * Set exclude to next[j + 1] (length of subsequence starting from j + 1).
//          - Store the maximum of include and exclude in curr[j + 1].
//    b. Swap curr and next arrays for the next iteration.
// 3. Return next[0] as the length of the longest increasing subsequence starting from the beginning of nums.

int solveUsingSO(vector<int> &nums)
{
    int n = nums.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= -1; j--)
        {
            int include = 0;
            if (j == -1 || nums[i] > nums[j])
            {
                include = 1 + next[i + 1];
            }
            int exclude = 0 + next[j + 1];
            curr[j + 1] = max(include, exclude);
        }
        next = curr;
    }
    return next[0];
}
int lengthOfLIS(vector<int> &nums)
{
    int ans = solveUsingSO(nums);
    return ans;
}

// SPACE OPTIMIZATION APPROACH - TC=O(N^2), SC=O(N)
// Steps:
// 1. Initialize a DP array `dp` where `dp[i]` stores the length of the LIS ending at index `i`. Set all values to 1 initially, as every element alone forms an increasing subsequence of length 1.
// 2. Iterate over each index `i` of the array:
//    - For each `i`, check all previous elements `j` (where `j < i`):
//       - If `nums[i] > nums[j]`, update `dp[i]` as `max(dp[i], dp[j] + 1)`.
// 3. Maintain `maxi`, the maximum LIS found so far.
// 4. Return `maxi` as the final answer.

int solveUsingSO2(vector<int> &nums)
{
    int n = nums.size();
    int maxi = 1;
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (nums[i] > nums[j] && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        if(dp[i]>maxi){
            maxi=dp[i];
        }
    }
    return maxi;
}
int lengthOfLIS(vector<int> &nums)
{
    int ans = solveUsingSO2(nums);
    return ans;
}

// USING BINARY SEARCH - TC=O(N*LOGN), SC=O(N)
// Steps:
// 1. Initialize an empty vector ans to store the increasing subsequence.
// 2. Iterate through each element in nums starting from the second element:
//    a. If nums[i] is greater than the last element in ans (ans.back()), push nums[i] to ans.
//    b. Otherwise, use binary search (lower_bound) to find the position in ans where nums[i] can replace an element:
//       - Replace the element at this position with nums[i].
// 3. Return the size of ans, which represents the length of the longest increasing subsequence.
int solveUsingBS(vector<int> &nums)
{
    vector<int> ans;
    ans.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > ans.back())
        {
            ans.push_back(nums[i]);
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[index] = nums[i];
        }
    }
    return ans.size();
}
int lengthOfLIS(vector<int> &nums)
{
    int ans = solveUsingBS(nums);
    return ans;
}