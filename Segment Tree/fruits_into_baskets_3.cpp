#include<iostream>
using namespace std;

// FRUITS INTO BASKETS III (LEETCODE 3479)
// USING SEGMENT TREE AND RANGE MAX QUERY - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Build a segment tree to store max values in each range of `baskets`.
// 2. For each fruit:
//     - Try placing it in the leftmost basket whose capacity ≥ fruit size.
//     - If found, mark that basket as used by updating it to -1.
// 3. If no valid basket is found for a fruit, increment the unplaced count.
// 4. Return the total number of unplaced fruits.

void buildTree(int i, int left, int right, vector<int> &baskets, vector<int> &segTree)
{
    if (left == right)
    {
        segTree[i] = baskets[left];
        return;
    }
    int mid = (left + right) / 2;
    buildTree(2 * i + 1, left, mid, baskets, segTree);
    buildTree(2 * i + 2, mid + 1, right, baskets, segTree);
    segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
}
bool queryTree(int i, int left, int right, int fruit, vector<int> &segTree)
{
    if (segTree[i] < fruit)
        return false;
    if (left == right)
    {
        segTree[i] = -1;
        return true;
    }
    int mid = (left + right) / 2;
    bool placed = false;
    if (segTree[2 * i + 1] >= fruit)
    {
        placed = queryTree(2 * i + 1, left, mid, fruit, segTree);
    }
    else
    {
        placed = queryTree(2 * i + 2, mid + 1, right, fruit, segTree);
    }
    segTree[i] = max(segTree[2 * i + 1], segTree[2 * i + 2]);
    return placed;
}
int numOfUnplacedFruits(vector<int> &fruits, vector<int> &baskets)
{
    int n = fruits.size();
    vector<int> segTree(4 * n, -1);
    buildTree(0, 0, n - 1, baskets, segTree);
    int count = 0;
    for (int &fruit : fruits)
    {
        if (!queryTree(0, 0, n - 1, fruit, segTree))
        {
            count++;
        }
    }
    return count;
}