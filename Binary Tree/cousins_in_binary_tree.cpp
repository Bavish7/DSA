#include<iostream>
using namespace std;

// COUSINS IN BINARY TREE (LEETCODE 993)
// USING BFS TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// 1. Perform level-order traversal using BFS.
// 2. For each level:
//    - Track if `x` and `y` are found (set flags).
//    - Check if `x` and `y` are siblings → if yes, return false.
// 3. After level ends:
//    - If both found → return true (they are cousins).
//    - If only one is found → return false.
// 4. Repeat until tree ends.

bool isCousins(TreeNode *root, int x, int y)
{
    if (!root)
        return false;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        int levelSize = q.size();
        bool foundX = false, foundY = false;
        for (int i = 0; i < levelSize; i++)
        {
            TreeNode *current = q.front();
            q.pop();
            if (current->left && current->right)
            {
                if ((current->left->val == x && current->right->val == y) ||
                    (current->left->val == y && current->right->val == x))
                {
                    return false;
                }
            }
            if (current->left)
            {
                q.push(current->left);
                if (current->left->val == x)
                    foundX = true;
                if (current->left->val == y)
                    foundY = true;
            }
            if (current->right)
            {
                q.push(current->right);
                if (current->right->val == x)
                    foundX = true;
                if (current->right->val == y)
                    foundY = true;
            }
        }
        if (foundX && foundY)
            return true;
        if (foundX || foundY)
            return false;
    }
    return false;
}