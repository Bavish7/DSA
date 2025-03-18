#include<iostream>
using namespace std;

// LONGEST STRING CHAIN (LEETCODE 1048)
// USING SORTING AND LIS - TC=O(N^2*L), SC=O(N)

// Steps:
// 1. Sort the words by length to ensure that shorter words are processed before longer ones.
// 2. Use dynamic programming where dp[i] stores the longest chain ending at words[i].
// 3. For each word words[i], check all previous words words[j] such that:
//    a. The length difference is exactly 1.
//    b. words[j] can form words[i] by adding exactly one character (checked using the helper function isPossible).
//    c. If both conditions are true, update dp[i] to dp[j] + 1.
// 4. Track and return the maximum chain length found in dp.

static bool compare(string &s1, string &s2)
{
    return s1.size() < s2.size();
}
static bool isPossible(string &s1, string &s2)
{
    int l1 = s1.size();
    int l2 = s2.size();
    if (l1 != l2 + 1)
        return false;
    int first = 0, second = 0;
    while (first < l1)
    {
        if (second < l2 && s1[first] == s2[second])
        {
            first++, second++;
        }
        else
        {
            first++;
        }
    }
    if (first == second + 1)
        return true;
    return false;
}
int longestStrChain(vector<string> &words)
{
    sort(words.begin(), words.end(), compare);
    int n = words.size();
    vector<int> dp(n, 1);
    int maxChain = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (isPossible(words[i], words[j]) && dp[i] < dp[j] + 1)
            {
                dp[i] = dp[j] + 1;
            }
        }
        if (dp[i] > maxChain)
        {
            maxChain = dp[i];
        }
    }
    return maxChain;
}