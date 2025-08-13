#include<iostream>
using namespace std;

// MINIMUM ONE BIT OPERATIONS TO MAKE INTEGERS ZERO (LEETCODE 1611)
// USING BIT MANIPULATION. TC=O(1), SC=O(1)

// Steps:
// 1. If `n == 0`, return 0 because no operation is needed.
// 2. Precompute `F[i]` where `F[i]` = minimum steps to reduce `1 << i` to 0.
//    - Formula: F[i] = 2 * F[i-1] + 1
// 3. Initialize `ans = 0` and `sign = 1`.
// 4. Traverse bits from MSB (30) down to LSB (0):
//    - If the current bit is set in `n`:
//        - If `sign > 0` → add `F[i]` to `ans`.
//        - If `sign < 0` → subtract `F[i]` from `ans`.
//        - Flip `sign` after processing the bit.
// 5. Return `ans` as the total minimum operations required.

int minimumOneBitOperations(int n)
{
    if (n == 0)
        return 0;
    vector<long long> F(31, 0);
    F[0] = 1;
    for (int i = 1; i <= 30; i++)
    {
        F[i] = 2 * F[i - 1] + 1;
    }
    int ans = 0;
    int sign = 1;
    for (int i = 30; i >= 0; i--)
    {
        int setBit = (n & (1 << i));
        if (setBit == 0)
            continue;
        if (sign > 0)
        {
            ans += F[i];
        }
        else
        {
            ans -= F[i];
        }
        sign = -sign;
    }
    return ans;
}