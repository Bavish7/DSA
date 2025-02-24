#include<iostream>
using namespace std;

// DIVIDE TWO INTEGERS (LEETCODE 29)
// USING BIT MANIPULATION - TC=O((LOGN)^2), SC=O(1)

// Steps:
// 1. Handle edge case: If `dividend == divisor`, return 1 directly.
// 2. Determine the sign of the result using the signs of `dividend` and `divisor`.
// 3. Convert both `dividend` and `divisor` to their absolute values to simplify calculations.
// 4. Use bit manipulation to find the largest power of 2 such that `divisor * 2^count` is less than or equal to the `dividend`.
// 5. Subtract the shifted divisor (`divisor * 2^count`) from `dividend` and add `2^count` to the result.
// 6. Repeat until `dividend` becomes smaller than `divisor`.
// 7. Handle overflow for the maximum 32-bit integer range.
// 8. Apply the computed sign to the result and return it.

int divide(int dividend, int divisor)
{
    if (dividend == divisor)
        return 1;
    bool sign = true;
    if (dividend >= 0 && divisor < 0)
        sign = false;
    if (dividend < 0 && divisor > 0)
        sign = false;
    long n = labs(dividend);
    long d = labs(divisor);
    long ans = 0;
    while (n >= d)
    {
        int count = 0;
        while (n >= (d << (count + 1)))
        {
            count++;
        }
        ans += (1 << count);
        n = n - (d << count);
    }
    if (ans == (1 << 31) && sign)
    {
        return INT_MAX;
    }
    if (ans == (1 << 31) && !sign)
    {
        return INT_MIN;
    }
    return sign ? ans : -ans;
}