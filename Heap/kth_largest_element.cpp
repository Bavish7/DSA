#include<iostream>
using namespace std;

// Kth LARGEST ELEMENT IN AN ARRAY (LEETCODE 215)
// USING MIN HEAP ON FIRST K ELEMENTS AND THEN COMPARING THE REST ELEMENTS - TC=O(N), SC=O(K)

// Steps:
// 1. Create a min heap (priority queue) that will store the largest K elements encountered so far.
// 2. Insert the first K elements of the array into the min heap.
// 3. For each of the remaining elements in the array:
//    - If the element is greater than the top of the min heap, remove the top element from the heap and insert the current element.
//    - This ensures that the heap always contains the K largest elements encountered so far.
// 4. The top element of the min heap will be the Kth largest element in the array.

int findKthLargest(vector<int> &nums, int k)
{
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int i = 0; i < k; i++)
    {
        int element = nums[i];
        pq.push(element);
    }
    for (int i = k; i < nums.size(); i++)
    {
        int element = nums[i];
        if (element > pq.top())
        {
            pq.pop();
            pq.push(element);
        }
    }
    int ans = pq.top();
    return ans;
}