#include<iostream>
using namespace std;

// SIZE OF LARGEST BST IN A BINARY TREE
// BOTTOM-UP TRAVERSAL OF BST - TC=O(N), SC=O(N)

// Steps:
// 1. If root is NULL, return {true, INT_MIN, INT_MAX, 0}.
// 2. Recursively get information from left and right subtrees.
// 3. Update current subtree's info:
//    - size = left.size + right.size + 1
//    - max = max(left.max, right.max, root->val)
//    - min = min(left.min, right.min, root->val)
//    - isValid = (root->val > left.max && root->val < right.min && left.isValid && right.isValid)
// 4. If current subtree forms a valid BST, update maxBST with max(maxBST, current size).
// 5. Return current subtree's info.

class info
{
public:
    bool isValid;
    int max, min, size;
};

info helper(TreeNode *root, int &maxBST)
{
    if (!root)
        return {true, INT_MIN, INT_MAX, 0};
    info left = helper(root->left, maxBST);
    info right = helper(root->right, maxBST);
    info currInfo;
    currInfo.size = left.size + right.size + 1;
    currInfo.max = max(max(left.max, right.max), root->data);
    currInfo.min = min(min(left.min, right.min), root->data);
    currInfo.isValid = (root->data > left.max && root->data < right.min && left.isValid && right.isValid);
    if (currInfo.isValid)
        maxBST = max(maxBST, currInfo.size);
    return currInfo;
}

int largestBST(TreeNode *root)
{
    if (!root)
        return 0;
    if (!root->left && !root->right)
        return 1;
    int ans = -1;
    helper(root, ans);
    return ans;
}