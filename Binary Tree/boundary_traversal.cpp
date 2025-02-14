#include <iostream>
#include<vector>
using namespace std;

// BOUNDARY TRAVERSAL OF BINARY TREE
// USING RECURSION - TC=O(N), SC=O(N)

// Steps:
// traverseLeft(TreeNode<int> *root, vector<int> &ans):
// 1. If root is NULL or a leaf, return.
// 2. Push root's data into 'ans'.
// 3. Recursively call traverseLeft on left child if exists, else on right child.
//
// traverseLeaf(TreeNode<int> *root, vector<int> &ans):
// 1. If root is NULL, return.
// 2. If root is leaf, push its data into 'ans' and return.
// 3. Recursively call traverseLeaf on left and right children.
//
// traverseRight(TreeNode<int> *root, vector<int> &ans):
// 1. If root is NULL or a leaf, return.
// 2. Recursively call traverseRight on right child if exists, else on left child.
// 3. Push root's data into 'ans' after recursive calls.
//
// traverseBoundary(TreeNode<int> *root):
// 1. Initialize empty vector 'ans'.
// 2. If root is NULL, return 'ans'.
// 3. Push root's data into 'ans'.
// 4. Call traverseLeft, traverseLeaf, traverseRight in sequence.
// 5. Return 'ans' containing nodes in boundary traversal order.

void traverseLeft(TreeNode<int> *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    ans.push_back(root->data);
    if (root->left)
    {
        traverseLeft(root->left, ans);
    }
    else
    {
        traverseLeft(root->right, ans);
    }
}
void traverseLeaf(TreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    if (root->left == NULL && root->right == NULL)
    {
        ans.push_back(root->data);
        return;
    }
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
}
void traverseRight(TreeNode<int> *root, vector<int> &ans)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
    {
        return;
    }
    if (root->right)
    {
        traverseRight(root->right, ans);
    }
    else
    {
        traverseRight(root->left, ans);
    }
    ans.push_back(root->data);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
    vector<int> ans;
    if (root == NULL)
    {
        return ans;
    }
    ans.push_back(root->data);
    traverseLeft(root->left, ans);
    traverseLeaf(root->left, ans);
    traverseLeaf(root->right, ans);
    traverseRight(root->right, ans);
    return ans;
}