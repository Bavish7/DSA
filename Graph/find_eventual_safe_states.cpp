#include<iostream>
using namespace std;

// FIND EVENTUAL SAFE STATES (LEETCODE 802)
// USING DFS TRAVERSAL - TC=O(V+E), SC=O(V)

// Steps:
// 1. Use a Depth-First Search (DFS) approach to detect cycles in the directed graph.
// 2. Mark nodes visited during the DFS traversal and also keep track of nodes in the current path using `pathVis`.
// 3. If a node is revisited in the same DFS path, a cycle is detected.
// 4. Nodes not in any cycle are eventually safe nodes.
// 5. Collect and return nodes that are not part of any cycle.

bool cycleDFS(int i, vector<vector<int>> &graph, vector<bool> &vis, vector<bool> &pathVis)
{
    vis[i] = true;
    pathVis[i] = true;
    for (auto child : graph[i])
    {
        if (!vis[child])
        {
            bool ans = cycleDFS(child, graph, vis, pathVis);
            if (ans == true)
                return true;
        }
        else if (vis[child] == true && pathVis[child] == true)
        {
            return true;
        }
    }
    pathVis[i] = false;
    return false;
}
vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<bool> vis(n, false);
    vector<bool> pathVis(n, false);
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            cycleDFS(i, graph, vis, pathVis);
        }
    }
    vector<int> ans;
    for (int i = 0; i < n; i++)
    {
        if (!pathVis[i])
        {
            ans.push_back(i);
        }
    }
    return ans;
}

// USING BFS TRAVERSAL OR KAHN'S ALGORITHM - TC=O(V+E), SC=O(V)
// Steps:
// 1. Build a reverse graph (adjList) from the original graph to track incoming edges.
// 2. Compute indegree for each node to find nodes with no outgoing edges (safe nodes).
// 3. Use a queue to perform a BFS-like topological sort on nodes with indegree zero.
// 4. Add nodes with indegree zero to the `safeNodes` list and update indegree for neighbors.
// 5. Sort and return the list of safe nodes in ascending order.

vector<int> eventualSafeNodes(vector<vector<int>> &graph)
{
    int n = graph.size();
    unordered_map<int, list<int>> adjList;
    vector<int> indegree(n, 0);
    vector<int> safeNodes;
    for (int i = 0; i < n; i++)
    {
        for (auto it : graph[i])
        {
            adjList[it].push_back(i);
            indegree[i]++;
        }
    }
    queue<int> q;
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int node = q.front();
        safeNodes.push_back(node);
        q.pop();
        for (auto child : adjList[node])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }
    sort(safeNodes.begin(), safeNodes.end());
    return safeNodes;
}