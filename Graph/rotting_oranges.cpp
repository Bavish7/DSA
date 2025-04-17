#include<iostream>
using namespace std;

// ROTTING ORANGES (LEETCODE 994)
// USING BFS TRAVERSAL -TC=O(M*N), SC=O(M*N)

// Steps:
// 1. Initialize a queue `q` for BFS traversal and a `visited` grid (initialized to the original `grid`) to track rotting and fresh oranges.
//    - `fresh` counter to keep track of the number of fresh oranges.
// 2. Traverse the grid to:
//    - Push all rotten oranges (value 2) into the queue.
//    - Count the total number of fresh oranges (value 1).
// 3. If there are no fresh oranges initially, return 0 (since no time is needed).
//    If there are no rotten oranges to start with but fresh oranges exist, return -1 (impossible to rot fresh oranges).
// 4. Initialize `minutes` to -1 (to count the time elapsed).
// 5. While the queue is not empty:
//    - Process all the oranges at the current level of BFS (i.e., all oranges that were added to the queue in the previous minute).
//    - For each orange, check its adjacent cells (up, down, left, right).
//      - If an adjacent cell contains a fresh orange, rot it by changing its value to 2, decrement the `fresh` counter, and add it to the queue.
//    - Increment the `minutes` counter after processing all oranges at the current level.
// 6. After the BFS completes:
//    - If there are no fresh oranges left, return `minutes` (total time needed to rot all oranges).
//    - If there are still fresh oranges left, return -1 (some oranges cannot be rotted).

int orangesRotting(vector<vector<int>> &grid)
{
    queue<pair<int, int>> q;
    vector<vector<int>> visited = grid;
    int fresh = 0;
    int m = grid.size();
    int n = grid[0].size();
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 2)
            {
                q.push({i, j});
            }
            if (visited[i][j] == 1)
            {
                fresh++;
            }
        }
    }
    if (fresh == 0)
    {
        return 0;
    }
    if (q.empty())
    {
        return -1;
    }
    int minutes = -1;
    while (!q.empty())
    {
        int size = q.size();
        while (size--)
        {
            pair<int, int> frontPair = q.front();
            q.pop();
            int x = frontPair.first;
            int y = frontPair.second;
            int dx[] = {-1, 0, 1, 0};
            int dy[] = {0, 1, 0, -1};
            for (int i = 0; i < 4; i++)
            {
                int newX = x + dx[i];
                int newY = y + dy[i];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && visited[newX][newY] == 1)
                {
                    visited[newX][newY] = 2;
                    fresh--;
                    q.push({newX, newY});
                }
            }
        }
        minutes++;
    }
    if (fresh == 0)
    {
        return minutes;
    }
    else
    {
        return -1;
    }
}