#include<iostream>
#include <algorithm>
using namespace std;

// FRACTIONAL KNAPSACK 
// USING GREEDY APPROACH - TC=O(N*LOGN), SC=O(1)

// Steps:
// 1. Sort the items based on their value-to-weight ratio in descending order.
// 2. Initialize `maxValue` to store the maximum value and `currWeight` to track the current weight in the knapsack.
// 3. Iterate through the sorted items:
//    - If adding the current item doesn't exceed the capacity `w`, add its full weight and value to the knapsack.
//    - If adding the current item exceeds the capacity `w`, add the fractional part of the item that fits in the knapsack.
// 4. Return the maximum value obtained.

bool compare(pair<int, int> &a, pair<int, int> &b)
{
    double r1 = (double)a.second / a.first;
    double r2 = (double)b.second / b.first;

    return r1 > r2;
}
double maximumValue(vector<pair<int, int>> &items, int n, int w)
{
    sort(items.begin(), items.end(), compare);
    double maxValue = 0;
    int currWeight = 0;
    for (int i = 0; i < n; i++)
    {
        if (currWeight + items[i].first <= w)
        {
            currWeight += items[i].first;
            maxValue += items[i].second;
        }
        else
        {
            int remainingWeight = w - currWeight;
            maxValue += items[i].second * ((double)remainingWeight / items[i].first);
            break;
        }
    }
    return maxValue;
}