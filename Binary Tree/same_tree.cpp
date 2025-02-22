#include <iostream>
using namespace std;

// SAME TREE (LEETCODE 100) 
// USING RECURSION - TC=O(N), SC=O(N)

bool isSameTree(TreeNode *p, TreeNode *q)
{
    if (p == NULL && q == NULL)
    {
        return true;
    }
    if (p == NULL && q != NULL)
    {
        return false;
    }
    if (p != NULL && q == NULL)
    {
        return false;
    }
    bool left = isSameTree(p->left, q->left);
    bool right = isSameTree(p->right, q->right);
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