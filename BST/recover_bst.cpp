#include<iostream>
using namespace std;

// RECOVER BINARY SEARCH TREE (LEETCODE 99)
// USING INORDER TRAVERSAL - TC=O(N), SC=O(H)

// Steps:
// 1. Perform an in-order traversal to identify swapped nodes in a BST:
//    - Maintain pointers (`first`, `middle`, `last`) to track misplaced nodes.
//    - If `prev->val > root->val`, it indicates a breach of BST properties:
//      - If `first` is not set, assign `first = prev` and `middle = root`.
//      - If `first` is already set, assign `last = root`.
// 2. After the traversal, there are two cases:
//    - Case 1: Non-adjacent nodes are swapped (nodes `first` and `last`).
//    - Case 2: Adjacent nodes are swapped (nodes `first` and `middle`).
// 3. Swap the values of the identified nodes to fix the BST.

TreeNode *first;
TreeNode *middle;
TreeNode *last;
TreeNode *prev;
void inorder(TreeNode *root)
{
    if (root == NULL)
        return;
    inorder(root->left);
    if (prev != NULL && (root->val < prev->val))
    {
        if (first == NULL)
        {
            first = prev;
            middle = root;
        }
        else
        {
            last = root;
        }
    }
    prev = root;
    inorder(root->right);
}
void recoverTree(TreeNode *root)
{
    first = middle = last = NULL;
    prev = new TreeNode(INT_MIN);
    inorder(root);
    if (first && last)
        swap(first->val, last->val);
    else if (first && middle)
        swap(first->val, middle->val);
}