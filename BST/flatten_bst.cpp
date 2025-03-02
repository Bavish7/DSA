#include<iostream>
using namespace std;

// FLATTEN BST TO A SORTED LIST
// USING INORDER TRAVERSAL AND CREATING LIST SEPARATELY - TC=O(N), SC=O(N)

// Steps:
// 1. Perform an in-order traversal of the given binary tree.
//    - Store the values of the nodes in a vector `ans` in sorted order.
// 2. Create a new root node for the flattened tree with the first element of the vector.
// 3. Traverse the remaining elements in the vector:
//    - For each element, create a new node.
//    - Set the current node's right pointer to the new node and its left pointer to NULL.
//    - Move to the new node and repeat the process.
// 4. Ensure the last node has both left and right pointers set to NULL, as it's the end of the flattened tree.

void inorderTraversal(TreeNode<int> *root, vector<int> &ans)
{
    if (root == NULL)
    {
        return;
    }
    inorderTraversal(root->left, ans);
    ans.push_back(root->data);
    inorderTraversal(root->right, ans);
}
TreeNode<int> *flatten(TreeNode<int> *root)
{
    vector<int> ans;
    inorderTraversal(root, ans);
    int n = ans.size();
    TreeNode<int> *newRoot = new TreeNode<int>(ans[0]);
    TreeNode<int> *curr = newRoot;
    for (int i = 1; i < n; i++)
    {
        TreeNode<int> *temp = new TreeNode<int>(ans[i]);
        curr->left = NULL;
        curr->right = temp;
        curr = temp;
    }
    curr->left = NULL;
    curr->right = NULL;
    return newRoot;
}

// USING INORDER TRAVERSAL - TC=O(N), SC=O(H)

// Steps:
// 1. Create a dummy node to act as the starting point for the flattened tree.
// 2. Perform an in-order traversal of the tree:
//    - For each node, set the `prev` node's left pointer to NULL and right pointer to the current node.
//    - Move `prev` to the current node.
// 3. After the traversal, ensure the last node's left and right pointers are set to NULL.
// 4. Return the right child of the dummy node, which points to the new flattened tree.

void inorderTraversal(TreeNode<int> *root, TreeNode<int> *&prev)
{
    if (!root)
        return;
    inorderTraversal(root->left, prev);
    prev->left = NULL;
    prev->right = root;
    prev = root;
    inorderTraversal(root->right, prev);
}
TreeNode<int> *flatten(TreeNode<int> *root)
{
    TreeNode<int> *dummy = new TreeNode<int>(-1);
    TreeNode<int> *prev = dummy;
    inorderTraversal(root, prev);
    prev->left = prev->right = NULL;
    return dummy->right;
}