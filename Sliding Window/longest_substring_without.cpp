#include<iostream>
using namespace std;

// LONGEST SUBSTRING WITHOUT REPEATING CHARACTERS (LEETCODE 3)
// USING VARIABLE SIZE WINDOW - TC=O(N), SC=O(N)

// Steps:
// 1. Use a sliding window approach with two pointers (`l` and `r`) to track the current substring.
// 2. Maintain a map `mp` to store the last seen index of each character.
// 3. If a duplicate character is encountered (`s[r]` exists in `mp` and its index ≥ `l`):
//    - Move the left pointer (`l`) to exclude the previous occurrence of `s[r]`.
// 4. Calculate the length of the current substring (`r - l + 1`) and update `maxLen`.
// 5. Add/update `s[r]` in the map with its index and move the right pointer (`r`).
// 6. Return `maxLen` after processing the entire string.

int lengthOfLongestSubstring(string s)
{
    if (s.size() == 0)
        return 0;
    unordered_map<char, int> mp;
    int l = 0, r = 0;
    int len = 0, maxLen = 0;
    while (r < s.size())
    {
        if (mp.find(s[r]) != mp.end())
        {
            if (mp[s[r]] >= l)
            {
                l = mp[s[r]] + 1;
            }
        }
        len = r - l + 1;
        maxLen = max(len, maxLen);
        mp[s[r]] = r;
        r++;
    }
    return maxLen;
}