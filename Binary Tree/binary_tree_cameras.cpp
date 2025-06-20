#include<iostream>
using namespace std;

// BINARY TREE CAMERAS (LEETCODE 968)
// USING DFS TRAVERSAL - TC=O(N), SC=O(H)

// Steps:
// 1. Use DFS to traverse the binary tree in post-order.
// 2. Each node returns a state:
//     - 0: Node is not covered by any camera.
//     - 1: Node is covered by a camera (but does not have one itself).
//     - 2: Node has a camera installed.
// 3. If any child returns 0 (not covered), install a camera at the current node (`count++`, return 2).
// 4. If any child has a camera (returns 2), this node is covered (return 1).
// 5. If both children are covered (return 1), but don't have cameras, this node is not covered (return 0).
// 6. After full DFS, if the root is not covered (returns 0), install a camera at the root.

int count = 0;
int dfs(TreeNode *root)
{
    if (!root)
        return 1;
    int left = dfs(root->left);
    int right = dfs(root->right);
    if (left == 0 || right == 0)
    {
        count++;
        return 2;
    }
    if (left == 2 || right == 2)
        return 1;
    return 0;
}
int minCameraCover(TreeNode *root)
{
    if (dfs(root) == 0)
        count++;
    return count;
}