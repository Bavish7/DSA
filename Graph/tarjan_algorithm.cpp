#include<iostream>
using namespace std;

// CRITICAL CONNECTIONS IN A NETWORK (LEETCODE 1192)
// USING TARJAN'S ALGORITHM - TC=O(V+E), SC=O(V)

// Steps:
// 1. Build the adjacency list `adjList` for the graph using the input connections.
//    - Each edge is bidirectional, so add both directions in the adjacency list.
// 2. Initialize variables for Tarjan's algorithm:
//    - `timer` to track the discovery time of nodes.
//    - `tin` and `low` vectors to store discovery and lowest reachable times for each node.
//    - `visited` map to track visited nodes.
//    - `ans` vector to store the critical connections.
// 3. Perform DFS traversal on each unvisited node:
//    - Update the discovery time and lowest time for the current node.
//    - For each neighbor, check if it is visited:
//      - If not visited, recursively perform DFS, update the lowest time of the current node.
//        - If the lowest time of the neighbor is greater than the discovery time of the current node, record the edge as a critical connection.
//      - If visited, update the lowest time of the current node based on the neighbor's lowest time.
// 4. Return the `ans` vector containing all critical connections.

void dfs(int src, int parent, unordered_map<int, list<int>> &adjList, int &timer, vector<int> &tin, vector<int> &low, unordered_map<int, bool> &visited, vector<vector<int>> &ans)
{
    visited[src] = true;
    tin[src] = timer;
    low[src] = timer;
    timer++;
    for (auto nbr : adjList[src])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!visited[nbr])
        {
            dfs(nbr, src, adjList, timer, tin, low, visited, ans);
            low[src] = min(low[src], low[nbr]);
            if (low[nbr] > tin[src])
            {
                ans.push_back({src, nbr});
            }
        }
        else
        {
            low[src] = min(low[src], low[nbr]);
        }
    }
}
vector<vector<int>> criticalConnections(int n, vector<vector<int>> &connections)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < connections.size(); i++)
    {
        int u = connections[i][0];
        int v = connections[i][1];
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    int src = 0;
    int parent = -1;
    int timer = 1;
    vector<vector<int>> ans;
    vector<int> tin(n, 0);
    vector<int> low(n, 0);
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, parent, adjList, timer, tin, low, visited, ans);
        }
    }
    return ans;
}