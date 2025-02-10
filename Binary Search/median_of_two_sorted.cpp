#include<iostream>
using namespace std;

// MEDIAN OF TWO SORTED ARRAYS (LEETCODE 4)
// USING BINARY SEARCH - TC=O(LOG(MIN(M,N))), SC=O(1)

// Steps:
// 1. Ensure `nums1` is the smaller array for optimized binary search.
// 2. Define the size of the combined array and calculate the left partition size (`left`).
// 3. Perform binary search on `nums1` to find the correct partition:
//    - Use `mid1` as the partition index for `nums1`, and derive `mid2` for `nums2` as `left - mid1`.
//    - Define values at the boundaries of partitions (`l1`, `l2`, `r1`, `r2`), assigning extreme values for out-of-bound indices.
// 4. Check if the partitions are valid:
//    - If `l1 <= r2` and `l2 <= r1`, compute the median based on the total size:
//      - If odd, return the maximum of `l1` and `l2`.
//      - If even, return the average of the max of the left and the min of the right elements.
//    - If invalid, adjust the binary search range:
//      - If `l1 > r2`, move `high` to the left.
//      - Otherwise, move `low` to the right.
// 5. Return 0 as fallback (unreachable in valid cases).

double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2)
{
    int m = nums1.size(), n = nums2.size();
    if (m > n)
        return findMedianSortedArrays(nums2, nums1);
    int size = m + n;
    int low = 0, high = m;
    int left = (m + n + 1) / 2;
    while (low <= high)
    {
        int mid1 = (low + high) / 2;
        int mid2 = left - mid1;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < m)
            r1 = nums1[mid1];
        if (mid2 < n)
            r2 = nums2[mid2];
        if (mid1 - 1 >= 0)
            l1 = nums1[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = nums2[mid2 - 1];
        if (l1 <= r2 && l2 <= r1)
        {
            if (size % 2 != 0)
                return max(l1, l2);
            else
            {
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
            }
        }
        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}