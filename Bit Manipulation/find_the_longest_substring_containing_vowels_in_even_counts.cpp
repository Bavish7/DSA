#include<iostream>
using namespace std;

// FIND THE LONGEST SUBSTRING CONTAINING VOWELS IN EVEN COUNTS (LEETCODE 1371)
// USING BIT MANIPULATION AND UNORDERED MAP - TC=O(N), SC=O(1)

// Steps:
// 1. Track vowel parity state (5 bits: a,e,i,o,u). Toggle (xor with 1) whenever a vowel is seen.
// 2. Convert state into a string key ("01001") for hashmap.
// 3. Store first occurrence of each state in map (initialize "00000" → index -1).
// 4. If state seen before → substring between prevIndex+1 and current i has even counts of vowels → update maxLen.
// 5. Otherwise, record first index of this state.
// 6. Return maxLen.

int findTheLongestSubstring(string s)
{
    unordered_map<string, int> mp;
    vector<int> state(5, 0);
    string currState = "00000";
    mp[currState] = -1;
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
        {
            state[0] = (state[0] + 1) % 2;
        }
        else if (s[i] == 'e')
        {
            state[1] = (state[1] + 1) % 2;
        }
        else if (s[i] == 'i')
        {
            state[2] = (state[2] + 1) % 2;
        }
        else if (s[i] == 'o')
        {
            state[3] = (state[3] + 1) % 2;
        }
        else if (s[i] == 'u')
        {
            state[4] = (state[4] + 1) % 2;
        }
        currState = "";
        for (int j = 0; j < 5; j++)
        {
            currState += to_string(state[j]);
        }
        if (mp.find(currState) != mp.end())
        {
            maxLen = max(maxLen, i - mp[currState]);
        }
        else
            mp[currState] = i;
    }
    return maxLen;
}

// USING BITMASKING AND UNORDERED MAP - TC=O(N), SC=O(1)
// Steps:
// 1. Use a 5-bit mask to represent parity of vowels:
//    bit0→a, bit1→e, bit2→i, bit3→o, bit4→u.
// 2. Toggle corresponding bit using XOR when a vowel appears.
// 3. If current mask seen before, substring between prevIndex+1 and i has even count of vowels → update maxLen.
// 4. Otherwise, record first index of this mask in map.
// 5. Return maxLen.

int findTheLongestSubstring(string s)
{
    unordered_map<int, int> mp;
    int mask = 0;
    mp[mask] = -1;
    int maxLen = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == 'a')
        {
            mask = mask ^ (1 << 0);
        }
        else if (s[i] == 'e')
        {
            mask = mask ^ (1 << 1);
        }
        else if (s[i] == 'i')
        {
            mask = mask ^ (1 << 2);
        }
        else if (s[i] == 'o')
        {
            mask = mask ^ (1 << 3);
        }
        else if (s[i] == 'u')
        {
            mask = mask ^ (1 << 4);
        }
        if (mp.find(mask) != mp.end())
        {
            maxLen = max(maxLen, i - mp[mask]);
        }
        else
            mp[mask] = i;
    }
    return maxLen;
}