#include<iostream>
using namespace std;

// CONNECT N ROPES WITH MINIMUM COST
// USING MIN HEAP AND GREEDY APPROACH - TC=O(N*LOGN), SC=O(N)
long long connectRopes(int *arr, int n)
{
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    for (int i = 0; i < n; i++)
    {
        minHeap.push(arr[i]);
    }
    long long ans = 0;
    while (minHeap.size() > 1)
    {
        long long first = minHeap.top();
        minHeap.pop();
        long long second = minHeap.top();
        minHeap.pop();
        long long sum = first + second;
        ans += sum;
        minHeap.push(sum);
    }
    return ans;
}