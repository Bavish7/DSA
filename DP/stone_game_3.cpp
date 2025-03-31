#include<iostream>
using namespace std;

// STONE GAME III (LEETCODE 1406)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N), SC=O(N)

// Steps:
// 1. Define `solveUsingMem` to calculate the maximum score Alice can achieve from index `i`.
//    - Base Case: Return 0 if index `i` reaches the end of the stones array.
//    - Memoization: If result for `i` is already in `dp`, return it.
//    - Try picking 1, 2, or 3 stones, calculating score difference for each option.
//    - Update `ans` with the maximum score difference Alice can achieve at `i`.
// 2. Initialize `dp` array to store results and call `solveUsingMem` from index 0.
// 3. Check `ans` to decide the result:
//    - If `ans > 0`, Alice wins ("Alice").
//    - If `ans < 0`, Bob wins ("Bob").
//    - If `ans == 0`, it's a "Tie".

int solveUsingMem(vector<int> &stones, int i, vector<int> &dp)
{
    if (i == stones.size())
        return 0;
    if (dp[i] != -1)
        return dp[i];
    int ans = INT_MIN;
    int total = 0;
    for (int x = 1; x <= 3; x++)
    {
        if (i + x - 1 >= stones.size())
            break;
        total += stones[i + x - 1];
        ans = max(ans, total - solveUsingMem(stones, i + x, dp));
    }
    dp[i] = ans;
    return dp[i];
}
string stoneGameIII(vector<int> &stoneValue)
{
    int n = stoneValue.size();
    vector<int> dp(n, -1);
    int ans = solveUsingMem(stoneValue, 0, dp);
    if (ans > 0)
        return "Alice";
    if (ans < 0)
        return "Bob";
    return "Tie";
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N), SC=O(N)
// Steps:
// 1. Initialize `dp` array to store maximum score difference achievable from each position.
// 2. Traverse from the end of `stones` array towards the start:
//    - Initialize `total` as the sum of stones taken by Alice.
//    - For each `x` in range [1, 3], calculate the score difference if Alice takes `x` stones:
//      - Update `total` by adding the stone value.
//      - Set `ans` to maximum of current `ans` and `total - dp[i + x]`.
//    - Store the best score difference in `dp[i]`.
// 3. Return `dp[0]` as the result, which indicates the optimal score difference if Alice starts at the beginning.
// 4. In `stoneGameIII`, determine the winner based on the result:
//    - If `ans > 0`, Alice wins.
//    - If `ans < 0`, Bob wins.
//    - If `ans == 0`, it's a tie.

int solveUsingTab(vector<int> &stones)
{
    int n = stones.size();
    vector<int> dp(n + 1, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        int ans = INT_MIN;
        int total = 0;
        for (int x = 1; x <= 3; x++)
        {
            if (i + x - 1 >= stones.size())
                break;
            total += stones[i + x - 1];
            ans = max(ans, total - dp[i + x]);
        }
        dp[i] = ans;
    }
    return dp[0];
}
string stoneGameIII(vector<int> &stoneValue)
{
    int ans = solveUsingTab(stoneValue);
    if (ans > 0)
        return "Alice";
    if (ans < 0)
        return "Bob";
    return "Tie";
}