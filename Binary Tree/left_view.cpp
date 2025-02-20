#include <iostream>
#include <vector>
using namespace std;

// LEFT VIEW OF A BINARY TREE
// USING PREORDER TRAVERSAL - TC=O(N), SC=O(N)
void solve(TreeNode<int> *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->left, ans, level + 1);
    solve(root->right, ans, level + 1);
}
vector<int> getLeftView(TreeNode<int> *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}