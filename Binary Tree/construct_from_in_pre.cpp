#include <iostream>
#include <vector>
using namespace std;

// CONSTRUCT BINARY TREE FROM PREORDER AND INORDER TRAVERSAL (LEETCODE 105)
// USING RECURSION - TC=O(N), SC=O(N)

// Steps:
// solve(inorder, postorder, index, start, end, map):
// 1. Return NULL if index < 0 or start > end.
// 2. Extract element from postorder using index, create TreeNode.
// 3. Locate element's position in inorder using map.
// 4. Recursively build right subtree (solve with updated index, range).
// 5. Recursively build left subtree (solve with updated index, range).
// 6. Return constructed root node.
//
// buildTree(inorder, postorder):
// 1. Initialize 'n' to size of inorder.
// 2. Set 'index' to n - 1 (last index of postorder).
// 3. Create map 'm' to store inorder indices for quick lookup.
// 4. Call solve(inorder, postorder, index, 0, n - 1, m) to build tree.
// 5. Return root of constructed binary tree.

TreeNode *solve(vector<int> &preorder, vector<int> &inorder, int &index, int n, int start, int end, map<int, int> &m)
{
    if (index >= n || start > end)
    {
        return NULL;
    }
    int element = preorder[index++];
    TreeNode *root = new TreeNode(element);
    int position = m[element];
    root->left = solve(preorder, inorder, index, n, start, position - 1, m);
    root->right = solve(preorder, inorder, index, n, position + 1, end, m);
    return root;
}
TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder)
{
    int index = 0;
    int n = inorder.size();
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[inorder[i]] = i;
    }
    TreeNode *root = solve(preorder, inorder, index, n, 0, n - 1, m);
    return root;
}