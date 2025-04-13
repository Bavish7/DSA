#include<iostream>
using namespace std;

// MOST PROFITABLE PATH IN A TREE (LEETCODE 2467)
// USING DFS TRAVERSAL - TC=O(V+E), SC=O(V+E)

// Steps:
// 1. Construct an adjacency list `adj` for the tree using the given edges.
// 2. Perform DFS from Bob’s starting node to record the `bobTime` at which he reaches each node.
//    - If Bob reaches a node earlier than Alice, he takes the full amount.
//    - If both reach at the same time, the amount is halved.
//    - If Alice reaches first, she takes the full amount.
// 3. Perform DFS for Alice starting from node 0, updating her income based on Bob’s timings.
// 4. If Alice reaches a leaf node (except node 0), update `aliceAmt` to store the maximum profit.
// 5. Return `aliceAmt`, representing the maximum amount Alice can collect while avoiding Bob.

unordered_map<int, vector<int>> adj;
unordered_map<int, int> bobTime;
int aliceAmt;
bool DFSBob(int curr, int time, vector<bool> &vis)
{
    vis[curr] = true;
    bobTime[curr] = time;
    if (curr == 0)
        return true;
    for (auto &nbr : adj[curr])
    {
        if (!vis[nbr])
        {
            if (DFSBob(nbr, time + 1, vis))
                return true;
        }
    }
    bobTime.erase(curr);
    return false;
}
void DFSAlice(int curr, int time, int income, vector<bool> &vis, vector<int> &amount)
{
    vis[curr] = true;
    if (bobTime.find(curr) == bobTime.end() || time < bobTime[curr])
    {
        income += amount[curr];
    }
    else if (bobTime[curr] == time)
    {
        income += (amount[curr] / 2);
    }
    if (adj[curr].size() == 1 && curr != 0)
    {
        aliceAmt = max(aliceAmt, income);
    }
    for (auto &nbr : adj[curr])
    {
        if (!vis[nbr])
        {
            DFSAlice(nbr, time + 1, income, vis, amount);
        }
    }
}
int mostProfitablePath(vector<vector<int>> &edges, int bob, vector<int> &amount)
{
    int n = amount.size();
    for (vector<int> &edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<bool> vis(n, false);
    int time = 0;
    DFSBob(bob, time, vis);
    aliceAmt = INT_MIN;
    vis.assign(n, false);
    int income = 0;
    DFSAlice(0, 0, income, vis, amount);
    return aliceAmt;
}