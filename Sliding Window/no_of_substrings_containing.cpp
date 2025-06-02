#include<iostream>
using namespace std;

// NUMBER OF SUBSTRINGS CONTAINING ALL THREE CHARACTERS (LEETCODE 1358)
// USING VARIABLE SIZE WINDOW - TC=O(2N), SC=O(1)

// Steps:
// 1. Initialize the left pointer `l`, right pointer `r`, a hashmap `mp` to track character frequencies, and `count` to store the number of valid substrings.
// 2. Traverse the string using the right pointer `r`:
//    - Add or update the frequency of the current character `s[r]` in the hashmap.
//    - If the size of the hashmap reaches 3 (i.e., there are 3 distinct characters), move the left pointer `l` to shrink the window and count the valid substrings. Each time the left pointer moves, all substrings starting from `l` and ending at positions between `r` and `n-1` are valid.
//        - Decrease the frequency of `s[l]` and remove it from the hashmap if its frequency reaches zero.
// 3. The count of valid substrings is accumulated in `count` as the window shrinks.
// 4. Return `count` as the total number of valid substrings after traversing the string.

int numberOfSubstrings(string s)
{
    unordered_map<char, int> mp;
    int l = 0, r = 0, count = 0, n = s.length();
    while (r < n)
    {
        mp[s[r]]++;
        while (mp.size() == 3)
        {
            count += n - r;
            mp[s[l]]--;
            if (mp[s[l]] == 0)
            {
                mp.erase(s[l]);
            }
            l++;
        }
        r++;
    }
    return count;
}

// USING LAST SEEN ARRAY - TC=O(N), SC=O(1)
// Steps:
// 1. Initialize an array `lastSeen` to store the last seen index of each character ('a', 'b', 'c'). Set all values to -1 initially.
// 2. Iterate through the string using an index `i`:
//    - Update the last seen index of the current character `s[i]` in `lastSeen`.
//    - If all characters ('a', 'b', 'c') have been seen at least once (i.e., their indices are not -1), calculate how many valid substrings end at index `i` by adding the minimum of the last seen indices.
//    - The valid substrings are formed by extending from the smallest index of the last seen characters to the current index `i`.
// 3. Accumulate the number of valid substrings in `count` and return it as the result.

int numberOfSubstrings(string s)
{
    int lastSeen[3] = {-1, -1, -1};
    int count = 0;
    for (int i = 0; i < s.size(); i++)
    {
        lastSeen[s[i] - 'a'] = i;
        if (lastSeen[0] != -1 && lastSeen[1] != -1 && lastSeen[2] != -1)
        {
            count += 1 + min(lastSeen[0], min(lastSeen[1], lastSeen[2]));
        }
    }
    return count;
}
