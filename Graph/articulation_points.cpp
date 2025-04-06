#include<iostream>
using namespace std;

// ARTICULATION POINTS IN A GRAPH
// USING TARJAN'S ALGORITHM - TC=O(V+E), SC=O(V+E)

// Steps:
// 1. Construct the adjacency list for the graph from the connections.
// 2. Initialize vectors for tracking discovery time (`tin`), the lowest point reachable (`low`), and articulation point markers (`mark`).
// 3. Use a DFS to traverse the graph, updating `tin` and `low` for each node, and identifying articulation points based on the conditions:
//    - A node is an articulation point if it has more than one child and is the root.
//    - A node is an articulation point if it has a child with no back edge that can reach the parent.
// 4. After DFS, collect all nodes marked as articulation points.
// 5. Return the list of articulation points or `-1` if none exist.

void dfs(int src, int parent, unordered_map<int, list<int>> &adjList, int &timer, vector<int> &tin, vector<int> &low, unordered_map<int, bool> &visited, vector<int>&mark)
{
    visited[src] = true;
    tin[src] = timer;
    low[src] = timer;
    timer++;
    int child = 0;
    for (auto nbr : adjList[src])
    {
        if (nbr == parent)
        {
            continue;
        }
        if (!visited[nbr])
        {
            dfs(nbr, src, adjList, timer, tin, low, visited, mark);
            low[src] = min(low[src], low[nbr]);
            if (low[nbr] >= tin[src] && parent!=-1)
            {
                mark[src] = 1;
            }
            child++;
        }
        else
        {
            low[src] = min(low[src], low[nbr]);
        }
    }
    if(child>1 && parent==-1){
        mark[src] = 1;
    }
}
vector<int> articulationPoints(int n, vector<vector<int>> &connections)
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
    vector<int> ans;
    vector<int> tin(n, 0);
    vector<int> low(n, 0);
    vector<int> mark(n, 0);
    unordered_map<int, bool> visited;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(i, parent, adjList, timer, tin, low, visited, mark);
        }
    }
    for (int i = 0; i < n;i++){
        if(mark[i]==1){
            ans.push_back(i);
        }
    }
    if(ans.size()==0) return {-1};
    return ans;
}