#include<iostream>
using namespace std;

// NUMBER OF ISLANDS II
// USING DISJOINT SET - TC=O(Q), SC=O(N*M)

// Steps:
// 1. Initialize a grid `vis` to track land cells and a `count` to track islands.
// 2. Use `DisjointSet` for union-find operations on a grid treated as a flat array.
// 3. Iterate over the list of positions `q`:
//    - For each position, if it's already land, append the current island count to `ans`.
//    - Otherwise, mark it as land, increment `count`, and check its four neighbors.
//    - If a neighbor is land and not in the same set, union them and decrement `count`.
// 4. Append the updated `count` to `ans` after processing each position.

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
bool isValid(int newRow, int newCol, int n, int m, vector<vector<int>> &vis)
{
    if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && vis[newRow][newCol] == 1)
    {
        return true;
    }
    return false;
}
vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q)
{
    vector<vector<int>> vis(n, vector<int>(m, 0));
    int count = 0;
    vector<int> ans;
    DisjointSet ds(n * m);
    for (auto it : q)
    {
        int row = it[0];
        int col = it[1];
        if (vis[row][col] == 1)
        {
            ans.push_back(count);
            continue;
        }
        vis[row][col] = 1;
        count++;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            if (isValid(newRow, newCol, n, m, vis))
            {
                int nodeNo = row * m + col;
                int newNode = newRow * m + newCol;
                if (ds.findParent(nodeNo) != ds.findParent(newNode))
                {
                    count--;
                    ds.unionSet(nodeNo, newNode);
                }
            }
        }
        ans.push_back(count);
    }
    return ans;
}