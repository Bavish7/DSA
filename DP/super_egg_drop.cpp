#include<iostream>
using namespace std;

// SUPER EGG DROP (LEETCODE 887)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N*N*K), SC=O(N*K) - TLE

// Steps:
// 1. Base cases:
//    - If there’s 1 egg, the worst case is dropping from each floor (n moves).
//    - If there’s 0 or 1 floor, the worst case is equal to the number of floors.
// 2. Use recursion with memoization to store results of (k, n).
// 3. Try dropping from each floor (1 to n) and take the worst-case scenario:
//    - If egg breaks → search below (k-1, i-1).
//    - If egg doesn’t break → search above (k, n-i).
// 4. Store the minimum moves needed in `dp[k][n]`.

int solveUsingMem(int k, int n, vector<vector<int>> &dp)
{
    if (n == 0 || n == 1 || k == 1)
    {
        return n;
    }
    if (dp[k][n] != -1)
        return dp[k][n];
    int minMoves = INT_MAX;
    for (int i = 1; i <= n; i++)
    {
        int maxFloor = 1 + max(solveUsingMem(k - 1, i - 1, dp), solveUsingMem(k, n - i, dp));
        minMoves = min(minMoves, maxFloor);
    }
    return dp[k][n] = minMoves;
}
int superEggDrop(int k, int n)
{
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
    return solveUsingMem(k, n, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N*K^2), SC=O(N*K) - TLE
// Steps:
// 1. Initialize DP table `dp[k][n]`, where `dp[i][j]` represents the minimum attempts
//    needed with `i` eggs and `j` floors.
// 2. Base cases:
//    - If there’s 1 egg, the worst case is dropping from each floor (n moves).
//    - If there’s 0 floors, no drops are needed. If there’s 1 floor, only 1 move is needed.
// 3. Fill DP table iteratively:
//    - For each egg count `eggs`, iterate over floor count `floors`.
//    - Try dropping from each floor and take the worst case scenario:
//      - Egg breaks → check below (eggs-1, i-1).
//      - Egg doesn’t break → check above (eggs, floors-i).
//    - Store the minimum moves needed in `dp[eggs][floors]`.
// 4. Return `dp[k][n]` as the answer.

int solveUsingTab(int k, int n)
{
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    for (int eggs = 0; eggs <= k; eggs++)
    {
        dp[eggs][0] = 0, dp[eggs][1] = 1;
    }
    for (int floors = 1; floors <= n; floors++)
    {
        dp[1][floors] = floors;
    }
    for (int eggs = 2; eggs <= k; eggs++)
    {
        for (int floors = 2; floors <= n; floors++)
        {
            int minMoves = INT_MAX;
            for (int i = 1; i <= floors; i++)
            {
                int maxFloor = 1 + max(dp[eggs - 1][i - 1], dp[eggs][floors - i]);
                minMoves = min(minMoves, maxFloor);
            }
            dp[eggs][floors] = minMoves;
        }
    }
    return dp[k][n];
}
int superEggDrop(int k, int n)
{
    return solveUsingTab(k, n);
}

// MEMOIZATION AND BINARY SEARCH - TC=O(K*N*LOGN), SC=O(N*K)
// Steps:
// 1. Base Cases:
//    - If `n == 0` (no floors), return 0 attempts.
//    - If `n == 1` (one floor), return 1 attempt.
//    - If `k == 1` (one egg), worst case is dropping from each floor (n attempts).
// 2. Check Memoized Result: If already computed, return stored result.
// 3. Binary Search Optimization:
//    - Instead of checking all floors linearly, use binary search to optimize the worst case scenario.
//    - Midpoint `mid` is chosen to minimize the max attempts required.
//    - Two cases after dropping from `mid` floor:
//      - Egg breaks Search in the lower half (`k-1, mid-1`).
//      - Egg doesn’t break Search in the upper half (`k, n-mid`).
//    - Store the worst case attempts and update the minimum.
// 4. Memoize Result and return `dp[k][n]` to avoid recomputation.

int solveUsingMem(int k, int n, vector<vector<int>> &dp)
{
    if (n == 0 || n == 1 || k == 1)
    {
        return n;
    }
    if (dp[k][n] != -1)
        return dp[k][n];
    int minMoves = INT_MAX;
    int low = 1, high = n, maxFloor = 0;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int left = solveUsingMem(k - 1, mid - 1, dp);
        int right = solveUsingMem(k, n - mid, dp);
        int maxFloor = 1 + max(left, right);
        if (left < right)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
        minMoves = min(minMoves, maxFloor);
    }
    return dp[k][n] = minMoves;
}
int superEggDrop(int k, int n)
{
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, -1));
    return solveUsingMem(k, n, dp);
}

// TABULATION AND BINARY SEARCH - TC=O(K*N*LOGN), SC=O(N*K)
// Steps:
// 1. Base Cases Initialization:
//    - If `n == 0`, no attempts are needed (`dp[eggs][0] = 0`).
//    - If `n == 1`, only one attempt is needed (`dp[eggs][1] = 1`).
//    - If `k == 1`, worst case is dropping from each floor (`dp[1][floors] = floors`).
// 2. Filling DP Table:
//    - Iterate over `eggs` (2 to K) and `floors` (2 to N).
//    - Use binary search to find the optimal floor `mid` for dropping:
//      - Egg breaks: Search in `low` part (`dp[eggs-1][mid-1]`).
//      - Egg doesn’t break: Search in `high` part (`dp[eggs][floors-mid]`).
//      - Take the worst case scenario and minimize it across floors.
// 3. Return Result: `dp[k][n]` stores the minimum attempts needed.

int solveUsingTab(int k, int n)
{
    vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
    for (int eggs = 0; eggs <= k; eggs++)
    {
        dp[eggs][0] = 0, dp[eggs][1] = 1;
    }
    for (int floors = 1; floors <= n; floors++)
    {
        dp[1][floors] = floors;
    }
    for (int eggs = 2; eggs <= k; eggs++)
    {
        for (int floors = 2; floors <= n; floors++)
        {
            int minMoves = INT_MAX;
            int low = 1, high = floors, maxFloors = 0;
            while (low <= high)
            {
                int mid = (low + high) / 2;
                int left = dp[eggs - 1][mid - 1];
                int right = dp[eggs][floors - mid];
                int maxFloor = 1 + max(left, right);
                if (left < right)
                {
                    low = mid + 1;
                }
                else
                {
                    high = mid - 1;
                }
                minMoves = min(minMoves, maxFloor);
            }
            dp[eggs][floors] = minMoves;
        }
    }
    return dp[k][n];
}
int superEggDrop(int k, int n)
{
    return solveUsingTab(k, n);
}
