#include<iostream>
using namespace std;

// NUMBER OF ENCLAVES (LEETCODE 1020)
// USING DFS TRAVERSAL - TC=O(N*M), SC=O(N*M)

// Steps:
// 1. Initialize a `vis` matrix to keep track of visited cells.
// 2. Use Depth-First Search (DFS) to mark all land cells ('1's) connected to the borders as visited.
// 3. Traverse the first and last row, and first and last column, to perform DFS on all unvisited land cells, ensuring any land connected to the border is marked.
// 4. Count and return the number of unvisited land cells, which represent enclaves (land cells not connected to the border).

void dfs(int row, int col, int m, int n, vector<vector<int>> &grid, vector<vector<int>> &vis)
{
    vis[row][col] = 1;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && grid[nrow][ncol] == 1 && vis[nrow][ncol] == 0)
        {
            dfs(nrow, ncol, m, n, grid, vis);
        }
    }
}
int numEnclaves(vector<vector<int>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        if (vis[i][0] == 0 && grid[i][0] == 1)
        {
            dfs(i, 0, m, n, grid, vis);
        }
        if (vis[i][n - 1] == 0 && grid[i][n - 1] == 1)
        {
            dfs(i, n - 1, m, n, grid, vis);
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (vis[0][j] == 0 && grid[0][j] == 1)
        {
            dfs(0, j, m, n, grid, vis);
        }
        if (vis[m - 1][j] == 0 && grid[m - 1][j] == 1)
        {
            dfs(m - 1, j, m, n, grid, vis);
        }
    }
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0 && grid[i][j] == 1)
            {
                count++;
            }
        }
    }
    return count;
}