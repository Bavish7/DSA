#include<iostream>
using namespace std;

// Kth SMALLEST ELEMENT IN A BST (LEETCODE 230)
// USING INORDER TRAVERSAL - TC=O(N), SC=O(N)
void solve(TreeNode *root, int k, int &i, int &ans)
{
    if (root == NULL)
    {
        return;
    }
    solve(root->left, k, i, ans);
    i++;
    if (i == k)
    {
        ans = root->val;
    }
    solve(root->right, k, i, ans);
}
int kthSmallest(TreeNode *root, int k)
{
    int i = 0;
    int ans = 0;
    solve(root, k, i, ans);
    return ans;
}