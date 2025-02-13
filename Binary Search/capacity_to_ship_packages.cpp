#include<iostream>
using namespace std;

// CAPACITY TO SHIP PACKAGES WITHIN D DAYS (LEETCODE 1011)
// USING FOR LOOP - TC=O(N*(SUM-MAXI)), SC=O(1)

// Steps:
// 1. Define `solve` to check if `weights` can be shipped within `days` using `maxWeight` as the weight limit per day.
//    - Accumulate weights in a day until exceeding `maxWeight`, then increment the day count.
// 2. Calculate `sum` (total weight of all packages) and `maxi` (heaviest package) to set bounds for binary search.
// 3. Perform a linear search from `maxi` to `sum` to find the minimum weight capacity that satisfies the condition.
//    - Use `solve` to check feasibility for each capacity.
// 4. Return the minimum capacity satisfying the condition.

bool solve(vector<int> &weights, int maxWeight, int days)
{
    int sum = 0, totalDays = 1;
    for (int i = 0; i < weights.size(); i++)
    {
        if (sum + weights[i] <= maxWeight)
        {
            sum += weights[i];
        }
        else
        {
            totalDays++;
            sum = weights[i];
        }
    }
    return totalDays <= days;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int sum = 0, maxi = INT_MIN;
    int n = weights.size();
    for (int i = 0; i < n; i++)
    {
        sum += weights[i];
        maxi = max(maxi, weights[i]);
    }
    for (int i = maxi; i <= sum; i++)
    {
        if (solve(weights, i, days))
        {
            return i;
        }
    }
    return -1;
}

// USING BINARY SEARCH - TC=O(N*LOG(SUM-MAXI)), SC=O(1)
// Steps:
// 1. Define `solve` to check if weights can be shipped within `days` using `maxWeight` as the weight limit per day:
//    - Accumulate weights in a day until exceeding `maxWeight`, then increment the day count.
// 2. Calculate `sum` (total weight of all packages) and `maxi` (heaviest package) to set bounds for binary search:
//    - `maxi` is the minimum possible weight capacity (at least the heaviest package).
//    - `sum` is the maximum possible weight capacity (all packages shipped in one day).
// 3. Use binary search to find the minimum weight capacity that satisfies the condition:
//    - If `solve` returns `true` for `mid`, adjust `high` to explore smaller capacities.
//    - Otherwise, adjust `low` to explore larger capacities.
// 4. Return `low`, which is the minimum capacity required to ship all packages within `days`.

bool solve(vector<int> &weights, int maxWeight, int days)
{
    int sum = 0, totalDays = 1;
    for (int i = 0; i < weights.size(); i++)
    {
        if (sum + weights[i] <= maxWeight)
        {
            sum += weights[i];
        }
        else
        {
            totalDays++;
            sum = weights[i];
        }
    }
    return totalDays <= days;
}
int shipWithinDays(vector<int> &weights, int days)
{
    int sum = 0, maxi = INT_MIN;
    int n = weights.size();
    for (int i = 0; i < n; i++)
    {
        sum += weights[i];
        maxi = max(maxi, weights[i]);
    }
    int low = maxi, high = sum;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (solve(weights, mid, days))
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