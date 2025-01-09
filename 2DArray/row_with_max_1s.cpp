#include<iostream>
using namespace std;

// ROW WITH MAXIMUM 1S
// USING BINARY SEARCH - TC=O(N*LOG(M)), SC=O(1)

// Steps:
// 1. Use a helper function `lowerBound` (Binary Search) to find the first index of 1 in a row.
// 2. For each row in the matrix:
//    - Calculate the number of 1s using `m - lowerBound`.
//    - Update the maximum count of 1s and the corresponding row index if the current row has more 1s.
// 3. Return the index of the row with the maximum number of 1s, or -1 if all rows are empty.

int lowerBound(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int cnt_max = 0, index = -1;
    for (int i = 0; i < n; i++)
    {
        int cnt_ones = m - lowerBound(matrix[i], m, 1);
        if (cnt_ones > cnt_max)
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
}

// USING BINARY SEARCH - TC=O(N+M), SC=O(1)
// Steps:
// 1. Start from the top-right corner of the matrix (i=0, j=m-1).
// 2. While within matrix bounds:
//    - If the current element is 1, move left (j--) and update the row index.
//    - If the current element is 0, move down (i++).
// 3. Return the index of the row with the maximum number of 1s, or -1 if no 1s are found.

int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{
    int cnt_max = 0, index = -1;
    int i = 0, j = m - 1;
    while (i < n && j >= 0)
    {
        if (matrix[i][j] == 1)
        {
            j--;
            index = i;
        }
        else
        {
            i++;
        }
    }
    return index;
}