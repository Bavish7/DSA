#include<iostream>
using namespace std;

// MINIMUM TIME DIFFERENCE (LEETCODE 539)
// USING STRING AND SORTING - O(N*LOGN), SC=O(N)

// Steps:
// 1. Convert each time string to its equivalent in minutes from 00:00 using a helper function.
// 2. Sort the list of times in minutes.
// 3. Calculate the minimum difference between consecutive times.
// 4. Consider the circular nature of the clock by comparing the difference between the first and last time points across midnight.
// 5. Return the smallest difference found.

int convertToMin(string &time)
{
    int hour = stoi(time.substr(0, 2));
    int min = stoi(time.substr(3, 2));
    return 60 * hour + min;
}
int findMinDifference(vector<string> &timePoints)
{
    int diff = INT_MAX;
    vector<int> mins;
    for (auto time : timePoints)
    {
        mins.push_back(convertToMin(time));
    }
    sort(mins.begin(), mins.end());
    for (int i = 0; i < mins.size() - 1; i++)
    {
        diff = min(mins[i + 1] - mins[i], diff);
    }
    int lastDiff = mins[0] + 1440 - mins[mins.size() - 1];
    diff = min(diff, lastDiff);
    return diff;
}