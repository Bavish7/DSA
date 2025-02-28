#include<iostream>
using namespace std;

// CONSTRUCT BST FROM PREORDER TRAVERSAL (LEETCODE 1008)
// USING RANGE FOR EACH NODE AND RECURSION - TC=O(N), SC=O(N)

// Steps:
// 1. Return NULL if i is out of range or preorder[i] is not within (mini, maxi).
// 2. Create new TreeNode with preorder[i], increment i.
// 3. Recursively build left subtree with range (mini, root->val).
// 4. Recursively build right subtree with range (root->val, maxi).
// 5. Return root.

TreeNode *solve(vector<int> &preorder, int mini, int maxi, int &i)
{
    if (i >= preorder.size())
    {
        return NULL;
    }
    if (preorder[i] < mini || preorder[i] > maxi)
    {
        return NULL;
    }
    TreeNode *root = new TreeNode(preorder[i++]);
    root->left = solve(preorder, mini, root->val, i);
    root->right = solve(preorder, root->val, maxi, i);
    return root;
}
TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int mini = INT_MIN;
    int maxi = INT_MAX;
    int i = 0;
    return solve(preorder, mini, maxi, i);
}