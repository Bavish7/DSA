#include<iostream>
using namespace std;

// COUSINS IN BINARY TREE II (LEETCODE 2641)
// USING 2 BFS TRAVERSALS - TC=O(N), SC=O(N)

// Steps:
// 1. Do BFS to compute total sum of nodes at each level → store in `levelSum`.
// 2. Set root value to 0 (special case).
// 3. BFS again to update children:
//    - For each node:
//       a. Calculate sum of its children’s values (siblingSum).
//       b. Set each child’s value to `levelSum[j] - siblingSum`.
// 4. Increment level index `j` as we move down levels.

TreeNode *replaceValueInTree(TreeNode *root)
{
    if (!root)
        return NULL;
    vector<int> levelSum;
    queue<TreeNode *> q;
    q.push(root);
    int level = 0;
    while (!q.empty())
    {
        int n = q.size();
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            TreeNode *front = q.front();
            q.pop();
            sum += front->val;
            if (front->left)
                q.push(front->left);
            if (front->right)
                q.push(front->right);
        }
        levelSum.push_back(sum);
        level++;
    }
    q.push(root);
    root->val = 0;
    int j = 1;
    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            int siblingSum = curr->left != NULL ? curr->left->val : 0;
            siblingSum += curr->right != NULL ? curr->right->val : 0;
            if (curr->left)
            {
                curr->left->val = levelSum[j] - siblingSum;
                q.push(curr->left);
            }
            if (curr->right)
            {
                curr->right->val = levelSum[j] - siblingSum;
                q.push(curr->right);
            }
        }
        j++;
    }
    return root;
}

// USING BFS TRAVERSAL - TC=O(N), SC=O(N)
// Steps:
// 1. Initialize queue with root and set `levelSum` to root's value.
// 2. Traverse level by level using BFS:
//    a. For each node, update its value as `levelSum - node->val`.
//    b. Calculate `siblingSum` of its children.
//    c. Update each child’s value to `siblingSum`.
//    d. Add children to queue and accumulate their original values into `nextLevelSum`.
// 3. After each level, update `levelSum` to `nextLevelSum`.
// 4. Return updated tree root.

TreeNode *replaceValueInTree(TreeNode *root)
{
    if (!root)
        return NULL;
    queue<TreeNode *> q;
    q.push(root);
    int levelSum = root->val;
    while (!q.empty())
    {
        int n = q.size();
        int nextLevelSum = 0;
        for (int i = 0; i < n; i++)
        {
            TreeNode *front = q.front();
            q.pop();
            front->val = levelSum - front->val;
            int siblingSum = front->left != NULL ? front->left->val : 0;
            siblingSum += front->right != NULL ? front->right->val : 0;
            if (front->left)
            {
                nextLevelSum += front->left->val;
                front->left->val = siblingSum;
                q.push(front->left);
            }
            if (front->right)
            {
                nextLevelSum += front->right->val;
                front->right->val = siblingSum;
                q.push(front->right);
            }
        }
        levelSum = nextLevelSum;
    }
    return root;
}