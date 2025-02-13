#include<iostream>
using namespace std;

// KOKO EATING BANANAS (LEETCODE 875)
// USING BINARY SEARCH - TC=O(N*LOG(MAXPILE)), SC=O(1)

// Steps:
// 1. Define a helper function `findMax(piles)` to find the maximum pile size, as it sets the upper limit for Koko's eating speed.
// 2. Define another helper function `calHours(piles, mid)` to calculate the total hours Koko needs to eat all the piles at a speed of `mid` bananas/hour:
//    - For each pile, divide the pile size by `mid` and take the ceiling of the result.
//    - Accumulate these values to get the total hours required.
// 3. Use binary search to find the minimum eating speed:
//    - Initialize `low` to 1 and `high` to the maximum pile size (from `findMax`).
//    - Calculate `mid` as the middle speed in the current range.
//    - Use `calHours` to determine the total hours needed at speed `mid`.
//    - If `totalH <= h` (can finish within the allowed hours), try smaller speeds by setting `high = mid - 1`.
//    - If `totalH > h`, try larger speeds by setting `low = mid + 1`.
// 4. Return `low` as the minimum eating speed that satisfies the condition after exiting the loop.

int findMax(vector<int> &piles)
{
    int ans = INT_MIN;
    for (int i = 0; i < piles.size(); i++)
    {
        ans = max(ans, piles[i]);
    }
    return ans;
}
long long calHours(vector<int> &piles, int mid)
{
    long long totalH = 0;
    int n = piles.size();
    for (int i = 0; i < n; i++)
    {
        totalH += ceil((double)piles[i] / (double)mid);
    }
    return totalH;
}
int minEatingSpeed(vector<int> &piles, int h)
{
    int low = 1, high = findMax(piles);
    while (low <= high)
    {
        int mid = (low + high) / 2;
        long long totalH = calHours(piles, mid);
        if (totalH <= h)
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return low;
}