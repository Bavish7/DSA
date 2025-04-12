#include<iostream>
using namespace std;

// MAXIMUM NUMBER OF POINTS FROM GRID QUERIES (LEETCODE 2503)
// USING PRIORITY QUEUE AND BFS TRAVERSAL - TC=O(M*N*LOG(M*N)+Q*LOGQ), SC=O(M*N)

// Steps:
// 1. Sort `queries` while keeping track of their original indices.
// 2. Use a min-heap `pq` (min-priority queue) to explore the grid in increasing order of values.
// 3. Start BFS from the top-left cell (0,0), pushing it into `pq`.
// 4. For each query:
//    - Expand all reachable cells with values < query value using BFS (priority queue).
//    - Count the number of such cells and store it in `ans[idx]`.
// 5. Return `ans`, which contains the count of accessible points for each query in the original order.

vector<int> maxPoints(vector<vector<int>> &grid, vector<int> &queries)
{
    int m = grid.size(), n = grid[0].size();
    vector<pair<int, int>> sortedQ;
    for (int i = 0; i < queries.size(); i++)
    {
        sortedQ.push_back({queries[i], i});
    }
    sort(sortedQ.begin(), sortedQ.end());
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    vector<vector<bool>> vis(m, vector<bool>(n, false));
    int points = 0;
    vector<int> ans(queries.size());
    pq.push({grid[0][0], {0, 0}});
    vis[0][0] = true;
    for (int i = 0; i < sortedQ.size(); i++)
    {
        int query = sortedQ[i].first;
        int idx = sortedQ[i].second;
        while (!pq.empty() && pq.top().first < query)
        {
            auto front = pq.top();
            int val = front.first;
            int row = front.second.first;
            int col = front.second.second;
            points++;
            pq.pop();
            int dx[4] = {-1, 0, 1, 0};
            int dy[4] = {0, 1, 0, -1};
            for (int j = 0; j < 4; j++)
            {
                int newRow = row + dx[j];
                int newCol = col + dy[j];
                if (newRow >= 0 && newRow < m && newCol >= 0 && newCol < n && !vis[newRow][newCol])
                {
                    vis[newRow][newCol] = true;
                    pq.push({grid[newRow][newCol], {newRow, newCol}});
                }
            }
        }
        ans[idx] = points;
    }
    return ans;
}