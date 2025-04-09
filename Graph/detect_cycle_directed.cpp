#include<iostream>
#include <list>
#include <unordered_map>
using namespace std;

// DETECT CYCLE IN A DIRECTED GRAPH
// USING DFS TRAVERSAL - TC=O(V+E) , SC=O(V+E)

// Steps:
// 1. Create adjacency list adjList from the edges.
// 2. Initialize visited and dfsTrack maps to keep track of visited nodes and nodes in the current DFS path respectively.
// 3. Perform DFS traversal for each vertex to detect a cycle:
//    a. If a vertex is not visited, call cycleDFS for it.
//    b. In cycleDFS function, mark the vertex as visited and part of the current DFS path (dfsTrack).
//    c. For each neighbor, if it is not visited, recursively call cycleDFS. If it returns true, a cycle is detected.
//    d. If a neighbor is visited and is part of the current DFS path (dfsTrack), a cycle is detected.
//    e. After exploring all neighbors, unmark the vertex from the current DFS path (dfsTrack).
// 4. If any DFS traversal detects a cycle, return true. Otherwise, return false.

bool cycleDFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, unordered_map<int, bool> &dfsTrack)
{
    visited[src] = true;
    dfsTrack[src] = true;
    for (auto child : adjList[src])
    {
        if (!visited[child])
        {
            bool ans = cycleDFS(child, visited, adjList, dfsTrack);
            if (ans == true)
            {
                return true;
            }
        }
        else if (visited[child] == true && dfsTrack[child] == true)
        {
            return true;
        }
    }
    dfsTrack[src] = false;
    return false;
}
bool isCyclic(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, bool> visited;
    unordered_map<int, bool> dfsTrack;
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < e; i++)
    {
        int x = edges[i][0];
        int y = edges[i][1];
        adjList[x].push_back(y);
    }
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            bool ans = cycleDFS(i, visited, adjList, dfsTrack);
            if (ans == true)
            {
                return true;
            }
        }
    }
    return false;
}

// USING BFS TRAVERSAL OR KAHN'S ALGORITHM - TC=O(V+E), SC=O(V)

// Steps:
// 1. Create adjacency list adj from the edges.
// 2. Use Kahn's Algorithm (Topological Sort with BFS) to detect cycles:
//    a. Calculate the indegree of each vertex.
//    b. Initialize a queue with all vertices that have an indegree of 0.
//    c. Process the vertices in the queue:
//       - Remove a vertex from the queue, add it to the topological sort result.
//       - Decrease the indegree of its neighbors. If a neighbor's indegree becomes 0, add it to the queue.
//    d. If the number of vertices in the topological sort result is equal to the number of vertices in the graph, there is no cycle.
//    e. Otherwise, a cycle exists in the graph.

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
bool isCyclic(vector<vector<int>> &edges, int v, int e)
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
    if (ans.size() == v)
    {
        return false;
    }
    else
    {
        return true;
    }
}