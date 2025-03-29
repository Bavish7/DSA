#include<iostream>
using namespace std;

// PREDICT WINNER (LEETCODE 486)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(N^2)

// Steps:
// 1. Define `solveUsingMem` to calculate the maximum score difference Player 1 can achieve over Player 2 for any subarray [start, end].
// 2. Base Case: If `start == end`, return `nums[start]` (only one element to pick).
// 3. Recursive Case:
//    a. `diffByStart`: Choose the element at `start`, and calculate remaining score difference for `nums[start+1] to nums[end]`.
//    b. `diffByEnd`: Choose the element at `end`, and calculate remaining score difference for `nums[start] to nums[end-1]`.
//    c. Store and return the max of `diffByStart` and `diffByEnd` in `dp[start][end]` to maximize Player 1's advantage.
// 4. Player 1 wins or ties if the result from `solveUsingMem(nums, 0, n-1, dp)` is >= 0.

int solveUsingMem(vector<int> &nums, int start, int end, vector<vector<int>> &dp)
{
    if (start == end)
        return nums[start];
    if (dp[start][end] != -1)
    {
        return dp[start][end];
    }
    int diffByStart = nums[start] - solveUsingMem(nums, start + 1, end, dp);
    int diffByEnd = nums[end] - solveUsingMem(nums, start, end - 1, dp);
    dp[start][end] = max(diffByStart, diffByEnd);
    return dp[start][end];
}
bool predictTheWinner(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return solveUsingMem(nums, 0, nums.size() - 1, dp) >= 0;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^2), SC=O(N^2)
// Steps:
// 1. Initialize a 2D `dp` array where `dp[start][end]` holds the maximum score difference Player 1 can achieve over Player 2 for the subarray `nums[start...end]`.
// 2. Base Case: For subarrays of length 1 (i.e., `start == end`), set `dp[i][i] = nums[i]` since the only option is to pick that single element.
// 3. Fill `dp` in reverse order for `start` and increasing `end` to handle all subarray lengths.
// 4. For each subarray `[start, end]`:
//    a. `diffByStart`: Choose the element at `start`, then Player 2's best response for `nums[start+1...end]` is subtracted from Player 1's choice.
//    b. `diffByEnd`: Choose the element at `end`, then Player 2's best response for `nums[start...end-1]` is subtracted from Player 1's choice.
//    c. `dp[start][end] = max(diffByStart, diffByEnd)` to maximize Player 1's advantage.
// 5. Player 1 wins or ties if the result from `dp[0][n-1]` is >= 0.

int solveUsingTab(vector<int> &nums)
{
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(n + 1, -1));
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = nums[i];
    }
    for (int start = n - 1; start >= 0; start--)
    {
        for (int end = start + 1; end < n; end++)
        {
            int diffByStart = nums[start] - dp[start + 1][end];
            int diffByEnd = nums[end] - dp[start][end - 1];
            dp[start][end] = max(diffByStart, diffByEnd);
        }
    }
    return dp[0][n - 1];
}
bool predictTheWinner(vector<int> &nums)
{
    return solveUsingTab(nums) >= 0;
}