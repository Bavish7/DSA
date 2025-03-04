#include<iostream>
using namespace std;

// RANGE SUM OF BST (LEETCODE 938)
// USING RECURSION - TC=O(N), SC=O(N)

// Steps:
// 1. Define a recursive function `solve` to traverse the tree.
// 2. If the current node is NULL, return.
// 3. If the node's value is within the range [low, high], add its value to `sum` and recurse both left and right subtrees.
// 4. If the node's value is less than `low`, recurse only the right subtree (as left subtree values are smaller).
// 5. If the node's value is greater than `high`, recurse only the left subtree (as right subtree values are larger).
// 6. Initialize sum to 0, call `solve`, and return the computed sum.

void solve(TreeNode *root, int low, int high, int &sum)
{
    if (!root)
        return;
    if (root->val >= low && root->val <= high)
    {
        sum += root->val;
        solve(root->left, low, high, sum);
        solve(root->right, low, high, sum);
    }
    else if (root->val < low)
    {
        solve(root->right, low, high, sum);
    }
    else if (root->val > high)
    {
        solve(root->left, low, high, sum);
    }
}
int rangeSumBST(TreeNode *root, int low, int high)
{
    int sum = 0;
    solve(root, low, high, sum);
    return sum;
}