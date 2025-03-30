#include<iostream>
using namespace std;

// REDUCING DISHES (LEETCODE 1402)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(N^2)

// 1. Sort the satisfaction array to prioritize smaller values first.
// 2. Use memoization to store results of subproblems in dp[index][time].
// 3. Base case: If index == n, return 0 (no more dishes to consider).
// 4. If result is already in dp[index][time], return it.
// 5. Compute two options:
//    - Include the current dish: satisfaction[index] * (time + 1) + solve for the next dish.
//    - Exclude the current dish: solve for the next dish with the same time.
// 6. Store and return the maximum of the two options in dp[index][time].
// 7. In maxSatisfaction, sort the satisfaction array and call solveUsingMem for index 0 and time 0.

int solveUsingMem(vector<int> &satisfaction, int n, int index, int time, vector<vector<int>> &dp)
{
    if (index == n)
    {
        return 0;
    }
    if (dp[index][time] != -1)
    {
        return dp[index][time];
    }
    int include = satisfaction[index] * (time + 1) + solveUsingMem(satisfaction, n, index + 1, time + 1, dp);
    int exclude = 0 + solveUsingMem(satisfaction, n, index + 1, time, dp);
    dp[index][time] = max(include, exclude);
    return dp[index][time];
}
int maxSatisfaction(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    sort(satisfaction.begin(), satisfaction.end());
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, -1));
    return solveUsingMem(satisfaction, n, 0, 0, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^2), SC=O(N^2)
// 1. Sort the satisfaction array to prioritize smaller values first.
// 2. Initialize a 2D dp table of size (n+1) x (n+1) with 0, where n is the number of dishes.
// 3. Iterate from the last dish to the first (index=n-1 to 0) and from the last time to the first (time=n-1 to 0):
//    - Option 1 (Include): Add current dish's satisfaction with the next dish's optimal result at time+1.
//    - Option 2 (Exclude): Move to the next dish without including the current one.
//    - Store the maximum of both options in dp[index][time].
// 4. Return the result at dp[0][0] (starting from the first dish and time 0).
// 5. In maxSatisfaction, sort the satisfaction array and call solveUsingTab for the solution.

int solveUsingTab(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = n - 1; time >= 0; time--)
        {
            int include = satisfaction[index] * (time + 1) + dp[index + 1][time + 1];
            int exclude = 0 + dp[index + 1][time];
            dp[index][time] = max(include, exclude);
        }
    }
    return dp[0][0];
}
int maxSatisfaction(vector<int> &satisfaction)
{
    sort(satisfaction.begin(), satisfaction.end());
    return solveUsingTab(satisfaction);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N^2), SC=O(N)
// 1. Sort the satisfaction array to prioritize smaller values first.
// 2. Initialize two 1D arrays `curr` and `next` of size (n+1) with 0 to store results for the current and next iterations.
// 3. Iterate from the last dish to the first (index=n-1 to 0) and from the last time to the first (time=n-1 to 0):
//    - Option 1 (Include): Add current dish's satisfaction to the result from the next dish with time+1.
//    - Option 2 (Exclude): Move to the next dish without including the current one.
//    - Store the maximum of both options in `curr[time]`.
// 4. After each index iteration, set `next = curr` to prepare for the next round.
// 5. Return the result at `curr[0]` (starting from the first dish and time 0).
// 6. In maxSatisfaction, sort the satisfaction array and call solveUsingSO for the solution.

int solveUsingSO(vector<int> &satisfaction)
{
    int n = satisfaction.size();
    vector<int> curr(n + 1, 0);
    vector<int> next(n + 1, 0);
    for (int index = n - 1; index >= 0; index--)
    {
        for (int time = n - 1; time >= 0; time--)
        {
            int include = satisfaction[index] * (time + 1) + next[time + 1];
            int exclude = 0 + next[time];
            curr[time] = max(include, exclude);
        }
        next = curr;
    }
    return curr[0];
}
int maxSatisfaction(vector<int> &satisfaction)
{
    sort(satisfaction.begin(), satisfaction.end());
    return solveUsingSO(satisfaction);
}

// USING GREEDY ALGORITHM - TC=O(N*LOGN), SC=O(1)
// 1. Sort the satisfaction array in descending order to prioritize the dishes with the highest satisfaction values.
// 2. Initialize three variables:
//    - `ans`: to store the maximum satisfaction score.
//    - `cur`: to track the current total satisfaction score.
//    - `sum`: to accumulate the sum of satisfaction values.
// 3. Iterate through the satisfaction array:
//    - Add the current dish's satisfaction value to `sum`.
//    - Add `sum` to `cur`, which represents the total satisfaction score at this point.
//    - If the current total `cur` is less than the previous best answer `ans`, break the loop (as adding more dishes decreases the total score).
//    - Otherwise, update `ans` to the current total `cur`.
// 4. Return the maximum satisfaction score stored in `ans`.

int maxSatisfaction(vector<int> &satisfaction)
{
    sort(satisfaction.begin(), satisfaction.end(), greater<int>());
    int ans = 0, cur = 0, sum = 0;
    for (int i = 0; i < satisfaction.size(); i++)
    {
        sum += satisfaction[i];
        cur += sum;
        if (cur < ans)
            break;
        else
            ans = cur;
    }
    return ans;
}