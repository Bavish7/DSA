#include<iostream>
using namespace std;

// HARD PARTITION WITH MINIMUM DIFFERENCE
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*SUM), SC=O(N*SUM)

// Steps:
// 1. Calculate the total sum of the array.
// 2. Initialize a DP table dp, where dp[i][j] represents whether it's possible to form sum j using the first i elements of the array.
// 3. Use subset sum logic to populate the DP table. Start by filling for the base cases:
//    - A sum of 0 is always possible.
//    - If only the first element is considered, check if it can form the target sum.
// 4. For each sum from 1 to total sum, check if it can be formed using the first n-1 elements, or by including the current element.
// 5. After filling the DP table, find the smallest difference between two subset sums by iterating through all possible sums and checking if they can be formed.
// 6. The result is the minimum difference found.

bool subsetSumUtil(int ind, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (target == 0)
        return dp[ind][target] = true;
    if (ind == 0)
        return dp[ind][target] = (arr[0] == target);
    if (dp[ind][target] != -1)
        return dp[ind][target];
    bool notTaken = subsetSumUtil(ind - 1, target, arr, dp);
    bool taken = false;
    if (arr[ind] <= target)
        taken = subsetSumUtil(ind - 1, target - arr[ind], arr, dp);
    return dp[ind][target] = notTaken || taken;
}
int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }
    vector<vector<int>> dp(n, vector<int>(totSum + 1, -1));
    for (int i = 0; i <= totSum; i++)
    {
        bool dummy = subsetSumUtil(n - 1, i, arr, dp);
    }
    int mini = 1e9;
    for (int i = 0; i <= totSum; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*SUM), SC=O(N*SUM)
// Steps:
// 1. Calculate the total sum of the array.
// 2. Initialize a DP table dp[n][totSum+1] where dp[i][j] will store whether it's possible to form sum j using the first i elements of the array.
// 3. Set the base cases:
//    - dp[i][0] = true, as sum 0 can always be achieved by excluding all elements.
//    - If arr[0] is less than or equal to totSum, set dp[0][arr[0]] = true.
// 4. Fill the DP table by considering whether to include or exclude the current element for each target sum.
// 5. For each sum from 1 to total sum, check if it's possible to form that sum using the available elements.
// 6. Iterate through the DP table to find the smallest difference between two subset sums.
// 7. Return the minimum difference.

int minSubsetSumDifference(vector<int> &arr, int n)
{
    int totSum = 0;
    for (int i = 0; i < n; i++)
    {
        totSum += arr[i];
    }
    vector<vector<bool>> dp(n, vector<bool>(totSum + 1, false));
    for (int i = 0; i < n; i++)
    {
        dp[i][0] = true;
    }
    if (arr[0] <= totSum)
        dp[0][totSum] = true;
    for (int ind = 1; ind < n; ind++)
    {
        for (int target = 1; target <= totSum; target++)
        {
            bool notTaken = dp[ind - 1][target];
            bool taken = false;
            if (arr[ind] <= target)
                taken = dp[ind - 1][target - arr[ind]];
            dp[ind][target] = notTaken || taken;
        }
    }
    int mini = 1e9;
    for (int i = 0; i <= totSum; i++)
    {
        if (dp[n - 1][i] == true)
        {
            int diff = abs(i - (totSum - i));
            mini = min(mini, diff);
        }
    }
    return mini;
}