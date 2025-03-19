#include<iostream>
using namespace std;

// MAKE ARRAY STRICTLY INCREASING (LEETCODE 1187)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(M*NLOGN), SC=O(M*N)

// Steps:
// 1. Define a recursive `solveUsingMem` function with memoization to explore two options:
//    - If `arr1[i]` is greater than `prev`, we can keep `arr1[i]` in the sequence without replacement.
//    - Use binary search to find the smallest element in `arr2` greater than `prev` and replace `arr1[i]` with it.
// 2. For each option:
//    - Option 1 (`op1`): If `prev < arr1[i]`, continue to the next index without replacement.
//    - Option 2 (`op2`): Use `upper_bound` to find the first element in `arr2` greater than `prev`. Replace `arr1[i]` with `arr2[index]`, increment the count by 1, and proceed to the next index.
// 3. Memoize results for each `(prev, i)` combination in `dp`.
// 4. In `makeArrayIncreasing`, initialize `prev` as `-1` to allow the smallest possible start, sort `arr2` for efficient binary search, and call `solveUsingMem`.
// 5. If the result is `INF`, return `-1` (no valid transformations possible). Otherwise, return the result.

#define INF (1e9 + 1)
int solveUsingMem(vector<int> &arr1, vector<int> &arr2, int prev, int i, map<pair<int, int>, int> &dp)
{
    if (i == arr1.size())
        return 0;
    if (dp.find({prev, i}) != dp.end())
    {
        return dp[{prev, i}];
    }
    int op1 = INF;
    if (prev < arr1[i])
    {
        op1 = solveUsingMem(arr1, arr2, arr1[i], i + 1, dp);
    }
    int op2 = INF;
    auto it = upper_bound(arr2.begin(), arr2.end(), prev);
    if (it != arr2.end())
    {
        int index = it - arr2.begin();
        op2 = 1 + solveUsingMem(arr1, arr2, arr2[index], i + 1, dp);
    }
    return dp[{prev, i}] = min(op1, op2);
}
int makeArrayIncreasing(vector<int> &arr1, vector<int> &arr2)
{
    sort(arr2.begin(), arr2.end());
    map<pair<int, int>, int> dp;
    int ans = solveUsingMem(arr1, arr2, -1, 0, dp);
    return ans == INF ? -1 : ans;
}