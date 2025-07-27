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

// USING POSTORDER TRAVERSAL - TC=O(N), SC=O(H)
// Steps:
// 1. Recursively find the height of left and right subtrees.
// 2. If current node is the starting node:
//    - Update `ans` with the max of leftHeight and rightHeight (infection spreads down).
//    - Return -1 to signal upwards that infection started here.
// 3. If both subtrees return valid heights (>= 0):
//    - Return max height + 1 for normal tree height computation.
// 4. If one child returns -1 (infection path):
//    - Calculate distance to the deepest node in the opposite direction.
//    - Update `ans` with this depth (infection spread in both directions).
//    - Return negative height - 1 to continue upward propagation.
// 5. The final `ans` is the total time to infect the entire tree.

int ans = 0;
int solve(TreeNode *root, int start)
{
    if (!root)
        return 0;
    int leftHeight = solve(root->left, start);
    int rightHeight = solve(root->right, start);
    if (root->val == start)
    {
        ans = max(leftHeight, rightHeight);
        return -1;
    }
    else if (leftHeight >= 0 && rightHeight >= 0)
    {
        return max(leftHeight, rightHeight) + 1;
    }
    else
    {
        int depth = abs(leftHeight) + abs(rightHeight);
        ans = max(ans, depth);
        return min(leftHeight, rightHeight) - 1;
    }
}
int amountOfTime(TreeNode *root, int start)
{
    solve(root, start);
    return ans;
}