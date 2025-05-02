#include<iostream>
using namespace std;

// MINIMUM DIFFERENCE IN SUMS AFTER REMOVAL OF ELEMENTS (LEETCODE 2163)
// USING PREFIX SUM AND HEAP - TC=O(NLOGK), SC=O(N)

// Steps:
// Initialize k as one third of the size of nums and n as the total size of nums.
// Create prefix and suffix vectors to store cumulative sums, initialized to -1.
// Create a variable sum to store the current sum and a maxHeap to maintain the k largest elements.
// Iterate over nums to fill the prefix array:
//   - Update the cumulative sum by adding the current element.
//   - Push the current element into maxHeap.
//   - If maxHeap exceeds size k, pop the largest element and adjust the sum.
//   - If maxHeap size equals k, store the current sum in the prefix array.
// Repeat the same process for the suffix array but iterate in reverse order using a minHeap.
// After populating prefix and suffix arrays, initialize ans to a large value.
// Iterate from k-1 to 2*k-1 and update ans with the minimum difference between prefix[i] and suffix[i+1].

#define ll long long
long long minimumDifference(vector<int> &nums)
{
    int k = nums.size() / 3;
    int n = nums.size();
    vector<ll> prefix(n, -1), suffix(n, -1);
    ll sum = 0;
    priority_queue<ll> maxHeap;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
        maxHeap.push(nums[i]);
        if (maxHeap.size() > k)
        {
            sum -= maxHeap.top();
            maxHeap.pop();
        }
        if (maxHeap.size() == k)
        {
            prefix[i] = sum;
        }
    }
    sum = 0;
    priority_queue<ll, vector<ll>, greater<ll>> minHeap;
    for (int i = n - 1; i >= 0; i--)
    {
        sum += nums[i];
        minHeap.push(nums[i]);
        if (minHeap.size() > k)
        {
            sum -= minHeap.top();
            minHeap.pop();
        }
        if (minHeap.size() == k)
        {
            suffix[i] = sum;
        }
    }
    ll ans = LONG_LONG_MAX;
    for (int i = k - 1; i < 2 * k; i++)
    {
        ans = min(ans, prefix[i] - suffix[i + 1]);
    }
    return ans;
}