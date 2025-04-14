#include<iostream>
using namespace std;

// NETWORK DELAY TIME (LEETCODE 743)
// USING DIJSKTRA'S ALGORITHM - TC=O(E*LOGV), SC=O(V)

// Steps:
// 1. Construct the adjacency list from the input `times`, where each entry contains a directed edge and its weight.
// 2. Implement Dijkstra's algorithm:
//    - Initialize a min-heap priority queue to keep track of the node with the shortest known distance from the source.
//    - Set all distances to `INT_MAX` except the starting node `k`, which is set to 0.
//    - While the priority queue is not empty, extract the node with the minimum distance.
//    - For each neighbor of this node, calculate the potential new distance and update if it is smaller than the current known distance.
//    - Push the updated distance to the priority queue.
// 3. After the algorithm completes, determine the maximum distance from the source to all other nodes. If any node remains unreachable (distance is `INT_MAX`), return `-1`.
// 4. Return the maximum distance as the result, representing the time for all nodes to receive the signal from node `k`.

int dijkstraAlgo(int n, int k, unordered_map<int, list<pair<int, int>>> &adjList)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    vector<int> dist(n + 1, INT_MAX);
    pq.push({0, k});
    dist[k] = 0;
    while (!pq.empty())
    {
        auto top = pq.top();
        pq.pop();
        int topDist = top.first;
        int topNode = top.second;
        for (auto nbr : adjList[topNode])
        {
            int nbrNode = nbr.first;
            int nbrDist = nbr.second;
            if (topDist + nbrDist < dist[nbrNode])
            {
                dist[nbrNode] = topDist + nbrDist;
                pq.push({dist[nbrNode], nbrNode});
            }
        }
    }
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        ans = max(ans, dist[i]);
    }
    return ans == INT_MAX ? -1 : ans;
}
int networkDelayTime(vector<vector<int>> &times, int n, int k)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < times.size(); i++)
    {
        int u = times[i][0];
        int v = times[i][1];
        int w = times[i][2];
        adjList[u].push_back({v, w});
    }
    return dijkstraAlgo(n, k, adjList);
}