#include<iostream>
using namespace std;

// MINIMUM COST TO CUT A STICK (LEETCODE 1547)
// TOP-DOWN MEMOIZATION - TC=O(N^3), SC=O(N^2)

// Steps:
// 1. Insert the boundary points `0` and `n` into the cuts vector to handle edge cases and sort it.
// 2. `solveUsingMem(i, j, cuts, dp)` recursively finds the minimum cost of cutting between indices `i` and `j`.
// 3. Base case: Return `0` if `i > j` since no cuts are required.
// 4. For each partition index `ind` between `i` and `j`, calculate the cost of the current partition as
//    `cuts[j + 1] - cuts[i - 1]` plus the recursive cost for the left and right partitions.
// 5. Store and return the minimum partition cost in `dp[i][j]`.
// 6. Return the result stored in `dp[1][c]` which represents the minimum total cost.

int solveUsingMem(int i, int j, vector<int> &cuts, vector<vector<int>> &dp)
{
    if (i > j)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int mini = 1e9;
    for (int ind = i; ind <= j; ind++)
    {
        int cost = cuts[j + 1] - cuts[i - 1] + solveUsingMem(i, ind - 1, cuts, dp) + solveUsingMem(ind + 1, j, cuts, dp);
        mini = min(cost, mini);
    }
    return dp[i][j] = mini;
}
int minCost(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 1, vector<int>(c + 1, -1));
    return solveUsingMem(1, c, cuts, dp);
}

// BOTTOM-UP TABULATION - TC=O(N^3), SC=O(N^2)
// Steps:
// 1. Insert boundary cuts `0` and `n` in the cuts vector and sort it to handle all partitions.
// 2. Initialize a DP table `dp[i][j]` where `i` and `j` represent the current segment of cuts.
// 3. Iterate over the possible lengths of segments in reverse order for optimal filling of the DP table.
// 4. For each segment defined by `i` and `j`, compute the minimum partition cost by trying all possible partition points.
// 5. Compute the cost as `cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j]`.
// 6. Store the minimum cost in `dp[i][j]`.
// 7. Return `dp[1][c]` as the final result representing the minimum cost of making all cuts.

int solveUsingTab(int n, vector<int> &cuts)
{
    int c = cuts.size();
    cuts.push_back(n);
    cuts.insert(cuts.begin(), 0);
    sort(cuts.begin(), cuts.end());
    vector<vector<int>> dp(c + 2, vector<int>(c + 2, 0));
    for (int i = c; i >= 1; i--)
    {
        for (int j = i; j <= c; j++)
        {
            int mini = 1e9;
            for (int ind = i; ind <= j; ind++)
            {
                int cost = cuts[j + 1] - cuts[i - 1] + dp[i][ind - 1] + dp[ind + 1][j];
                mini = min(cost, mini);
            }
            dp[i][j] = mini;
        }
    }
    return dp[1][c];
}
int minCost(int n, vector<int> &cuts)
{
    return solveUsingTab(n, cuts);
}