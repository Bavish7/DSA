#include<iostream>
#include <unordered_map>
#include <list>
#include <queue>
using namespace std;

// PRIM'S ALGORITHM - TC=O(V^2), SC=O(V^2)

// Steps:
// 1. Build the adjacency list `adjList` for the graph using the input edges.
//    - Each entry in `adjList` contains a list of pairs where each pair represents an adjacent node and the weight of the edge connecting them.
// 2. Initialize:
//    - `weights` vector with INT_MAX for all nodes, except for the starting node (0 or 1) which is set to 0.
//    - `visited` vector to keep track of nodes that have been included in the MST, initialized to `false` for all nodes.
//    - `parent` vector to store the parent of each node in the MST, initialized to -1.
// 3. For each node (from 1 to n):
//    - Find the node `u` with the minimum weight that has not yet been included in the MST.
//    - Mark node `u` as visited.
//    - For each adjacent node `v` of `u`:
//      - If `v` has not been visited and the weight of the edge (u, v) is less than the current weight of `v`:
//        - Update `parent[v]` to `u` and `weights[v]` to the weight of the edge (u, v).
// 4. Construct the result vector `ans`:
//    - For each node (from 2 to n), add the edge connecting `parent[i]` and `i` with weight `weights[i]` to `ans`.
// 5. Return the result vector `ans`, which contains the edges of the MST.

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wt = g[i].second;
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }
    vector<int> weights(n + 1, INT_MAX);
    vector<bool> visited(n + 1, false);
    vector<int> parent(n + 1, -1);
    weights[0] = weights[1] = 0;
    for (int i = 1; i <= n; i++)
    {
        int mini = INT_MAX;
        int u;
        for (int v = 1; v <= n; v++)
        {
            if (visited[v] == false && weights[v] < mini)
            {
                u = v;
                mini = weights[v];
            }
        }
        visited[u] = true;
        for (auto nbr : adjList[u])
        {
            int v = nbr.first;
            int wt = nbr.second;
            if (visited[v] == false && wt < weights[v])
            {
                parent[v] = u;
                weights[v] = wt;
            }
        }
    }
    vector<pair<pair<int, int>, int>> ans;
    for (int i = 2; i <= n; i++)
    {
        ans.push_back({{parent[i], i}, weights[i]});
    }
    return ans;
}

// PRIM'S ALGORITHM USING MIN HEAP - TC=O(E*LOGE), SC=O(V+E)

// Steps:
// 1. Build the adjacency list `adjList` for the graph using the input edges.
//    - Each entry in `adjList` contains a list of pairs where each pair represents an adjacent node and the weight of the edge connecting them.
// 2. Initialize:
//    - `visited` vector to keep track of nodes that have been included in the MST, initialized to `false` for all nodes.
//    - `minHeap`, a priority queue, to store nodes along with their edge weights. The priority queue is ordered by edge weights, with the smallest weight at the top.
//    - Push the starting node (1) into the heap with weight 0 and an invalid parent (-1).
// 3. While the priority queue is not empty:
//    - Extract the node with the minimum edge weight from the heap.
//    - If the node has already been visited, continue to the next iteration.
//    - Mark the node as visited.
//    - If the node has a valid parent, add the edge connecting the node and its parent to the result vector `ans`.
//    - For each unvisited neighbor of the node, push the neighbor along with the weight of the edge connecting it to the node into the priority queue.
// 4. Return the result vector `ans`, which contains the edges of the MST.

vector<pair<pair<int, int>, int>> calculatePrimsMST(int n, int m, vector<pair<pair<int, int>, int>> &g)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < m; i++)
    {
        int u = g[i].first.first;
        int v = g[i].first.second;
        int wt = g[i].second;
        adjList[u].push_back({v, wt});
        adjList[v].push_back({u, wt});
    }
    vector<pair<pair<int, int>, int>> ans;
    vector<bool> visited(n + 1, false);
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
    minHeap.push({0, {1, -1}});
    while (!minHeap.empty())
    {
        auto topPair = minHeap.top();
        int wt = topPair.first;
        int node = topPair.second.first;
        int parent = topPair.second.second;
        minHeap.pop();
        if (visited[node])
        {
            continue;
        }
        visited[node] = true;
        if (parent != -1)
        {
            ans.push_back({{node, parent}, wt});
        }
        for (auto nbr : adjList[node])
        {
            int nbrNode = nbr.first;
            int nbrWt = nbr.second;
            if (visited[nbrNode] == false)
            {
                minHeap.push({nbrWt, {nbrNode, node}});
            }
        }
    }
    return ans;
}