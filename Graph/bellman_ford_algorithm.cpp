#include<iostream>
using namespace std;

// SINGLE SOURCE SHORTEST PATH FOR NEGATIVE CYCLE
// USING BELLMAN FORD ALGORITHM - TC=O(N*M), SC=O(N)

// Steps:
// 1. Initialize distance vector dist with a large value (infinity) for all vertices except the source vertex src.
//    Set dist[src] = 0.
// 2. Relax edges repeatedly:
//    a. Iterate n-1 times (where n is the number of vertices):
//       - For each edge (u, v, wt) in edges:
//         If dist[u] + wt < dist[v], update dist[v] to dist[u] + wt.
// 3. Check for negative weight cycles:
//    a. Iterate through all edges again:
//       - If an edge (u, v, wt) can be relaxed further (dist[u] + wt < dist[v]), there is a negative weight cycle.
// 4. Return the distance vector dist, which contains the shortest path distances from the source vertex src.

vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges)
{
    vector<int> dist(n + 1, 1e8);
    dist[src] = 0;
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int u = edges[j][0];
            int v = edges[j][1];
            int wt = edges[j][2];
            if ((dist[u] + wt) < dist[v])
            {
                dist[v] = dist[u] + wt;
            }
        }
    }
    bool anyUpdate = false;
    for (int j = 0; j < m; j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        if (dist[u] != 1e8 && (dist[u] + wt) < dist[v])
        {
            anyUpdate = true;
        }
    }
    return dist;
}