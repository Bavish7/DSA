#include<iostream>
using namespace std;

// MINIMUM NUMBER OF REFUELING STOPS (LEETCODE 871)
// USING MAX HEAP - TC=O(NLOGN), SC=O(N)

// Steps:
// 1. Initialize dist (current distance traveled) to 0, stops (number of refuel stops) to 0,
//    and fuel (initial fuel) to startFuel.
// 2. Use a priority_queue to store the fuel amounts of stations that can be reached within the current distance.
// 3. Traverse through the stations:
//    - If a station's distance is less than or equal to the current maximum distance that can be covered (dist + fuel),
//      push its fuel into the priority_queue.
//    - Break the loop if the station is beyond the current distance plus fuel.
// 4. Add the available fuel to dist and reduce the remaining fuel to 0.
// 5. If the distance (dist) exceeds or equals the target, break the loop and return the number of stops.
// 6. If no stations can be reached (priority_queue is empty) but the target has not been reached, return -1.
// 7. Otherwise, pop the largest fuel value from the queue, refuel, update the current distance to the station's position,
//    and increment the number of stops.
// 8. Continue the process until the target is reached or all stations are exhausted.

int minRefuelStops(int target, int startFuel, vector<vector<int>> &stations)
{
    int dist = 0;
    int stops = 0;
    int i = 0;
    int fuel = startFuel;
    priority_queue<pair<int, int>> pq;
    while (true)
    {
        while (i < stations.size())
        {
            if (stations[i][0] <= dist + fuel)
            {
                pq.push({stations[i][1], stations[i][0]});
            }
            else
            {
                break;
            }
            i++;
        }
        dist += fuel;
        fuel = 0;
        if (dist >= target)
            break;
        if (pq.empty())
        {
            stops = -1;
            break;
        }
        auto top = pq.top();
        fuel = (dist - top.second) + top.first;
        dist = top.second;
        pq.pop();
        stops++;
    }
    return stops;
}