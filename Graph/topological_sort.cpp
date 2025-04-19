#include<iostream>
#include <unordered_map>
#include <list>
#include <stack>
using namespace std;

// TOPOLOGICAL SORT
// USING DFS TRAVERSAL - TC=O(V+E), SC=O(V)

// Steps:
// 1. Build the adjacency list `adj` for the graph using the input edges.
//    - Each edge is directed, so add the directed edge in the adjacency list.
// 2. Initialize a `visited` vector to track visited nodes and a `stack` to store the topological order.
// 3. Perform DFS traversal on each unvisited node:
//    - For each node, mark it as visited and recursively perform DFS on all its unvisited neighbors.
//    - After visiting all neighbors, push the node onto the stack.
// 4. After the DFS traversal, the stack contains nodes in reverse topological order.
// 5. Pop all elements from the stack to get the nodes in topological order and return this order.

void topSortDFS(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<int>> &adj)
{
    visited[node] = 1;
    for (auto neighbour : adj[node])
    {
        if (!visited[neighbour])
        {
            topSortDFS(neighbour, visited, s, adj);
        }
    }
    s.push(node);
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    vector<bool> visited(v);
    stack<int> s;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            topSortDFS(i, visited, s, adj);
        }
    }
    vector<int> ans;
    while (!s.empty())
    {
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

// USING BFS TRAVERSAL OR KAHN'S ALGORITHM - TC=O(V+E), SC=O(V)
// Steps:
// 1. Build the adjacency list `adj` for the graph using the input edges.
//    - Each edge is directed, so add the directed edge in the adjacency list.
// 2. Compute the indegree of each node:
//    - Iterate through each node's neighbors and increment their indegree.
// 3. Initialize a queue and push all nodes with an indegree of 0 into it.
// 4. Perform BFS traversal:
//    - While the queue is not empty:
//      - Dequeue a node, add it to the result list.
//      - Decrease the indegree of its neighbors. If any neighbor's indegree becomes 0, enqueue it.
// 5. The result list contains nodes in topological order.

vector<int> topSortBFS(unordered_map<int, list<int>> &adj, int v)
{
    queue<int> q;
    vector<int> indegree(v);
    for (auto i : adj)
    {
        for (auto neighbour : i.second)
        {
            indegree[neighbour]++;
        }
    }
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for (auto neighbour : adj[frontNode])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < e; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adj[u].push_back(v);
    }
    vector<int> ans;
    ans = topSortBFS(adj, v);
    return ans;
}