#include<iostream>
using namespace std;

// ALL NODES DISTANCE K IN BINARY TREE (LEETCODE 863)
// USING BFS - TC=O(N), SC=O(N)

// Steps:
// 1. Use a helper function `markParents` to store parent pointers for all nodes in an unordered map.
// 2. Initialize a queue for BFS traversal starting from the target node, and mark it as visited.
// 3. Perform BFS up to `k` levels. For each node at the current level:
//    - Push its parent, left child, and right child into the queue if not visited.
//    - Mark the visited nodes to avoid revisiting.
// 4. After `k` levels, the nodes remaining in the queue are at a distance `k` from the target.
// 5. Extract their values into a result vector and return it.

void markParents(TreeNode *root, unordered_map<TreeNode *, TreeNode *> &parent)
{
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        if (curr->left)
        {
            parent[curr->left] = curr;
            q.push(curr->left);
        }
        if (curr->right)
        {
            parent[curr->right] = curr;
            q.push(curr->right);
        }
    }
}
vector<int> distanceK(TreeNode *root, TreeNode *target, int k)
{
    unordered_map<TreeNode *, TreeNode *> parent;
    markParents(root, parent);
    unordered_map<TreeNode *, bool> visited;
    queue<TreeNode *> q;
    q.push(target);
    visited[target] = true;
    int distance = 0;
    while (!q.empty())
    {
        int size = q.size();
        if (distance++ == k)
            break;
        for (int i = 0; i < size; i++)
        {
            TreeNode *curr = q.front();
            q.pop();
            if (parent[curr] && !visited[parent[curr]])
            {
                q.push(parent[curr]);
                visited[parent[curr]] = true;
            }
            if (curr->left && !visited[curr->left])
            {
                q.push(curr->left);
                visited[curr->left] = true;
            }
            if (curr->right && !visited[curr->right])
            {
                q.push(curr->right);
                visited[curr->right] = true;
            }
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        ans.push_back(curr->val);
    }
    return ans;
}