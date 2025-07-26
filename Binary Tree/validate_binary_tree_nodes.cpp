#include<iostream>
using namespace std;

// VALIDATE BINARY TREE NODES (LEETCODE 1361)
// USING BINARY TREE PROPERTIES AND BFS - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize a `parent` array to track if any node has more than one parent.
// 2. Build adjacency list for each node and check:
//    - If a child is already assigned a parent, return false (invalid tree).
// 3. Identify the root node — only one node must have no parent.
//    - If multiple or no roots, return false.
// 4. Use BFS from the root to ensure all nodes are reachable and no cycles exist.
// 5. Keep a count of visited nodes.
// 6. Return true if all nodes are visited exactly once (i.e., count == n), else false.

bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild)
{
    vector<int> parent(n, -1);
    unordered_map<int, vector<int>> adj;
    for (int i = 0; i < n; i++)
    {
        if (leftChild[i] != -1)
        {
            adj[i].push_back(leftChild[i]);
            if (parent[leftChild[i]] != -1)
                return false;
            else
                parent[leftChild[i]] = i;
        }
        if (rightChild[i] != -1)
        {
            adj[i].push_back(rightChild[i]);
            if (parent[rightChild[i]] != -1)
                return false;
            else
                parent[rightChild[i]] = i;
        }
    }
    int root = -1;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == -1)
        {
            if (root != -1)
                return false;
            root = i;
        }
    }
    if (root == -1)
        return false;
    int count = 0;
    queue<int> q;
    vector<int> vis(n, false);
    q.push(root);
    count++;
    vis[root] = true;
    while (!q.empty())
    {
        int node = q.front();
        q.pop();
        for (auto &it : adj[node])
        {
            if (!vis[it])
            {
                vis[it] = true;
                count++;
                q.push(it);
            }
        }
    }
    return count == n;
}