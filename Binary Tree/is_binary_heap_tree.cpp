#include<iostream>
using namespace std;

// IS BINARY HEAP TREE 
// USING PREORDER TRAVRSAL - TC=O(N), SC=O(H)

// Steps:
// 1. Calculate the total number of nodes in the tree using a recursive function.
// 2. Check if the binary tree is a complete binary tree (CBT) by validating if all nodes follow the structure of a CBT:
//    - Each node should be indexed correctly according to CBT rules (left child is at 2*i and right child is at 2*i+1).
// 3. Check if the binary tree follows the max-heap property:
//    - Each node should have a value greater than or equal to its children.
// 4. A tree is a valid binary heap if it is both a complete binary tree and satisfies the max-heap property.

int nodeCount(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return 0;
    int leftCount = nodeCount(root->left);
    int rightCount = nodeCount(root->right);
    return 1 + leftCount + rightCount;
}
bool isCBT(BinaryTreeNode<int> *root, int i, int &n)
{
    if (root == NULL)
        return true;
    if (i > n)
        return false;
    return isCBT(root->left, 2 * i, n) && isCBT(root->right, 2 * i + 1, n);
}
bool isMaxHeap(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return true;
    bool left = isMaxHeap(root->left);
    bool right = isMaxHeap(root->right);
    bool ans = false;
    if (root->left == NULL && root->right == NULL)
    {
        ans = true;
    }
    else if (root->left->data <= root->data && root->right == NULL)
    {
        ans = true;
    }
    else if (root->left->data <= root->data && root->right->data <= root->data)
    {
        ans = true;
    }
    return ans && left && right;
}
bool isBinaryHeapTree(BinaryTreeNode<int> *root)
{
    int n = nodeCount(root);
    int i = 1;
    return isCBT(root, i, n) && isMaxHeap(root);
}