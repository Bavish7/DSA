#include<iostream>
using namespace std;

// LONGEST ZIGZAG PATH IN A BINARY TREE (LEETCODE 1372)
// USING PREORDER TRAVERSAL - TC=O(N), SC=O(H)

// Steps:
// 1. Start DFS from root with initial direction as left (`goLeft = true`) and 0 steps.
// 2. At each node, if going left, move to left child with steps+1 and switch direction.
//    Simultaneously, start a new path from right child with steps=1 and opposite direction.
// 3. Similarly, if going right, move to right child and switch direction, and start a new path from left.
// 4. Track the maximum steps (zigzag length) during traversal.
// 5. Final result is the longest zigzag path found.

int maxPath = 0;
void solve(TreeNode *root, int steps, bool goLeft)
{
    if (!root)
        return;
    maxPath = max(maxPath, steps);
    if (goLeft)
    {
        solve(root->left, steps + 1, false);
        solve(root->right, 1, true);
    }
    else
    {
        solve(root->right, steps + 1, true);
        solve(root->left, 1, false);
    }
}
int longestZigZag(TreeNode *root)
{
    solve(root, 0, true);
    return maxPath;
}

// USING PREORDER TRAVERSAL WITH TWO PARAMETERS - TC=O(N), SC=O(H)
// Steps:
// 1. Use two parameters: `left` (length of zigzag path if last move was left) and `right` (if last move was right).
// 2. At each node, update `maxPath` with the max of current `left` and `right` values.
// 3. Recur for left child by increasing `right` (because next move would be right) and resetting `left` to 0.
// 4. Recur for right child by increasing `left` (next move is left) and resetting `right` to 0.
// 5. Continue this traversal for all nodes and track the maximum zigzag path encountered.

int maxPath = 0;
void solve(TreeNode *root, int left, int right)
{
    if (!root)
        return;
    maxPath = max({maxPath, left, right});
    solve(root->left, right + 1, 0);
    solve(root->right, 0, left + 1);
}
int longestZigZag(TreeNode *root)
{
    solve(root, 0, 0);
    return maxPath;
}