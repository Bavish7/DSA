#include<iostream>
using namespace std;

// LONGEST INCREASING SUBSEQUENCE II (LEETCODE 2407)
// USING SEGMENT TREE - TC=O(N*LOG(MAXVAL)), SC=O(4*MAXVAL+N)

// Steps:
// 1. Define a SegmentTree to maintain and query the maximum LIS length efficiently in a given range.
// 2. For each nums[i], find the maximum LIS ending with values in the range [nums[i] - k, nums[i) using segment tree.
// 3. Update dp[i] = 1 + max LIS in that range.
// 4. Update the segment tree at nums[i] with dp[i].
// 5. At the end, the maximum value in dp[] gives the answer.

class SegmentTree
{
private:
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) : n(size)
    {
        tree.resize(4 * n, 0);
    }
    void updateTree(int index, int value, int node, int left, int right)
    {
        if (left == right)
        {
            tree[node] = value;
        }
        else
        {
            int mid = (left + right) / 2;
            if (index <= mid)
            {
                updateTree(index, value, 2 * node + 1, left, mid);
            }
            else
            {
                updateTree(index, value, 2 * node + 2, mid + 1, right);
            }
            tree[node] = max(tree[2 * node + 1], tree[2 * node + 2]);
        }
    }
    void update(int index, int value)
    {
        updateTree(index, value, 0, 0, n - 1);
    }
    int queryTree(int start, int end, int node, int left, int right)
    {
        if (start > right || end < left)
        {
            return 0;
        }
        if (start <= left && end >= right)
        {
            return tree[node];
        }
        int mid = (left + right) / 2;
        return max(queryTree(start, end, 2 * node + 1, left, mid), queryTree(start, end, 2 * node + 2, mid + 1, right));
    }
    int query(int left, int right)
    {
        if (left > right)
            return 0;
        return queryTree(left, right, 0, 0, n - 1);
    }
};

class Solution
{
public:
    int lengthOfLIS(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> dp(n, 0);
        int maxVal = *max_element(nums.begin(), nums.end());
        SegmentTree segTree(maxVal + 1);
        for (int i = 0; i < n; ++i)
        {
            int maxLength = segTree.query(max(0, nums[i] - k), nums[i] - 1);
            dp[i] = maxLength + 1;
            segTree.update(nums[i], dp[i]);
        }
        return *max_element(dp.begin(), dp.end());
    }
};