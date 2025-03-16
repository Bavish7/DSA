#include<iostream>
using namespace std;

// MINIMUM TIME TO REPAIR CARS (LEETCODE 2594)
// USING BINARY SEARCH ON ANSWER - TC=O(N*LOG(MIN*CARS*CARS)), SC=O(1)

// Steps:
// 1. `isPossible` function checks if `mid` time is sufficient to repair `cars`:
//    - Iterate through `ranks`, computing the number of cars each mechanic can repair within `mid` using `sqrt(mid / ranks[i])`.
//    - Sum up the total repaired cars and return true if `count >= cars`, else return false.
// 2. `repairCars` finds the minimum time required using binary search:
//    - Initialize `left` as 1 (minimum possible time) and `right` as the worst-case time (smallest rank * cars²).
//    - Perform binary search on `mid`, the candidate minimum time.
//    - If `isPossible(mid)` is true, update `ans` and search for a smaller valid `mid`.
//    - Otherwise, increase `left` to find a feasible `mid`.
//    - Return `ans`, the minimum time required to repair all cars.

bool isPossible(vector<int> &ranks, int cars, long long mid)
{
    long long count = 0;
    for (int i = 0; i < ranks.size(); i++)
    {
        count += sqrt(mid / ranks[i]);
    }
    return count >= cars;
}
long long repairCars(vector<int> &ranks, int cars)
{
    int n = ranks.size();
    long long left = 1;
    long long right = LONG_LONG_MAX;
    for (int i = 0; i < n; i++)
    {
        if (ranks[i] < right)
        {
            right = ranks[i];
        }
    }
    right = right * cars * cars;
    long long ans = -1;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (isPossible(ranks, cars, mid))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}