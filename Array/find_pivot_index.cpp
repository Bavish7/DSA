#include<iostream>
using namespace std;

// FIND PIVOT INDEX (LEETCODE 724)
// USING PREFIX SUM - TC=O(N), SC=O(N)

// Steps:
// 1. Calculate the prefix sums for the left and right parts of the array.
// 2. Iterate through the array and compute the prefix sums for the left part.
// 3. Iterate through the array backwards and compute the prefix sums for the right part.
// 4. Compare the prefix sums of left and right parts at each index to find the pivot index.
// 5. Return the index if found, otherwise return -1.

int pivotIndex(vector<int> &nums)
{
    int n = nums.size();
    vector<int> left(n, 0);
    vector<int> right(n, 0);
    for (int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] + nums[i - 1];
    }
    for (int j = n - 2; j >= 0; j--)
    {
        right[j] = right[j + 1] + nums[j + 1];
    }
    for (int k = 0; k < n; k++)
    {
        if (left[k] == right[k])
        {
            return k;
        }
    }
    return -1;
}