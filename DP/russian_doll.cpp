#include<iostream>
using namespace std;

// RUSSIAN DOLL ENVELOPES (LEETCODE 354)
// USING BINARY SEARCH - TC=O(N*LOGN), SC=O(N)

// Steps:
// 1. Sort the envelopes primarily by width (ascending), and by height (descending) for equal widths.
// 2. Initialize an array ans to store the heights of envelopes forming the Russian doll sequence.
// 3. Iterate through each envelope starting from the second one:
//    a. If the height of the current envelope is greater than the last envelope in ans, append it to ans.
//    b. Otherwise, find the smallest height in ans that is not less than the current envelope's height using binary search (lower_bound).
//       - Replace that height with the current envelope's height.
// 4. Return the size of ans, which represents the length of the longest increasing subsequence of heights.

static bool comp(vector<int> &a, vector<int> &b)
{
    if (a[0] == b[0])
    {
        return a[1] > b[1];
    }
    return a[0] < b[0];
}
int maxEnvelopes(vector<vector<int>> &envelopes)
{
    sort(envelopes.begin(), envelopes.end(), comp);
    int i, j, n = envelopes.size();
    vector<int> ans;
    ans.push_back(envelopes[0][1]);
    for (int i = 1; i < n; i++)
    {
        if (envelopes[i][1] > ans.back())
        {
            ans.push_back(envelopes[i][1]);
        }
        else
        {
            int index = lower_bound(ans.begin(), ans.end(), envelopes[i][1]) - ans.begin();
            ans[index] = envelopes[i][1];
        }
    }
    return ans.size();
}