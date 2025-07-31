#include<iostream>
using namespace std;

// NUMBER OF GOOD LEAF NODES PAIRS (LEETCODE 1530)
// USING GRAPH CONVERSION AND BFS TRAVERSAL - TC=O(N^2), SC=O(N)

// Steps:
// 1. Convert the binary tree to an undirected graph using adjacency list.
// 2. Identify all leaf nodes (no left and right children).
// 3. For each leaf node:
//    - Run BFS up to `distance` steps to find other reachable leaves within `distance`.
//    - If a different leaf node is found within the distance, increment count.
// 4. Since each pair is counted twice, return count / 2.

int countPairs(TreeNode *root, int distance)
{
    unordered_map<TreeNode *, vector<TreeNode *>> adj;
    unordered_set<TreeNode *> leafNodes;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();
        if (front->left == NULL && front->right == NULL)
            leafNodes.insert(front);
        if (front->left)
        {
            adj[front].push_back(front->left);
            adj[front->left].push_back(front);
            q.push(front->left);
        }
        if (front->right)
        {
            adj[front].push_back(front->right);
            adj[front->right].push_back(front);
            q.push(front->right);
        }
    }
    int count = 0;
    for (auto &leaf : leafNodes)
    {
        queue<TreeNode *> que;
        unordered_set<TreeNode *> vis;
        que.push(leaf);
        vis.insert(leaf);
        for (int level = 0; level <= distance; level++)
        {
            int n = que.size();
            for (int i = 0; i < n; i++)
            {
                TreeNode *front = que.front();
                que.pop();
                if (front != leaf && leafNodes.count(front))
                    count++;
                for (auto &nbr : adj[front])
                {
                    if (!vis.count(nbr))
                    {
                        que.push(nbr);
                        vis.insert(nbr);
                    }
                }
            }
        }
    }
    return count / 2;
}