#include<iostream>
#include <unordered_map>
#include <list>
#include<queue>
using namespace std;

// COURSE SCHEDULE (LEETCODE 207)
// USING TOPOLOGICAL SORT WITH BFS - O(V+E), SC=O(V)

// Steps:
// 1. Create an adjacency list adjList from the prerequisites.
// 2. Perform a topological sort using BFS:
//    a. Calculate the in-degrees of all vertices.
//    b. Add all vertices with 0 in-degree to a queue.
//    c. Process each vertex in the queue:
//       - Add it to the answer list ans.
//       - Reduce the in-degree of its neighbors.
//       - If a neighbor's in-degree becomes 0, add it to the queue.
// 3. Check if the topological sort includes all courses:
//    a. If the size of ans equals numCourses, return true (all courses can be finished).
//    b. Otherwise, return false (not all courses can be finished).

void topSortBFS(unordered_map<int, list<int>> &adj, int v, vector<int> &ans)
{
    queue<int> q;
    unordered_map<int, int> indegree;
    for (auto i : adj)
    {
        for (auto neighbour : i.second)
        {
            indegree[neighbour]++;
        }
    }
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for (auto neighbour : adj[frontNode])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
}
bool canFinish(int numCourses, vector<vector<int>> &prerequisites)
{
    unordered_map<int, list<int>> adjList;
    int n = prerequisites.size();
    for (auto i : prerequisites)
    {
        int u = i[0];
        int v = i[1];
        adjList[v].push_back(u);
    }
    vector<int> ans;
    topSortBFS(adjList, numCourses, ans);
    if (ans.size() == numCourses)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// COURSE SCHEDULE II (LEETCODE 210)
// USING TOPOLOGICAL SORT WITH BFS - O(V+E), SC=O(V)

// Steps:
// 1. Create an adjacency list adjList from the prerequisites.
// 2. Perform a topological sort using BFS:
//    a. Calculate the in-degrees of all vertices.
//    b. Add all vertices with 0 in-degree to a queue.
//    c. Process each vertex in the queue:
//       - Add it to the answer list ans.
//       - Reduce the in-degree of its neighbors.
//       - If a neighbor's in-degree becomes 0, add it to the queue.
// 3. Check if the topological sort includes all courses:
//    a. If the size of ans equals numCourses, return ans (order of courses to finish).
//    b. Otherwise, return an empty vector (not all courses can be finished).

vector<int> topSortBFS(unordered_map<int, list<int>> &adj, int v)
{
    queue<int> q;
    vector<int> indegree(v);
    for (auto i : adj)
    {
        for (auto neighbour : i.second)
        {
            indegree[neighbour]++;
        }
    }
    for (int i = 0; i < v; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    vector<int> ans;
    while (!q.empty())
    {
        int frontNode = q.front();
        q.pop();
        ans.push_back(frontNode);
        for (auto neighbour : adj[frontNode])
        {
            indegree[neighbour]--;
            if (indegree[neighbour] == 0)
            {
                q.push(neighbour);
            }
        }
    }
    return ans;
}
vector<int> findOrder(int numCourses, vector<vector<int>> &prerequisites)
{
    unordered_map<int, list<int>> adjList;
    int n = prerequisites.size();
    for (auto i : prerequisites)
    {
        int u = i[0];
        int v = i[1];
        adjList[v].push_back(u);
    }
    vector<int> ans;
    ans = topSortBFS(adjList, numCourses);
    if (ans.size() == numCourses)
    {
        return ans;
    }
    else
    {
        return {};
    }
}