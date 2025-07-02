#include<iostream>
using namespace std;

// MOST STONES REMOVED WITH SAME ROW OR COLUMN (LEETCODE 947)
// USING DFS TRAVERSAL - TC=O(N^2), SC=O(N)

// Steps:
// 1. Treat each stone as a node. An edge exists between two stones if they share the same row or column.
// 2. Use DFS to find all stones connected to the current stone (same row or column).
// 3. Each DFS marks one connected component. We can remove (component size - 1) stones from each component.
// 4. Total removable stones = Total stones - Number of connected components.

void dfs(int index, vector<vector<int>> &stones, int row, int col, vector<bool> &vis)
{
    vis[index] = true;
    for (int i = 0; i < stones.size(); i++)
    {
        if (!vis[i])
        {
            int newRow = stones[i][0];
            int newCol = stones[i][1];
            if (newRow == row || newCol == col)
            {
                dfs(i, stones, newRow, newCol, vis);
            }
        }
    }
}
int removeStones(vector<vector<int>> &stones)
{
    int n = stones.size();
    vector<bool> vis(n, 0);
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (!vis[i])
        {
            int row = stones[i][0];
            int col = stones[i][1];
            dfs(i, stones, row, col, vis);
            count++;
        }
    }
    return n - count;
}

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