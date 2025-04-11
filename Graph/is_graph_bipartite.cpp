#include<iostream>
using namespace std;

// IS GRAPH BIPARTITE (LEETCODE 785)
// USING BFS TRAVERSAL - TC=O(N+E), SC=O(N+E)

// Steps:
// 1. Initialize a `color` vector to track the color of each node, initialized to -1 (uncolored).
// 2. Use BFS to attempt to color the graph, starting from each uncolored node, using two colors (0 and 1).
// 3. If any adjacent nodes end up with the same color during BFS traversal, the graph is not bipartite.
// 4. If BFS completes without conflict for all components, the graph is bipartite.

bool bfs(int i, vector<vector<int>> &graph, vector<int> &color)
{
    queue<int> q;
    q.push(i);
    color[i] = 0;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        for (auto it : graph[frontNode])
        {
            if (color[it] == -1)
            {
                color[it] = !color[frontNode];
                q.push(it);
            }
            else if (color[it] == color[frontNode])
            {
                return false;
            }
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            if (!bfs(i, graph, color))
                return false;
        }
    }
    return true;
}

// USING DFS TRAVERSAL - TC=O(N+E), SC=O(N+E)
// Steps:
// 1. Initialize a `color` vector to track the color of each node, initialized to -1 (uncolored).
// 2. Use Depth-First Search (DFS) to attempt to color the graph using two colors (0 and 1).
// 3. If any adjacent nodes end up with the same color during DFS traversal, the graph is not bipartite.
// 4. If DFS completes without conflict for all components, the graph is bipartite.

bool dfs(int i, vector<vector<int>> &graph, vector<int> &color)
{
    for (auto it : graph[i])
    {
        if (color[it] == -1)
        {
            color[it] = !color[i];
            if (!dfs(it, graph, color))
                return false;
        }
        else if (color[it] == color[i])
        {
            return false;
        }
    }
    return true;
}
bool isBipartite(vector<vector<int>> &graph)
{
    int n = graph.size();
    vector<int> color(n, -1);
    for (int i = 0; i < n; i++)
    {
        if (color[i] == -1)
        {
            color[i] = 0;
            if (!dfs(i, graph, color))
                return false;
        }
    }
    return true;
}