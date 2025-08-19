#include<iostream>
using namespace std;

// MINIMUM ARRAY END (LEETCODE 3133)
// USING BIT MANIPULATION - TC=O(N), SC=O(1)

// Steps:
// 1. Start with num = x (given base).
// 2. For each step from 2 to n:
//    - Increment num by 1.
//    - Apply bitwise OR with x → ensures all bits set in x remain set in num.
// 3. After n-1 iterations, return num.

long long minEnd(int n, int x)
{
    long long num = x;
    for (int i = 1; i < n; i++)
    {
        num = (num + 1) | x;
    }
    return num;
}