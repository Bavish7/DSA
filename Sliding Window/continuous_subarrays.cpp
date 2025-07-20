#include<iostream>
using namespace std;

// CONTINUOUS SUBARRAYS (LEETCODE 2762)
// USING VARIABLE SIZE SLIDING WINDOW AND HEAPS - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Maintain a sliding window [left, right] with MaxHeap and MinHeap to track max/min in the window.
// 2. Push (value, index) pairs into both heaps as window expands.
// 3. If max - min > 2, update `left` to exclude outdated elements and lazily remove all heap elements with index < left.
// 4. For each valid window, add (right - left + 1) to count of subarrays.
// 5. Continue until the full array is processed, return total count.

long long continuousSubarrays(vector<int> &nums)
{
    int n = nums.size();
    priority_queue<pair<int, int>> maxHeap;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    int left = 0, right = 0;
    long long count = 0;
    while (right < n)
    {
        maxHeap.push({nums[right], right});
        minHeap.push({nums[right], right});
        while (maxHeap.top().first - minHeap.top().first > 2)
        {
            left = min(minHeap.top().second, maxHeap.top().second) + 1;
            while (maxHeap.top().second < left)
            {
                maxHeap.pop();
            }
            while (minHeap.top().second < left)
            {
                minHeap.pop();
            }
        }
        count += right - left + 1;
        right++;
    }
    return count;
}

// USING VARIABLE SIZE SLIDING WINDOW AND ORDERED MAP - TC=O(N), SC=O(1)
// Steps:
// 1. Use a sliding window [left, right] to explore all valid subarrays.
// 2. Maintain a `map` to count frequencies and get min/max elements in window using `begin()` and `rbegin()`.
// 3. If max - min > 2, shrink the window from the left until it's valid.
// 4. For each valid window, add (right - left + 1) to total subarray count.
// 5. Repeat until all positions are checked, return total count.

long long continuousSubarrays(vector<int> &nums)
{
    int n = nums.size();
    map<int, int> mp;
    int left = 0, right = 0;
    long long count = 0;
    while (right < n)
    {
        mp[nums[right]]++;
        while (abs(mp.rbegin()->first - mp.begin()->first) > 2)
        {
            mp[nums[left]]--;
            if (mp[nums[left]] == 0)
                mp.erase(nums[left]);
            left++;
        }
        count += right - left + 1;
        right++;
    }
    return count;
}

// USING VARIABLE SIZE SLIDING WINDOW AND DEQUES - TC=O(N), SC=O(1)
// Steps:
// 1. Maintain two deques:
//    - maxDeque stores indices in decreasing order of values (monotonic decreasing)
//    - minDeque stores indices in increasing order of values (monotonic increasing)
// 2. For each right index:
//    - Clean both deques to maintain monotonic property before inserting `right`
// 3. Shrink the window from the left if the current window violates the constraint (max - min > 2)
//    - Pop indices from front if they fall out of window
// 4. For each valid window, add (right - left + 1) to the count of subarrays
// 5. Return the total count of such valid subarrays

long long continuousSubarrays(vector<int> &nums)
{
    int n = nums.size();
    deque<int> maxDeque, minDeque;
    int left = 0, right = 0;
    long long count = 0;
    while (right < n)
    {
        while (!maxDeque.empty() && nums[maxDeque.back()] <= nums[right])
            maxDeque.pop_back();
        maxDeque.push_back(right);
        while (!minDeque.empty() && nums[minDeque.back()] >= nums[right])
            minDeque.pop_back();
        minDeque.push_back(right);
        while (nums[maxDeque.front()] - nums[minDeque.front()] > 2)
        {
            if (maxDeque.front() == left)
                maxDeque.pop_front();
            if (minDeque.front() == left)
                minDeque.pop_front();
            left++;
        }
        count += right - left + 1;
        right++;
    }
    return count;
}
