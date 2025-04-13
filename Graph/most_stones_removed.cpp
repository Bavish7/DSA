#include<iostream>
using namespace std;

// MOST STONES REMOVED WITH SAME ROW OR COLUMN (LEETCODE 947)
// USING DISJOINT SET - TC=O(N), SC=O(N)

// Steps:
// 1. Determine the maximum row and column values from the stone coordinates.
// 2. Initialize a DisjointSet with a size large enough to handle both row and column nodes uniquely.
// 3. For each stone, treat its row and column as nodes and union them, representing the stone's position.
// 4. Use a map to keep track of all unique nodes (row and column).
// 5. Count the number of connected components by checking if the node is its own parent.
// 6. Calculate the maximum number of stones that can be removed by subtracting the number of connected components from the total number of stones.

class DisjointSet
{
public:
    vector<int> rank, parent;
    DisjointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }
    }
    int findParent(int node)
    {
        if (node == parent[node])
        {
            return node;
        }
        return parent[node] = findParent(parent[node]);
    }
    void unionSet(int u, int v)
    {
        u = findParent(u);
        v = findParent(v);
        if (rank[u] < rank[v])
        {
            parent[u] = v;
        }
        else if (rank[u] > rank[v])
        {
            parent[v] = u;
        }
        else
        {
            parent[v] = u;
            rank[u]++;
        }
    }
};
class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int maxRow = 0;
        int maxCol = 0;
        for (auto it : stones)
        {
            maxRow = max(maxRow, it[0]);
            maxCol = max(maxCol, it[1]);
        }
        DisjointSet ds(maxRow + maxCol + 1);
        unordered_map<int, int> stoneNodes;
        for (auto it : stones)
        {
            int nodeRow = it[0];
            int nodeCol = it[1] + maxRow + 1;
            ds.unionSet(nodeRow, nodeCol);
            stoneNodes[nodeRow] = 1;
            stoneNodes[nodeCol] = 1;
        }
        int count = 0;
        for (auto it : stoneNodes)
        {
            if (ds.findParent(it.first) == it.first)
            {
                count++;
            }
        }
        return stones.size() - count;
    }
};