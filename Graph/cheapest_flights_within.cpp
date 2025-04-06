#include<iostream>
using namespace std;

// CHEAPEST FLIGHTS WITHIN K STOPS (LEETCODE 787)
// USING BFS TRAVERSAL - TC=O(V+E), SC=O(V+E)

// Steps:
// 1. Create an adjacency list to represent the flight connections and their costs.
// 2. Initialize a queue for BFS, starting with the source node and zero cost, along with a counter for stops.
// 3. Use a distance vector initialized to a large value (1e9) to track the minimum cost to each node.
// 4. While the queue is not empty:
//    a. Extract the front element, including the current node, cost, and number of stops.
//    b. If the number of stops exceeds k, skip further processing for this path.
//    c. For each neighbor of the current node, calculate the new cost.
//    d. If the new cost is less than the recorded distance and stops are within the limit, update the distance and push the neighbor into the queue with updated cost and stops.
// 5. After the BFS, check if the destination node was reached within k stops; if not, return -1. Otherwise, return the minimum cost.

int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k)
{
    vector<pair<int, int>> adj[n];
    for (auto it : flights)
    {
        adj[it[0]].push_back({it[1], it[2]});
    }
    queue<pair<int, pair<int, int>>> q;
    q.push({0, {src, 0}});
    vector<int> dist(n, 1e9);
    while (!q.empty())
    {
        auto it = q.front();
        q.pop();
        int stops = it.first;
        int node = it.second.first;
        int dis = it.second.second;
        if (stops > k)
            break;
        for (auto it : adj[node])
        {
            int adjNode = it.first;
            int edjW = it.second;
            if (dis + edjW < dist[adjNode] && stops <= k)
            {
                dist[adjNode] = dis + edjW;
                q.push({stops + 1, {adjNode, edjW + dis}});
            }
        }
    }
    if (dist[dst] == 1e9)
        return -1;
    return dist[dst];
}
