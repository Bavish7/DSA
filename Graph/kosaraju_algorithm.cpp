#include<iostream>
#include <stack>
#include <list>
#include <unordered_map>
using namespace std;

// COUNT STRONGLY CONNECTED COMPONENTS
// USING KOSARAJU ALGORITHM - TC=O(V+E), SC=O(V+E)

// Steps:
// 1. Build the adjacency list adjList for the graph using the input edges.
// 2. Perform a Depth-First Search (DFS) to fill a stack with nodes ordered by finish time.
//    - Mark nodes as visited during traversal.
// 3. Reverse the direction of all edges to create a new adjacency list newAdj.
// 4. Perform DFS on nodes popped from the stack in step 2 (using newAdj).
//    - Count each traversal as a new strongly connected component (SCC).
// 5. Return the count of strongly connected components.

void dfs(int node, stack<int> &ordering, unordered_map<int, bool> &visited, unordered_map<int, list<int>> &adjList)
{
    visited[node] = true;
    for (auto nbr : adjList[node])
    {
        if (!visited[nbr])
        {
            dfs(nbr, ordering, visited, adjList);
        }
    }
    ordering.push(node);
}
void dfs2(int node, unordered_map<int, bool> &newVisited, unordered_map<int, list<int>> &newAdj)
{
    newVisited[node] = true;
    for (auto nbr : newAdj[node])
    {
        if (!newVisited[nbr])
        {
            dfs2(nbr, newVisited, newAdj);
        }
    }
}
int stronglyConnectedComponents(int v, vector<vector<int>> &edges)
{
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        adjList[u].push_back(v);
    }
    stack<int> ordering;
    unordered_map<int, bool> visited;
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
        {
            dfs(i, ordering, visited, adjList);
        }
    }
    unordered_map<int, list<int>> newAdj;
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0];
        int v = edges[i][1];
        newAdj[v].push_back(u);
    }
    int count = 0;
    unordered_map<int, bool> newVisited;
    while (!ordering.empty())
    {
        int node = ordering.top();
        ordering.pop();
        if (!newVisited[node])
        {
            dfs2(node, newVisited, newAdj);
            count++;
        }
    }
    return count;
}