#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// RAT IN A MAZE
// USING RECURSION AND BACKTRACKING - TC=O(4^(N^2)), SC=O(N*M)

// Steps of the logic:
// 1. **isSafe**: Check if a cell (x, y) is within bounds, not visited, and open (value 1).
// 2. **solve**:
//    - **Base Case**: If the destination (bottom-right corner) is reached, add the path to the result list.
//    - Mark the current cell as visited.
//    - Explore the four possible directions (Down, Up, Left, Right).
//    - For each valid move, update the path, recursively call solve, and backtrack by removing the last move.
//    - Unmark the current cell as visited before exploring other paths.
// 3. **searchMaze**:
//    - Initialize the visited matrix and path string.
//    - Start solving the maze from the top-left corner.
//    - Sort the result paths in lexicographical order before returning.

bool isSafe(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> &arr)
{
    if ((x >= 0 && x < n) && (y >= 0 && y < n) && visited[x][y] == 0 && arr[x][y] == 1)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void solve(vector<vector<int>> &arr, vector<string> &ans, int n, int x, int y, vector<vector<int>> visited, string path)
{
    if (x == n - 1 && y == n - 1)
    {
        ans.push_back(path);
        return;
    }
    visited[x][y] = 1;
    // Down
    int newx = x + 1;
    int newy = y;
    if (isSafe(newx, newy, n, visited, arr))
    {
        path.push_back('D');
        solve(arr, ans, n, newx, newy, visited, path);
        path.pop_back();
    }
    // Up
    newx = x - 1;
    newy = y;
    if (isSafe(newx, newy, n, visited, arr))
    {
        path.push_back('U');
        solve(arr, ans, n, newx, newy, visited, path);
        path.pop_back();
    }
    // Left
    newx = x;
    newy = y - 1;
    if (isSafe(newx, newy, n, visited, arr))
    {
        path.push_back('L');
        solve(arr, ans, n, newx, newy, visited, path);
        path.pop_back();
    }
    // Right
    newx = x;
    newy = y + 1;
    if (isSafe(newx, newy, n, visited, arr))
    {
        path.push_back('R');
        solve(arr, ans, n, newx, newy, visited, path);
        path.pop_back();
    }
    visited[x][y] = 0;
}
vector<string> searchMaze(vector<vector<int>> &arr, int n)
{
    vector<string> ans;
    if (arr[0][0] == 0)
    {
        return ans;
    }
    int srcx = 0;
    int srcy = 0;
    vector<vector<int>> visited = arr;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            visited[i][j] = 0;
        }
    }
    string path = "";
    solve(arr, ans, n, srcx, srcy, visited, path);
    sort(ans.begin(), ans.end());
    return ans;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> arr = {{1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1}};
    vector<string> ans;
    ans = searchMaze(arr, n);
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << " ";
    }
}