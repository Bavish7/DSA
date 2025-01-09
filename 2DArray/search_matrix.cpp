#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// SEARCH A 2D MATRIX (LEETCODE 74)
// USING BINARY SEARCH - TC=O(LOG(ROW*COL)), SC=O(1)

// Steps:
// 1. Determine the number of rows ('row') and columns ('col') in the matrix.
// 2. Initialize 'start' to 0 and 'end' to (row * col - 1) for binary search across flattened matrix indices.
// 3. Perform binary search:
//    - Calculate 'mid' as the middle index between 'start' and 'end'.
//    - Convert 'mid' to matrix coordinates using 'mid / col' (row index) and 'mid % col' (column index).
//    - Retrieve matrix element at matrix[mid / col][mid % col].
//    - Adjust 'start' or 'end' based on comparison of retrieved element with 'target'.
// 4. Return true if 'target' is found, false if 'start' exceeds 'end'.

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int start = 0;
    int end = row * col - 1;
    int mid = start + (end - start) / 2;
    while (start <= end)
    {
        int element = matrix[mid / col][mid % col];
        if (element == target)
        {
            return true;
        }
        else if (element < target)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
        mid = start + (end - start) / 2;
    }
    return false;
}
int main(){
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int target;
    cin >> target;
    cout << searchMatrix(matrix, target);
}

// SEARCH A 2D MATRIX 2 (LEETCODE 240)
// USING BINARY SEARCH - TC=O(ROW+COL), SC=O(1)

// Steps:
// 1. Determine the number of rows ('row') and columns ('col') in the matrix.
// 2. Initialize 'rowIndex' to 0 (starting from the first row) and 'colIndex' to col-1 (starting from the last column).
// 3. Perform search:
//    - Retrieve the element at matrix[rowIndex][colIndex].
//    - If element equals 'target', return true.
//    - If element is less than 'target', increment 'rowIndex' to move down the matrix.
//    - If element is greater than 'target', decrement 'colIndex' to move left across the matrix.
// 4. Continue the loop until 'rowIndex' exceeds 'row' or 'colIndex' falls below 0, then return false.

bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int row = matrix.size();
    int col = matrix[0].size();
    int rowIndex = 0;
    int colIndex = col-1;
    while (rowIndex < row && colIndex >= 0)
    {
        int element = matrix[rowIndex][colIndex];
        if (element == target)
        {
            return true;
        }
        else if (element < target)
        {
            rowIndex++;
        }
        else
        {
            colIndex--;
        }
    }
    return false;
}
