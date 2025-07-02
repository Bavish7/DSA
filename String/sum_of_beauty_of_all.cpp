#include<iostream>
using namespace std;

// SUM OF BEAUTY OF ALL SUBSTRINGS(LEETCODE 1781)
// USING UNORDERED MAP - TC=O(N^2), SC=O(N)

// Steps:
// 1. Traverse all substrings starting from each character in the string using two nested loops.
// 2. Use an unordered_map to count the frequency of each character in the current substring.
// 3. For each substring, calculate the maximum and minimum frequency of characters.
// 4. Add the difference (maxFreq - minFreq) to the total beauty sum.
// 5. Clear the frequency map before processing the next substring starting from a new character.
// 6. Return the total beauty sum.

int beautySum(string s)
{
    int n = s.size();
    unordered_map<char, int> mp;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            mp[s[j]]++;
            int maxFreq = INT_MIN;
            int minFreq = INT_MAX;
            for (auto it : mp)
            {
                maxFreq = max(maxFreq, it.second);
                minFreq = min(minFreq, it.second);
            }
            sum += maxFreq - minFreq;
        }
        mp.clear();
    }
    return sum;
}

// USING ARRAY - TC=O(N^2), SC=O(1)
// Steps:
// 1. Traverse all substrings starting from each character in the string using two nested loops.
// 2. Use an array to count the frequency of each character in the current substring.
// 3. For each substring, calculate the maximum and minimum frequency of characters.
// 4. Add the difference (maxFreq - minFreq) to the total beauty sum.
// 5. Clear the frequency array before processing the next substring starting from a new character.
// 6. Return the total beauty sum.

int beautySum(string s)
{
    int n = s.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> freq(26, 0);
        for (int j = i; j < n; j++)
        {
            freq[s[j] - 'a']++;
            int maxFreq = INT_MIN;
            int minFreq = INT_MAX;
            for (int k = 0; k < 26; k++)
            {
                if (freq[k] > 0)
                {
                    maxFreq = max(maxFreq, freq[k]);
                    minFreq = min(minFreq, freq[k]);
                }
            }
            sum += maxFreq - minFreq;
        }
    }
    return sum;
}

