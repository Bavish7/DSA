#include<iostream>
using namespace std;

// KRUSKAL'S ALGORITHM 
// USING DISJOINT SETS - TC=O(E*LOGV), SC=O(V+E)

// Steps:
// 1. Initialize the parent and rank arrays for the disjoint set.
// 2. Define a function findParent to find the representative (root) of a set.
// 3. Define a function unionSet to union two sets by rank.
// 4. Sort the edges based on their weights.
// 5. Iterate through the sorted edges and use findParent to check if the current edge forms a cycle.
//    - If it doesn't form a cycle, add its weight to the minimum spanning tree (MST) and union the sets.
// 6. Return the total weight of the MST.

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    parent[node] = findParent(parent, parent[node]);
    return parent[node];
}
void unionSet(int u, int v, vector<int> &parent, vector<int> &rank)
{
    u = findParent(parent, u);
    v = findParent(parent, v);
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
bool cmp(vector<int> &a, vector<int> &b)
{
    return a[2] < b[2];
}
int minimumSpanningTree(vector<vector<int>> &edges, int n)
{
    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    sort(edges.begin(), edges.end(), cmp);
    int minWeight = 0;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = findParent(parent, edges[i][0]);
        int v = findParent(parent, edges[i][1]);
        int wt = edges[i][2];
        if (u != v)
        {
            minWeight += wt;
            unionSet(u, v, parent, rank);
        }
    }
    return minWeight;
}