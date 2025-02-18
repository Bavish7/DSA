#include <iostream>
#include <vector>
using namespace std;

// CONSTRUCT BINARY TREE FROM INORDER AND POSTORDER TRAVERSAL (LEETCODE 106)
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
TreeNode *solve(vector<int> &inorder, vector<int> &postorder, int &index, int n, int start, int end, map<int, int> &m)
{
    if (index < 0 || start > end)
    {
        return NULL;
    }
    int element = postorder[index--];
    TreeNode *root = new TreeNode(element);
    int pos = m[element];
    root->right = solve(inorder, postorder, index, n, pos + 1, end, m);
    root->left = solve(inorder, postorder, index, n, start, pos - 1, m);
    return root;
}
TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder)
{
    int n = inorder.size();
    int index = n - 1;
    map<int, int> m;
    for (int i = 0; i < n; i++)
    {
        m[inorder[i]] = i;
    }
    TreeNode *root = solve(inorder, postorder, index, n, 0, n - 1, m);
    return root;
}