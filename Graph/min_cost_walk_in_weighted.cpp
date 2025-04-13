#include<iostream>
using namespace std;

// MINIMUM COST WALK IN WEIGHTED GRAPH (LEETCODE 3108)
// USING DISJOINT SETS AND BIT MANIPULATION - TC=O(N+E+Q), SC=O(N)

// Steps:
// 1. Initialize `parent` array for union-find and `cost` array to store min bitwise AND cost.
// 2. Process all edges and perform union-find operations:
//    - Find parents of both nodes.
//    - If they belong to different sets, merge them and update `cost` using bitwise AND.
// 3. Process queries:
//    - Find the parent of both nodes in the query.
//    - If they are in different components, return `-1`.
//    - If `s == t`, return `0` (same node).
//    - Otherwise, return the `cost` of the connected component.

int findParent(vector<int> &parent, int node)
{
    if (parent[node] == node)
    {
        return node;
    }
    parent[node] = findParent(parent, parent[node]);
    return parent[node];
}
void unionSet(int u, int v, vector<int> &parent)
{
    parent[v] = u;
}
vector<int> minimumCost(int n, vector<vector<int>> &edges, vector<vector<int>> &query)
{
    vector<int> parent(n);
    vector<int> cost(n, -1);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }
    for (auto &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        int parentU = findParent(parent, u);
        int parentV = findParent(parent, v);
        if (parentU != parentV)
        {
            unionSet(parentU, parentV, parent);
            cost[parentU] &= cost[parentV];
        }
        cost[parentU] &= w;
    }
    vector<int> ans;
    for (auto &q : query)
    {
        int s = q[0];
        int t = q[1];
        int parentS = findParent(parent, s);
        int parentT = findParent(parent, t);
        if (s == t)
        {
            ans.push_back(0);
        }
        else if (parentS != parentT)
        {
            ans.push_back(-1);
        }
        else
        {
            ans.push_back(cost[parentS]);
        }
    }
    return ans;
}