#include<iostream>
using namespace std;

// SYMMETRIC TREE (LEETCODE 101)
// USING RECURSION - TC=O(N), SC=O(N)

// Steps : 
// 1. Define a helper function `isMirror` to check if two trees are mirrors of each other.
// 2. If both nodes are NULL, return true; if only one is NULL, return false.
// 3. Recursively check if the left subtree of one tree is a mirror of the right subtree of the other, and vice versa.
// 4. Ensure the values of the two nodes are equal.
// 5. If both subtrees and values match, return true; otherwise, return false.
// 6. The main function `isSymmetric` checks if the left and right subtrees of the root are mirrors using `isMirror`.

bool isMirror(TreeNode * p, TreeNode *q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    else if (p == NULL && q != NULL)
    {
        return false;
    }
    else if (p != NULL && q == NULL)
    {
        return false;
    }
    bool left = isMirror(p->left, q->right);
    bool right = isMirror(p->right, q->left);
    bool value = p->val == q->val;
    if (left && right && value)
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool isSymmetric(TreeNode *root)
{
    return isMirror(root->left, root->right);
}