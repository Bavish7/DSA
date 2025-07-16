#include<iostream>
using namespace std;

// BINARY SUBARRRAYS WITH SUM (LEETCODE 930)
// USING PREFIX SUM AND UNORDERED MAP - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize prefix sum (currSum) and hashmap (mp) to store frequency of prefix sums.
// 2. mp[0] = 1 ensures subarrays starting from index 0 are counted if they meet the goal.
// 3. Iterate through the array and keep updating currSum.
// 4. If (currSum - goal) exists in mp, add its frequency to count (i.e., valid subarrays end at current index).
// 5. Update mp[currSum] to reflect the current prefix sum's frequency.

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int n = nums.size();
    unordered_map<int, int> mp;
    int count = 0, currSum = 0;
    mp[0] = 1;
    for (int &num : nums)
    {
        currSum += num;
        if (mp.find(currSum - goal) != mp.end())
        {
            count += mp[currSum - goal];
        }
        mp[currSum]++;
    }
    return count;
}

// USING VARIABLE SIZE WINDOW - TC=O(4N), SC=O(1)
// Steps:
// 1. Define a helper function `solve` to count subarrays with a sum ≤ `goal`.
//    - Use a sliding window approach with two pointers (`l` and `r`).
//    - Expand the right pointer (`r`) and add `nums[r]` to `sum`.
//    - If `sum > goal`, shrink the window by moving the left pointer (`l`) and subtracting `nums[l]`.
//    - For each valid window, count the number of subarrays (`r - l + 1`).
// 2. The result for exact `goal` is the difference between subarrays with sum ≤ `goal` and sum ≤ `goal - 1`.
// 3. Return the result.

int solve(vector<int> &nums, int goal)
{
    if (goal < 0)
        return 0;
    int l = 0, r = 0, sum = 0, count = 0;
    while (r < nums.size())
    {
        sum += nums[r];
        while (sum > goal)
        {
            sum -= nums[l];
            l++;
        }
        count += (r - l + 1);
        r++;
    }
    return count;
}
int numSubarraysWithSum(vector<int> &nums, int goal)
{
    return solve(nums, goal) - solve(nums, goal - 1);
}

// USING VARIABLE SIZE WINDOW AND PREFIX SUM - TC=O(N), SC=O(1)
// Steps:
// 1. Initialize pointers `start`, `end`, `prefixZero`, `count`, and `sum`.
// 2. Expand the window by moving the `end` pointer and adding `nums[end]` to `sum`.
// 3. Contract the window from the `start` side while the `sum` exceeds `goal` or there are leading zeros.
//    - Update `prefixZero` to count zeros before the current subarray's first one.
//    - Adjust `sum` by subtracting `nums[start]` and move `start` forward.
// 4. When the `sum` equals `goal`, add `prefixZero + 1` to `count` to account for all valid subarrays ending at the current `end` position.
// 5. Move the `end` pointer to the next position.
// 6. Return the total count of valid subarrays.

int numSubarraysWithSum(vector<int> &nums, int goal)
{
    int start = 0;
    int end = 0;
    int prefixZero = 0;
    int count = 0;
    int sum = 0;
    while (end < nums.size())
    {
        sum = sum + nums[end];
        while (start < end && (sum > goal || nums[start] == 0))
        {
            if (nums[start] == 1)
            {
                prefixZero = 0;
            }
            else
            {
                prefixZero += 1;
            }
            sum = sum - nums[start];
            start++;
        }
        if (sum == goal)
        {
            count += prefixZero + 1;
        }
        end++;
    }
    return count;
}

