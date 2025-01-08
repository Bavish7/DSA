#include<iostream>
using namespace std;

// FIND A PEAK ELEMENT II (LEETCODE 1901)
// USING BINARY SEARCH - TC=O(N*LOGM), SC=O(1)

// Steps:
// 1. Use binary search on the columns (`mid` column) to find a peak element.
// 2. For the current `mid` column, find the row index of the maximum element.
// 3. Compare the maximum element in the `mid` column with its neighbors (left and right):
//    - If it is greater than both, it is a peak; return its position.
//    - If it is smaller than the left neighbor, move the search to the left half (high = mid - 1).
//    - Otherwise, move the search to the right half (low = mid + 1).
// 4. If no peak is found, return {-1, -1} (should not occur for a valid input).

int findMaxRow(vector<vector<int>> &mat, int n, int m, int col)
{
    int maxValue = -1;
    int index = -1;
    for (int i = 0; i < n; i++)
    {
        if (mat[i][col] > maxValue)
        {
            maxValue = mat[i][col];
            index = i;
        }
    }
    return index;
}
vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();
    int low = 0, high = m - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int maxRowIndex = findMaxRow(mat, n, m, mid);
        int left = mid - 1 >= 0 ? mat[maxRowIndex][mid - 1] : -1;
        int right = mid + 1 < m ? mat[maxRowIndex][mid + 1] : -1;
        if (mat[maxRowIndex][mid] > left && mat[maxRowIndex][mid] > right)
        {
            return {maxRowIndex, mid};
        }
        else if (mat[maxRowIndex][mid] < left)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return {-1, -1};
}
