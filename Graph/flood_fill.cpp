#include<iostream>
using namespace std;

// FLOOD FILL (LEETCODE 733)
// USING DFS TRAVERSAL - TC=O(N), SC=O(N)

// Steps:
// 1. Create a copy of the input image called ans to store the result.
// 2. Identify the old color of the starting pixel at (sr, sc).
// 3. Call the dfs function to perform depth-first search and fill the region with the new color.
// 4. Return the modified image ans.

void dfs(int oldColor, int newColor, vector<vector<int>> &ans, vector<vector<int>> &image, int sr, int sc)
{
    ans[sr][sc] = newColor;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int newX = sr + dx[i];
        int newY = sc + dy[i];
        if (newX >= 0 && newY >= 0 && newX < image.size() && newY < image[0].size() && image[newX][newY] == oldColor && ans[newX][newY] != newColor)
        {
            dfs(oldColor, newColor, ans, image, newX, newY);
        }
    }
}
vector<vector<int>> floodFill(vector<vector<int>> &image, int sr, int sc, int color)
{
    vector<vector<int>> ans = image;
    int oldColor = image[sr][sc];
    int newColor = color;
    dfs(oldColor, newColor, ans, image, sr, sc);
    return ans;
}