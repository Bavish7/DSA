#include<iostream>
using namespace std;

// MAXIMUM XOR PRODUCT (LEETCODE 2939)
// USING BIT MANIPULATION AND GREEDY APPROACH - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize two numbers `aXorx` and `bXorx` as XOR results of `a` and `b` with `x`.
// 2. For bits from 49 down to `n`:
//    - If `a` has the bit set → flip it in `aXorx`.
//    - If `b` has the bit set → flip it in `bXorx`.
// 3. For bits from `n-1` down to 0:
//    - If both bits in `a` and `b` are same → set the bit in both `aXorx` and `bXorx`.
//    - Otherwise, set the bit in the smaller number so far (greedy approach).
// 4. Take modulo for `aXorx` and `bXorx` to avoid overflow.
// 5. Return `(aXorx * bXorx) % mod` as the maximum possible product.

int mod = 1e9 + 7;
typedef long long ll;
int maximumXorProduct(long long a, long long b, int n)
{
    ll aXorx = 0, bXorx = 0;
    for (ll i = 49; i >= n; i--)
    {
        bool aBit = ((a >> i) & 1) > 0;
        bool bBit = ((b >> i) & 1) > 0;
        if (aBit)
        {
            aXorx = (aXorx ^ (1ll << i));
        }
        if (bBit)
        {
            bXorx = (bXorx ^ (1ll << i));
        }
    }
    for (ll i = n - 1; i >= 0; i--)
    {
        bool aBit = ((a >> i) & 1) > 0;
        bool bBit = ((b >> i) & 1) > 0;
        if (aBit == bBit)
        {
            aXorx = (aXorx ^ (1ll << i));
            bXorx = (bXorx ^ (1ll << i));
            continue;
        }
        if (aXorx > bXorx)
        {
            bXorx = (bXorx ^ (1ll << i));
        }
        else
        {
            aXorx = (aXorx ^ (1ll << i));
        }
    }
    aXorx = (aXorx) % mod;
    bXorx = (bXorx) % mod;
    return (aXorx * bXorx) % mod;
}