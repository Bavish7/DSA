#include<iostream>
using namespace std;

// 01 MATRIX (LEETCODE 542)
// USING BFS TRAVERSAL - TC=O(N*M), SC=O(N*M)

// Steps:
// 1. Initialize a `vis` matrix to keep track of visited cells and a `dist` matrix to store the distances.
// 2. Traverse the matrix to enqueue all cells with 0 and mark them as visited.
// 3. Use Breadth-First Search (BFS) from each 0 to calculate the minimum distance to the nearest 0 for all cells.
//    - For each cell, enqueue its neighbors if they are valid and not yet visited.
//    - Update their distances and mark them as visited.
// 4. Return the `dist` matrix containing the shortest distances from each cell to the nearest 0.

bool isValid(int row, int col, int m, int n, vector<vector<int>> &vis)
{
    if (row >= 0 && row < m && col >= 0 && col < n && vis[row][col] == 0)
    {
        return true;
    }
    return false;
}
vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
{
    int m = mat.size();
    int n = mat[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    vector<vector<int>> dist(m, vector<int>(n, 0));
    queue<pair<pair<int, int>, int>> q;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (mat[i][j] == 0)
            {
                q.push({{i, j}, 0});
                vis[i][j] = 1;
            }
            else
            {
                vis[i][j] = 0;
            }
        }
    }
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    while (!q.empty())
    {
        int row = q.front().first.first;
        int col = q.front().first.second;
        int steps = q.front().second;
        q.pop();
        dist[row][col] = steps;
        for (int i = 0; i < 4; i++)
        {
            int nrow = row + dx[i];
            int ncol = col + dy[i];
            if (isValid(nrow, ncol, m, n, vis))
            {
                vis[nrow][ncol] = 1;
                q.push({{nrow, ncol}, steps + 1});
            }
        }
    }
    return dist;
}