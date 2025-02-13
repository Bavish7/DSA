#include<iostream>
using namespace std;

// MINIMUM NUMBER OF DAYS TO MAKE M BOUQUETS (LEETCODE 1482)
// USING FOR LOOP - TC=O(N*(MAXI-MINI)), SC=O(1) - TLE

// Steps:
// 1. Define a helper function `solve` to check if `m` bouquets can be made on or before a specific `day`:
//    - Traverse the `bloomDay` array and count consecutive flowers blooming on or before `day`.
//    - If the count of consecutive flowers reaches `k`, increase the bouquet count and reset the count.
//    - Add any remaining bouquets formed at the end of the array.
//    - Return true if the bouquet count is at least `m`, otherwise return false.
// 2. In `minDays` function:
//    - If `m * k > n` (total required flowers exceed available), return -1 as it's impossible to make the bouquets.
//    - Find the minimum (`mini`) and maximum (`maxi`) bloom days by iterating through `bloomDay`.
//    - Use a linear search from `mini` to `maxi`:
//        - For each day in this range, check if it is possible to make `m` bouquets using `solve`.
//        - Return the first day where `solve` returns true.
//    - If no valid day is found, return -1.

bool solve(vector<int> &bloomDay, int day, int m, int k)
{
    int count = 0, bouquet = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= day)
        {
            count++;
        }
        else
        {
            bouquet += count / k;
            count = 0;
        }
    }
    bouquet += count / k;
    if (bouquet >= m)
    {
        return true;
    }
    return false;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    int maxi = INT_MIN, mini = INT_MAX;
    int n = bloomDay.size();
    if (m * k > n)
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] < mini)
        {
            mini = bloomDay[i];
        }
        if (bloomDay[i] > maxi)
        {
            maxi = bloomDay[i];
        }
    }
    for (int i = mini; i <= maxi; i++)
    {
        if (solve(bloomDay, i, m, k))
        {
            return i;
        }
    }
    return -1;
}

// USING BINARY SEARCH - TC=O(N*LOG(MAXI-MINI)), SC=O(1)
// Steps:
// 1. Define a helper function `solve` to check if `m` bouquets can be made on or before a specific `day`:
//    - Traverse the `bloomDay` array and count consecutive flowers blooming on or before `day`.
//    - When the count reaches `k` (flowers needed for one bouquet), increase the bouquet count and reset the count.
//    - Add any remaining bouquets formed at the end of the array.
//    - Return true if the bouquet count is at least `m`, otherwise return false.
// 2. In the `minDays` function:
//    - If `(double)m * k > n`, return -1 because it is impossible to make the required bouquets.
//    - Find the minimum (`mini`) and maximum (`maxi`) bloom days by iterating through `bloomDay`.
//    - Use binary search on the range of days [mini, maxi]:
//        - Calculate the mid-point `mid` of the range.
//        - Check if it is possible to make `m` bouquets on `mid` day using `solve`.
//        - If yes, update `high = mid - 1` to find a smaller possible day.
//        - Otherwise, update `low = mid + 1` to find a valid day.
//    - Return `low`, which will be the minimum day to make `m` bouquets.

bool solve(vector<int> &bloomDay, int day, int m, int k)
{
    int count = 0, bouquet = 0;
    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= day)
        {
            count++;
        }
        else
        {
            bouquet += count / k;
            count = 0;
        }
    }
    bouquet += count / k;
    if (bouquet >= m)
    {
        return true;
    }
    return false;
}
int minDays(vector<int> &bloomDay, int m, int k)
{
    int maxi = INT_MIN, mini = INT_MAX;
    int n = bloomDay.size();
    if ((double)m * k > n)
    {
        return -1;
    }
    for (int i = 0; i < n; i++)
    {
        if (bloomDay[i] < mini)
        {
            mini = bloomDay[i];
        }
        if (bloomDay[i] > maxi)
        {
            maxi = bloomDay[i];
        }
    }
    int low = mini, high = maxi;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (solve(bloomDay, mid, m, k))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}