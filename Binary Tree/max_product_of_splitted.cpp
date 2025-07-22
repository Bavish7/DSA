#include<iostream>
using namespace std;

// MAXIMUM PRODUCT OF SPLITTED BINARY TREE (LEETCODE 1339)
// USING POSTORDER TRAVERSAL - TC=O(N), SC=O(H)

// Steps:
// 1. Calculate the total sum of all node values in the binary tree.
// 2. Perform a postorder traversal to calculate the sum of each subtree.
//    - For each node, calculate the sum of its left and right subtrees.
// 3. For each subtree sum, calculate the product of the subtree sum and the remaining tree sum (total sum - subtree sum).
// 4. Keep track of the maximum product found during the traversal.

long M = 1e9 + 7;
long totalSum = 0, maxP = 0;
int findTotalSum(TreeNode *root)
{
    if (!root)
        return 0;
    int leftSubtreeSum = findTotalSum(root->left);
    int rightSubtreeSum = findTotalSum(root->right);
    int sum = root->val + leftSubtreeSum + rightSubtreeSum;
    maxP = max(maxP, (totalSum - sum) * sum);
    return sum;
}
int maxProduct(TreeNode *root)
{
    if (!root)
        return 0;
    maxP = 0;
    totalSum = findTotalSum(root);
    findTotalSum(root);
    return maxP % M;
}