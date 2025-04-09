#include<iostream>
#include <queue>
#include <list>
#include <unordered_map>
using namespace std;

// CYCLE DETECTION IN AN UNDIRECTED GRAPH
// USING BFS TRAVERSAL - TC=O(N+M), SC=O(N)

// Steps:
// 1. Create adjacency list adjList from the edges for an undirected graph.
// 2. Initialize a visited map to track visited vertices.
// 3. For each vertex, if it has not been visited, call cycleBFS to detect a cycle starting from that vertex:
//    a. Initialize a queue and a parent map for BFS traversal.
//    b. Mark the source vertex as visited and set its parent to -1.
//    c. Perform BFS traversal:
//       - For each vertex, explore its neighbors.
//       - If a neighbor is not visited, mark it as visited, set its parent, and add it to the queue.
//       - If a neighbor is already visited and it is not the parent of the current vertex, a cycle is detected.
// 4. If a cycle is detected, return "Yes". Otherwise, return "No".

bool cycleBFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    queue<int> q;
    unordered_map<int, int> parent;
    visited[src] = true;
    parent[src] = -1;
    q.push(src);
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        for (auto child : adjList[frontNode])
        {
            if (!visited[child])
            {
                q.push(child);
                visited[child] = true;
                parent[child] = frontNode;
            }
            else if (visited[child] && child != parent[frontNode])
            {
                return true;
            }
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            bool ans = cycleBFS(i, visited, adjList);
            if (ans)
            {
                return "Yes";
            }
        }
    }
    return "No";
}

// USING DFS TRAVERSAL - TC=O(N+M), SC=O(N)
// Steps:
// 1. Create adjacency list adjList from the edges for an undirected graph.
// 2. Initialize a visited map to track visited vertices.
// 3. For each vertex, if it has not been visited, call cycleDFS to detect a cycle starting from that vertex:
//    a. Mark the source vertex as visited.
//    b. For each neighbor of the current vertex:
//       - If the neighbor has not been visited, recursively call cycleDFS with the neighbor and set the current vertex as its parent.
//       - If the neighbor is already visited and is not the parent of the current vertex, a cycle is detected.
// 4. If a cycle is detected, return "Yes". Otherwise, return "No".

bool cycleDFS(int src, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList, int parent)
{
    visited[src] = true;
    for (auto child : adjList[src])
    {
        if (!visited[child])
        {
            bool ans = cycleDFS(child, visited, adjList, src);
            if (ans == true)
            {
                return true;
            }
        }
        else if (visited[child] == true && child != parent)
        {
            return true;
        }
    }
    return false;
}

string cycleDetection(vector<vector<int>> &edges, int n, int m)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            int parent = -1;
            bool ans = cycleDFS(i, visited, adjList, parent);
            if (ans == true)
            {
                return "Yes";
            }
        }
    }
    return "No";
}
