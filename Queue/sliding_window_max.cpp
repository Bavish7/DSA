#include <iostream>
#include <queue>
using namespace std;

// SLIDING WINDOW MAXIMUM (LEETCODE 239) - TC=O(N), SC=O(K)
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