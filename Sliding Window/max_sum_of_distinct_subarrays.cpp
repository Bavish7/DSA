#include<iostream>
using namespace std;

// MAXIMUM SUM OF DISTINCT SUBARRAYS WITH LENGTH K (LEETCODE 2461)
// USING VARIABLE SIZE WINDOW AND HASH SET - TC=O(N), SC=O(N)

// Steps:
// 1. Maintain a sliding window [left, right] ensuring all elements are unique using a HashSet.
// 2. If nums[right] already exists in the set, shrink the window from left until it's removed.
// 3. Add nums[right] to the window and update sum.
// 4. If window size == k, update maxSum and then shrink the window from the left for next iteration.
// 5. Continue until end of array.

long long maximumSubarraySum(vector<int> &nums, int k)
{
    int n = nums.size();
    unordered_set<int> st;
    long long sum = 0, maxSum = 0;
    int left = 0, right = 0;
    while (right < n)
    {
        while (st.count(nums[right]))
        {
            sum -= nums[left];
            st.erase(nums[left]);
            left++;
        }
        sum += nums[right];
        st.insert(nums[right]);
        if (right - left + 1 == k)
        {
            maxSum = max(maxSum, sum);
            sum -= nums[left];
            st.erase(nums[left]);
            left++;
        }
        right++;
    }
    return maxSum;
}