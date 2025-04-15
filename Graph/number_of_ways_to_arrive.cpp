#include<iostream>
using namespace std;

// NUMBER OF WAYS TO ARRIVE AT DESTINATION (LEETCODE 1976)
// USING DIJKSTRA'S ALGORITHM - TC=O(E*LOGV), SC=O(V)

// Steps:
// 1. Build an adjacency list `mp` to store roads as an undirected weighted graph.
// 2. Initialize `distance` array with large values and `ways` array with 0, except `distance[0] = 0` and `ways[0] = 1`.
// 3. Use a min-heap (priority queue) to implement Dijkstra’s algorithm for shortest paths.
// 4. Process each node:
//    - If a shorter path is found to a neighbor, update `distance` and push it into the heap.
//    - If an equal shortest path is found, update `ways` using modular addition.
// 5. Return `ways[n-1]`, the number of ways to reach the last node.

int countPaths(int n, vector<vector<int>> &roads)
{
    int mod = 1e9 + 7;
    unordered_map<int, list<pair<int, int>>> mp;
    for (int i = 0; i < roads.size(); i++)
    {
        int u = roads[i][0];
        int v = roads[i][1];
        int w = roads[i][2];
        mp[u].push_back({v, w});
        mp[v].push_back({u, w});
    }
    vector<long long> distance(n, 1e15), ways(n, 0);
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, 0});
    distance[0] = 0;
    ways[0] = 1;
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        long long dist = top.first;
        int node = top.second;
        for (auto nbr : mp[node])
        {
            int nbrNode = nbr.first;
            long long nbrDist = nbr.second;
            if (dist + nbrDist < distance[nbrNode])
            {
                distance[nbrNode] = dist + nbrDist;
                pq.push({dist + nbrDist, nbrNode});
                ways[nbrNode] = ways[node];
            }
            else if (dist + nbrDist == distance[nbrNode])
            {
                ways[nbrNode] = (ways[nbrNode] + ways[node]) % mod;
            }
        }
    }
    return ways[n - 1] % mod;
}