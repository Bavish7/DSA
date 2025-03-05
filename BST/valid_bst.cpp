#include<iostream>
using namespace std;

// VALID BST (LEETCODE 98)
// USING RANGE FOR EACH NODE AND RECURSION - TC=O(N), SC=O(N)

// Steps:
// isBST(root, min, max):
// 1. If root is NULL, return true.
// 2. Check if root's value is within the valid range (min, max).
// 3. Recursively check left subtree with updated max limit as root's value.
// 4. Recursively check right subtree with updated min limit as root's value.
// 5. Return true if both left and right subtrees are valid BSTs; otherwise, false.

bool isBST(TreeNode *root, long long min, long long max)
{
    if (root == NULL)
    {
        return true;
    }
    if (root->val > min && root->val < max)
    {
        bool left = isBST(root->left, min, root->val);
        bool right = isBST(root->right, root->val, max);
        return left && right;
    }
    else
    {
        return false;
    }
}
bool isValidBST(TreeNode *root)
{
    long long int min = -1000000000000, max = 1000000000000;
    return isBST(root, min, max);
}
