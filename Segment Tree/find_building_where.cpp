#include<iostream>
using namespace std;

// FIND BUILDING WHERE ALICE AND BOB CAN MEET (LEETCODE 2940)
// USING SEGMENT TREE AND BINARY SEARCH - TC=O(N+Q*(LOGN)^2), SC=O(N)

// Steps:
// 1. Build a segment tree to store the index of the maximum height in each segment.
// 2. For each query, determine the direction by comparing heights at query[0] and query[1]:
//    - If both indices are same, return that index.
//    - If height at right index > height at left, return right index.
// 3. Otherwise, we need to find the first building to the right of max(query[0], query[1])
//    that has height > max(height[query[0]], height[query[1]]).
// 4. Use binary search from maxIndex + 1 to end of array:
//    - In each step, query the segment tree for max height in [l, mid].
//    - If the height at that index is greater than both heights, update answer and move left.
//    - Otherwise, search to the right.
// 5. Store and return the result for each query.

vector<int> segTree;
void buildTree(int i, int left, int right, vector<int> &heights, vector<int> &segTree)
{
    if (left == right)
    {
        segTree[i] = left;
        return;
    }
    int mid = (left + right) / 2;
    buildTree(2 * i + 1, left, mid, heights, segTree);
    buildTree(2 * i + 2, mid + 1, right, heights, segTree);
    if (heights[segTree[2 * i + 1]] >= heights[segTree[2 * i + 2]])
    {
        segTree[i] = segTree[2 * i + 1];
    }
    else
    {
        segTree[i] = segTree[2 * i + 2];
    }
}
int rangeMaxIndex(int i, int left, int right, int start, int end, vector<int> &heights, vector<int> &segTree)
{
    if (left > end || right < start)
    {
        return -1;
    }
    if (start <= left && right <= end)
    {
        return segTree[i];
    }
    int mid = (left + right) / 2;
    int leftIndex = rangeMaxIndex(2 * i + 1, left, mid, start, end, heights, segTree);
    int rightIndex = rangeMaxIndex(2 * i + 2, mid + 1, right, start, end, heights, segTree);
    if (leftIndex == -1)
        return rightIndex;
    if (rightIndex == -1)
        return leftIndex;
    return (heights[leftIndex] >= heights[rightIndex]) ? leftIndex : rightIndex;
}
vector<int> leftmostBuildingQueries(vector<int> &heights, vector<vector<int>> &queries)
{
    int n = heights.size();
    segTree.resize(4 * n);
    buildTree(0, 0, n - 1, heights, segTree);
    vector<int> ans;
    for (auto &query : queries)
    {
        int minIndex = min(query[0], query[1]);
        int maxIndex = max(query[0], query[1]);
        if (minIndex == maxIndex)
        {
            ans.push_back(maxIndex);
            continue;
        }
        else if (heights[maxIndex] > heights[minIndex])
        {
            ans.push_back(maxIndex);
            continue;
        }
        int l = maxIndex + 1;
        int r = n - 1;
        int curr = -1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            int index = rangeMaxIndex(0, 0, n - 1, l, mid, heights, segTree);
            if (heights[index] > max(heights[maxIndex], heights[minIndex]))
            {
                curr = mid;
                r = mid - 1;
            }
            else
            {
                l = mid + 1;
            }
        }
        ans.push_back(curr);
    }
    return ans;
}