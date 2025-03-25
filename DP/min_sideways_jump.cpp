#include<iostream>
using namespace std;

// MINIMUM SIDEWAYS JUMP (LEETCODE 1824)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N), SC=O(N)

// Steps:
// 1. Define a recursive function `solveUsingMem` to calculate the minimum side jumps needed, starting at a given index and lane.
// 2. Base Case: If we reach the end of the obstacle array (index == n), return 0 as no more jumps are needed.
// 3. Check if the current subproblem (currLane, index) has been solved before by checking the `dp` table. If yes, return the stored result.
// 4. If the next position (index + 1) in the same lane (`currLane`) is not blocked by an obstacle, proceed forward without switching lanes.
// 5. If there's an obstacle in the current lane at the next index, calculate the minimum side jumps by trying to switch to other lanes (1, 2, 3) that are not blocked at the current index.
// 6. For each possible lane change, recursively calculate the number of jumps required and add 1 for the lane switch.
// 7. Store the result of the current subproblem in the `dp` table and return the result.
// 8. In the `minSideJumps` function, initialize a `dp` table to store solutions for subproblems and start the recursion from lane 2 at the 0th index.
// 9. Return the minimum side jumps needed from the starting position.

int solveUsingMem(vector<int> &obstacles, int n, int index, int currLane, vector<vector<int>> &dp)
{
    if (index == n)
    {
        return 0;
    }
    if (dp[currLane][index] != -1)
    {
        return dp[currLane][index];
    }
    if (obstacles[index + 1] != currLane)
    {
        dp[currLane][index] = solveUsingMem(obstacles, n, index + 1, currLane, dp);
        return dp[currLane][index];
    }
    else
    {
        int ans = INT_MAX;
        for (int i = 1; i <= 3; i++)
        {
            if (obstacles[index] != i && currLane != i)
            {
                ans = min(ans, 1 + solveUsingMem(obstacles, n, index, i, dp));
            }
        }
        dp[currLane][index] = ans;
        return dp[currLane][index];
    }
}
int minSideJumps(vector<int> &obstacles)
{
    int n = obstacles.size() - 1;
    vector<vector<int>> dp(4, vector<int>(n + 1, -1));
    return solveUsingMem(obstacles, n, 0, 2, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N), SC=O(N)
// Steps:
// 1. Initialize a 2D DP table `dp[4][n+1]` where `dp[lane][index]` stores the minimum jumps needed from `index` in `lane` to reach the end.
// 2. Base Case: Set `dp[i][n] = 0` for all lanes `i` because if you're at the last position, no further jumps are needed.
// 3. Traverse the obstacle array in reverse from the second last position (n-1) to the start (0).
// 4. For each lane `currLane` at the current index, check if the next position in the same lane is blocked by an obstacle:
//    - If not blocked, copy the value from `dp[currLane][index+1]` (no jump needed, just move forward).
//    - If blocked, calculate the minimum jumps needed by switching to other lanes that are not blocked at the current index. Add 1 for the lane switch and store the minimum result in `dp[currLane][index]`.
// 5. After filling the DP table, return the minimum of the results starting from lane 2 at index 0, and the results of jumping to lane 1 or lane 3 from the start (each with one jump).
// 6. In the `minSideJumps` function, call `solveUsingTab` to compute the result.

int solveUsingTab(vector<int> &obstacles)
{
    int n = obstacles.size() - 1;
    vector<vector<int>> dp(4, vector<int>(n + 1, INT_MAX));
    for (int i = 0; i <= 3; i++)
    {
        dp[i][n] = 0;
    }
    for (int index = n - 1; index >= 0; index--)
    {
        for (int currLane = 1; currLane <= 3; currLane++)
        {
            if (obstacles[index + 1] != currLane)
            {
                dp[currLane][index] = dp[currLane][index + 1];
            }
            else
            {
                int ans = INT_MAX;
                for (int i = 1; i <= 3; i++)
                {
                    if (obstacles[index] != i && currLane != i)
                    {
                        ans = min(ans, 1 + dp[i][index + 1]);
                    }
                }
                dp[currLane][index] = ans;
            }
        }
    }
    return min(dp[2][0], min(1 + dp[1][0], 1 + dp[3][0]));
}
int minSideJumps(vector<int> &obstacles)
{
    return solveUsingTab(obstacles);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N), SC=O(1)
// Steps:
// 1. Initialize two 1D arrays `curr` and `next` of size 4, where `next[lane]` represents the minimum jumps needed to reach the end from the current lane. Set all elements of `next` to 0 as a base case since no jumps are needed from the last position.
// 2. Traverse the obstacles array in reverse from `n-1` to 0.
// 3. For each lane `currLane` at the current index, check if the next position in the same lane is blocked by an obstacle:
//    - If not blocked, set `curr[currLane]` to the value of `next[currLane]` (no jump needed, just move forward).
//    - If blocked, calculate the minimum jumps needed by switching to other lanes that are not blocked at the current index. Add 1 for the lane switch and store the minimum result in `curr[currLane]`.
// 4. After filling the current state, update `next` to `curr` for the next iteration.
// 5. After the loop, return the minimum of `next[2]`, `1+next[1]`, and `1+next[3]` because we start at lane 2 and can switch lanes as needed.
// 6. In the `minSideJumps` function, call `solveUsingSO` to compute the result.

int solveUsingSO(vector<int> &obstacles)
{
    int n = obstacles.size() - 1;
    vector<int> curr(4, INT_MAX);
    vector<int> next(4, INT_MAX);
    for (int i = 0; i <= 3; i++)
    {
        next[i] = 0;
    }
    for (int index = n - 1; index >= 0; index--)
    {
        for (int currLane = 1; currLane <= 3; currLane++)
        {
            if (obstacles[index + 1] != currLane)
            {
                curr[currLane] = next[currLane];
            }
            else
            {
                int ans = INT_MAX;
                for (int i = 1; i <= 3; i++)
                {
                    if (obstacles[index] != i && currLane != i)
                    {
                        ans = min(ans, 1 + next[i]);
                    }
                }
                curr[currLane] = ans;
            }
        }
        next = curr;
    }
    return min(next[2], min(1 + next[1], 1 + next[3]));
}
int minSideJumps(vector<int> &obstacles)
{
    return solveUsingSO(obstacles);
}