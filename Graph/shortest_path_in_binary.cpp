#include<iostream>
using namespace std;

// SHORTEST PATH IN BINARY MATRIX (LEETCODE 1091)
// USING BFS TRAVERSAL - TC=O(N^2), SC=O(N^2)

// Steps:
// 1. Check if the starting or ending cell is blocked. If either is blocked, return -1 as the path is not possible.
// 2. Initialize a queue for BFS, starting with the top-left corner (0,0) and an initial distance of 1.
// 3. Create a `visited` matrix to track visited cells and mark the starting cell as visited.
// 4. While the queue is not empty:
//    a. Extract the front element which contains the current position (row, col) and distance.
//    b. If the current cell is the bottom-right corner, return the distance as the shortest path is found.
//    c. Explore all 8 possible directions (including diagonals) from the current cell.
//    d. For each direction, check if the move is valid using the `isValid` function.
//    e. If valid, push the new position and updated distance into the queue and mark the cell as visited.
// 5. If the queue is empty and the bottom-right corner hasn't been reached, return -1 as no path exists.

bool isValid(int row, int col, int n, vector<vector<int>> &grid, vector<vector<int>> &visited)
{
    if (row >= 0 && row < n && col >= 0 && col < n && grid[row][col] == 0 && visited[row][col] != 1)
    {
        return true;
    }
    return false;
}
int shortestPathBinaryMatrix(vector<vector<int>> &grid)
{
    int n = grid.size();
    if (grid[0][0] != 0)
        return -1;
    if (grid[n - 1][n - 1] != 0)
        return -1;
    queue<pair<pair<int, int>, int>> q;
    vector<vector<int>> visited(n, vector<int>(n, 0));
    q.push({{0, 0}, 1});
    visited[0][0] = 1;
    while (!q.empty())
    {
        auto node = q.front();
        int row = node.first.first;
        int col = node.first.second;
        int dist = node.second;
        q.pop();
        if (row == n - 1 && col == n - 1)
        {
            return dist;
        }
        int dx[] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};
        for (int i = 0; i < 8; i++)
        {
            int newRow = row + dx[i];
            int newCol = col + dy[i];
            if (isValid(newRow, newCol, n, grid, visited))
            {
                q.push({{newRow, newCol}, dist + 1});
                visited[newRow][newCol] = 1;
            }
        }
    }
    return -1;
}