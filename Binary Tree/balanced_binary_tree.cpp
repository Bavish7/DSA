#include <iostream>
using namespace std;

// BALANCED BINARY TREE (LEETCODE 110)
// USING RECURSION OF HEIGHT AND BALANCED SEPARATELY - TC=O(N^2), SC=O(N)

// Steps:
// height(TreeNode *root):
// 1. If root is NULL, return 0.
// 2. Calculate the height of the left subtree recursively using height(root->left).
// 3. Calculate the height of the right subtree recursively using height(root->right).
// 4. Return the maximum of left height and right height + 1 (for the current node).

// isBalanced(TreeNode *root):
// 1. If root is NULL, return true (an empty tree is balanced).
// 2. Recursively check if the left subtree is balanced using isBalanced(root->left).
// 3. Recursively check if the right subtree is balanced using isBalanced(root->right).
// 4. Calculate the absolute height difference between the left and right subtrees.
// 5. If both subtrees are balanced (step 2 and 3) and the height difference is <= 1, return true.
// 6. Otherwise, return false.

int height(TreeNode *root){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);
    return max(left, right) + 1;
}
bool isBalanced(TreeNode *root){
    if(root==NULL){
        return true;
    }
    bool left = isBalanced(root->left);
    bool right = isBalanced(root->right);
    bool diff = abs(height(root->left) - height(root->right)) <= 1;
    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
}

// USING RECURSION OF HEIGHT AND BALANCED - TC=O(N), SC=O(N)

// Steps:
// height(TreeNode *root, bool &balanced):
// 1. If root is NULL or 'balanced' flag is false, return 0.
// 2. Recursively calculate the height of the left subtree using height(root->left, balanced).
// 3. Recursively calculate the height of the right subtree using height(root->right, balanced).
// 4. If the absolute difference between left and right subtree heights is greater than 1, set 'balanced' to false.
// 5. Return the maximum of left height and right height + 1.

// isBalanced(TreeNode *root):
// 1. If root is NULL, return true (an empty tree is balanced).
// 2. Initialize a boolean variable 'balanced' to true.
// 3. Call height(root, balanced) to recursively compute the height and check balance.
// 4. Return the value of 'balanced'.

int height(TreeNode *root, bool &balanced)
{
    if (root == NULL || balanced == false)
    {
        return 0;
    }
    int left = height(root->left, balanced);
    int right = height(root->right, balanced);
    if (abs(left - right) > 1)
    {
        balanced = false;
    }
    return max(left, right) + 1;
}
bool isBalanced(TreeNode *root)
{
    if (root == NULL)
    {
        return true;
    }
    bool balanced = true;
    height(root, balanced);
    return balanced;
}