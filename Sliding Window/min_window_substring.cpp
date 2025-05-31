#include<iostream>
using namespace std;

// MINIMUM WINDOW SUBSTRING (LEETCODE 76)
// USING VARIABLE SIZE WINDOW AND UNORDERED MAP - TC=O(N+M), SC=O(N+M)

// Steps:
// 1. Initialize `sMap` and `tMap` to store the frequency of characters in `s` and `t`, respectively.
// 2. Populate `tMap` with the frequency of each character in `t`.
// 3. Use two pointers, `start` and `end`, to represent the current window. Initialize `count` to track the number of characters in the current window that match those in `t`.
// 4. Expand the window by moving the `end` pointer and updating `sMap` with the character at `end`.
// 5. If the current window contains all characters of `t` (i.e., `count` equals the length of `t`), check if this window is smaller than the previous smallest window.
// 6. Contract the window from the left by moving the `start` pointer while the window still contains all characters of `t`.
// 7. Update the minimum length and starting index if a smaller window is found.
// 8. Continue expanding and contracting the window until the `end` pointer reaches the end of `s`.
// 9. Return the smallest window substring found, or an empty string if no such window exists.

string minWindow(string s, string t)
{
    int len1 = s.length();
    int len2 = t.length();
    if (len1 < len2)
    {
        return "";
    }
    unordered_map<char, int> sMap;
    unordered_map<char, int> tMap;
    for (char ch : t)
    {
        tMap[ch]++;
    }
    int ansIndex = -1;
    int ansLen = INT_MAX;
    int start = 0;
    int end = 0;
    int count = 0;
    while (end < len1)
    {
        char ch = s[end];
        sMap[ch]++;
        if (sMap[ch] <= tMap[ch])
        {
            count++;
        }
        if (count == len2)
        {
            while (sMap[s[start]] > tMap[s[start]])
            {
                sMap[s[start]]--;
                start++;
            }
            int windowLen = end - start + 1;
            if (windowLen < ansLen)
            {
                ansLen = windowLen;
                ansIndex = start;
            }
        }
        end++;
    }
    if (ansIndex == -1)
    {
        return "";
    }
    else
    {
        return s.substr(ansIndex, ansLen);
    }
}

// USING VARIABLE SIZE WINDOW AND ARRAY - TC=O(N+M), SC=O(1)
// Steps:
// 1. Initialize a hash map `hashMap` to store character frequencies of string `t`.
// 2. Iterate through `t` and populate `hashMap`.
// 3. Use a sliding window `[l, r]` over `s` to track the minimum substring containing all characters of `t`:
//    - Expand the window by incrementing `r` and decrement the count in `hashMap` for the character `s[r]`.
//    - If `hashMap[s[r]] > 0` before decrementing, increment the `count` of matched characters.
// 4. When `count == t.size()`, check if the current window size `(r - l + 1)` is smaller than `minLen`. If yes, update `minLen` and `sIndex`.
// 5. Shrink the window by incrementing `l`, restoring the character count in `hashMap`, and decrementing `count` if a required character's frequency becomes positive.
// 6. Return the substring starting at `sIndex` with length `minLen`, or an empty string if no valid window is found.

string minWindow(string s, string t)
{
    int hashMap[256] = {0};
    int l = 0, r = 0, count = 0, sIndex = -1, minLen = INT_MAX;
    for (int i = 0; i < t.size(); i++)
    {
        hashMap[t[i]]++;
    }
    while (r < s.size())
    {
        if (hashMap[s[r]] > 0)
            count++;
        hashMap[s[r]]--;
        while (count == t.size())
        {
            if (r - l + 1 < minLen)
            {
                minLen = r - l + 1;
                sIndex = l;
            }
            hashMap[s[l]]++;
            if (hashMap[s[l]] > 0)
                count--;
            l++;
        }
        r++;
    }
    return sIndex == -1 ? "" : s.substr(sIndex, minLen);
}