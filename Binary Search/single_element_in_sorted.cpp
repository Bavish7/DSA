#include<iostream>
using namespace std;

// SINGLE ELEMENT IN A SORTED ARRAY (LEETCODE 540)
// USING BINARY SEARCH - TC=O(LOGN), SC=O(1)

// Steps:
// 1. Handle edge cases where the single element is at the beginning or the end of the array:
//    - If the array has one element, return it.
//    - If the first element is unique, return it.
//    - If the last element is unique, return it.
// 2. Initialize `low` to 1 and `high` to `n-2` to focus the binary search on the middle part of the array.
// 3. Perform binary search while `low <= high`:
//    - Calculate `mid` as the middle index.
//    - If `nums[mid]` is not equal to its neighbors (`nums[mid-1]` and `nums[mid+1]`), return `nums[mid]` as it is the unique element.
//    - Check the pattern of pairs:
//       - If `mid` is odd and matches `nums[mid-1]`, or if `mid` is even and matches `nums[mid+1]`, the single element is in the right half, so update `low = mid + 1`.
//       - Otherwise, the single element is in the left half, so update `high = mid - 1`.
// 4. If no unique element is found (edge case), return -1.

int singleNonDuplicate(vector<int> &nums)
{
    int n = nums.size();
    if (n == 1)
        return nums[0];
    if (nums[0] != nums[1])
        return nums[0];
    if (nums[n - 1] != nums[n - 2])
        return nums[n - 1];
    int low = 1, high = n - 2;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return nums[mid];
        }
        if ((mid % 2 == 1 && nums[mid] == nums[mid - 1]) || (mid % 2 == 0 && nums[mid] == nums[mid + 1]))
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return -1;
}