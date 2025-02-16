#include<iostream>
using namespace std;

// CHILD SUM PROPERTY
// USING POST ORDER TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// 1. Traverse the tree recursively. For each node:
//    - Calculate the sum of its children's values (`child`).
//    - If `child >= root->data`, update the root's value to `child`.
//    - Otherwise, update the children's values to match the root's value.
// 2. Recursively apply the above logic to the left and right subtrees.
// 3. After processing both subtrees, update the root's value to the sum of its children's values, ensuring the tree's "children sum property."

void changeTree(BinaryTreeNode<int> *root)
{
    if (root == NULL)
        return;
    int child = 0;
    if (root->left)
        child += root->left->data;
    if (root->right)
        child += root->right->data;
    if (child >= root->data)
        root->data = child;
    else
    {
        if (root->left)
            root->left->data = root->data;
        if (root->right)
            root->right->data = root->data;
    }
    changeTree(root->left);
    changeTree(root->right);
    int total = 0;
    if (root->left)
        total += root->left->data;
    if (root->right)
        total += root->right->data;
    if (root->left || root->right)
        root->data = total;
}