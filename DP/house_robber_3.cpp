#include<iostream>
using namespace std;

// HOUSE ROBBER III (LEETCODE 337)
// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N), SC=O(N)

// Steps:
// 1. Base case: If the root is null, return 0, as there’s no money to rob from an empty node.
// 2. Check if the current root's value is already in `dp`. If so, return it to avoid redundant calculations.
// 3. Calculate `include` sum if we include the current node:
//    - Add the root's value.
//    - Recursively add values from the grandchildren of the current root (if they exist).
// 4. Calculate `exclude` sum if we exclude the current node:
//    - Recursively add values from the left and right children of the current root.
// 5. Choose the maximum between `include` and `exclude` sums and store it in `dp` for the current root.
// 6. Return `dp[root]`, which holds the maximum amount that can be robbed starting from the current node.

int solveUsingMem(TreeNode *root, unordered_map<TreeNode *, int> &dp)
{
    if (!root)
        return 0;
    if (dp.find(root) != dp.end())
    {
        return dp[root];
    }
    int include = 0, exclude = 0;
    include += root->val;
    if (root->left)
    {
        include += solveUsingMem(root->left->left, dp) + solveUsingMem(root->left->right, dp);
    }
    if (root->right)
    {
        include += solveUsingMem(root->right->left, dp) + solveUsingMem(root->right->right, dp);
    }
    exclude += solveUsingMem(root->left, dp) + solveUsingMem(root->right, dp);
    dp[root] = max(include, exclude);
    return dp[root];
}
int rob(TreeNode *root)
{
    unordered_map<TreeNode *, int> dp;
    return solveUsingMem(root, dp);
}