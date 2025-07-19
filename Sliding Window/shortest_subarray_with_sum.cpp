#include<iostream>
using namespace std;

// SHORTEST SUBARRAY WITH SUM ATLEAST K (LEETCODE 862)
// USING VARIABLE SIZE WINDOW, PREFIX SUM AND DEQUE - TC=O(N), SC=O(N)

// Steps:
// 1. Compute prefix sum at each index while iterating.
// 2. If prefixSum[right] ≥ k → update ans to right+1 (entire subarray from 0)
// 3. Maintain a deque to track indices with increasing prefixSum:
//    - While deque not empty and current prefixSum − prefixSum[dq.front()] ≥ k:
//      → valid subarray found → update ans and pop dq.front()
// 4. Maintain monotonic increasing deque by popping back if prefixSum[right] ≤ prefixSum[dq.back()] (to ensure shortest valid subarrays)
// 5. Push current index to deque.
// 6. Return `ans` if updated; else return -1.

int shortestSubarray(vector<int> &nums, int k)
{
    int n = nums.size();
    deque<int> dq;
    vector<long long> prefixSum(n, 0);
    int ans = INT_MAX;
    int right = 0;
    while (right < n)
    {
        if (right == 0)
            prefixSum[0] = nums[0];
        else
        {
            prefixSum[right] = prefixSum[right - 1] + nums[right];
        }
        if (prefixSum[right] >= k)
        {
            ans = min(ans, right + 1);
        }
        while (!dq.empty() && prefixSum[right] - prefixSum[dq.front()] >= k)
        {
            ans = min(ans, right - dq.front());
            dq.pop_front();
        }
        while (!dq.empty() && prefixSum[right] <= prefixSum[dq.back()])
        {
            dq.pop_back();
        }
        dq.push_back(right);
        right++;
    }
    return ans == INT_MAX ? -1 : ans;
}