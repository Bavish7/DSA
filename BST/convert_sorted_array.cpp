#include<iostream>
using namespace std;

// CONVERT SORTED ARRAY TO BST (LEETCODE 108)
// USING DIVIDE AND CONQUER AND RECURSION - TC=O(N), SC=O(N)

// Steps:
// 1. Return NULL if start > end.
// 2. Calculate mid index as (start + end) / 2.
// 3. Create TreeNode with value nums[mid].
// 4. Recursively set left child as BSTFromArray(nums, start, mid - 1).
// 5. Recursively set right child as BSTFromArray(nums, mid + 1, end).
// 6. Return constructed root.

TreeNode *BSTFromArray(vector<int> &nums, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    int element = nums[mid];
    TreeNode *root = new TreeNode(element);
    root->left = BSTFromArray(nums, start, mid - 1);
    root->right = BSTFromArray(nums, mid + 1, end);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    int start = 0;
    int end = nums.size() - 1;
    TreeNode *root = BSTFromArray(nums, start, end);
    return root;
}