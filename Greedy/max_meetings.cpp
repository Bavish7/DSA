#include<iostream>
using namespace std;

// MAXIMUM MEETINGS
// USING GREEDY APPROACH - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Create a vector of pairs to store the end time and start time of each meeting.
// 2. Sort the vector of pairs by the end time.
//    - This ensures that we are considering meetings that end earlier first, maximizing the number of meetings we can attend.
// 3. Initialize a count of meetings that can be attended and set the end time of the first meeting as the previous end time.
// 4. Iterate through the sorted vector of pairs:
//    - For each meeting, check if its start time is greater than the previous meeting's end time.
//    - If yes, increment the count and update the previous start and end times to the current meeting's times.
// 5. Return the total count of meetings that can be attended.

int maximumMeetings(vector<int> &start, vector<int> &end)
{
    int n = start.size();
    vector<pair<int, int>> time;
    for (int i = 0; i < n; i++)
    {
        time.push_back({end[i], start[i]});
    }
    sort(time.begin(), time.end());
    int count = 1;
    int prevStart = time[0].second;
    int prevEnd = time[0].first;
    for (int i = 1; i < n; i++)
    {
        int currStart = time[i].second;
        int currEnd = time[i].first;
        if (currStart > prevEnd)
        {
            count++;
            prevStart = currStart;
            prevEnd = currEnd;
        }
    }
    return count;
}