#include <iostream>
using namespace std;

// MAXIMUM DEPTH OF BINARY TREE (LEETCODE 104)
// USING RECURSION - TC=O(N), SC=O(N)

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