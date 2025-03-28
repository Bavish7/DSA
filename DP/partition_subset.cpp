#include<iostream>
using namespace std;

// PARTITION EQUAL SUBSET SUM (LEETCODE 416)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*TARGET), SC=O(N*TARGET)

// Steps:
// 1. Check if index is out of bounds:
//    - If yes, return false.
// 2. Check if currSum equals target:
//    - If yes, return true.
// 3. Check if currSum exceeds target:
//    - If yes, return false.
// 4. Check if dp[index][currSum] is already computed:
//    - If yes, return dp[index][currSum].
// 5. Recursively include or exclude nums[index] and update dp[index][currSum]:
//    - Set include to solveUsingMem(nums, index + 1, target, currSum + nums[index], dp).
//    - Set exclude to solveUsingMem(nums, index + 1, target, currSum + 0, dp).
//    - Store include || exclude in dp[index][currSum].
// 6. Return dp[index][currSum].

bool solveUsingMem(vector<int> &nums, int index, int target, int currSum, vector<vector<int>> &dp)
{
    if (index >= nums.size())
    {
        return false;
    }
    if (currSum == target)
    {
        return true;
    }
    if (currSum > target)
    {
        return false;
    }
    if (dp[index][currSum] != -1)
    {
        return dp[index][currSum];
    }
    bool include = solveUsingMem(nums, index + 1, target, currSum + nums[index], dp);
    bool exclude = solveUsingMem(nums, index + 1, target, currSum + 0, dp);
    dp[index][currSum] = include || exclude;
    return dp[index][currSum];
}
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum & 1)
    {
        return false;
    }
    int target = sum / 2;
    int index = 0;
    int currSum = 0;
    vector<vector<int>> dp(nums.size() + 1, vector<int>(target + 1, -1));
    bool ans = solveUsingMem(nums, index, target, currSum, dp);
    return ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*TARGET), SC=O(N*TARGET)
// Steps:
// 1. Initialize dp table with dimensions (nums.size() + 2) x (target + 1), all initialized to 0.
// 2. Set base case: dp[row][target] = true for all rows.
// 3. Iterate over nums from end to start (index = nums.size() - 1 to 0):
//    a. Iterate over currSum from target to 0:
//       - Calculate include as dp[index + 1][currSum + nums[index]] if within bounds.
//       - Set exclude as dp[index + 1][currSum].
//       - Store include || exclude in dp[index][currSum].
// 4. Return dp[0][0], which holds the result if subset sum equal to target exists.

bool solveUsingTab(vector<int> &nums, int target)
{
    vector<vector<int>> dp(nums.size() + 2, vector<int>(target + 1, 0));
    for (int row = 0; row <= nums.size(); row++)
    {
        dp[row][target] = 1;
    }
    for (int index = nums.size() - 1; index >= 0; index--)
    {
        for (int currSum = target; currSum >= 0; currSum--)
        {
            bool include = 0;
            if (currSum + nums[index] <= target)
            {
                include = dp[index + 1][currSum + nums[index]];
            }
            bool exclude = dp[index + 1][currSum];
            dp[index][currSum] = include || exclude;
        }
    }
    return dp[0][0];
}
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum & 1)
    {
        return false;
    }
    int target = sum / 2;
    bool ans = solveUsingTab(nums, target);
    return ans;
}

// SPACE OPTIMIZATION APPROACH - TC=O(N*TARGET), SC=O(TARGET)
// Steps:
// 1. Initialize two vectors: currRow and nextRow, each of size target + 1.
//    - currRow[currSum] will store the result for current iteration.
//    - nextRow[currSum] will store the result for the next iteration.
// 2. Initialize base case: currRow[target] = nextRow[target] = true.
// 3. Iterate over nums from end to start (index = nums.size() - 1 to 0):
//    a. Iterate over currSum from target to 0:
//       - Calculate include as nextRow[currSum + nums[index]] if within bounds.
//       - Set exclude as nextRow[currSum].
//       - Store include || exclude in currRow[currSum].
// 4. Move currRow to nextRow for the next iteration of nums.
// 5. Return nextRow[0], which holds the result if subset sum equal to target exists.
bool solveUsingSO(vector<int> &nums, int target)
{
    vector<int> currRow(target + 1);
    vector<int> nextRow(target + 1);
    currRow[target] = 1;
    nextRow[target] = 1;
    for (int index = nums.size() - 1; index >= 0; index--)
    {
        for (int currSum = target; currSum >= 0; currSum--)
        {
            bool include = 0;
            if (currSum + nums[index] <= target)
            {
                include = nextRow[currSum + nums[index]];
            }
            bool exclude = nextRow[currSum];
            currRow[currSum] = include || exclude;
        }
        nextRow = currRow;
    }
    return nextRow[0];
}
bool canPartition(vector<int> &nums)
{
    int sum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        sum += nums[i];
    }
    if (sum & 1)
    {
        return false;
    }
    int target = sum / 2;
    bool ans = solveUsingSO(nums, target);
    return ans;
}