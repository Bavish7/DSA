#include <iostream>
#include <queue>
using namespace std;

// SLIDING WINDOW MAXIMUM (LEETCODE 239)
// USING MAX HEAP - TC=O(NLOGN), SC=O(N)

// Steps:
// 1. Initialize a priority_queue (max heap) to store pairs of numbers and their indices.
// 2. Fill the heap with the first k elements from nums and add the maximum element to the result.
// 3. Iterate through the remaining elements in nums starting from index k.
//    - Push the current element into the heap.
//    - Remove the elements from the heap that are no longer within the sliding window of size k (i.e., elements whose index is <= i - k).
//    - Add the maximum element to the result after each iteration.
// 4. Return the result vector containing the maximums of each sliding window.

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    priority_queue<pair<int, int>> pq;
    vector<int> ans;
    for (int i = 0; i < k; i++)
    {
        pq.push({nums[i], i});
    }
    ans.push_back(pq.top().first);
    for (int i = k; i < nums.size(); i++)
    {
        pq.push({nums[i], i});
        while (pq.top().second <= i - k)
        {
            pq.pop();
        }
        ans.push_back(pq.top().first);
    }
    return ans;
}

// USING FIXED SIZE WINDOW - TC=O(N), SC=O(K)
// Steps:
// 1. Initialize a deque `q` to keep track of indices of potential maximum values in the current window.
// 2. Initialize a vector `res` to store the maximum values of each window.
// 3. Loop through the first `k` elements to populate the deque:
// a. Remove indices from the back of the deque while the current element is greater than the element at those indices.
// b. Add the index of the current element to the back of the deque.
// 4. Loop through the rest of the elements:
// a. Add the maximum value of the current window (element at the front of the deque) to `res`.
// b. Remove the index at the front of the deque if it is outside the current window (i.e., if `i - q.front() >= k`).
// c. Remove indices from the back of the deque while the current element is greater than the element at those indices.
// d. Add the index of the current element to the back of the deque.
// 5. After processing all elements, add the maximum value of the last window to `res` (element at the front of the deque).
// 6. Return the `res` vector containing the maximum values for each sliding window.

vector<int> maxSlidingWindow(vector<int> &nums, int k)
{
    deque<int> q;
    vector<int> res;
    int n = nums.size();
    for (int i = 0; i < k; i++)
    {
        int element = nums[i];
        while (!q.empty() && element > nums[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    for (int i = k; i < n; i++)
    {
        res.push_back(nums[q.front()]);
        if (!q.empty() && i - q.front() >= k)
        {
            q.pop_front();
        }
        while (!q.empty() && nums[i] > nums[q.back()])
        {
            q.pop_back();
        }
        q.push_back(i);
    }
    res.push_back(nums[q.front()]);
    return res;
}