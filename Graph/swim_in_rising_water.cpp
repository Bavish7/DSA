#include<iostream>
using namespace std;

// SWIM IN RISING WATER (LEETCODE 778)
// USING DIJKSTRA'S ALGORITHM. TC=O(N^2LOGN), SC=O(N^2)

// Steps:
// 1. Use Dijkstra’s algorithm with a min-heap to find the minimum elevation path in a grid.
// 2. Push the starting cell (0,0) into the priority queue with its elevation.
// 3. Use a `vis` matrix to track visited cells.
// 4. Process cells in increasing order of max elevation encountered.
// 5. Explore all 4 possible directions (up, down, left, right).
// 6. If the new cell is within bounds and unvisited, update the max elevation required and push it into the queue.
// 7. Stop when reaching the bottom-right cell and return the max elevation encountered.
// 8. If the loop completes without reaching (n-1, m-1), return -1

int swimInWater(vector<vector<int>> &grid)
{
    int n = grid.size();
    int m = grid[0].size();
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    pq.push({grid[0][0], {0, 0}});
    vis[0][0] = true;
    while (!pq.empty())
    {
        int maxDist = pq.top().first;
        int x = pq.top().second.first;
        int y = pq.top().second.second;
        pq.pop();
        if (x == n - 1 && y == m - 1)
            return maxDist;
        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dx[i];
            int newY = y + dy[i];
            if (newX >= 0 && newX < n && newY >= 0 && newY < m && !vis[newX][newY])
            {
                vis[newX][newY] = true;
                int newDist = max(maxDist, grid[newX][newY]);
                pq.push({newDist, {newX, newY}});
            }
        }
    }
    return -1;
}
