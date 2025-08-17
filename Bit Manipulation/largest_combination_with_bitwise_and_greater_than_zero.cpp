#include<iostream>
using namespace std;

// LARGEST COMBINATION WITH BITWISE AND GREATER THAN ZERO (LEETCODE 2275)
// USING BIT MANIPULATION - TC=O(N), SC=O(1)

// Steps:
// 1. For each bit position (0 → 31), check how many numbers have that bit set.
// 2. Count set bits for current position across all candidates.
// 3. Track the maximum count among all bit positions.
// 4. Return this maximum → it represents the largest subset where all numbers share that bit.

int largestCombination(vector<int> &candidates)
{
    int maxCount = 0;
    for (int i = 0; i < 32; i++)
    {
        int count = 0;
        for (int &num : candidates)
        {
            if (num & (1 << i))
                count++;
        }
        maxCount = max(maxCount, count);
    }
    return maxCount;
}