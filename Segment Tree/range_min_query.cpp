#include<iostream>
using namespace std;

// RANGE MINIMUM QUERY
// USING SEGMENT TREE - TC=O(N+LOGN), SC=O(N)

// Steps:
// 1. Build a Segment Tree using recursion:
//    - Base Case: If left == right, store the array element at the current tree node.
//    - Recursive Case: Split array into two halves, build left and right subtrees, and store the minimum of both in the current node.
// 2. For Range Minimum Query (RMQ):
//    - If query range is completely outside the node range, return ∞ (INT_MAX).
//    - If query range fully covers the node range, return the node's value.
//    - Else, split query and recursively get the min from left and right children.
// 3. Use `constructST()` to get the segment tree, and `RMQ()` to perform queries.

void buildTree(int i, int left, int right, int arr[], int tree[])
{
    if (left == right)
    {
        tree[i] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    buildTree(2 * i + 1, left, mid, arr, tree);
    buildTree(2 * i + 2, mid + 1, right, arr, tree);
    tree[i] = min(tree[2 * i + 1], tree[2 * i + 2]);
}
int *constructST(int arr[], int n)
{
    int *tree = new int[4 * n];
    buildTree(0, 0, n - 1, arr, tree);
    return tree;
}
int minQuery(int i, int start, int end, int left, int right, int tree[])
{
    if (left > end || right < start)
        return INT_MAX;
    if (left >= start && right <= end)
    {
        return tree[i];
    }
    else
    {
        int mid = (left + right) / 2;
        return min(minQuery(2 * i + 1, start, end, left, mid, tree), minQuery(2 * i + 2, start, end, mid + 1, right, tree));
    }
}
int RMQ(int st[], int n, int a, int b)
{
    return minQuery(0, a, b, 0, n - 1, st);
}