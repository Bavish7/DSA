#include<iostream>
using namespace std;

// NUMBER OF WONDERFUL SUBSTRINGS (LEETCODE 1915)
// USING PREFIX XOR AND UNORDERED MAP. TC=O(N), SC=O(1)

// Steps:
// 1. Initialize totalXor = 0 to store the XOR mask of character counts mod 2.
// 2. Use mp to store frequency of each XOR mask encountered; start with mp[0] = 1 for the empty prefix.
// 3. For each character:
//    - Update totalXor by toggling the bit for the current letter.
//    - Add mp[totalXor] to ans (counts substrings where all characters have even frequency).
//    - For each letter 'a' to 'j':
//        * Flip its bit in totalXor → check if that state exists in mp → add its frequency to ans.
//        * This accounts for substrings where exactly one letter has an odd count.
//    - Increment mp[totalXor] for future matches.
// 4. Return ans as total number of wonderful substrings.

#define ll long long
long long wonderfulSubstrings(string word)
{
    int totalXor = 0;
    ll ans = 0;
    unordered_map<ll, ll> mp;
    mp[0] = 1;
    for (char &ch : word)
    {
        int shift = ch - 'a';
        totalXor ^= (1 << shift);
        ans += mp[totalXor];
        for (char c = 'a'; c <= 'j'; c++)
        {
            shift = c - 'a';
            ll currXor = (totalXor ^ (1 << shift));
            ans += mp[currXor];
        }
        mp[totalXor]++;
    }
    return ans;
}