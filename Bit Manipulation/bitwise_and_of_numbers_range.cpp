#include<iostream>
using namespace std;

// BITWISE AND OF NUMBERS RANGE (LEETCODE 201)
// USING BIT MANIPULATION - TC=O(LOG(RIGHT)), SC=O(1)

// Steps:
// 1. While `right > left`:
//    - Remove the lowest set bit from `right` using `right & (right - 1)`.
//    - This ensures we keep only the common prefix bits that match `left`.
// 2. Once `right <= left`, the remaining bits are the common prefix for the entire range.
// 3. Return `right` as the result of the range bitwise AND.

int rangeBitwiseAnd(int left, int right)
{
    while (right > left)
    {
        right &= (right - 1);
    }
    return right;
}