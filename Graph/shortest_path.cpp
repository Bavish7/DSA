#include<iostream>
#include <unordered_map>
#include <queue>
#include <list>
#include <set>
using namespace std;

// SHORTEST PATH IN AN UNDIRECTED GRAPH
// USING BFS TRAVERSAL - TC=O(V+E), SC=O(V+E)

// Steps:
// 1. Build the adjacency list `adj` for the graph using the input edges.
// 2. Initialize BFS components:
//    - A queue `q` to manage nodes during traversal.
//    - A `visited` map to keep track of visited nodes.
//    - A `parent` map to record the parent of each node (used to reconstruct the path).
// 3. Start BFS from the source node `s`:
//    - Mark `s` as visited and set its parent to -1.
//    - While the queue is not empty, process each node:
//      - For each unvisited neighbor of the current node, mark it as visited, set its parent, and enqueue it.
// 4. After BFS completes, reconstruct the shortest path from the destination node `t` to the source node `s`:
//    - Use the `parent` map to trace the path back from `t` to `s`.
//    - Reverse the path since it was built backwards.
// 5. Return the reconstructed path as the result.

vector<int> bfsTraversal(unordered_map<int, list<int>> &adj, int s, int t)
{
    queue<int> q;
    unordered_map<int, bool> visited;
    unordered_map<int, int> parent;
    q.push(s);
    visited[s] = true;
    parent[s] = -1;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        for (auto neighbour : adj[frontNode])
        {
            if (!visited[neighbour])
            {
                q.push(neighbour);
                visited[neighbour] = true;
                parent[neighbour] = frontNode;
            }
        }
    }
    vector<int> ans;
    while (t != -1)
    {
        ans.push_back(t);
        t = parent[t];
    }
    reverse(ans.begin(), ans.end());
    return ans;
}
vector<int> shortestPath(vector<pair<int, int>> edges, int n, int m, int s, int t)
{
    unordered_map<int, list<int>> adj;
    for (int i = 0; i < m; i++)
    {
        int u = edges[i].first;
        int v = edges[i].second;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> ans;
    ans = bfsTraversal(adj, s, t);
    return ans;
}

// SHORTEST PATH IN A WEIGHTED DIRECTED GRAPH
// USING DFS TRAVERSAL OR SSSPA (SINGLE SOURCE SHORTEST PATH ALGORITHM)

// Steps:
// 1. Build the adjacency list `adj` for the graph using the input edges.
//    - Each edge is added to the adjacency list with its weight.
// 2. Perform a topological sort of the graph using DFS:
//    - Initialize a `visited` vector to track visited nodes and a `stack` to store the nodes in topological order.
//    - Perform DFS for each node that hasn't been visited, pushing nodes onto the stack after visiting all their neighbors.
// 3. Calculate the shortest path distances using the topologically sorted nodes:
//    - Initialize a `distance` vector with `INT_MAX` for all nodes except the source node, which is set to 0.
//    - Process each node from the stack, updating the distance of its neighbors based on the current node's distance and edge weights.
// 4. Return the `distance` vector containing the shortest path distances from the source node to all other nodes.

void topSortDFS(int node, vector<bool> &visited, stack<int> &s, unordered_map<int, list<pair<int,int>>> &adj)
{
    visited[node] = 1;
    for (auto nbrPair : adj[node])
    {
        int nbrData = nbrPair.first;
        if (!visited[nbrData])
        {
            topSortDFS(nbrData, visited, s, adj);
        }
    }
    s.push(node);
}
vector<int> shortestPathDFS(stack<int> &s, int v, unordered_map<int, list<pair<int, int>>> &adj)
{
    vector<int> distance(v, INT_MAX);
    int src = s.top();
    s.pop();
    distance[src] = 0;
    for(auto nbrPair: adj[src]){
        int nbrData = nbrPair.first;
        int nbrDist = nbrPair.second;
        if(distance[src]+nbrDist<distance[nbrData]){
            distance[nbrData] = distance[src] + nbrDist;
        }
    }
    while(!s.empty()){
        int src = s.top();
        s.pop();
        for (auto nbrPair : adj[src])
        {
            int nbrData = nbrPair.first;
            int nbrDist = nbrPair.second;
            if (distance[src] + nbrDist < distance[nbrData])
            {
                distance[nbrData] = distance[src] + nbrDist;
            }
        } 
    }
    return distance;
}
vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)
{
    unordered_map<int, list<pair<int,int>>> adj;
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
    ans = shortestPathDFS(s, v, adj);
    return ans;
}

