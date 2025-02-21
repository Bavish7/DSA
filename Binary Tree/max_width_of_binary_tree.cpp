#include<iostream>
using namespace std;

// MAXIMUM WIDTH OF A BINARY TREE (LEETCODE 662)
// USING LEVEL ORDER TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// 1. Perform a level-order traversal using a queue to compute the width at each level.
// 2. For each node, store its index based on a 0-based indexing system.
// 3. Normalize indices by subtracting the minimum index at each level to prevent overflow for large indices.
// 4. For each level, calculate the width as `last - first + 1`.
// 5. Keep track of the maximum width across all levels and return it at the end.

int widthOfBinaryTree(TreeNode *root)
{
    if (root == NULL)
        return 0;
    int ans = 0;
    queue<pair<TreeNode *, int>> q;
    q.push({root, 0});
    while (!q.empty())
    {
        int size = q.size();
        int mini = q.front().second;
        int first, last;
        for (int i = 0; i < size; i++)
        {
            int cur_id = q.front().second - mini;
            TreeNode *curr = q.front().first;
            q.pop();
            if (i == 0)
                first = cur_id;
            if (i == size - 1)
                last = cur_id;
            if (curr->left)
            {
                q.push({curr->left, (long long)cur_id * 2 + 1});
            }
            if (curr->right)
            {
                q.push({curr->right, (long long)cur_id * 2 + 2});
            }
        }
        ans = max(ans, last - first + 1);
    }
    return ans;
}