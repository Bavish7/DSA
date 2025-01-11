#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// SPIRAL MATRIX (LEETCODE 54)
// USING WHILE LOOP - TC=O(ROW*COL), SC=O(1)

// Steps:
// 1. Initialize an empty vector 'ans'.
// 2. Set boundaries: 'startingRow', 'endingRow', 'startingCol', 'endingCol'.
// 3. Loop until 'count' equals total elements:
//    a. Traverse from left to right along 'startingRow', then increment 'startingRow'.
//    b. Traverse from top to bottom along 'endingCol', then decrement 'endingCol'.
//    c. Traverse from right to left along 'endingRow' (if applicable), then decrement 'endingRow'.
//    d. Traverse from bottom to top along 'startingCol' (if applicable), then increment 'startingCol'.
// 4. Return 'ans' containing elements in spiral order.

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    vector<int> ans;
    int row = matrix.size();
    int col = matrix[0].size();
    int count = 0;
    int total = row * col;
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = row - 1;
    int endingCol = col - 1;
    while (count < total)
    {
        for (int i = startingCol; count < total && i <= endingCol; i++)
        {
            ans.push_back(matrix[startingRow][i]);
            count++;
        }
        startingRow++;
        for (int i = startingRow; count < total && i <= endingRow; i++)
        {
            ans.push_back(matrix[i][endingCol]);
            count++;
        }
        endingCol--;
        for (int i = endingCol; count < total && i >= startingCol; i--)
        {
            ans.push_back(matrix[endingRow][i]);
            count++;
        }
        endingRow--;
        for (int i = endingRow; count < total && i >= startingRow; i--)
        {
            ans.push_back(matrix[i][startingCol]);
            count++;
        }
        startingCol++;
    }
    return ans;
}

// SPIRAL MATRIX 2 (LEETCODE 59)
// USING WHILE LOOP - TC=O(N^2), SC=O(N^2)
// Steps:
// 1. Initialize a matrix of size n x n with zeros.
// 2. Set boundaries: 'startingRow', 'endingRow', 'startingCol', 'endingCol'.
// 3. Initialize 'count' to 1 and loop until 'count' reaches n*n:
//    a. Fill from left to right along 'startingRow', then increment 'startingRow'.
//    b. Fill from top to bottom along 'endingCol', then decrement 'endingCol'.
//    c. Fill from right to left along 'endingRow' (if applicable), then decrement 'endingRow'.
//    d. Fill from bottom to top along 'startingCol' (if applicable), then increment 'startingCol'.
// 4. Return the generated spiral matrix.

vector<vector<int>> generateMatrix(int n)
{
    vector<vector<int>> matrix(n,vector<int>(n));
    int count = 1;
    int total = n * n;
    int startingRow = 0;
    int startingCol = 0;
    int endingRow = n - 1;
    int endingCol = n - 1;
    while (count <= total)
    {
        for (int i = startingCol; count <= total && i <= endingCol; i++)
        {
            matrix[startingRow][i] = count;
            count++;
        }
        startingRow++;
        for (int i = startingRow; count <= total && i <= endingRow; i++)
        {
            matrix[i][endingCol] = count;
            count++;
        }
        endingCol--;
        for (int i = endingCol; count <= total && i >= startingCol; i--)
        {
            matrix[endingRow][i] = count;
            count++;
        }
        endingRow--;
        for (int i = endingRow; count <= total && i >= startingRow; i--)
        {
            matrix[i][startingCol] = count;
            count++;
        }
        startingCol++;
    }
    return matrix;
}
