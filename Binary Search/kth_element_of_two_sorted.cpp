#include<iostream>
using namespace std;

// KTH ELEMENT OF TWO SORTED ARRAYS
// USING BINARY SEARCH - TC=O(LOG(MIN(M,N))), SC=O(1)

// Steps:
// 1. Ensure `arr1` is the smaller array for optimized binary search.
// 2. Define the size of the combined array and calculate the left partition size (`left`).
// 3. Perform binary search on `arr1` to find the kth element:
//    - Define the search range (`low`, `high`) based on the kth element.
//    - Use `mid1` as the partition index for `arr1`, and derive `mid2` for `arr2` as `left - mid1`.
//    - Define values at the boundaries of partitions (`l1`, `l2`, `r1`, `r2`), assigning extreme values for out-of-bound indices.
// 4. Check if the partitions are valid:
//    - If `l1 <= r2` and `l2 <= r1`, return the maximum of `l1` and `l2`.
//    - If invalid, adjust the binary search range:
//      - If `l1 > r2`, move `high` to the left.
//      - Otherwise, move `low` to the right.
// 5. Return 0 as fallback (unreachable in valid cases).

int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
{
    if (n > m)
        return kthElement(arr2, arr1, m, n, k);
    int size = m + n;
    int low = max(0, k - m), high = min(k, n);
    int left = k;
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n)
            r1 = arr1[mid1];
        if (mid2 < m)
            r2 = arr2[mid2];
        if (mid1 - 1 >= 0)
            l1 = arr1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = arr2[mid2 - 1];
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}