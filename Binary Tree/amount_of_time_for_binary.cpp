#include<iostream>
using namespace std;

// AMOUNT OF TIME FOR BINARY TREE TO BE INFECTED (LEETCODE 2385)
// USING ADJACENCY LIST AND BFS TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// 1. Convert the binary tree into an undirected graph using adjacency list:
//    - For each node, connect it bidirectionally with its left and right children.
// 2. Run BFS starting from the `start` node (the infected node):
//    - At each level, increment the `minutes` counter.
//    - Spread to unvisited adjacent nodes (neighbors).
// 3. Continue until BFS completes (no new nodes to infect).
// 4. Return `minutes` — total time taken to infect the entire tree.

int amountOfTime(TreeNode *root, int start)
{
    unordered_map<int, vector<int>> adj;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *front = q.front();
        q.pop();
        if (front->left)
        {
            q.push(front->left);
            adj[front->val].push_back(front->left->val);
            adj[front->left->val].push_back(front->val);
        }
        if (front->right)
        {
            q.push(front->right);
            adj[front->val].push_back(front->right->val);
            adj[front->right->val].push_back(front->val);
        }
    }
    int minutes = 0;
    queue<int> que;
    unordered_set<int> vis;
    que.push(start);
    vis.insert(start);
    while (!que.empty())
    {
        int n = que.size();
        for (int i = 0; i < n; i++)
        {
            int front = que.front();
            que.pop();
            for (auto &nbr : adj[front])
            {
                if (!vis.count(nbr))
                {
                    que.push(nbr);
                    vis.insert(nbr);
                }
            }
        }
        minutes++;
    }
    return minutes-1;
}