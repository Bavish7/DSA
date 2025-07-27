#include<iostream>
using namespace std;

// DISTRIBUTE COINS IN BINARY TREE (LEETCODE 979)
// USING POSTORDER TRAVERSAL - TC=O(N), SC=O(H)

// Steps:
// 1. Traverse left and right subtrees recursively (postorder).
// 2. For each node, compute net coins = left + right + root->val - 1:
//    - `-1` because each node needs exactly 1 coin.
//    - Surplus (positive) or deficit (negative) is returned upward.
// 3. Track `moves` by adding absolute value of coins moved in/out from left and right.
//    - `abs(left)` is the number of moves from left child.
//    - `abs(right)` is the number of moves from right child.
// 4. Total moves needed is accumulated in `moves`.
// 5. Return final `moves` after full traversal.

int moves = 0;
int solve(TreeNode *root)
{
    if (!root)
        return 0;
    int left = solve(root->left);
    int right = solve(root->right);
    moves += abs(left) + abs(right);
    return left + right + root->val - 1;
}
int distributeCoins(TreeNode *root)
{
    solve(root);
    return moves;
}