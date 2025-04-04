#include<iostream>
using namespace std;

// ALIEN DICTIONARY (LEETCODE 269)
// USING TOPOLOGICAL SORT - TC=O(V+E), SC=O(V)

// Steps:
//  1. Construct the adjacency list representing the precedence constraints between characters based on the given dictionary.
// 2. Calculate the in-degree of each node (character).
// 3. Use a queue to perform a Breadth-First Search (BFS) for topological sorting.
// 4. Append characters to the result string as they are processed in BFS order.
// 5. Return the topologically sorted string representing the alien language order.

string topSortBFS(unordered_map<int, list<int>> &adjList, int n)
{
    vector<int> indegree(n, 0);
    queue<int> q;
    for (auto it : adjList)
    {
        for (auto child : it.second)
        {
            indegree[child]++;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (indegree[i] == 0)
        {
            q.push(i);
        }
    }
    string ans = "";
    while (!q.empty())
    {
        int node = q.front();
        ans += char(node + 'a');
        q.pop();
        for (auto child : adjList[node])
        {
            indegree[child]--;
            if (indegree[child] == 0)
            {
                q.push(child);
            }
        }
    }
    return ans;
}
string getAlienLanguage(vector<string> &dictionary, int k)
{
    int n = dictionary.size();
    unordered_map<int, list<int>> adjList;
    for (int i = 0; i < n - 1; i++)
    {
        string first = dictionary[i];
        string second = dictionary[i + 1];
        int len = min(first.size(), second.size());
        for (int j = 0; j < len; j++)
        {
            if (first[j] != second[j])
            {
                adjList[first[j] - 'a'].push_back(second[j] - 'a');
                break;
            }
        }
    }
    return topSortBFS(adjList, k);
}