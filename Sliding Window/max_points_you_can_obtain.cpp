#include<iostream>
using namespace std;

// MAXIMUM POINTS YOU CAN OBTAIN FROM CARDS (LEETCODE 1423)
// USING FIXED SIZE WINDOW - TC=O(K), SC=O(1)

// Steps:
// 1. Compute the sum of the first `k` cards as the initial sum and set it as `maxSum`.
// 2. Use a sliding window to shift cards:
//    - Remove cards from the left of the current window (`cardPoints[l]`) and add cards from the right (`cardPoints[r]`).
//    - Update `maxSum` with the maximum observed sum during each shift.
// 3. Return `maxSum` after evaluating all possible windows.

int maxScore(vector<int> &cardPoints, int k)
{
    int sum = 0, maxSum = INT_MIN;
    int n = cardPoints.size();
    for (int i = 0; i < k; i++)
    {
        sum += cardPoints[i];
    }
    maxSum = max(sum, maxSum);
    int l = k - 1, r = n - 1;
    while (l >= 0)
    {
        sum -= cardPoints[l];
        l--;
        sum += cardPoints[r];
        r--;
        maxSum = max(sum, maxSum);
    }
    return maxSum;
}