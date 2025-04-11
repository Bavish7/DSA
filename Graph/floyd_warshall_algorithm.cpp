#include<iostream>
using namespace std;

// MULTIPLE SOURCE SHORTEST PATH FOR NEGATIVE CYCLE
// USING FLOYD WARSHALL ALGORITHM - TC=O(N^3), SC=O(N^2)

// Steps:
// 1. Initialize a 2D distance matrix dist with a large value (infinity) for all pairs of vertices except the diagonal (self-loop).
//    Set dist[i][i] = 0 for all vertices i.
// 2. Update the distance matrix with direct edges from the input edges list.
// 3. Apply the Floyd-Warshall algorithm:
//    a. Use three nested loops:
//       - The outer loop iterates through each intermediate vertex (helper).
//       - The middle loop iterates through each source vertex.
//       - The inner loop iterates through each destination vertex.
//    b. If there is a shorter path through the current intermediate vertex, update the distance matrix.
// 4. Return the shortest distance from the source vertex src to the destination vertex dest.

int floydWarshall(int n, int m, int src, int dest, vector<vector<int>> &edges)
{
    vector<vector<int>> dist(n + 1, vector<int>(n + 1, 1e9));
    for (int i = 1; i <= n; i++)
    {
        dist[i][i] = 0;
    }
    for (int j = 0; j < edges.size(); j++)
    {
        int u = edges[j][0];
        int v = edges[j][1];
        int wt = edges[j][2];
        dist[u][v] = wt;
    }
    for (int helper = 1; helper <= n; helper++)
    {
        for (int source = 1; source <= n; source++)
        {
            for (int des = 1; des <= n; des++)
            {
                if (dist[source][helper] != 1e9 && dist[helper][des] != 1e9)
                {
                    dist[source][des] = min(dist[source][des], dist[source][helper] + dist[helper][des]);
                }
            }
        }
    }
    return dist[src][dest];
}