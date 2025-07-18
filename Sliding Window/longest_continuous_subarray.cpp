#include<iostream>
using namespace std;

// LONGEST CONTINUOUS SUBARRAY WITH ABSOLUTE DIFFERENCE LESS THAN K (LEETCODE 1438)
// USING VARIABLE SIZE SLIDING WINDOW AND HEAPS - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Use two heaps:
//    - Max-heap to track the maximum in the current window.
//    - Min-heap to track the minimum.
// 2. Slide the window by moving `right` pointer and inserting into heaps.
// 3. If current window's max - min > limit, shrink window from the left by updating `left`.
// 4. Ensure outdated heap elements (with index < left) are removed.
// 5. Track the maximum window length satisfying the condition.

int longestSubarray(vector<int> &nums, int limit)
{
    int n = nums.size();
    priority_queue<pair<int, int>> maxHeap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    int left = 0, right = 0, diff = 0;
    int maxLen = 0;
    while (right < n)
    {
        maxHeap.push({nums[right], right});
        minHeap.push({nums[right], right});
        while (maxHeap.top().first - minHeap.top().first > limit)
        {
            left = min(maxHeap.top().second, minHeap.top().second) + 1;
            while (maxHeap.top().second < left)
            {
                maxHeap.pop();
            }
            while (minHeap.top().second < left)
            {
                minHeap.pop();
            }
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

// USING VARIABLE SIZE SLIDING WINDOW AND MULTISET - TC=O(N*LOGN), SC=O(N)
// Steps:
// 1. Use a multiset to maintain the current window's elements in sorted order.
// 2. Insert each element at `right` into the multiset.
// 3. While the difference between max (*rbegin) and min (*begin) exceeds `limit`,
//    shrink the window from the left by removing nums[left] from the set and incrementing `left`.
// 4. Update max length of the valid window after each iteration.

int longestSubarray(vector<int> &nums, int limit)
{
    int n = nums.size();
    multiset<int> st;
    int left = 0, right = 0;
    int maxLen = 0;
    while (right < n)
    {
        st.insert(nums[right]);
        while (*st.rbegin() - *st.begin() > limit)
        {
            st.erase(st.find(nums[left]));
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}

// USING VARIABLE SIZE SLIDING WINDOW AND DEQUES - TC=O(N), SC=O(N)
// Steps:
// 1. Maintain two deques:
//    - maxDeque (decreasing): stores indices of potential max values in window
//    - minDeque (increasing): stores indices of potential min values in window
// 2. For each `right`, remove elements from back of deques that violate monotonicity, then push `right`.
// 3. If the current window's max - min exceeds `limit`, move `left` forward and pop outdated indices from the front.
// 4. After adjusting the window, update the maximum valid subarray length.

int longestSubarray(vector<int> &nums, int limit)
{
    int n = nums.size();
    deque<int> maxDeque, minDeque;
    int left = 0, right = 0;
    int maxLen = 0;
    while (right < n)
    {
        while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right])
            maxDeque.pop_back();
        maxDeque.push_back(right);
        while (!minDeque.empty() && nums[minDeque.back()] >= nums[right])
            minDeque.pop_back();
        minDeque.push_back(right);
        while (nums[maxDeque.front()] - nums[minDeque.front()] > limit)
        {
            if (maxDeque.front() == left)
                maxDeque.pop_front();
            if (minDeque.front() == left)
                minDeque.pop_front();
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return maxLen;
}