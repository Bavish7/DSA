#include<iostream>
using namespace std;

// DIAGONAL TRAVERSE (LEETCODE 498)
// USING SIMULATION - TC=O(M*N), SC=O(1)

// Steps:
// 1. Start from top-left cell (0,0).
// 2. Traverse diagonals in alternating directions:
//    - If (row+col) is even → move "up-right".
//    - If (row+col) is odd → move "down-left".
// 3. Handle boundary cases:
//    - If at last column → move down.
//    - If at first row → move right.
//    - If at last row → move right.
//    - If at first column → move down.
// 4. Repeat until all elements (m*n) are added into result[].

vector<int> findDiagonalOrder(vector<vector<int>> &matrix)
{
    if (matrix.empty() || matrix[0].empty())
        return {};
    int m = matrix.size(), n = matrix[0].size();
    vector<int> result(m * n);
    int row = 0, col = 0;
    for (int i = 0; i < m * n; i++)
    {
        result[i] = matrix[row][col];
        if ((row + col) % 2 == 0)
        {
            if (col == n - 1)
                row++;
            else if (row == 0)
                col++;
            else
            {
                row--;
                col++;
            }
        }
        else
        {
            if (row == m - 1)
                col++;
            else if (col == 0)
                row++;
            else
            {
                row++;
                col--;
            }
        }
    }
    return result;
}