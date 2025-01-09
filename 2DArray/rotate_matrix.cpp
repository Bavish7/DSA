#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// ROTATE IMAGE (LEETCODE 48)
// USING TRANSPOSE AND REVERSING - TC=O(N^2), SC=O(1)

// Steps:
// 1. Determine the number of rows (and columns, since it's a square matrix) using 'matrix.size()'.
// 2. Swap elements across the diagonal (matrix[i][j] with matrix[j][i]) using nested loops for the top-left triangle.
// 3. Reverse the elements of each row to complete the 90-degree clockwise rotation.

void rotate(vector<vector<int>> &matrix)
{
    int row = matrix.size();
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < i; j++)
        {
            swap(matrix[i][j], matrix[j][i]);
        }
    }
    for (int i = 0; i < row; i++)
    {
        reverse(matrix[i].begin(), matrix[i].end());
    }
}