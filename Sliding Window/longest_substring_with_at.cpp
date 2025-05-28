#include<iostream>
using namespace std;

// LONGEST SUBSTRING WITH AT MOST K DISTINCT CHARACTERS (LEETCODE 340)
// USING VARIABLE SIZE WINDOW - TC=O(2N), SC=O(N)

// Steps:
// 1. Initialize variables: `l` (left pointer), `r` (right pointer), `mp` (hashmap to track character counts), and `maxLen` (stores maximum length of valid substring).
// 2. Traverse the string with the right pointer `r`:
//    - Increment the count of `s[r]` in the hashmap.
//    - If the size of the hashmap exceeds `k` (more than `k` distinct characters in the window):
//        - Reduce the count of `s[l]` and increment `l` to shrink the window.
//        - Remove the character from the hashmap if its count becomes 0.
// 3. Update `maxLen` with the current window size (`r - l + 1`) after each step.
// 4. Return `maxLen` as the result after traversing the string.

int lengthOfLongestSubstringKDistinct(string s, int k)
{
    unordered_map<char, int> mp;
    int l = 0, r = 0, maxLen = 0;
    while (r < s.length())
    {
        mp[s[r]]++;
        while (mp.size() > k)
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
            {
                mp.erase(s[l]);
            }
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}

// USING VARIABLE SIZE WINDOW - TC=O(N), SC=O(N)
// Steps:
// 1. Initialize the left pointer `l`, right pointer `r`, a hashmap `mp` to track character frequencies, and `maxLen` to store the length of the longest valid substring.
// 2. Traverse the string using the right pointer `r`:
//    - Add or update the frequency of the current character `s[r]` in the hashmap.
//    - If the size of the hashmap exceeds `k` (more than `k` distinct characters), shrink the window by moving the left pointer `l` to the right until the hashmap size is `k` or less.
//        - Decrease the frequency of `s[l]` and remove it from the hashmap if its frequency reaches zero.
// 3. Update `maxLen` with the size of the current window (i.e., `r - l + 1`) if the hashmap size is valid (≤ `k`).
// 4. Return `maxLen` as the result after traversing the string.

int lengthOfLongestSubstringKDistinct(string s, int k)
{
    unordered_map<char, int> mp;
    int l = 0, r = 0, maxLen = 0;
    while (r < s.length())
    {
        mp[s[r]]++;
        if (mp.size() > k)
        {
            mp[s[l]]--;
            if (mp[s[l]] == 0)
            {
                mp.erase(s[l]);
            }
            l++;
        }
        if (mp.size() <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}