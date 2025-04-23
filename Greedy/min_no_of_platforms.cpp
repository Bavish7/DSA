#include<iostream>
using namespace std;

// MINIMUM NUMBER OF PLATFORMS REQUIRED
// USING GREEDY APPROACH - TC=O(N*LOGN), SC=O(1)

// Steps:
// 1. Sort the arrival and departure times of trains.
// 2. Initialize `platforms` to 1 (for the first train) and set `maxPlatforms` to 1.
// 3. Iterate through the arrival and departure times of trains:
//    - If the arrival time of the current train is less than or equal to the departure time of the train at the current platform:
//      - Increment `platforms`.
//      - Update `maxPlatforms` to the maximum of `maxPlatforms` and `platforms`.
//    - Otherwise, move to the next train.
// 4. Return `maxPlatforms`, which is the minimum number of platforms required.

int minPlatforms(vector<int> &arrival, vector<int> &departure)
{
    int n = arrival.size();
    sort(arrival.begin(), arrival.end());
    sort(departure.begin(), departure.end());
    int platforms = 1, maxPlatforms = 1;
    int i = 1, j = 0;
    while (i < n && j < n)
    {
        if (arrival[i] <= departure[j])
        {
            platforms++;
            maxPlatforms = max(maxPlatforms, platforms);
            i++;
        }
        else
        {
            platforms--;
            j++;
        }
    }
    return maxPlatforms;
}
