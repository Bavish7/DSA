#include<iostream>
using namespace std;

// INSERT INTERVAL (LEETCODE 57)
// USING GREEDY APPROACH - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize an empty vector `ans` to store the merged intervals.
// 2. Iterate through the intervals until the current interval's end time is less than the new interval's start time:
//    - Add the current interval to the `ans` vector.
// 3. Merge the overlapping intervals:
//    - Update the new interval's start time to the minimum of the current interval's start time and the new interval's start time.
//    - Update the new interval's end time to the maximum of the current interval's end time and the new interval's end time.
// 4. Add the merged interval to the `ans` vector.
// 5. Add the remaining intervals to the `ans` vector.
// 6. Return the merged intervals.

vector<vector<int>> insert(vector<vector<int>> &intervals, vector<int> &newInterval)
{
    int n = intervals.size();
    vector<vector<int>> ans;
    int i = 0;
    while (i < n && intervals[i][1] < newInterval[0])
    {
        ans.push_back(intervals[i]);
        i++;
    }
    while (i < n && intervals[i][0] <= newInterval[1])
    {
        newInterval[0] = min(newInterval[0], intervals[i][0]);
        newInterval[1] = max(newInterval[1], intervals[i][1]);
        i++;
    }
    ans.push_back(newInterval);
    while (i < n)
    {
        ans.push_back(intervals[i]);
        i++;
    }
    return ans;
}