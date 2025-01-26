#include<iostream>
using namespace std;

// REARRANGE ARRAY ELEMENTS BY SIGN (LEETCODE 2149)
// USING TWO POINTERS - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize an output array `ans` of the same size as the input array `nums` with default values.
// 2. Use two pointers: `posIndex` for placing positive numbers (starting at index 0)
//    and `negIndex` for placing negative numbers (starting at index 1).
// 3. Traverse the input array:
//    - If the current number is positive, place it at `posIndex` and increment `posIndex` by 2.
//    - If the current number is negative, place it at `negIndex` and increment `negIndex` by 2.
// 4. Return the `ans` array.

vector<int> rearrangeArray(vector<int> &nums)
{
    int n = nums.size();
    vector<int> ans(n, 0);
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] > 0)
        {
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
        else
        {
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
    }
    return ans;
}