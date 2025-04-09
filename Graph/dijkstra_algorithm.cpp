#include<iostream>
using namespace std;

// SHORTEST PATH IN A WEIGHTED UNDIRECTED GRAPH USING DIJKSTRA'S ALGORITHM 
// USING PRIORITY QUEUE - TC=O(E*LOGV), SC=O(V)

// Steps:
// 1. Build the adjacency list from the input edges.
// 2. Initialize a distance vector `dist` with `INT_MAX` for all nodes, and set `dist[source]` to 0.
// 3. Use a min-heap (priority queue) to process nodes, starting with the source node.
// 4. While the min-heap is not empty:
//    a. Extract the node with the smallest distance.
//    b. For each neighbor of this node, calculate the potential new distance.
//    c. If the new distance is smaller, update the distance and push the neighbor with the new distance into the heap.
// 5. Return the distance vector after processing all nodes.

vector<int> dijkstraAlgo(int vertices, int source, unordered_map<int, list<pair<int, int>>> &adjList)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
    vector<int> dist(vertices, INT_MAX);
    minHeap.push({0, source});
    dist[source] = 0;
    while (!minHeap.empty())
    {
        auto top = minHeap.top();
        int currDist = top.first;
        int currNode = top.second;
        minHeap.pop();
        for (auto nbr : adjList[currNode])
        {
            int nbrNode = nbr.first;
            int nbrDist = nbr.second;
            if (currDist + nbrDist < dist[nbrNode])
            {
                dist[nbrNode] = currDist + nbrDist;
                minHeap.push({dist[nbrNode], nbrNode});
            }
        }
    }
    return dist;
}
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> adjList;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int w = vec[i][2];
        adjList[u].push_back({v, w});
        adjList[v].push_back({u, w});
    }
    return dijkstraAlgo(vertices, source, adjList);
}

// USING SET - TC=O(E*LOGV), SC=O(V)
// Steps:
// 1. Create adjacency list adj from the given edges for an undirected graph.
// 2. Initialize the distance vector dist with a large value (infinity) for all vertices except the source vertex. Set dist[source] = 0.
// 3. Use a set st to keep track of the minimum distance vertex to be processed next:
//    a. Insert the source vertex with distance 0 into the set.
// 4. While the set is not empty:
//    a. Extract the vertex with the smallest distance (topNode) from the set.
//    b. For each neighbor (nbrNode) of topNode, update the distance if a shorter path is found:
//       - If dist[topNode] + weight of edge to nbrNode < dist[nbrNode], update dist[nbrNode] and insert it into the set.
// 5. Return the distance vector dist, which contains the shortest path distances from the source vertex.

vector<int> dijkstraShortPath(int vertices, int source, unordered_map<int, list<pair<int, int>>> &adj)
{
    vector<int> dist(vertices, INT_MAX);
    set<pair<int, int>> st;
    st.insert({0, source});
    dist[source] = 0;
    while (!st.empty())
    {
        auto topElement = st.begin();
        pair<int, int> topPair = *topElement;
        int topDist = topPair.first;
        int topNode = topPair.second;
        st.erase(st.begin());
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
    return dist;
}
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source)
{
    unordered_map<int, list<pair<int, int>>> adj;
    for (int i = 0; i < edges; i++)
    {
        int u = vec[i][0];
        int v = vec[i][1];
        int wt = vec[i][2];
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    vector<int> ans;
    ans = dijkstraShortPath(vertices, source, adj);
    return ans;
}