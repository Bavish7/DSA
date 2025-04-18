#include<iostream>
using namespace std;

// SURROUNDED REGIONS (LEETCODE 130)
// USING DFS TRAVERSAL - TC=O(N*M), SC=O(N*M)

// Steps:
// 1. Initialize a `vis` matrix to keep track of visited cells.
// 2. Perform a Depth-First Search (DFS) from all 'O' cells on the board's boundaries (first and last row/column).
//    - Mark cells visited during DFS to avoid reprocessing.
// 3. Traverse the entire board, and for any 'O' cell not visited, change it to 'X'.
//    - These are the cells surrounded by 'X' and hence should be flipped.

void dfs(int row, int col, int m, int n, vector<vector<char>> &board, vector<vector<int>> &vis)
{
    vis[row][col] = 1;
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + dx[i];
        int ncol = col + dy[i];
        if (nrow >= 0 && nrow < m && ncol >= 0 && ncol < n && board[nrow][ncol] == 'O' && vis[nrow][ncol] == 0)
        {
            dfs(nrow, ncol, m, n, board, vis);
        }
    }
}
void solve(vector<vector<char>> &board)
{
    int m = board.size();
    int n = board[0].size();
    vector<vector<int>> vis(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++)
    {
        if (vis[i][0] == 0 && board[i][0] == 'O')
        {
            dfs(i, 0, m, n, board, vis);
        }
        if (vis[i][n - 1] == 0 && board[i][n - 1] == 'O')
        {
            dfs(i, n - 1, m, n, board, vis);
        }
    }
    for (int j = 0; j < n; j++)
    {
        if (vis[0][j] == 0 && board[0][j] == 'O')
        {
            dfs(0, j, m, n, board, vis);
        }
        if (vis[m - 1][j] == 0 && board[m - 1][j] == 'O')
        {
            dfs(m - 1, j, m, n, board, vis);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (vis[i][j] == 0 && board[i][j] == 'O')
            {
                board[i][j] = 'X';
            }
        }
    }
}