#include<iostream>
using namespace std;

// MINIMUM NUMBER OF BIT FLIPS TO CONVERT NUMBER (LEETCODE 2220)
// USING BIT MANIPULATION - TC=O(31), SC=O(1)

// Steps:
// 1. Calculate the XOR of `start` and `goal` to find the bits that need to be flipped.
// 2. Initialize a variable `count` to store the number of bits that need to be flipped.
// 3. Iterate from 0 to 31 and check if the `i-th` bit of `ans` is set.
//    - If the bit is set, increment the `count`.
// 4. Return the `count` as the minimum number of bit flips required to convert `start` to `goal`.

int minBitFlips(int start, int goal)
{
    int ans = start ^ goal;
    int count = 0;
    for (int i = 0; i <= 31; i++)
    {
        if (ans & (1 << i))
        {
            count++;
        }
    }
    return count;
}