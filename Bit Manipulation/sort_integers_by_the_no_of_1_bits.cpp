#include<iostream>
using namespace std;

// SORT INTEGERS BY THE NUMBER OF 1 BITS (LEETCODE 1356)
// USING BIT MANIPULATION AND CUSTOM COMPARATOR - TC=O(N*LOGN), SC=O(1)

// Steps:
// 1. Define comparator `comp`:
//    - Count set bits in `a` and `b` using `__builtin_popcount`.
//    - If counts are equal, return the smaller number first.
//    - Otherwise, return the number with fewer set bits first.
// 2. Sort `arr` using this comparator.
// 3. Return the sorted array.

static bool comp(int &a, int &b)
{
    int countOnesA = __builtin_popcount(a);
    int countOnesB = __builtin_popcount(b);
    if (countOnesA == countOnesB)
    {
        return a < b;
    }
    return countOnesA < countOnesB;
}
vector<int> sortByBits(vector<int> &arr)
{
    sort(arr.begin(), arr.end(), comp);
    return arr;
}