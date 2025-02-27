#include<iostream>
using namespace std;

// BALANCE A BST (LEETCODE 1382)
// USING INORDER TRAVERSAL AND CONVERTING INTO BST - TC=O(N), SC=O(N)

// Steps:
// inorderTraversal(root, ans):
// 1. Return if root is NULL.
// 2. Traverse left subtree.
// 3. Add root value to ans.
// 4. Traverse right subtree.
//
// convertToBST(ans, start, end):
// 1. Return NULL if start > end.
// 2. Calculate mid index, create new TreeNode with ans[mid].
// 3. Recursively build left and right subtrees using mid index.
// 4. Return new TreeNode as root of subtree.
//
// balanceBST(root):
// 1. Perform inorder traversal to get sorted values in ans.
// 2. Use convertToBST to create balanced BST from ans.
// 3. Return new root.

void inorderTraversal(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left, ans);
    ans.push_back(root->val);
    inorderTraversal(root->right, ans);
}
TreeNode *convertToBST(vector<int> &ans, int start, int end)
{
    if (start > end)
    {
        return NULL;
    }
    int mid = (start + end) / 2;
    int element = ans[mid];
    TreeNode *newRoot = new TreeNode(element);
    newRoot->left = convertToBST(ans, start, mid - 1);
    newRoot->right = convertToBST(ans, mid + 1, end);
    return newRoot;
}
TreeNode *balanceBST(TreeNode *root)
{
    vector<int> ans;
    inorderTraversal(root, ans);
    int start = 0, end = ans.size() - 1;
    TreeNode *newRoot = convertToBST(ans, start, end);
    return newRoot;
}