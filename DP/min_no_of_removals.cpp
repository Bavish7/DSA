#include<iostream>
using namespace std;

// MINIMUM NUMBER OF REMOVALS TO MAKE MOUNTAIN ARRAY (LEETCODE 1671)
// USING BINARY SEARCH - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Define a helper function `longIncSub` to calculate the longest increasing subsequence (LIS) lengths for `nums` and store results in `lis`.
//    - Initialize `ans` with the first element of `nums` and `lis` with 1 (length of LIS for the first element).
//    - For each element in `nums`:
//      - If it's greater than the last element of `ans`, add it to `ans` and update `lis` with the new length of `ans`.
//      - Otherwise, find the position to replace in `ans` using `lower_bound`, update `ans`, and store the position+1 in `lis`.
// 2. Compute the LIS for `nums` from the left and store it in `lis`.
// 3. Reverse `nums`, then compute LIS for the reversed array (representing the longest decreasing subsequence (LDS)) and store it in `lds`.
// 4. Reverse `lds` so each index in `lis` and `lds` corresponds to the correct position in `nums`.
// 5. Calculate the maximum length of any mountain by checking each index `i`:
//    - Skip indices where either `lis[i]` or `lds[i]` is 1 (indicating no peak).
//    - Update `maxSize` to the largest sum of `lis[i] + lds[i] - 1`.
// 6. Return the minimum removals needed as `nums.size() - maxSize`.

int longIncSub(vector<int> &nums, vector<int> &lis)
{
    vector<int> ans;
    lis.push_back(1);
    ans.push_back(nums[0]);
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] > ans.back())
        {
            ans.push_back(nums[i]);
            lis.push_back(ans.size());
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), nums[i]) - ans.begin();
            ans[index] = nums[i];
            lis.push_back(index + 1);
        }
    }
    return ans.size();
}
int minimumMountainRemovals(vector<int> &nums)
{
    vector<int> lis, lds;
    longIncSub(nums, lis);
    reverse(nums.begin(), nums.end());
    longIncSub(nums, lds);
    int maxSize = INT_MIN;
    for (int i = 0; i < nums.size(); i++)
    {
        if (lis[i] == 1 || lds[nums.size() - i - 1] == 1)
            continue;
        maxSize = max(maxSize, lis[i] + lds[nums.size() - i - 1] - 1);
    }
    return nums.size() - maxSize;
}