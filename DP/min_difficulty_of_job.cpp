#include<iostream>
using namespace std;

// MINIMUM DIFFICULTY OF A JOB SCHEDULE (LEETCODE 1335)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2*D), SC=O(N*D)

// Steps:
// 1. If number of days `d` exceeds number of jobs `n`, return -1 (not enough jobs).
// 2. Use recursion with memoization: `solveUsingMem(index, days)` returns the minimum difficulty
//    of scheduling jobs from `index` to `n-1` in `days` days.
// 3. Base Case: If `days == 1`, return the maximum difficulty from `index` to `n-1` (must do all remaining jobs in one day).
// 4. Memoization: If this subproblem has already been solved, return the cached value `dp[index][days]`.
// 5. For each partition point `i` from `index` to `n - days`, do:
//    - Track the maximum job difficulty `maxD` in the current day (jobs from `index` to `i`).
//    - Recursively solve the remaining part with `days - 1` from `i+1` onwards.
//    - Add `maxD` to result of recursive call and track the minimum of all such partitions in `ans`.
// 6. Store and return `dp[index][days] = ans`.

int solveUsingMem(int index, int days, vector<int>&jobs, int n, vector<vector<int>>&dp){
    if(days==1){
        int maxD=jobs[index];
        for(int i=index;i<n;i++){
            maxD=max(maxD,jobs[i]);
        }
        return maxD;
    }
    if(dp[index][days]!=-1) return dp[index][days];
    int maxD=jobs[index];
    int ans=INT_MAX;
    for(int i=index;i<=n-days;i++){
        maxD=max(maxD,jobs[i]);
        int sum=maxD+solveUsingMem(i+1,days-1,jobs,n,dp);
        ans=min(sum,ans);
    }
    return dp[index][days]=ans;
}
int minDifficulty(vector<int>& jobDifficulty, int d) {
    int n=jobDifficulty.size();
    if(d>n) return -1;
    vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
    return solveUsingMem(0,d, jobDifficulty,n,dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^2*D), SC=O(N*D)
// Steps:
// 1. If number of days `d` exceeds number of jobs `n`, return -1 (impossible).
// 2. Create a DP table `dp[i][j]` representing the min difficulty to schedule jobs from `i` to `n-1` in `j` days.
// 3. Base Case: For `1` day, fill `dp[i][1]` with the maximum job difficulty from index `i` to `n-1` (since all must be done in one day).
// 4. For each index from `n-1` to `0`, and for each day from `2` to `d`:
//    - Initialize `maxD` with current job difficulty.
//    - Iterate `i` from `index` to `n - days` to partition jobs.
//    - At each step, update `maxD`, and calculate total difficulty as:
//      `maxD (current segment) + dp[i+1][days-1] (remaining segments)`
//    - Track the minimum across all valid partitions in `ans`.
// 5. Return `dp[0][d]` as the answer.

int solveUsingTab(vector<int> &jobs, int d, int n)
{
    vector<vector<int>> dp(n + 1, vector<int>(d + 1, 0));
    for (int i = 0; i < n; i++)
    {
        int maxD = jobs[i];
        for (int j = i; j < n; j++)
        {
            maxD = max(maxD, jobs[j]);
        }
        dp[i][1] = maxD;
    }
    for (int index = n - 1; index >= 0; index--)
    {
        for (int days = 2; days <= d; days++)
        {
            int maxD = jobs[index];
            int ans = INT_MAX;
            for (int i = index; i <= n - days; i++)
            {
                maxD = max(maxD, jobs[i]);
                int sum = maxD + dp[i + 1][days - 1];
                ans = min(sum, ans);
            }
            dp[index][days] = ans;
        }
    }
    return dp[0][d];
}
int minDifficulty(vector<int> &jobDifficulty, int d)
{
    int n = jobDifficulty.size();
    if (d > n)
        return -1;
    return solveUsingTab(jobDifficulty, d, n);
}
