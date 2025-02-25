#include<iostream>
using namespace std;

// CONSTRUCT BINARY TREE FROM PREORDER AND POSTORDER TRAVERSAL (LEETCODE 889)
// USING RECURSION - TC=O(N^2), SC=O(N)

// Steps:
// 1. Recursively reconstruct the binary tree from given preorder and postorder traversals.
// 2. Create a `TreeNode` with the current `preorder` value.
// 3. If only one node remains, return it as the leaf node.
// 4. Identify the left subtree's root in `postorder` by locating the next `preorder` value.
// 5. Calculate the number of nodes in the left subtree.
// 6. Recursively construct the left and right subtrees using adjusted indices.
// 7. Return the reconstructed tree.

TreeNode *solve(int preStart, int postStart, int preEnd, vector<int> &preorder, vector<int> &postorder)
{
    if (preStart > preEnd)
        return NULL;
    TreeNode *node = new TreeNode(preorder[preStart]);
    if (preStart == preEnd)
        return node;
    int nextNode = preorder[preStart + 1];
    int j = postStart;
    while (postorder[j] != nextNode)
    {
        j++;
    }
    int num = j - postStart + 1;
    node->left = solve(preStart + 1, postStart, preStart + num, preorder, postorder);
    node->right = solve(preStart + num + 1, j + 1, preEnd, preorder, postorder);
    return node;
}
TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    TreeNode *root = solve(0, 0, preorder.size() - 1, preorder, postorder);
    return root;
}

// USING RECURSION AND HASHMAP - TC=O(N), SC=O(N)
// Steps:
// 1. Use a hash map to store the indices of postorder elements for quick lookup.
// 2. Recursively reconstruct the binary tree from preorder and postorder traversals.
// 3. Create a `TreeNode` with the current `preorder` value.
// 4. If only one node remains, return it as the leaf node.
// 5. Identify the left subtree's root in `postorder` using the hash map.
// 6. Calculate the number of nodes in the left subtree.
// 7. Recursively construct the left and right subtrees using adjusted indices.
// 8. Return the reconstructed tree.

unordered_map<int, int> mp;
TreeNode *solve(int preStart, int postStart, int preEnd, vector<int> &preorder, vector<int> &postorder)
{
    if (preStart > preEnd)
        return NULL;
    TreeNode *node = new TreeNode(preorder[preStart]);
    if (preStart == preEnd)
        return node;
    int nextNode = preorder[preStart + 1];
    int j = mp[nextNode];
    int num = j - postStart + 1;
    node->left = solve(preStart + 1, postStart, preStart + num, preorder, postorder);
    node->right = solve(preStart + num + 1, j + 1, preEnd, preorder, postorder);
    return node;
}
TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder)
{
    int n = preorder.size();
    for (int i = 0; i < n; i++)
    {
        mp[postorder[i]] = i;
    }
    TreeNode *root = solve(0, 0, n - 1, preorder, postorder);
    return root;
}