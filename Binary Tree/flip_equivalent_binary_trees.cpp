#include<iostream>
using namespace std;

// FLIP EQUIVALENT BINARY TREES (LEETCODE 951)
// USING RECURSION - TC=O(N), SC=O(H)

// Steps:
// 1. If both nodes are null → return true (base case).
// 2. If only one is null or values don't match → return false.
// 3. Recursively check for two cases:
//    a. Without flipping → left matches left and right matches right.
//    b. With flipping → left matches right and right matches left.
// 4. Return true if either case returns true.

bool flipEquiv(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return true;
    if (!root1 || !root2)
        return false;
    if (root1->val != root2->val)
    {
        return false;
    }
    bool withoutFlip = flipEquiv(root1->left, root2->left) && flipEquiv(root1->right, root2->right);
    bool withFlip = flipEquiv(root1->left, root2->right) && flipEquiv(root1->right, root2->left);
    return withoutFlip || withFlip;
}