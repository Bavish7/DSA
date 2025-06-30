#include<iostream>
using namespace std;

// NUMBER OF SUBSEQUENCES THAT SATISFY THE GIVEN SUM CONDITION (LEETCODE 1498)
// USING TWO POINTERS AND SORTING - TC=O(N*LOGN+N), SC=O(N)

// Steps:
// 1. Sort the array to efficiently use two pointers for checking valid subsequences.
// 2. Precompute powers of 2 up to n, where power[i] = 2^i % mod (represents number of subsequences).
// 3. Initialize two pointers i = 0 and j = n - 1.
// 4. While i ≤ j:
//    - If nums[i] + nums[j] ≤ target, then all subsequences between i and j are valid (2^(j - i) choices).
//    - Add power[j - i] to answer and increment i.
//    - Else decrement j.
// 5. Return final answer modulo 1e9+7.

int mod = 1e9 + 7;
int numSubseq(vector<int> &nums, int target)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int i = 0, j = n - 1;
    vector<int> power(n, 0);
    power[0] = 1;
    for (int i = 1; i < n; i++)
    {
        power[i] = (power[i - 1] * 2) % mod;
    }
    int ans = 0;
    while (i <= j)
    {
        if (nums[i] + nums[j] <= target)
        {
            ans = (ans + power[j - i] % mod) % mod;
            i++;
        }
        else
        {
            j--;
        }
    }
    return ans % mod;
}