#include<iostream>
using namespace std;

// NINJA'S TRAINING
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*4*3), SC=O(N*4)

// Steps:
// Define solveUsingMem function with parameters day, last, points, and dp.
// If day == 0, initialize maxi to 0, iterate through tasks, and return the maximum points excluding the last task.
// Check if the result for dp[day][last] is already computed. If so, return it.
// Initialize maxi to 0 and iterate over all tasks. Exclude the last task, recursively calculate points for the previous day, and update maxi.
// Store the result in dp[day][last] and return it.
// In ninjaTraining, initialize a dp table of size n x 4 with -1.
// Call solveUsingMem for the last day (n-1) with last = 3.
// Return the computed result.

int solveUsingMem(int day, int last, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int task = 0; task < 3; task++)
        {
            if (task != last)
            {
                maxi = max(maxi, points[day][task]);
            }
        }
        return maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int maxi = 0;
    for (int task = 0; task < 3; task++)
    {
        if (task != last)
        {
            int point = points[day][task] + solveUsingMem(day - 1, task, points, dp);
            maxi = max(maxi, point);
        }
    }
    return dp[day][last] = maxi;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return solveUsingMem(n - 1, 3, points, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*4*3), SC=O(N*4)
// Steps:
// 1. Use tabulation to iteratively calculate the maximum points for each day and task.
// 2. Initialize the base case for day 0, storing max points for all tasks except the last completed one.
// 3. Iterate over all days and tasks, updating the dp table to store the maximum points achievable for each task and previous day's restriction.
// 4. Return the maximum points for the last day, considering any task can be done.

int solveUsingTab(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    for (int day = 1; day < n; day++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[day][last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + dp[day - 1][task];
                    dp[day][last] = max(dp[day][last], point);
                }
            }
        }
    }
    return dp[n - 1][3];
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    return solveUsingTab(n, points);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N*4*3), SC=O(4)
// Steps:
// 1. Use space optimization to reduce the dp table to two 1D arrays : `prev` (previous day) and `temp` (current day).                                                                                           // 2. Initialize the base case for day 0, storing the maximum points for all tasks except the last completed one.                                                                                            // 3. Iterate over all days, updating the `temp` array for the current day based on the previous day's values in `prev`.
// 4. Update `prev` to `temp` after processing each day to move to the next iteration.
// 5. Return the maximum points stored in `prev[3]` for the last day, considering any task can be done. 

int solveUsingSO(int n, vector<vector<int>> &points)
{
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
    for (int day = 1; day < n; day++)
    {
        vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int task = 0; task < 3; task++)
            {
                if (task != last)
                {
                    int point = points[day][task] + prev[task];
                    temp[last] = max(temp[last], point);
                }
            }
        }
        prev = temp;
    }
    return prev[3];
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    return solveUsingSO(n, points);
}