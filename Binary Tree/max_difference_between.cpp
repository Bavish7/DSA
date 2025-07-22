#include<iostream>
using namespace std;

// MAXIMUM DIFFERENCE BETWEEN NODE AND ANCESTOR (LEETCODE 1026)
// USING POSTORDER TRAVERSAL - TC=O(N), SC=O(H)

// Steps:
// 1. Perform a postorder traversal of the binary tree.
// 2. For each node, keep track of the minimum and maximum values encountered from the root to that node.
// 3. At each node, calculate the difference between the current node's value and both the minimum and maximum values.
// 4. Return the maximum of these differences as the result.

int findMaxDiff(TreeNode *root, int minV, int maxV)
{
    if (!root)
        return abs(minV - maxV);
    minV = min(root->val, minV);
    maxV = max(root->val, maxV);
    int l = findMaxDiff(root->left, minV, maxV);
    int r = findMaxDiff(root->right, minV, maxV);
    return max(l, r);
}
int maxAncestorDiff(TreeNode *root)
{
    int minV = root->val;
    int maxV = root->val;
    return findMaxDiff(root, minV, maxV);
}