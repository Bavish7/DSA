#include<iostream>
using namespace std;

// SET MATRIX ZEROES (LEETCODE 73)
// USING ROW AND COL ARRAYS - TC=O(M*N), SC=O(M+N)

// Steps:
// 1. Create two auxiliary arrays `row` and `col` to mark rows and columns that need to be zeroed.
// 2. Traverse the matrix. If any element is 0, mark its row and column in `row` and `col` arrays.
// 3. Traverse the matrix again and set the elements to 0 if their row or column is marked in `row` or `col`.
// 4. The matrix is updated in-place.

void setZeroes(vector<vector<int>> &matrix)
{
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> col(n, 0);
    vector<int> row(m, 0);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (matrix[i][j] == 0)
            {
                row[i] = 1;
                col[j] = 1;
            }
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (row[i] == 1 || col[j] == 1)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

// USING IN-PLACE TRAVERSAL - TC=O(M*N), SC=O(1)
// Steps:
// 1. Use the first row and column to store markers indicating if a row/column should be zeroed.
// 2. Traverse the matrix to set these markers.
// 3. Traverse the matrix again in reverse order to apply the zeroing, using the markers from step 1.

void setZeroes(vector<vector<int>> &matrix)
{
    int col0 = 1, rows = matrix.size(), cols = matrix[0].size();
    for (int i = 0; i < rows; i++)
    {
        if (matrix[i][0] == 0)
            col0 = 0;
        for (int j = 1; j < cols; j++)
            if (matrix[i][j] == 0)
                matrix[i][0] = matrix[0][j] = 0;
    }
    for (int i = rows - 1; i >= 0; i--)
    {
        for (int j = cols - 1; j >= 1; j--)
            if (matrix[i][0] == 0 || matrix[0][j] == 0)
                matrix[i][j] = 0;
        if (col0 == 0)
            matrix[i][0] = 0;
    }
}