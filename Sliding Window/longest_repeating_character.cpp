#include<iostream>
using namespace std;

// LONGEST REPEATING CHARACTER REPLACEMENT (LEETCODE 424)
// USING VARIABLE SIZE WINDOW - TC=O(2N), SC=O(1)

// Steps:
// 1. Initialize a frequency map `mp` to store the count of characters in the window, variables `l` and `r` for left and right pointers, and `maxFreq` to track the maximum frequency of any character in the window.
// 2. Iterate through the string using `r` as the right pointer:
//    - Update the frequency map for the current character `s[r]`.
//    - Update `maxFreq` to store the maximum frequency of any character within the window.
//    - If the window size minus `maxFreq` exceeds `k`, increment the left pointer `l` and adjust the frequency of the character at `l`.
// 3. Update `maxLen` with the size of the valid window (`r - l + 1`).
// 4. Return the result, which is the longest valid substring length.

int characterReplacement(string s, int k)
{
    unordered_map<char, int> mp;
    int l = 0, r = 0, maxLen = 0, maxFreq = 0;
    while (r < s.length())
    {
        mp[s[r]]++;
        maxFreq = max(maxFreq, mp[s[r]]);
        while (r - l + 1 - maxFreq > k)
        {
            mp[s[l]]--;
            l++;
        }
        maxLen = max(maxLen, r - l + 1);
        r++;
    }
    return maxLen;
}

// USING VARIABLE SIZE WINDOW - TC=O(N), SC=O(1)
// Steps:
// 1. Initialize an unordered map `mp` to track character frequencies, left (`l`) and right (`r`) pointers, `maxLen` for the longest valid substring, and `maxFreq` for the highest frequency of any character in the window.
// 2. Iterate with the right pointer `r` through the string:
//    - Update the frequency map for the current character `s[r]`.
//    - Update `maxFreq` to store the maximum frequency of any character in the current window.
//    - If the window size minus `maxFreq` exceeds `k`, move the left pointer `l` to shrink the window and adjust frequencies.
// 3. Update `maxLen` with the maximum window size that satisfies the condition `(r - l + 1) - maxFreq <= k`.
// 4. Return the longest valid substring length.

int characterReplacement(string s, int k)
{
    unordered_map<char, int> mp;
    int l = 0, r = 0, maxLen = 0, maxFreq = 0;
    while (r < s.length())
    {
        mp[s[r]]++;
        maxFreq = max(maxFreq, mp[s[r]]);
        if ((r - l + 1) - maxFreq > k)
        {
            mp[s[l]]--;
            l++;
        }
        if ((r - l + 1) - maxFreq <= k)
        {
            maxLen = max(maxLen, r - l + 1);
        }
        r++;
    }
    return maxLen;
}