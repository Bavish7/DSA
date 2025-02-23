#include <iostream>
#include<queue>
using namespace std;

// BINARY TREE ZIGZAG LEVEL ORDER TRAVERSAL (LEETCODE 103)
// USING LEVEL ORDER TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// 1. If root is NULL, return empty result vector.
// 2. Initialize queue q and push root.
// 3. Initialize boolean leftToRight to true for zigzag pattern.
// 4. While q is not empty:
//    a. Get size of current level.
//    b. Initialize ans vector of current level's size.
//    c. For each node in the current level:
//       i. Pop front node from q.
//       ii. Determine index based on leftToRight.
//       iii. Insert node's value at determined index in ans.
//       iv. Push left child to q if exists.
//       v. Push right child to q if exists.
//    d. Toggle leftToRight for next level.
//    e. Append ans to result vector.
// 5. Return result vector.

vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> result;
    if (root == NULL)
    {
        return result;
    }
    queue<TreeNode *> q;
    q.push(root);
    bool leftToRight = true;
    while (!q.empty())
    {
        int size = q.size();
        vector<int> ans(size);
        for (int i = 0; i < size; i++)
        {
            TreeNode *frontNode = q.front();
            q.pop();
            int index = leftToRight ? i : size - i - 1;
            ans[index] = frontNode->val;
            if (frontNode->left)
            {
                q.push(frontNode->left);
            }
            if (frontNode->right)
            {
                q.push(frontNode->right);
            }
        }
        leftToRight = !leftToRight;
        result.push_back(ans);
    }
    return result;
}