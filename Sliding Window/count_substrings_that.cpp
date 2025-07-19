#include<iostream>
using namespace std;

// COUNT SUUBSTRINGS THAT SATISFY K-CONSTRAINT II (LEETCODE 3261)
// USING SLIDING WINDOW AND PREFIX SUM - TC=O(N+Q), SC=O(N)

// Steps:
// 1. For each index `i`, calculate `leftMost[i]`: leftmost valid start for substring ending at `i`
//    - Use sliding window to ensure both '0' and '1' occur at most `k` times
// 2. Similarly, for each index `i`, calculate `rightMost[i]`: rightmost valid end for substrings starting at `i`
//    - Use reverse sliding window (right to left)
// 3. For each `j`, compute `tempValidSubstr[j] = j - leftMost[j] + 1`
//    - This gives the number of valid substrings ending at `j`
// 4. Build prefix sum over `tempValidSubstr` to enable fast range queries
// 5. For each query [low, high]:
//    - Let `validHigh = min(high, rightMost[low])`: largest `j` in [low, high] such that [low..j] is valid
//    - Count all substrings starting at `low` and ending within [low..validHigh]: use formula (len * (len + 1)) / 2
//    - Add prefix sum of substrings ending beyond validHigh: prefixSum[high] - prefixSum[validHigh]
// 6. Return the result for each query

vector<long long> countKConstraintSubstrings(string s, int k, vector<vector<int>> &queries)
{
    int n = s.size();
    vector<int> leftMost(n, 0);
    vector<int> rightMost(n, 0);
    int left = 0, right = 0;
    unordered_map<char, int> mp;
    while (right < n)
    {
        mp[s[right]]++;
        while (mp['0'] > k && mp['1'] > k)
        {
            mp[s[left]]--;
            left++;
        }
        leftMost[right] = left;
        right++;
    }
    mp.clear();
    left = n - 1, right = n - 1;
    while (right >= 0)
    {
        mp[s[right]]++;
        while (mp['0'] > k && mp['1'] > k)
        {
            mp[s[left]]--;
            left--;
        }
        rightMost[right] = left;
        right--;
    }
    vector<int> tempValidSubstr(n, 0);
    for (int j = 0; j < n; j++)
    {
        tempValidSubstr[j] = j - leftMost[j] + 1;
    }
    vector<long long> prefixSum(n, 0);
    prefixSum[0] = tempValidSubstr[0];
    for (int i = 1; i < n; i++)
    {
        prefixSum[i] = prefixSum[i - 1] + tempValidSubstr[i];
    }
    vector<long long> ans;
    for (auto query : queries)
    {
        int low = query[0];
        int high = query[1];
        int validHigh = min(high, rightMost[low]);
        long long len = validHigh - low + 1;
        long long temp = len * (len + 1) / 2;
        temp += prefixSum[high] - prefixSum[validHigh];
        ans.push_back(temp);
    }
    return ans;
}