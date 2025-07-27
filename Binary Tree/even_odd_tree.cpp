#include<iostream>
using namespace std;

// EVEN ODD TREE (LEETCODE 1609)
// USING LEVEL ORDER TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// 1. Use level order traversal (BFS) using a queue.
// 2. For even-indexed levels (level % 2 == 0):
//    - Node values must be odd and strictly increasing left to right.
// 3. For odd-indexed levels (level % 2 == 1):
//    - Node values must be even and strictly decreasing left to right.
// 4. Maintain `prevVal` to compare consecutive node values at the same level.
// 5. If any violation occurs, return false.
// 6. After traversing all levels, return true.

bool isEvenOddTree(TreeNode *root)
{
    if (!root)
        return true;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int n = q.size();
        int prevVal = (level % 2 == 0) ? INT_MIN : INT_MAX;
        for (int i = 0; i < n; ++i)
        {
            TreeNode *node = q.front();
            q.pop();
            int val = node->val;
            if ((val % 2) == (level % 2))
                return false;
            if (level % 2 == 0)
            {
                if (val <= prevVal)
                    return false;
            }
            else
            {
                if (val >= prevVal)
                    return false;
            }
            prevVal = val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        level++;
    }
    return true;
}