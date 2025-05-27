#include<iostream>
using namespace std;

// COUNT OF SUBSTRINGS CONTAINING EVERY VOWEL AND K CONSONANTS II (LEETCODE 3306)
// USING VARIABLE SIZE WINDOW - TC=O(2N), SC=O(1)

// Steps:
// 1. Create a helper function `checkVowel` to check if a character is a vowel.
// 2. Initialize an unordered_map `mp` to store vowel frequencies and a vector `nextCons` to track the next consonant position for each index.
// 3. Traverse the string from right to left to fill `nextCons` with the index of the next consonant or `n` if none exists.
// 4. Use a sliding window approach with two pointers `i` and `j` to iterate through the string.
// 5. Expand the window by moving `j` and updating vowel frequency in `mp` or incrementing the consonant count.
// 6. If the consonant count exceeds `k`, shrink the window from the left by moving `i` until `cons == k`.
// 7. If the window contains all 5 vowels and exactly `k` consonants, count valid substrings using `nextCons[j] - j`.
// 8. Continue adjusting `i` while maintaining the vowel constraint to count all valid substrings.
// 9. Return the total count.

bool checkVowel(char ch)
{
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
    {
        return true;
    }
    return false;
}
long long countOfSubstrings(string word, int k)
{
    int n = word.size();
    unordered_map<char, int> mp;
    vector<int> nextCons(n);
    int lastCons = n;
    for (int i = n - 1; i >= 0; i--)
    {
        nextCons[i] = lastCons;
        if (!checkVowel(word[i]))
        {
            lastCons = i;
        }
    }
    int i = 0, j = 0, cons = 0;
    long long count = 0;
    while (j < n)
    {
        char ch = word[j];
        if (checkVowel(ch))
        {
            mp[ch]++;
        }
        else
        {
            cons++;
        }
        while (cons > k)
        {
            if (checkVowel(word[i]))
            {
                mp[word[i]]--;
                if (mp[word[i]] == 0)
                    mp.erase(word[i]);
            }
            else
            {
                cons--;
            }
            i++;
        }
        while (mp.size() == 5 && cons == k)
        {
            count += nextCons[j] - j;
            if (checkVowel(word[i]))
            {
                mp[word[i]]--;
                if (mp[word[i]] == 0)
                    mp.erase(word[i]);
            }
            else
                cons--;
            i++;
        }
        j++;
    }
    return count;
}