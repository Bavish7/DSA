#include<iostream>
using namespace std;

// PACIFIC ATLANTIC WATER FLOW (LEETCODE 417)
// USING DFS - TC=O(M*N), SC=O(M*N)

// Steps:
// 1. Create two boolean matrices `pacific` and `atlantic` to track visited cells for each ocean.
// 2. Perform DFS from the Pacific (left & top edges) and Atlantic (right & bottom edges).
// 3. A cell can flow to an ocean if its height is greater than or equal to the next cell in DFS.
// 4. After marking reachable cells, iterate over the matrix and collect cells that can reach both oceans.

void dfs(vector<vector<int>> &heights, vector<vector<bool>> &vis, int i, int j, int m, int n)
{
    if (i < 0 || i >= m || j < 0 || j >= n || vis[i][j])
        return;
    vis[i][j] = true;
    if (i + 1 < m && heights[i + 1][j] >= heights[i][j])
    {
        dfs(heights, vis, i + 1, j, m, n);
    }
    if (i - 1 >= 0 && heights[i - 1][j] >= heights[i][j])
    {
        dfs(heights, vis, i - 1, j, m, n);
    }
    if (j + 1 < n && heights[i][j + 1] >= heights[i][j])
    {
        dfs(heights, vis, i, j + 1, m, n);
    }
    if (j - 1 >= 0 && heights[i][j - 1] >= heights[i][j])
    {
        dfs(heights, vis, i, j - 1, m, n);
    }
}
vector<vector<int>> pacificAtlantic(vector<vector<int>> &heights)
{
    vector<vector<int>> ans;
    int m = heights.size();
    int n = heights[0].size();
    vector<vector<bool>> pacific(m, vector<bool>(n, false));
    vector<vector<bool>> atlantic(m, vector<bool>(n, false));
    for (int i = 0; i < m; i++)
    {
        dfs(heights, pacific, i, 0, m, n);
        dfs(heights, atlantic, i, n - 1, m, n);
    }
    for (int i = 0; i < n; i++)
    {
        dfs(heights, pacific, 0, i, m, n);
        dfs(heights, atlantic, m - 1, i, m, n);
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (pacific[i][j] && atlantic[i][j])
            {
                ans.push_back({i, j});
            }
        }
    }
    return ans;
}