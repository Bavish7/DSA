#include<iostream>
using namespace std;

// LOWEST COMMON ANCESTOR OF A BINARY TREE (LEETCODE 236)
// USING RECURSION TC=O(N), SC=O(N)

// Steps:
// 1. If root is NULL, return NULL.
// 2. If root matches either p or q, return root (as it's a potential LCA).
// 3. Recursively search left and right subtrees for p and q.
// 4. If both left and right subtrees return non-NULL values, then root is the LCA.
// 5. If only one subtree returns a non-NULL value, return that as potential LCA.
// 6. If both subtrees return NULL, return NULL.

TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->val == p->val || root->val == q->val)
    {
        return root;
    }
    TreeNode *leftAns = lowestCommonAncestor(root->left, p, q);
    TreeNode *rightAns = lowestCommonAncestor(root->right, p, q);
    if (leftAns != NULL && rightAns != NULL)
    {
        return root;
    }
    else if (leftAns != NULL && rightAns == NULL)
    {
        return leftAns;
    }
    else if (rightAns != NULL && leftAns == NULL)
    {
        return rightAns;
    }
    else
    {
        return NULL;
    }
}

// KTH ANCESTOR OF A NODE IN BINARY TREE
// USING RECURSION - TC=O(N), SC=O(H)

// Steps:
// 1. If root is NULL, return NULL.
// 2. If root's data matches targetNodeVal, return root.
// 3. Recursively search left and right subtrees for targetNodeVal.
// 4. If found in left subtree but not right, decrement k.
//    - If k becomes <= 0, return root (current node is the kth ancestor).
// 5. If found in right subtree but not left, decrement k.
//    - If k becomes <= 0, return root (current node is the kth ancestor).
// 6. Return NULL if neither subtree finds targetNodeVal.

BinaryTreeNode<int> *solve(BinaryTreeNode<int> *root, int targetNodeVal, int &k)
{
    if (root == NULL)
    {
        return NULL;
    }
    if (root->data == targetNodeVal)
    {
        return root;
    }
    BinaryTreeNode<int> *leftAns = solve(root->left, targetNodeVal, k);
    BinaryTreeNode<int> *rightAns = solve(root->right, targetNodeVal, k);
    if (leftAns != NULL && rightAns == NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }
    if (leftAns == NULL && rightAns != NULL)
    {
        k--;
        if (k <= 0)
        {
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }
    return NULL;
}
int findKthAncestor(BinaryTreeNode<int> *root, int targetNodeVal, int k)
{
    if (root == NULL)
    {
        return -1;
    }
    BinaryTreeNode<int> *ans = solve(root, targetNodeVal, k);
    if (ans == NULL || ans->data == targetNodeVal)
    {
        return -1;
    }
    else
    {
        return ans->data;
    }
}