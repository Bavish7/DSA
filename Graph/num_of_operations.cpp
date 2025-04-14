#include<iostream>
using namespace std;

// NUMBER OF OPERATIONS TO MAKE NETWORK CONNECTED (LEETCODE 1319)
// USING DISJOINT SETS - TC=O(E+V), SC=O(V)

// Steps:
// 1. Initialize `parent` and `rank` arrays for Union-Find, where each computer is its own parent initially.
// 2. For each connection:
//    a. Find the root of each computer (using path compression).
//    b. If they have different roots, union them to form one connected component.
//    c. If they already share a root, increase the `extraEdges` count, as this connection is redundant.
// 3. Count the total connected components in `parent`.
// 4. To connect all computers, the required edges = `connectedComp - 1`.
//    Check if `extraEdges` are sufficient to meet this requirement.
//    Return the required edges if sufficient, otherwise return -1.

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
int makeConnected(int n, vector<vector<int>> &connections)
{
    vector<int> parent(n);
    vector<int> rank(n, 0);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    int extraEdges = 0;
    for (auto connection : connections)
    {
        int u = connection[0];
        int v = connection[1];
        u = findParent(parent, u);
        v = findParent(parent, v);
        if (u != v)
        {
            unionSet(u, v, parent, rank);
        }
        else
        {
            extraEdges++;
        }
    }
    int connectedComp = 0;
    for (int i = 0; i < n; i++)
    {
        if (parent[i] == i)
        {
            connectedComp++;
        }
    }
    int ans = connectedComp - 1;
    return extraEdges >= ans ? ans : -1;
}