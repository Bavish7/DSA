#include<iostream>
using namespace std;

// CONVERT BST INTO SORTED LINKED LIST
// USING INORDER TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// inorderTraversal(root, ans):
// 1. If root is NULL, return.
// 2. Recursively traverse left subtree.
// 3. Add root->data to ans.
// 4. Recursively traverse right subtree.
//
// flatten(root):
// 1. Perform inorder traversal to get sorted elements.
// 2. Create new root node with first element of ans.
// 3. Iterate over ans to create linked list.
// 4. Set left of each node to NULL, right to next node.
// 5. Return new root of sorted linked list.

void inorderTraversal(TreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}
TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<int> ans;
    inorderTraversal(root, ans);
    int n = ans.size();
    TreeNode<int> *newRoot = new TreeNode<int>(ans[0]);
    TreeNode<int> *curr = newRoot;
    for (int i = 1; i < n; i++)
    {
        TreeNode<int> *temp = new TreeNode<int>(ans[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;
    return newRoot;
}