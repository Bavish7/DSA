#include<iostream>
using namespace std;

// 0 1 KNAPSACK
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*W), SC=O(N*W)

// Steps:
// 1. Base cases:
//    - If index reaches n (all items considered) or w becomes 0 (knapsack capacity exhausted), return 0.
//    - If dp[w][index] is already calculated, return dp[w][index].
// 2. Calculate include:
//    - If the current item's weight (weights[index]) is less than or equal to remaining capacity (w),
//      include the value of the current item plus the maximum value obtainable by considering the next items
//      with reduced capacity (w - weights[index]).
// 3. Calculate exclude:
//    - Exclude the current item and calculate the maximum value obtainable by considering the next items with
//      the same capacity (w).
// 4. Store the maximum value (include or exclude) in dp[w][index].
// 5. Return dp[w][index] as the maximum value obtainable with the given capacity w considering items from index onwards.

int solveUsingMem(vector<int> &values, vector<int> &weights, int n, int w, int index, vector<vector<int>> &dp)
{
    if (index == n || w == 0)
    {
        return 0;
    }
    if (dp[w][index] != -1)
    {
        return dp[w][index];
    }
    int include = 0;
    if (weights[index] <= w)
    {
        include = values[index] + solveUsingMem(values, weights, n, w - weights[index], index + 1, dp);
    }
    int exclude = 0 + solveUsingMem(values, weights, n, w, index + 1, dp);
    dp[w][index] = max(include, exclude);
    return dp[w][index];
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    int index = 0;
    vector<vector<int>> dp(w + 1, vector<int>(n + 1, -1));
    int ans = solveUsingMem(values, weights, n, w, index, dp);
    return ans;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*W), SC=O(N*W)
// Steps:
// 1. Initialize a 2D dp table with dimensions (w+1) x (n+1), where w is the capacity and n is the number of items.
// 2. Base case initialization: dp[row][n] = 0 for all rows (capacity) since no value can be obtained with no items.
// 3. Iterate over each capacity (row) from 0 to w and each item (col) from n-1 to 0:
//    a. Calculate include:
//       - If the current item's weight (weights[col]) is less than or equal to the current capacity (row),
//         include the value of the current item plus the value obtainable with remaining capacity (row - weights[col])
//         and considering the next item (col + 1).
//    b. Calculate exclude:
//       - Exclude the current item and consider the maximum value obtainable with the current capacity and the next item.
//    c. Store the maximum of include and exclude in dp[row][col].
// 4. Return dp[w][0] as the maximum value obtainable with capacity w and considering all items.

int solveUsingTab(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<vector<int>> dp(w + 1, vector<int>(n + 1, -1));
    for (int row = 0; row <= w; row++)
    {
        dp[row][n] = 0;
    }
    for (int row = 0; row <= w; row++)
    {
        for (int col = n - 1; col >= 0; col--)
        {
            int include = 0;
            if (weights[col] <= row)
            {
                include = values[col] + dp[row - weights[col]][col + 1];
            }
            int exclude = 0 + dp[row][col + 1];
            dp[row][col] = max(include, exclude);
        }
    }
    return dp[w][0];
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    int ans = solveUsingTab(values, weights, n, w);
    return ans;
}

// SPACE OPTIMIZATION APPROACH - TC=O(N*W), SC=O(W)
// Steps:
// 1. Initialize a dp array of size w+1 with all elements as 0. This array will store the maximum value
//    that can be obtained with a capacity ranging from 0 to w.
// 2. Iterate through each item and update the dp array from right to left (backwards):
//    a. For each item, iterate through the dp array from w down to weights[i].
//    b. Update dp[j] to be the maximum of its current value dp[j] and dp[j - weights[i]] + values[i],
//       which represents either excluding or including the current item based on the remaining capacity j.
// 3. Return dp[w] as it holds the maximum value that can be obtained with the full capacity w.

int solveUsingSO(vector<int> &values, vector<int> &weights, int n, int w)
{
    int dp[w + 1] = {0};
    for (int i = 0; i < n; i++)
    {
        for (int j = w; j >= weights[i]; j--)
        {
            dp[j] = max(dp[j], dp[j - weights[i]] + values[i]);
        }
    }
    return dp[w];
}
int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    int ans = solveUsingSO(values, weights, n, w);
    return ans;
}