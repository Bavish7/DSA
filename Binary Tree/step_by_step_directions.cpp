#include<iostream>
using namespace std;

// STEP-BY-STEP DIRECTIONS FROM A BINARY TREE NODE TO ANOTHER (LEETCODE 2096)
// USING LCA AND DFS TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// 1. Find the Lowest Common Ancestor (LCA) of start and destination nodes.
// 2. From LCA, find path to `startValue` and store directions in `lcaToStart`.
// 3. From LCA, find path to `destValue` and store directions in `lcaToDest`.
// 4. For each step in `lcaToStart`, add 'U' to result (going up from start to LCA).
// 5. Append `lcaToDest` to result to get full path from startValue to destValue.

TreeNode *lowestCommonAncestor(TreeNode *root, int startVal, int destVal)
{
    if (!root)
        return NULL;
    if (root->val == startVal || root->val == destVal)
    {
        return root;
    }
    TreeNode *left = lowestCommonAncestor(root->left, startVal, destVal);
    TreeNode *right = lowestCommonAncestor(root->right, startVal, destVal);
    if (left != NULL && right != NULL)
        return root;
    else if (left != NULL && right == NULL)
        return left;
    else if (left == NULL && right != NULL)
        return right;
    else
        return NULL;
}
bool findPath(TreeNode *lca, int node, string &lcaToNode)
{
    if (!lca)
        return false;
    if (lca->val == node)
        return true;
    lcaToNode += "L";
    if (findPath(lca->left, node, lcaToNode))
        return true;
    lcaToNode.pop_back();
    lcaToNode += "R";
    if (findPath(lca->right, node, lcaToNode))
        return true;
    lcaToNode.pop_back();
    return false;
}
string getDirections(TreeNode *root, int startValue, int destValue)
{
    TreeNode *lca = lowestCommonAncestor(root, startValue, destValue);
    string lcaToStart = "", lcaToDest = "";
    findPath(lca, startValue, lcaToStart);
    findPath(lca, destValue, lcaToDest);
    cout << lcaToStart << " ";
    string ans = string(lcaToStart.size(), 'U') + lcaToDest;
    return ans;
}

// USING DFS TRAVERSAL - TC=O(N), SC=O(N)
// Steps:
// 1. Find path from root to `startValue` → store in `rootToStart`.
// 2. Find path from root to `destValue` → store in `rootToDest`.
// 3. Find first mismatch index `i` in both paths (divergence point).
// 4. Replace remaining path from start node with 'U's (to move up to LCA).
// 5. Append remaining path from LCA to destination node using `rootToDest.substr(i)`.

bool findPath(TreeNode *root, int node, string &rootToNode)
{
    if (!root)
        return false;
    if (root->val == node)
        return true;
    rootToNode += "L";
    if (findPath(root->left, node, rootToNode))
        return true;
    rootToNode.pop_back();
    rootToNode += "R";
    if (findPath(root->right, node, rootToNode))
        return true;
    rootToNode.pop_back();
    return false;
}
string getDirections(TreeNode *root, int startValue, int destValue)
{
    string rootToStart = "", rootToDest = "";
    findPath(root, startValue, rootToStart);
    findPath(root, destValue, rootToDest);
    int i = 0;
    while (i < rootToStart.size() && i < rootToDest.size() && rootToStart[i] == rootToDest[i])
    {
        i++;
    }
    string ans = string(rootToStart.size() - i, 'U') + string(rootToDest.substr(i));
    return ans;
}