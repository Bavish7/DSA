#include <iostream>
#include <vector>
using namespace std;

// RIGHT VIEW 
// USING RECURSION - TC=O(N), SC=O(N)

void solve(BinaryTreeNode<int> *root, vector<int> &ans, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (level == ans.size())
    {
        ans.push_back(root->data);
    }
    solve(root->right, ans, level + 1);
    solve(root->left, ans, level + 1);
}
vector<int> printRightView(BinaryTreeNode<int> *root)
{
    vector<int> ans;
    solve(root, ans, 0);
    return ans;
}