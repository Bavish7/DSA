#include<iostream>
using namespace std;

// MINIMUM COST FOR TICKETS (LEETCODE 983)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N), SC=O(N)

// Steps:
// 1. Define a memoized recursive function `solveUsingMem` to find the minimum cost starting from a given day.
// 2. Base case: If index exceeds the total number of days, return 0.
// 3. Use memoization to store results in `dp` array and return if already computed.
// 4. Calculate cost for 1-day pass and recursively solve for the next day.
// 5. Calculate cost for 7-day pass by skipping days covered under 7-day pass.
// 6. Calculate cost for 30-day pass by skipping days covered under 30-day pass.
// 7. Store the minimum of the three costs in `dp` and return.

int solveUsingMem(vector<int> &days, vector<int> &costs, int index, int n, vector<int> &dp)
{
    if (index >= n)
    {
        return 0;
    }
    if (dp[index] != -1)
    {
        return dp[index];
    }
    int cost1 = costs[0] + solveUsingMem(days, costs, index + 1, n, dp);
    int i;
    for (i = index; i < n && days[i] < days[index] + 7; i++);
    int cost7 = costs[1] + solveUsingMem(days, costs, i, n, dp);
    for (i = index; i < n && days[i] < days[index] + 30; i++);
    int cost30 = costs[2] + solveUsingMem(days, costs, i, n, dp);
    dp[index] = min(cost1, min(cost7, cost30));
    return dp[index];
}
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    vector<int> dp(n + 1, -1);
    return solveUsingMem(days, costs, 0, n, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N), SC=O(N)
// Steps:
// 1. Initialize a dp array of size n+1, set dp[n] = 0 (base case).
// 2. Iterate from last day to the first.
// 3. Calculate 1-day pass cost and store dp[index+1] result.
// 4. Find the first day after 7 days and calculate 7-day pass cost.
// 5. Find the first day after 30 days and calculate 30-day pass cost.
// 6. Store the minimum of 1-day, 7-day, and 30-day pass costs in dp[index].
// 7. Return dp[0] as the minimum total cost.

int solveUsingTab(vector<int> &days, vector<int> &costs, int n)
{
    vector<int> dp(n + 1, INT_MAX);
    dp[n] = 0;
    for (int index = n - 1; index >= 0; index--)
    {
        int cost1 = costs[0] + dp[index + 1];
        int i;
        for (i = index; i < n && days[i] < days[index] + 7; i++)
            ;
        int cost7 = costs[1] + dp[i];
        for (i = index; i < n && days[i] < days[index] + 30; i++)
            ;
        int cost30 = costs[2] + dp[i];
        dp[index] = min(cost1, min(cost7, cost30));
    }
    return dp[0];
}
int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int n = days.size();
    return solveUsingTab(days, costs, n);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N), SC=O(1)
// Steps:
// 1. Initialize variables: `ans` to store the total minimum cost, and two queues for weekly and monthly tickets.
// 2. Iterate through each travel day in `days`:
//    a. Remove expired tickets from the `weekly` queue (tickets older than 7 days).
//    b. Remove expired tickets from the `monthly` queue (tickets older than 30 days).
// 3. Push the current day's cost for weekly and monthly tickets into the respective queues.
// 4. Update `ans` by selecting the minimum between:
//    - The cost of adding a 1-day pass,
//    - The cheapest valid weekly pass,
//    - The cheapest valid monthly pass.
// 5. Return `ans` as the minimum total cost.

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int ans = 0;
    queue<pair<int, int>> weekly;
    queue<pair<int, int>> monthly;
    for (int day : days)
    {
        while (!weekly.empty() && weekly.front().first + 7 <= day)
        {
            weekly.pop();
        }
        while (!monthly.empty() && monthly.front().first + 30 <= day)
        {
            monthly.pop();
        }
        weekly.push({day, ans + costs[1]});
        monthly.push({day, ans + costs[2]});
        ans = min(ans + costs[0], min(weekly.front().second, monthly.front().second));
    }
    return ans;
}