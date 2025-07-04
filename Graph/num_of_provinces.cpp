#include<iostream>
using namespace std;

// NUMBER OF PROVINCES (LEETCODE 547)
// USING DFS TRAVERSAL - TC=O(N^2), SC=O(N)

// Steps:
// 1. Initialize a visited map to keep track of visited nodes (cities).
// 2. Define a DFS function to visit all connected nodes starting from a given node.
//    - Mark the current node as visited.
//    - Iterate through all possible neighbors of the current node.
//    - If a neighbor is connected (value is 1) and not yet visited, recursively call DFS on that neighbor.
// 3. In the main function (findCircleNum):
//    - Initialize the count of provinces to 0.
//    - Iterate through all nodes (cities):
//       - If a node is not visited, perform DFS starting from that node to visit all connected nodes.
//       - Increment the province count for each DFS call (each connected component).
// 4. Return the count of provinces.

void dfs(unordered_map<int, bool> &visited, int i, int n, vector<vector<int>> &isConnected)
{
    visited[i] = true;
    int col = n;
    for (int nbr = 0; nbr < col; nbr++)
    {
        if (isConnected[i][nbr] == 1)
        {
            if (!visited[nbr])
            {
                dfs(visited, nbr, n, isConnected);
            }
        }
    }
}
int findCircleNum(vector<vector<int>> &isConnected)
{
    unordered_map<int, bool> visited;
    int n = isConnected.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!visited[i])
        {
            dfs(visited, i, n, isConnected);
            count++;
        }
    }
    return count;
}

// USING DISJOINT SET - TC=O(N^2), SC=O(N)
// Steps:
// 1. Initialize Disjoint Set with `parent` and `rank` arrays.
// 2. Implement `findParent` for path compression.
// 3. Implement `unionSet` to merge sets using union by rank.
// 4. Traverse `isConnected` matrix and union connected cities.
// 5. Count unique parents to determine the number of provinces.

class DisjointSet
{
public:
    vector<int> rank, parent;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionSet(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);
        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
};
class Solution
{
public:
    int findCircleNum(vector<vector<int>> &isConnected)
    {
        int n = isConnected.size();
        DisjointSet ds(n);
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (isConnected[i][j] == 1)
                {
                    ds.unionSet(i, j);
                }
            }
        }
        int count = 0;
        for (int i = 0; i < n; i++)
        {
            if (ds.parent[i] == i)
                count++;
        }
        return count;
    }
};