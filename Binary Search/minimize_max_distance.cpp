#include<iostream>
using namespace std;

// MINIMIZE MAX DISTANCE TO GAS STATION
// USING NESTED FOR LOOP - TC=O(K*N), SC=O(N)

// Steps:
// 1. Divide the intervals between gas stations to minimize the maximum distance between stations:
//    - Maintain a `howMany` array to track the number of additional stations added between consecutive gas stations.
//    - For each of the `k` stations to be added:
//      a. Identify the interval with the largest section length (computed as `diff / (howMany[i] + 1)`).
//      b. Increment the corresponding count in `howMany` to reduce that section's length.
// 2. After distributing all `k` stations, compute the maximum section length over all intervals with the updated `howMany` values.
// 3. Return the maximum section length as the result.

double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        double maxSection = -1;
        int maxInd = -1;
        for (int i = 0; i < n - 1; i++)
        {
            double diff = arr[i + 1] - arr[i];
            double sectionLength = diff / (double)(howMany[i] + 1);
            if (sectionLength > maxSection)
            {
                maxSection = sectionLength;
                maxInd = i;
            }
        }
        howMany[maxInd]++;
    }
    double maxAns = -1;
    for (int i = 0; i < n - 1; i++)
    {
        double diff = arr[i + 1] - arr[i];
        double sectionLength = diff / (double)(howMany[i] + 1);
        maxAns = max(maxAns, sectionLength);
    }
    return maxAns;
}

// USING MAX HEAP - TC=O(K*LOGN), SC=O(N)
// Steps:
// 1. Use a max-heap to efficiently manage the intervals between gas stations with the largest section lengths:
//    - Initialize a `howMany` array to track the number of additional stations added to each interval.
//    - Push all intervals into a max-heap, storing their initial lengths and indices.
// 2. For each of the `k` stations to be added:
//    - Extract the interval with the largest section length from the heap.
//    - Increment the count in `howMany` for this interval to simulate adding a station.
//    - Recompute the new section length for this interval and push it back into the heap.
// 3. The largest section length remaining in the heap is the minimized maximum distance after adding all `k` stations.
// 4. Return this value as the result.

double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    vector<int> howMany(n - 1, 0);
    priority_queue<pair<double, int>> maxHeap;
    for (int i = 0; i < n - 1; i++)
    {
        maxHeap.push({arr[i + 1] - arr[i], i});
    }
    for (int gasStations = 1; gasStations <= k; gasStations++)
    {
        auto top = maxHeap.top();
        maxHeap.pop();
        int secInd = top.second;
        howMany[secInd]++;
        double iniDiff = arr[secInd + 1] - arr[secInd];
        double newSecLen = iniDiff / (double)(howMany[secInd] + 1);
        maxHeap.push({newSecLen, secInd});
    }
    return maxHeap.top().first;
}

// USING BINARY SEARCH - TC=O(N*LOG(HIGH-LOW)), SC=O(1)
// Steps:
// 1. Define a helper function `noOfGasStations` to compute the number of additional gas stations required to ensure the distance between consecutive stations is at most `dist`:
//    - For each interval between stations, calculate the number of gas stations needed and sum them up.
//    - Adjust the count if the interval is perfectly divisible by `dist` to avoid overcounting.
// 2. Use binary search to minimize the maximum distance between consecutive stations:
//    - Initialize `low` to 0 and `high` to the largest initial interval between stations.
//    - Compute the midpoint (`mid`) and determine the number of stations needed using `noOfGasStations`.
//    - Adjust the search range:
//      - If more stations are needed (`count > k`), increase `low`.
//      - Otherwise, decrease `high`.
//    - Continue until the difference between `high` and `low` is within a precision (`1e-6`).
// 3. Return `high` as the minimized maximum distance.

int noOfGasStations(double dist, vector<int> &arr)
{
    int cnt = 0;
    for (int i = 1; i < arr.size(); i++)
    {
        int numInBetween = ((arr[i] - arr[i - 1]) / dist);
        if ((arr[i] - arr[i - 1]) / dist == numInBetween * dist)
        {
            numInBetween--;
        }
        cnt += numInBetween;
    }
    return cnt;
}
double minimiseMaxDistance(vector<int> &arr, int k)
{
    int n = arr.size();
    double low = 0;
    double high = 0;
    for (int i = 0; i < n - 1; i++)
    {
        high = max(high, (double)(arr[i + 1] - arr[i]));
    }
    double diff = 1e-6;
    while (high - low >= diff)
    {
        double mid = (low + high) / (2.0);
        int count = noOfGasStations(mid, arr);
        if (count > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}