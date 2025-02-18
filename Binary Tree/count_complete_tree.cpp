#include<iostream>
using namespace std;

// COUNT COMPLETE TREE NODES (LEETCODE 222)
// USING HEIGHT OF LEFT AND RIGHT SUBTREES - TC=O(LOGN*LOGN), SC=O(LOGN)

// Steps:
// 1. Define helper functions to calculate the height of the leftmost and rightmost paths in the tree:
//    - `findLeftHeight`: Traverse the leftmost path and count nodes.
//    - `findRightHeight`: Traverse the rightmost path and count nodes.
// 2. In `countNodes` function:
//    - If the tree is empty, return 0.
//    - Calculate the left height (`lh`) and right height (`rh`).
//    - If `lh == rh`, the tree is a perfect binary tree, and its total node count is `(2^lh) - 1`.
//    - If not, recursively calculate the total nodes in the left and right subtrees, adding 1 for the root node.
// 3. Return the total node count.

int findLeftHeight(TreeNode *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->left;
    }
    return height;
}
int findRightHeight(TreeNode *root)
{
    int height = 0;
    while (root)
    {
        height++;
        root = root->right;
    }
    return height;
}
int countNodes(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int lh = findLeftHeight(root);
    int rh = findRightHeight(root);
    if (lh == rh)
        return (1 << lh) - 1;
    return 1 + countNodes(root->left) + countNodes(root->right);
}