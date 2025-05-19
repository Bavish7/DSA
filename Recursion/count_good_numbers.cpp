#include<iostream>
using namespace std;

// COUNT GOOD NUMBERS(LEETCODE 1922)
// USING RECURSION - TC=O(LOGN), SC=O(LOGN)

// Steps:
// 1. Use modular exponentiation (`powerMod`) to compute powers efficiently under modulo.
//    - If the power `b` is 0, return 1 as the base case.
//    - Otherwise, compute the result recursively by dividing the exponent by 2.
//    - Handle even and odd cases separately to maintain modular arithmetic.
// 2. Calculate the number of valid digits for even-indexed positions (5 choices) and odd-indexed positions (4 choices):
//    - Use modular exponentiation to compute `5^(n+1)/2` and `4^(n/2)`.
// 3. Multiply these results under modulo to get the total count of "good numbers."

long long powerMod(int a, long long b, int mod)
{
    if (b == 0)
    {
        return 1;
    }
    long long x = powerMod(a, b / 2, mod);
    if (b % 2 == 0)
    {
        return (x * x) % mod;
    }
    else
    {
        return (((a * x) % mod) * x) % mod;
    }
}
int countGoodNumbers(long long n)
{
    int mod = 1e9 + 7;
    return (powerMod(5, (n + 1) / 2, mod) * powerMod(4, n / 2, mod)) % mod;
}