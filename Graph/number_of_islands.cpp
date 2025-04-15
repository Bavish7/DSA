#include<iostream>
using namespace std;

// NUMBER OF ISLANDS (LEETCODE 200)
// USING DFS TRAVERSAL - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. Define a DFS function to visit all connected land cells starting from a given cell.
//    - If the current cell is out of bounds, water ('0'), or already visited ('x'), return.
//    - Mark the current cell as visited by setting its value to 'x'.
//    - Recursively call DFS on all four possible neighboring cells (up, down, left, right).
// 2. In the main function (numIslands):
//    - Initialize a counter to track the number of islands (ans).
//    - Iterate through each cell in the grid:
//       - If the cell contains land ('1'), perform DFS starting from that cell to visit all connected land cells.
//       - Increment the island counter for each DFS call (each connected component of land).
// 3. Return the count of islands.

void dfs(vector<vector<char>> &grid, int i, int j)
{
    if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == '0' || grid[i][j] == 'x')
    {
        return;
    }
    grid[i][j] = 'x';
    dfs(grid, i - 1, j);
    dfs(grid, i + 1, j);
    dfs(grid, i, j - 1);
    dfs(grid, i, j + 1);
}
int numIslands(vector<vector<char>> &grid)
{
    int m = grid.size();
    int n = grid[0].size();
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1')
            {
                dfs(grid, i, j);
                ans++;
            }
        }
    }
    return ans;
}

// USING BFS TRAVERSAL - TC=O(M*N), SC=O(M*N)
// Steps:
// 1. Define a BFS function to explore all connected land cells starting from a given cell.
//    - Initialize a queue and mark the starting cell as visited.
//    - Enqueue the starting cell.
//    - While the queue is not empty:
//      - Dequeue a cell and explore its four neighbors (up, down, left, right).
//      - For each neighbor:
//        - If it is within bounds, is land ('1'), and not yet visited, mark it as visited and enqueue it.
// 2. In the main function (numIslands):
//    - Initialize a map to track visited cells.
//    - Initialize a counter to track the number of islands (count).
//    - Iterate through each cell in the grid:
//       - If the cell contains land ('1') and is not visited, perform BFS starting from that cell to explore all connected land cells.
//       - Increment the island counter for each BFS call (each connected component of land).
// 3. Return the count of islands.

void bfs(int i, int j, map<pair<int, int>, bool> &visited, vector<vector<char>> &grid)
{
    queue<pair<int, int>> q;
    visited[{i, j}] = true;
    q.push({i, j});
    while (!q.empty())
    {
        pair<int, int> frontNode = q.front();
        q.pop();
        int x = frontNode.first;
        int y = frontNode.second;
        int dx[] = {-1, 0, 1, 0};
        int dy[] = {0, 1, 0, -1};
        for (int k = 0; k < 4; k++)
        {
            int newX = x + dx[k];
            int newY = y + dy[k];
            if (newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] == '1' && !visited[{newX, newY}])
            {
                q.push({newX, newY});
                visited[{newX, newY}] = true;
            }
        }
    }
}
int numIslands(vector<vector<char>> &grid)
{
    map<pair<int, int>, bool> visited;
    int m = grid.size();
    int n = grid[0].size();
    int count = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (grid[i][j] == '1' && !visited[{i, j}])
            {
                bfs(i, j, visited, grid);
                count++;
            }
        }
    }
    return count;
}