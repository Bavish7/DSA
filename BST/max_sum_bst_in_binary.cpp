#include<iostream>
using namespace std;

// MAXIMUM SUM BST IN BINARY TREE (LEETCODE 1373)
// USING POSTORDER TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// 1. Use a helper function that returns information (`info` struct) about each subtree:
//    - `isValid`: Whether the subtree is a valid BST.
//    - `max` and `min`: Maximum and minimum values in the subtree.
//    - `sum`: Sum of the subtree’s node values.
// 2. Recursively get `info` from the left and right subtrees.
// 3. A subtree is a BST if the root value is greater than the max in the left subtree and less than the min in the right subtree, and both subtrees are valid BSTs.
// 4. If valid, update `maxBST` with the sum of the current subtree.
// 5. The final result is stored in `maxBST` and returned.

class info
{
public:
    bool isValid;
    int max, min, sum;
};
class Solution
{
public:
    info helper(TreeNode *root, int &maxBST)
    {
        if (!root)
            return {true, INT_MIN, INT_MAX, 0};
        info left = helper(root->left, maxBST);
        info right = helper(root->right, maxBST);
        info currInfo;
        currInfo.sum = left.sum + right.sum + root->val;
        currInfo.max = max(root->val, right.max);
        currInfo.min = min(root->val, left.min);
        currInfo.isValid = (root->val > left.max && root->val < right.min && left.isValid && right.isValid);
        if (currInfo.isValid)
            maxBST = max(maxBST, currInfo.sum);
        return currInfo;
    }
    int maxSumBST(TreeNode *root)
    {
        int ans = 0;
        helper(root, ans);
        return ans;
    }
};