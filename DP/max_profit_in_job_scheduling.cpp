#include<iostream>
using namespace std;

// MAXIMUM PROFIT IN JOB SCHEDULING (LEETCODE 1235)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Sort the jobs based on startTime to enable efficient searching.
// 2. Use binary search(getNextIndex) to find the next non-overlapping job where jobs[mid][0] >= jobs[i][1], reducing search complexity to O(log N).
// 3. Implement recursive DP with memoization (solveUsingMem).
// 4. Compute two options: including the current job (adding its profit and solving for the next valid job) or excluding it (solving for the next job).
// 5. Store computed results in dp[i] to prevent redundant calculations.
// 6. Return the maximum profit starting from index 0.

int getNextIndex(vector<vector<int>> &jobs, int low, int jobEnd)
{
    int high = jobs.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (jobs[mid][0] >= jobEnd)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int solveUsingMem(int i, vector<vector<int>> &jobs, vector<int> &dp)
{
    if (i >= jobs.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int nextIndex = getNextIndex(jobs, i + 1, jobs[i][1]);
    int include = jobs[i][2] + solveUsingMem(nextIndex, jobs, dp);
    int exclude = 0 + solveUsingMem(i + 1, jobs, dp);
    return dp[i] = max(include, exclude);
}
int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();
    vector<vector<int>> jobs(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        jobs[i] = {startTime[i], endTime[i], profit[i]};
    }
    sort(jobs.begin(), jobs.end());
    vector<int> dp(n, -1);
    return solveUsingMem(0, jobs, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*LOGN), SC=O(N)
// Steps:
// 1. Sort jobs based on startTime for efficient searching.
// 2. Use binary search (getNextIndex) to find the next non-overlapping job where jobs[mid][0] >= jobs[i][1], reducing search complexity to O(log N).
// 3. Implement bottom-up DP (solveUsingTab) using a 1D dp array of size n+1, initialized to zero.
// 4. Iterate jobs in reverse order and compute two options: including the current job (adding its profit and next valid job’s dp value) or excluding it (taking the next job’s dp value).
// 5. Store the maximum of the two choices in dp[i] to ensure optimal results.
// 6. Return dp[0], which holds the maximum profit starting from the first job.

int getNextIndex(vector<vector<int>> &jobs, int low, int jobEnd)
{
    int high = jobs.size() - 1;
    int ans = -1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (jobs[mid][0] >= jobEnd)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int solveUsingTab(vector<vector<int>> &jobs)
{
    int n = jobs.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int nextIndex = getNextIndex(jobs, i + 1, jobs[i][1]);
        int include = jobs[i][2] + (nextIndex == -1 ? 0 : dp[nextIndex]);
        int exclude = 0 + dp[i + 1];
        dp[i] = max(include, exclude);
    }
    return dp[0];
}
int jobScheduling(vector<int> &startTime, vector<int> &endTime, vector<int> &profit)
{
    int n = startTime.size();
    vector<vector<int>> jobs(n, vector<int>(3));
    for (int i = 0; i < n; i++)
    {
        jobs[i] = {startTime[i], endTime[i], profit[i]};
    }
    sort(jobs.begin(), jobs.end());
    return solveUsingTab(jobs);
}
