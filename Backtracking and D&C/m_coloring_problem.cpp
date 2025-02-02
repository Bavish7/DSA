#include<iostream>
using namespace std;

// M-COLORING PROBLEM
// USING RECURSION AND BACKTRACKING - TC=O(M^N), SC=O(N)

// Steps:
// 1. Use a recursive function `solve` to assign colors to each node of the graph.
//    - Base Case: If all nodes are colored, return true.
//    - For each color from 1 to m, check if it is safe to assign that color to the current node.
//    - If safe, assign the color to the current node and recursively call `solve` for the next node.
//    - Backtrack by unassigning the color after recursion.
// 2. Iterate through each node of the graph and assign colors using the `solve` function.
// 3. Return true if the graph can be colored with m colors, else return false.

bool isSafe(int node, vector<int> &color, vector<vector<int>> &mat, int n, int col)
{
    for (int k = 0; k < n; k++)
    {
        if (k != node && mat[k][node] == 1 && color[k] == col)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<int>> &mat, int m, int n, vector<int> &color, int node)
{
    if (node == n)
    {
        return true;
    }
    for (int i = 1; i <= m; i++)
    {
        if (isSafe(node, color, mat, n, i))
        {
            color[node] = i;
            if (solve(mat, m, n, color, node + 1))
            {
                return true;
            }
            color[node] = 0;
        }
    }
    return false;
}
string graphColoring(vector<vector<int>> &mat, int m)
{
    int n = mat.size();
    vector<int> color(n, 0);
    if (solve(mat, m, n, color, 0))
    {
        return "YES";
    }
    else
    {
        return "NO";
    }
}