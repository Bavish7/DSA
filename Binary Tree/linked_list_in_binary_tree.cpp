#include<iostream>
using namespace std;

// LINKED LIST IN BINARY TREE (LEETCODE 1367)
// USING DFS TRAVERSAL - TC=O(N*M), SC=O(N+M)

// Steps:
// 1. Traverse all nodes of the tree (DFS).
// 2. At each node, call `checkPath()` to try matching list from that point downward.
// 3. In `checkPath()`:
//    - If list ends → match success.
//    - If tree ends or values mismatch → fail.
//    - Recurse into left and right child with head->next.
// 4. Return true if any such subtree contains the list path.

bool checkPath(TreeNode *root, ListNode *head)
{
    if (!head)
        return true;
    if (!root)
        return false;
    if (root->val != head->val)
        return false;
    return checkPath(root->left, head->next) || checkPath(root->right, head->next);
}
bool isSubPath(ListNode *head, TreeNode *root)
{
    if (!root)
        return false;
    return checkPath(root, head) || isSubPath(head, root->left) || isSubPath(head, root->right);
}