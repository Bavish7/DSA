#include<iostream>
using namespace std;

// PUT MARBLES IN BAGS (LEETCODE 2551)
// USING GREEDY ALGORITHM - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Compute `pairSum` array, which stores the sum of adjacent weights.
// 2. Sort `pairSum` in ascending order.
// 3. Compute `minSum` using the smallest (k-1) values from `pairSum`.
// 4. Compute `maxSum` using the largest (k-1) values from `pairSum`.
// 5. Return the difference `maxSum - minSum`.

long long putMarbles(vector<int> &weights, int k)
{
    int n = weights.size();
    vector<int> pairSum(n - 1);
    for (int i = 0; i < n - 1; i++)
    {
        pairSum[i] = (weights[i] + weights[i + 1]);
    }
    sort(pairSum.begin(), pairSum.end());
    long long maxSum = 0;
    long long minSum = 0;
    for (int i = 0; i < k - 1; i++)
    {
        minSum += pairSum[i];
        maxSum += pairSum[n - i - 2];
    }
    return maxSum - minSum;
}

// USING MAXHEAP AND MINHEAP - TC=O(N*LOGK), SC=O(K)
// Steps:
// 1. Compute `pairSum` for adjacent weights and store them in two heaps:
//    - `maxHeap` to store the largest (k-1) elements.
//    - `minHeap` to store the smallest (k-1) elements.
// 2. Maintain the heap size at `k-1` by popping extra elements.
// 3. Compute `minSum` using elements from `maxHeap`.
// 4. Compute `maxSum` using elements from `minHeap`.
// 5. Return the difference `maxSum - minSum`.

long long putMarbles(vector<int> &weights, int k)
{
    int n = weights.size();
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;
    for (int i = 0; i < n - 1; i++)
    {
        maxHeap.push(weights[i] + weights[i + 1]);
        minHeap.push(weights[i] + weights[i + 1]);
        if (maxHeap.size() > k - 1)
        {
            maxHeap.pop();
            minHeap.pop();
        }
    }
    long long minSum = 0, maxSum = 0;
    while (!maxHeap.empty())
    {
        minSum += maxHeap.top();
        maxSum += minHeap.top();
        maxHeap.pop();
        minHeap.pop();
    }
    return maxSum - minSum;
}