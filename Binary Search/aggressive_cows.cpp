#include <iostream>
#include <array>
#include <vector>
#include <algorithm>
using namespace std;

// AGGRESSIVE COWS
// USING BINARY SEARCH - TC=O(N*LOGN), SC=O(LOGN)

// Steps:
// 1. Sort the stalls to facilitate binary search on possible distances.
// 2. Set the search range: 's' as 0 and 'e' as the maximum distance between stalls.
// 3. Use binary search to find the maximum possible minimum distance 'ans' where 'k' cows can be placed.
// 4. Check if it's possible to place 'k' cows with at least 'mid' distance using 'isPossible' function.
// 5. Adjust search range based on whether placing 'k' cows is possible at 'mid'.
// 6. Return the maximum possible minimum distance 'ans'.

bool isPossible(vector<int> &stalls, int k, int mid){
    int cowCount = 1;
    int lastPos = stalls[0];
    for (int i = 0; i < stalls.size(); i++)
    {
        if (stalls[i] - lastPos >= mid)
        {
            cowCount++;
            if (cowCount == k)
            {
                return true;
            }
            lastPos = stalls[i];
        }
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    sort(stalls.begin(), stalls.end());
    int s = 0;
    int maxi = -1;
    for (int i = 0; i < stalls.size(); i++)
    {
        maxi = max(maxi, stalls[i]);
    }
    int e = maxi;
    int ans = -1;
    int mid = (s + e) / 2;
    while (s <= e)
    {
        if (isPossible(stalls, k, mid))
        {
            ans = mid;
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
        mid = (s + e) / 2;
    }
    return ans;
}