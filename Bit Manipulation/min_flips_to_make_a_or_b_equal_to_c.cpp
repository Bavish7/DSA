#include<iostream>
using namespace std;

// MINIMUM FLIPS TO MAKE A OR B EQUAL TO C (LEETCODE 1318)
// USING BIT MANIPULATION - TC=O(D), SC=O(1)

// Steps:
// 1. Traverse bit-by-bit from LSB to MSB of `a`, `b`, and `c` simultaneously.
// 2. If the current bit in `c` is 1:
//     - Increment flips if both `a` and `b` have 0 at that bit (need at least one 1).
// 3. If the current bit in `c` is 0:
//     - Increment flips for each of `a` and `b` having 1 at that bit (need both 0).
// 4. Right shift all numbers to process the next bit.
// 5. Return total flips.

int minFlips(int a, int b, int c)
{
    int flips = 0;
    while (a != 0 || b != 0 || c != 0)
    {
        if ((c & 1) == 1)
        {
            if ((a & 1) == 0 && (b & 1) == 0)
                flips++;
        }
        else
        {
            if ((a & 1) == 1)
                flips++;
            if ((b & 1) == 1)
                flips++;
        }
        a >>= 1;
        b >>= 1;
        c >>= 1;
    }
    return flips;
}

// USING BIT MANIPULATION AND INBUILT FUNCTION - TC=O(1), SC=O(1)
// Steps:
// 1. `(a | b)` → bitwise OR to get bits that are 1 in either `a` or `b`.
// 2. `(a | b) ^ c` → XOR with `c` to find bits that differ from desired `c` (need flips).
// 3. `(a & b)` → find bits where both `a` and `b` have 1.
// 4. `(ans & temp)` → find bits that require **two flips** (both `a` and `b` have 1, but `c` wants 0).
// 5. `__builtin_popcount(ans)` → count bits needing at least 1 flip.
// 6. `__builtin_popcount(res)` → count extra flips needed for double-1 bits in step 4.
// 7. Return sum of both counts.

int minFlips(int a, int b, int c)
{
    int ans = ((a | b) ^ c);
    int temp = (a & b);
    int res = (ans & temp);
    return __builtin_popcount(ans) + __builtin_popcount(res);
}