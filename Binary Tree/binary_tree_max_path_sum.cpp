#include<iostream>
using namespace std;

// BINARY TREE MAXIMUM PATH SUM (LEETCODE 124)
// USING POST ORDER TRAVERSAL AND RECURSION - TC=O(N), SC=O(N)

// Steps:
// 1. Define a helper function `solve` to recursively compute max path sums.
// 2. For each node, calculate the maximum path sum from its left and right child, considering only non-negative sums.
// 3. Update the global maximum (`maxi`) with the current node's value plus left and right child sums.
// 4. Return the maximum sum path including the current node and one of its children (left or right).
// 5. Call `solve` from `maxPathSum` to compute the result, starting with `maxi` initialized to INT_MIN.

int solve(TreeNode *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int leftSum = max(0, solve(root->left, maxi));
    int rightSum = max(0, solve(root->right, maxi));
    maxi = max(maxi, root->val + leftSum + rightSum);
    return root->val + max(leftSum, rightSum);
}
int maxPathSum(TreeNode *root)
{
    int maxi = INT_MIN;
    solve(root, maxi);
    return maxi;
}