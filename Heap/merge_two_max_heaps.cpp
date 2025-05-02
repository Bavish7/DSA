#include<iostream>
using namespace std;

// MERGE TWO BINARY MAX HEAPS 
// USING HEAPIFY ALGORITHM - TC=O(N+M), SC=O(N+M)

// Steps:
// 1. Merge two arrays `arr1` and `arr2` into one vector `ans`.
// 2. Heapify the combined array:
//    - Start from the last non-leaf node (at index `size/2 - 1`) and heapify each node up to the root.
//    - The `heapify` function ensures that the subtree rooted at index `i` maintains the max-heap property by comparing the node with its children and swapping if necessary.
// 3. Recursively adjust the heap if any swaps are made.
// 4. The result is a valid max heap.

void heapify(vector<int> &ans, int i, int n)
{
    int leftIndex = 2 * i + 1;
    int rightIndex = 2 * i + 2;
    int largestIndex = i;
    if (leftIndex < n && ans[leftIndex] > ans[largestIndex])
    {
        largestIndex = leftIndex;
    }
    if (rightIndex < n && ans[rightIndex] > ans[largestIndex])
    {
        largestIndex = rightIndex;
    }
    if (i != largestIndex)
    {
        swap(ans[i], ans[largestIndex]);
        i = largestIndex;
        heapify(ans, i, n);
    }
}
vector<int> mergeHeap(int n, int m, vector<int> &arr1, vector<int> &arr2)
{
    vector<int> ans(arr1.begin(), arr1.end());
    ans.insert(ans.end(), arr2.begin(), arr2.end());
    int size = ans.size();
    for (int i = (size / 2) - 1; i >= 0; i--)
    {
        heapify(ans, i, size);
    }
    return ans;
}