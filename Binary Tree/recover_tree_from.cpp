#include<iostream>
using namespace std;

// RECOVER A TREE FROM PREORDER TRAVERSAL (LEETCODE 1028)
// USING PREORDER TRAVERSAL AND RECURSION - TC=O(N), SC=O(N)

// Steps:
// 1. Use recursion to construct the binary tree from the preorder traversal string.
// 2. Traverse the string to count dashes ('-'), determining the depth of the next node.
// 3. If the depth does not match the expected depth, return NULL (backtrack).
// 4. Extract the numerical value of the current node from the string.
// 5. Create a `TreeNode` with the extracted value and recursively call `solve`:
//    - First for the left subtree (increment depth).
//    - Then for the right subtree (same depth).
// 6. Return the constructed tree.

TreeNode *solve(string s, int &i, int depth, int n)
{
    if (i >= n)
        return NULL;
    int j = i;
    while (j < n && s[j] == '-')
    {
        j++;
    }
    int dash = j - i;
    if (depth != dash)
    {
        return NULL;
    }
    i = j;
    int num = 0;
    while (i < n && isdigit(s[i]))
    {
        num = (num * 10) + (s[i] - '0');
        i++;
    }
    TreeNode *node = new TreeNode(num);
    node->left = solve(s, i, depth + 1, n);
    node->right = solve(s, i, depth + 1, n);
    return node;
}
TreeNode *recoverFromPreorder(string traversal)
{
    int i = 0;
    TreeNode *root = solve(traversal, i, 0, traversal.size());
    return root;
}