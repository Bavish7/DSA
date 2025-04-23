#include<iostream>
using namespace std;

// NON-OVERLAPPING INTERVALS (LEETCODE 435)
// USING GREEDY APPROACH - TC=O(N*LOGN), SC=O(1)

// Steps:
// 1. Define a custom comparator `compare` to sort intervals by their end times (`interval1[1] < interval2[1]`).
// 2. Sort the `intervals` array using the comparator.
// 3. Initialize `count` to 1 (for the first interval) and set `prevEnd` to the end time of the first interval.
// 4. Iterate through the sorted intervals starting from the second interval:
//    - If the current interval's start time (`currStart`) is greater than or equal to `prevEnd`:
//      - Increment `count`.
//      - Update `prevEnd` to the current interval's end time (`currEnd`).
// 5. Return `n - count`, where `count` is the number of non-overlapping intervals.
//    - Subtracting this from `n` gives the number of intervals to remove.

static bool compare(vector<int> &interval1, vector<int> &interval2)
{
    return interval1[1] < interval2[1];
}
int eraseOverlapIntervals(vector<vector<int>> &intervals)
{
    int n = intervals.size();
    sort(intervals.begin(), intervals.end(), compare);
    int count = 1;
    int prevEnd = intervals[0][1];
    int prevStart = intervals[0][0];
    for (int i = 1; i < n; i++)
    {
        int currStart = intervals[i][0];
        int currEnd = intervals[i][1];
        if (currStart >= prevEnd)
        {
            count++;
            prevStart = currStart;
            prevEnd = currEnd;
        }
    }
    return n - count;
}