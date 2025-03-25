#include<iostream>
using namespace std;

// MINIMUM SWAPS TO MAKE SEQUENCES INCREASING (LEETCODE 801)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N), SC=O(N)

// Steps:
// 1. Define `solveUsingMem` to recursively compute the minimum swaps needed from the current `index` in `nums1` and `nums2`:
//      - Use a `swapped` flag to track if the previous elements were swapped.
//      - Base Case: If `index` exceeds `nums1` size, return 0 (no more swaps required).
// 2. Use memoization with `dp[index][swapped]` to avoid redundant calculations.
// 3. For each `index`, determine the minimum swaps needed under two cases:
//      - No Swap at Current Index: Only if the current elements in `nums1` and `nums2` follow an increasing order from the previous elements.
//      - Swap at Current Index: Only if swapping still keeps elements in increasing order relative to the previous elements.
// 4. Return the minimum swaps between these cases and store it in `dp[index][swapped]`.
// 5. Call `solveUsingMem` from `minSwap` for index 1, initializing the previous elements as -1 for comparison.

int solveUsingMem(vector<int> &nums1, vector<int> &nums2, int index, bool swapped, vector<vector<int>> &dp)
{
    if (index == nums1.size())
    {
        return 0;
    }
    if (dp[index][swapped] != -1)
    {
        return dp[index][swapped];
    }
    int prev1 = nums1[index - 1];
    int prev2 = nums2[index - 1];
    int ans = INT_MAX;
    if (swapped)
    {
        swap(prev1, prev2);
    }
    if (nums1[index] > prev1 && nums2[index] > prev2)
    {
        ans = solveUsingMem(nums1, nums2, index + 1, false, dp);
    }
    if (nums1[index] > prev2 && nums2[index] > prev1)
    {
        ans = min(ans, 1 + solveUsingMem(nums1, nums2, index + 1, true, dp));
    }
    dp[index][swapped] = ans;
    return dp[index][swapped];
}
int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    bool swapped = false;
    vector<vector<int>> dp(n + 1, vector<int>(2, -1));
    return solveUsingMem(nums1, nums2, 1, swapped, dp);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N), SC=O(N)
// Steps:
// 1. Define a DP table `dp[index][swapped]` where:
//      - `dp[index][0]` holds the minimum swaps needed at `index` if no swap is done.
//      - `dp[index][1]` holds the minimum swaps needed if a swap is done at `index`.
// 2. Traverse `nums1` and `nums2` backwards, starting from the second-last index, and populate `dp`.
// 3. For each `index` and `swapped` status:
//      - Retrieve previous elements (`prev1` and `prev2`) based on `swapped` value.
//      - **No Swap at Current Index**: If no swap at `index` maintains increasing order, set `ans = dp[index + 1][0]`.
//      - **Swap at Current Index**: If swapping at `index` keeps increasing order, set `ans = min(ans, 1 + dp[index + 1][1])`.
// 4. Set `dp[index][swapped]` as the minimum of the two cases.
// 5. Return `dp[1][0]` for the minimum swaps starting from index 1 with no initial swap.

int solveUsingTab(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int index = n - 1; index >= 1; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];
            int ans = INT_MAX;
            if (swapped)
            {
                swap(prev1, prev2);
            }
            if (nums1[index] > prev1 && nums2[index] > prev2)
            {
                ans = dp[index + 1][0];
            }
            if (nums1[index] > prev2 && nums2[index] > prev1)
            {
                ans = min(ans, 1 + dp[index + 1][1]);
            }
            dp[index][swapped] = ans;
        }
    }
    return dp[1][0];
}
int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    return solveUsingTab(nums1, nums2);
}

// SPACE OPTIMIZATION APPROACH - TC=O(N), SC=O(1)
// Steps:
// 1. Initialize four variables to track the current and next states:
//      - `nextSwap` and `nextNoswap` to store minimum swaps needed at the next index with/without swap.
//      - `currSwap` and `currNoswap` to store minimum swaps needed at the current index with/without swap.
// 2. Traverse from the end of the `nums1` and `nums2` arrays back to index 1.
// 3. For each `index` and `swapped` status:
//      - Retrieve previous elements (`prev1` and `prev2`). Swap these if `swapped` is true.
//      - **No Swap at Current Index**: If no swap at `index` keeps the increasing order, set `ans = nextNoswap`.
//      - **Swap at Current Index**: If swapping at `index` keeps the order, set `ans = min(ans, 1 + nextSwap)`.
// 4. Update `currSwap` or `currNoswap` based on `swapped` value for use in the next iteration.
// 5. After completing inner loop, update `nextSwap` and `nextNoswap` to `currSwap` and `currNoswap`.
// 6. Return `min(nextSwap, nextNoswap)` as the answer for minimum swaps needed.

int solveUsingSO(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    int currSwap = 0, currNoswap = 0, nextSwap = 0, nextNoswap = 0;
    for (int index = n - 1; index >= 1; index--)
    {
        for (int swapped = 1; swapped >= 0; swapped--)
        {
            int prev1 = nums1[index - 1];
            int prev2 = nums2[index - 1];
            int ans = INT_MAX;
            if (swapped)
            {
                swap(prev1, prev2);
            }
            if (nums1[index] > prev1 && nums2[index] > prev2)
            {
                ans = nextNoswap;
            }
            if (nums1[index] > prev2 && nums2[index] > prev1)
            {
                ans = min(ans, 1 + nextSwap);
            }
            if (swapped)
            {
                currSwap = ans;
            }
            else
            {
                currNoswap = ans;
            }
        }
        nextSwap = currSwap;
        nextNoswap = currNoswap;
    }
    return min(nextSwap, nextNoswap);
}
int minSwap(vector<int> &nums1, vector<int> &nums2)
{
    int n = nums1.size();
    nums1.insert(nums1.begin(), -1);
    nums2.insert(nums2.begin(), -1);
    return solveUsingSO(nums1, nums2);
}