#include<iostream>
using namespace std;

// FIND THE CITY WITH THE SMALLEST NUMBER OF NEIGHBORS AT A THRESHOLD DISTANCE (LEETCODE 1334)
// USING DIJKSTRA'S ALGORITHM - TC=O(V*(ELOGV)), SC=O(V+E)

// Steps:
// 1. Build the adjacency list from the given edges where each node is connected with a distance.
// 2. Use Dijkstra’s algorithm for each city as a starting point to calculate the number of reachable cities within the `distanceThreshold`.
//    a. For each city, initialize the distances to all other cities as infinity.
//    b. Use a set to store pairs of distance and nodes, processing the city with the smallest current distance.
//    c. For each neighbor, update the distance if a shorter path is found and add it back to the set.
//    d. Count the number of cities reachable within the threshold from this city.
// 3. Track the city with the minimum reachable cities, and in case of ties, choose the city with the higher index.

int dijkstraShortPath(int source, int n, unordered_map<int, list<pair<int, int>>> &adj, int &distanceThreshold)
{
    vector<int> dist(n, INT_MAX);
    set<pair<int, int>> st;
    st.insert({0, source});
    dist[source] = 0;
    int reachableCities = 0;
    while (!st.empty())
    {
        auto topElement = st.begin();
        pair<int, int> topPair = *topElement;
        int topDist = topPair.first;
        int topNode = topPair.second;
        st.erase(st.begin());
        if (topNode != source && topDist <= distanceThreshold)
        {
            reachableCities++;
        }
        for (auto nbrPair : adj[topNode])
        {
            int nbrNode = nbrPair.first;
            int nbrDist = nbrPair.second;
            if (topDist + nbrDist < dist[nbrNode])
            {
                auto prevEntry = st.find({dist[nbrNode], nbrNode});
                if (prevEntry != st.end())
                {
                    st.erase(prevEntry);
                }
                dist[nbrNode] = topDist + nbrDist;
                st.insert({dist[nbrNode], nbrNode});
            }
        }
    }
    return reachableCities;
}
int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for (auto edge : edges)
    {
        int u = edge[0];
        int v = edge[1];
        int w = edge[2];
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    int city = 0;
    int minReachableCities = INT_MAX;
    for (int u = 0; u < n; u++)
    {
        int reachableCities = dijkstraShortPath(u, n, adjList, distanceThreshold);
        if (reachableCities <= minReachableCities)
        {
            minReachableCities = reachableCities;
            city = u;
        }
    }
    return city;
}

// USING FLOYD WARSHALL ALGORITHM - TC=O(V^3), SC=O(V^2)
// Steps:
// 1. Initialize a distance matrix where `dist[i][j]` represents the shortest distance between city `i` and city `j`.
// 2. Set each city's distance to itself as 0, and use the input edges to initialize the direct distances between connected cities.
// 3. Use the Floyd-Warshall algorithm to compute the shortest paths between all pairs of cities by considering each city as an intermediate node.
// 4. Count the number of reachable cities within the `distanceThreshold` for each city and track the city with the minimum reachable cities. If there's a tie, choose the city with the largest index.

int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold)
{
    vector<vector<int>> dist(n, vector<int>(n, INT_MAX));
    for (int i = 0; i < n; ++i)
    {
        dist[i][i] = 0;
    }
    for (const auto &edge : edges)
    {
        int u = edge[0], v = edge[1], w = edge[2];
        dist[u][v] = w;
        dist[v][u] = w;
    }
    for (int k = 0; k < n; ++k)
    {
        for (int i = 0; i < n; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                if (dist[i][k] != INT_MAX && dist[k][j] != INT_MAX)
                {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    int minReachableCities = INT_MAX;
    int bestCity = -1;
    for (int i = 0; i < n; ++i)
    {
        int reachableCities = 0;
        for (int j = 0; j < n; ++j)
        {
            if (dist[i][j] <= distanceThreshold)
            {
                reachableCities++;
            }
        }
        if (reachableCities <= minReachableCities)
        {
            minReachableCities = reachableCities;
            bestCity = i;
        }
    }
    return bestCity;
}