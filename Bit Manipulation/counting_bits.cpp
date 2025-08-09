#include<iostream>
using namespace std;

// COUNTING BITS (LEETCODE 338)
// USING BIT MANIPULATION FOR EACH NUMBER- TC=O(N*LOGN), SC=O(1)

// Steps:
// 1. Create `ans` vector to store bit counts for numbers 0 to n.
// 2. For each number `i` from 0 to n:
//    a. Initialize `countOnes = 0`.
//    b. Copy `i` to `num`.
//    c. While `num` is non-zero:
//       - Add `num & 1` to `countOnes` (checks if LSB is set).
//       - Right shift `num` by 1 to check next bit.
//    d. Push `countOnes` into `ans`.
// 3. Return the `ans` vector.

vector<int> countBits(int n)
{
    vector<int> ans;
    for (int i = 0; i <= n; i++)
    {
        int countOnes = 0;
        int num = i;
        while (num)
        {
            countOnes += num & 1;
            num >>= 1;
        }
        ans.push_back(countOnes);
    }
    return ans;
}

// USING BIT MANIPULATION AND DP - TC=O(N), SC=O(1)
// Steps:
// 1. Initialize vector `ans` of size n+1 with zeros.
// 2. For each i from 1 to n:
//    a. If i is odd → i%2 == 1 → bits = bits in i/2 + 1 (because LSB is 1).
//    b. If i is even → i%2 == 0 → bits = bits in i/2 (because LSB is 0).
// 3. Return the `ans` vector containing bit counts for 0 to n.

vector<int> countBits(int n)
{
    vector<int> ans(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
            ans[i] = ans[i / 2] + 1;
        else
            ans[i] = ans[i / 2];
    }
    return ans;
}