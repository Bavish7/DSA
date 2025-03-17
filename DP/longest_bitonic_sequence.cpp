#include<iostream>
using namespace std;

// LONGEST BITONIC SUBSEQUENCE
// USING TWO LIS - TC=O(N^2), SC=O(N)

// Steps:
// 1. Compute the Longest Increasing Subsequence (LIS) for each index `i` using the `lisFront` vector.
//    - `lisFront[i]` stores the length of LIS ending at index `i`.
// 2. Compute the Longest Decreasing Subsequence (LDS) for each index `i` using the `lisBack` vector.
//    - `lisBack[i]` stores the length of LDS starting at index `i`.
// 3. Traverse each index `i` and compute `lisFront[i] + lisBack[i] - 1` to find the length of the bitonic subsequence ending at `i`.
//    - Subtract 1 because `arr[i]` is counted twice in both LIS and LDS.
// 4. Return the maximum bitonic subsequence length found.

int longestBitonicSubsequence(vector<int> &arr, int n)
{
    vector<int> lisFront(n, 1), lisBack(n, 1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[i] > arr[j] && lisFront[i] < lisFront[j] + 1)
            {
                lisFront[i] = lisFront[j] + 1;
            }
        }
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = n - 1; j > i; j--)
        {
            if (arr[i] > arr[j] && lisBack[i] < lisBack[j] + 1)
            {
                lisBack[i] = lisBack[j] + 1;
            }
        }
    }
    int maxLen = 1;
    for (int i = 0; i < n; i++)
    {
        maxLen = max(maxLen, lisFront[i] + lisBack[i] - 1);
    }
    return maxLen;
}