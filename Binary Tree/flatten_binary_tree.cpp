#include <iostream>
using namespace std;

// FLATTEN BINARY TREE TO LINKED LIST (LEETCODE 114)
// USING MORRIS TRAVERSAL - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize curr to root.
// 2. While curr is not NULL:
//    a. If curr has a left child:
//       i. Find the rightmost node in the left subtree (pred).
//       ii. Attach curr's right subtree to pred's right.
//       iii. Move curr's left subtree to curr's right and set left to NULL.
//    b. Move curr to its right child

void flatten(TreeNode *root)
{
    TreeNode *curr = root;
    while (curr)
    {
        if (curr->left)
        {
            TreeNode *pred = curr->left;
            while (pred->right)
            {
                pred = pred->right;
            }
            pred->right = curr->right;
            curr->right = curr->left;
            curr->left = NULL;
        }
        curr = curr->right;
    }
}