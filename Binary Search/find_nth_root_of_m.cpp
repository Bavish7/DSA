#include<iostream>
using namespace std;

// FIND NTH ROOT OF M
// USING BINARY SEARCH - TC=O(N*LOGM), SC=O(1)

// Steps:
// 1. Define a helper function `func(mid, n, m)` to calculate `mid^n` and compare it with `m`:
//    - Return 1 if `mid^n` equals `m`.
//    - Return 2 if `mid^n` exceeds `m` to stop unnecessary calculations.
//    - Return 0 if `mid^n` is less than `m`.
// 2. Use binary search to find the `n`th root of `m`:
//    - Initialize `s` (start) to 1 and `e` (end) to `m`.
//    - Calculate `mid` as the middle point of the range.
//    - Use `func` to determine if `mid` raised to the power `n` equals, exceeds, or is less than `m`.
//       - If `func` returns 1, return `mid` as the result.
//       - If `func` returns 0, move `s` to `mid + 1` to search in the higher range.
//       - If `func` returns 2, move `e` to `mid - 1` to search in the lower range.
// 3. If no `mid` satisfies the condition, return -1 as `m` does not have an integer `n`th root.

int func(int mid, int n, int m)
{
    long long ans = 1;
    for (int i = 1; i <= n; i++)
    {
        ans = ans * mid;
        if (ans > m)
            return 2;
    }
    if (ans == m)
        return 1;
    return 0;
}
int NthRoot(int n, int m)
{
    int s = 1;
    int e = m;
    long long int ans = -1;
    while (s <= e)
    {
        int mid = (s + e) / 2;
        int power = func(mid, n, m);
        if (power == 1)
        {
            return mid;
        }
        else if (power == 0)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}