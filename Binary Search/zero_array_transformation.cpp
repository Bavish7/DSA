#include<iostream>
using namespace std;

// ZERO ARRAY TRANSFORMATION II (LEETCODE 3356)
// USING DIFFERENCE ARRAY AND BINARY SEARCH - TC=O(LOGQ*(Q+N)), SC=O(N)

// Steps:
// 1. `checkDiff` function applies a range update using a difference array technique:
//    - Iterate over the first `k+1` queries and update `diff` to reflect range increments.
//    - Compute the prefix sum to apply the difference array and adjust `nums`.
//    - If any adjusted `nums[i]` remains positive, return false (modifications insufficient).
// 2. `minZeroArray` finds the minimum number of queries needed to make all elements zero:
//    - Check if `nums` is already all zeros; return 0 if true.
//    - Perform binary search (`l=0, r=q-1`) on the number of queries.
//    - Use `checkDiff` to determine if `mid` queries are sufficient.
//    - If valid, update `result` and search for a smaller valid `mid`.
//    - Return `result`, the minimum queries needed to make `nums` zero.

bool checkDiff(vector<int> &nums, vector<vector<int>> &queries, int k)
{
    vector<int> diff(nums.size(), 0);
    for (int i = 0; i <= k; i++)
    {
        int l = queries[i][0];
        int r = queries[i][1];
        int x = queries[i][2];
        diff[l] += x;
        if (r + 1 < nums.size())
        {
            diff[r + 1] -= x;
        }
    }
    int currSum = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        currSum += diff[i];
        diff[i] = currSum;
        if (nums[i] - diff[i] > 0)
            return false;
    }
    return true;
}
int minZeroArray(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    int q = queries.size();
    bool checkZero = true;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] != 0)
            checkZero = false;
    }
    if (checkZero)
        return 0;
    int l = 0, r = q - 1;
    int result = -1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (checkDiff(nums, queries, mid))
        {
            result = mid + 1;
            r = mid - 1;
        }
        else
            l = mid + 1;
    }
    return result;
}