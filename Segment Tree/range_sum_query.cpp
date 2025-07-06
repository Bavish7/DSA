#include<iostream>
using namespace std;

// RANGE SUM QUERY - MUTABLE (LEETCODE 307)
// USING SEGMENT TREE - TC=O(N+LOGN), SC=O(N)

// Steps:
// 1. Build a segment tree where each node stores the sum of a range of elements.
// 2. buildTree() recursively builds the tree in O(N) time.
// 3. updateTree() modifies the value at a given index and updates the affected nodes up the tree.
// 4. sumQuery() fetches the sum of values in the given range using standard segment tree range query logic.
// 5. update() and sumRange() are public methods to call updateTree and sumQuery respectively.
// 6. All operations are done in O(log N) time due to the balanced nature of the segment tree.

int n;
vector<int> tree;
void buildTree(vector<int> &arr, int index, int left, int right, vector<int> &tree)
{
    if (left == right)
    {
        tree[index] = arr[left];
        return;
    }
    int mid = (left + right) / 2;
    buildTree(arr, 2 * index + 1, left, mid, tree);
    buildTree(arr, 2 * index + 2, mid + 1, right, tree);
    tree[index] = tree[2 * index + 1] + tree[2 * index + 2];
}
NumArray(vector<int> &nums)
{
    n = nums.size();
    tree.resize(4 * n);
    buildTree(nums, 0, 0, n - 1, tree);
}
void updateTree(int index, int value, int root, int left, int right, vector<int> &tree)
{
    if (left == right)
    {
        tree[root] = value;
        return;
    }
    int mid = (left + right) / 2;
    if (index <= mid)
    {
        updateTree(index, value, 2 * root + 1, left, mid, tree);
    }
    else
    {
        updateTree(index, value, 2 * root + 2, mid + 1, right, tree);
    }
    tree[root] = tree[2 * root + 1] + tree[2 * root + 2];
}
void update(int index, int val)
{
    updateTree(index, val, 0, 0, n - 1, tree);
}
int sumQuery(int index, int start, int end, int left, int right, vector<int> &tree)
{
    if (left > end || right < start)
    {
        return 0;
    }
    else if (start <= left && end >= right)
    {
        return tree[index];
    }
    else
    {
        int mid = (left + right) / 2;
        return sumQuery(2 * index + 1, start, end, left, mid, tree) + sumQuery(2 * index + 2, start, end, mid + 1, right, tree);
    }
}
int sumRange(int left, int right)
{
    return sumQuery(0, left, right, 0, n - 1, tree);
}