#include<iostream>
using namespace std;

// MERGE INTERVALS (LEETCODE 56)
// USING SORTING - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Sort the intervals by their start times to ensure they are processed in order.
// 2. Traverse the sorted intervals and maintain the current interval being merged.
// 3. If the current interval overlaps with the next interval, extend the end of the current interval to include the next interval.
// 4. If there is no overlap, push the current interval into the result and start a new interval.
// 5. Skip intervals that are completely covered by the previous interval.
// 6. Return the merged intervals.

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        int start = intervals[i][0];
        int end = intervals[i][1];
        if (!ans.empty() && end <= ans.back()[1])
        {
            continue;
        }
        for (int j = i + 1; j < n; j++)
        {
            if (intervals[j][0] <= end)
            {
                end = max(end, intervals[j][1]);
            }
            else
            {
                break;
            }
        }
        ans.push_back({start, end});
    }
    return ans;
}

// USING SORTING - TC=O(N*LOGN), SC=O(N)
// 1. Sort the intervals by their start times to ensure they are processed in order.
// 2. Traverse the sorted intervals while maintaining the merged intervals in a result vector (`ans`).
// 3. If the result vector is empty or the current interval does not overlap with the last interval in the result, add the current interval to the result.
// 4. If there is an overlap, merge the current interval with the last interval in the result by updating the end of the last interval to the maximum end value.
// 5. Return the merged intervals after processing all intervals.

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end());
    vector<vector<int>> ans;
    for (int i = 0; i < n; i++)
    {
        if (ans.empty() || ans.back()[1] < intervals[i][0])
        {
            ans.push_back(intervals[i]);
        }
        else
        {
            ans.back()[1] = max(ans.back()[1], intervals[i][1]);
        }
    }
    return ans;
}