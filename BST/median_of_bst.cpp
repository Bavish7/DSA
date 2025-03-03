#include<iostream>
using namespace std;

// MEDIAN OF A BST IN O(1) SPACE
// USING MORRIS TRAVERSAL - TC=O(N), SC=O(1)

// Steps:
// 1. Define a `size` function to count the number of nodes in the BST using Morris traversal.
//     - Initialize `count` and `current` to root.
//     - If the left subtree is NULL, increment count and move to the right subtree.
//     - If there is a left subtree, find the rightmost node of the left subtree.
//     - Create a temporary link to traverse back to `current` after visiting the left subtree.
//     - When revisiting, increment count and move to the right subtree, removing the temporary link.
//     - This ensures O(1) space and avoids recursion.
// 2. In `medianBST`:
//     - Count total nodes using `size`.
//     - Traverse again with Morris traversal.
//     - For odd number of nodes, the median is the middle node `(nodes + 1)/2`.
//     - For even nodes, the median is the average of the two middle nodes `(nodes/2)` and `(nodes/2 + 1)`.
//     - Return the median value when the middle nodes are reached.

int size(TreeNode<int> *root)
{
    int count = 0;
    TreeNode<int> *current = root;
    TreeNode<int> *prev;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            count++;
            current = current->right;
        }
        else
        {
            prev = current->left;
            while (prev->right && prev->right != current)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = current;
                current = current->left;
            }
            else
            {
                prev->right = NULL;
                count++;
                current = current->right;
            }
        }
    }
    return count;
}
int medianBST(TreeNode<int> *root)
{
    TreeNode<int> *temp = root;
    int nodes = size(temp);
    TreeNode<int> *current = root;
    TreeNode<int> *prev;
    TreeNode<int> *previous;
    int count = 0;
    while (current != NULL)
    {
        if (current->left == NULL)
        {
            count++;
            if (nodes % 2 != 0 && count == (nodes + 1) / 2)
            {
                return current->data;
            }
            if (nodes % 2 == 0 && count == (nodes / 2 + 1))
            {
                return (previous->data + current->data) / 2;
            }
            previous = current;
            current = current->right;
        }
        else
        {
            prev = current->left;
            while (prev->right != NULL && prev->right != current)
            {
                prev = prev->right;
            }
            if (prev->right == NULL)
            {
                prev->right = current;
                current = current->left;
            }
            else
            {
                prev->right = NULL;
                previous = prev;
                count++;
                if (nodes % 2 != 0 && count == (nodes + 1) / 2)
                {
                    return current->data;
                }
                if (nodes % 2 == 0 && count == (nodes / 2 + 1))
                {
                    return (previous->data + current->data) / 2;
                }
                previous = current;
                current = current->right;
            }
        }
    }
}