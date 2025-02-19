#include <iostream>
using namespace std;

// DIAMETER OF BINARY TREE (LEETCODE 543)
// USING RECURSION OF HEIGHT AND DIAMETER SEPARATELY - TC=O(N^2), SC=O(N)

// Steps:
// maxDepth(root):
// 1. Return 0 if root is NULL.
// 2. Recursively calculate depth of left and right subtrees.
// 3. Return maximum depth + 1.
//
// diameterOfBinaryTree(root):
// 1. Return 0 if root is NULL.
// 2. Recursively find diameters of left and right subtrees.
// 3. Calculate combined diameter through left and right subtree depths.
// 4. Return maximum of left diameter, right diameter, or combined diameter.

int maxDepth(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = maxDepth(root->left);
    int right = maxDepth(root->right);
    int ans = max(left, right) + 1;
    return ans;
}
int diameterOfBinaryTree(TreeNode *root)
{
    if(root==NULL){
        return 0;
    }
    int left = diameterOfBinaryTree(root->left);
    int right = diameterOfBinaryTree(root->right);
    int combo = maxDepth(root->left) + maxDepth(root->right);
    int diameter = max(left, max(right, combo));
    return diameter;
}

// USING RECURSION OF HEIGHT AND DIAMETER - TC=O(N), SC=O(N)
// Steps:
// height(root, diameter):
// 1. Return 0 if root is NULL.
// 2. Recursively calculate height of left and right subtrees.
// 3. Update diameter if current subtree's diameter (left + right) is greater.
// 4. Return maximum height of left or right subtree + 1.
//
// diameterOfBinaryTree(root):
// 1. Return 0 if root is NULL.
// 2. Initialize diameter to 0.
// 3. Call height(root, diameter) to compute the tree's diameter.
// 4. Return the computed diameter.

int height(TreeNode *root, int &diameter)
{
    if (root == NULL)
    {
        return 0;
    }
    int left = height(root->left, diameter);
    int right = height(root->right, diameter);
    int maxHeight = max(left, right) + 1;
    diameter = max(diameter, (left + right));
    return maxHeight;
}
int diameterOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
    {
        return 0;
    }
    int diameter = 0;
    height(root, diameter);
    return diameter;
}