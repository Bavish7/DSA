#include<iostream>
using namespace std;

// MEDIAN IN A ROW-WISE SORTED MATRIX 
// USING NESTED FOR LOOPS - TC=O(N*M*LOG(M*N)), SC=O(M*N)

// Steps:
// 1. Flatten the matrix into a single array by iterating through all its elements.
// 2. Sort the flattened array in non-decreasing order.
// 3. Return the middle element of the sorted array as the median

int median(vector<vector<int>> &matrix, int m, int n)
{
    vector<int> arr;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            arr.push_back(matrix[i][j]);
        }
    }
    sort(arr.begin(), arr.end());
    return arr[(n * m) / 2];
}

// USING BINARY SEARCH - TC=O(M*LOG(MAX-MIN)*LOGN), SC=O(1)
// Steps:
// 1. Initialize `low` as the smallest element and `high` as the largest element in the matrix.
// 2. Perform binary search between `low` and `high` to find the median:
//    - Compute the middle value `mid`.
//    - Count the number of elements in the matrix ≤ `mid` using `upperBound` for each row.
//    - If the count is less than or equal to the required count (`req`), adjust `low`.
//    - Otherwise, adjust `high`.
// 3. When binary search completes, `low` will point to the median of the matrix.

int upperBound(vector<int> &arr, int x, int n)
{
    int low = 0, high = n - 1;
    int ans = n;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (arr[mid] > x)
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
int countSmallEqual(vector<vector<int>> &matrix, int m, int n, int mid)
{
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        cnt += upperBound(matrix[i], mid, n);
    }
    return cnt;
}
int median(vector<vector<int>> &matrix, int m, int n)
{
    int low = INT_MAX, high = INT_MIN;
    for (int i = 0; i < m; i++)
    {
        low = min(low, matrix[i][0]);
        high = max(high, matrix[i][n - 1]);
    }
    int req = (n * m) / 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int smallEqual = countSmallEqual(matrix, m, n, mid);
        if (smallEqual <= req)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}