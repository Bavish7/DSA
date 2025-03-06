#include<iostream>
using namespace std;

// LOWEST COMMON ANCESTOR OF A BST (LEETCODE 235)
// USING RECURSION - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize root to starting node.
// 2. While root is not NULL:
//    a. If both p and q are smaller than root's value, move to left subtree.
//    b. If both p and q are larger than root's value, move to right subtree.
//    c. If p and q are on different sides of root's value, return root.
// 3. Return NULL if no LCA found.

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val > p->val && root->val > q->val)
    {
        return lowestCommonAncestor(root->left, p, q);
    }
    else if (root->val < p->val && root->val < q->val)
    {
        return lowestCommonAncestor(root->right, p, q);
    }
    else if ((root->val > p->val && root->val < q->val) || (root->val < p->val && root->val > q->val))
    {
        return root;
    }
    return root;
}