#include<iostream>
using namespace std;

// CHOCOLATES PROBLEM 
// USING FIXED SIZE SLIDING WINDOW - TC=O(N*LOGN), SC=O(1)

// Steps:
// 1. Sort the array of chocolates. This ensures that the difference between the maximum and minimum chocolates in any subarray of size `m` is minimized.
// 2. Initialize two pointers, `i` and `j`, where `i` is the start of the current window and `j` is the end of the current window of size `m`.
// 3. Initialize `mini` to a very large value to keep track of the minimum difference.
// 4. Slide the window across the sorted array:
//    - Calculate the difference between the chocolates at the end and start of the window.
//    - Update `mini` if the current difference is smaller.
//    - Move the window forward by incrementing both `i` and `j`.
// 5. Return the minimum difference found.

int findMinDiff(int n, int m, vector<int> chocolates)
{
    sort(chocolates.begin(), chocolates.end());
    int i = 0;
    int j = m - 1;
    int mini = INT_MAX;
    while (j < chocolates.size())
    {
        int diff = chocolates[j] - chocolates[i];
        mini = min(mini, diff);
        i++;
        j++;
    }
    return mini;
}