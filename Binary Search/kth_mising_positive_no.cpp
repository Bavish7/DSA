#include<iostream>
using namespace std;

// KTH MISSING POSITIVE NUMBER (LEETCODE 1539)
// USING FOR LOOP - TC=O(N), SC=O(1)

// Steps:
// 1. Iterate through the array `arr` to track missing positive integers:
//    - If the current array element is less than or equal to `k`, it means the missing number count is adjusted (`k++`).
//    - Otherwise, return the current value of `k` as the missing positive integer.
// 2. If the loop completes without finding the result, return `k` (it accounts for remaining missing integers beyond the array's last value).

int findKthPositive(vector<int> &arr, int k)
{
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] <= k)
        {
            k++;
        }
        else
        {
            return k;
        }
    }
    return k;
}

// USING BINARY SEARCH - TC=O(LOGN), SC=O(1)
// Steps:
// 1. Use binary search to find the position where the `k`th missing positive integer should be:
//    - Compute the number of missing integers up to `arr[mid]` using the formula: `missing = arr[mid] - (mid + 1)`.
//    - If `missing < k`, move the search to the right half (`low = mid + 1`).
//    - Otherwise, move to the left half (`high = mid - 1`).
// 2. After the loop, `low` represents the count of numbers in the array before the `k`th missing integer.
// 3. Add `k` to `high+1` to compute the `k`th missing integer.
// 4. Return the result.

int findKthPositive(vector<int> &arr, int k)
{
    int low = 0, high = arr.size() - 1;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return k + high + 1;
}