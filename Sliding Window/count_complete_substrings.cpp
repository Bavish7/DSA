#include<iostream>
using namespace std;

// COUNT COMPLETE SUBSTRINGS (LEETCODE 2953)
// USING VARIABLE SIZE WINDOW - TC=O(26*N), SC=O(1)

// Steps:
// 1. Try every possible number of unique characters from 1 to 26
// 2. For each `uniqueChar`:
//    a. Set window length = uniqueChar * k
//    b. Initialize sliding window between `left` and `right` pointers
//    c. Use a frequency array to count character occurrences in current window
//    d. Maintain a `goodChar` counter: how many characters have exactly `k` frequency
//    e. While expanding window (right pointer):
//       - Update freq of current char, update `goodChar` accordingly if its freq becomes == k or == k+1
//       - If window size exceeds limit, shrink from left and update freq and `goodChar` accordingly
//       - If number of `goodChar` equals `uniqueChar`, increment valid substring count

int countSubstrings(int start, int end, string &word, int k)
{
    int count = 0;
    for (int uniqueChar = 1; uniqueChar <= 26 && uniqueChar <= end - start + 1; uniqueChar++)
    {
        vector<int> freq(26, 0);
        int goodChar = 0;
        int left = start, right = start;
        int windowLen = uniqueChar * k;
        while (right <= end)
        {
            char ch = word[right];
            freq[ch - 'a']++;
            if (freq[ch - 'a'] == k)
                goodChar++;
            else if (freq[ch - 'a'] == k + 1)
                goodChar--;
            if (right - left + 1 > windowLen)
            {
                int oldFreq = freq[word[left] - 'a'];
                if (oldFreq == k + 1)
                {
                    goodChar++;
                }
                else if (oldFreq == k)
                {
                    goodChar--;
                }
                freq[word[left] - 'a']--;
                left++;
            }
            if (goodChar == uniqueChar)
                count++;
            right++;
        }
    }
    return count;
}
int countCompleteSubstrings(string word, int k)
{
    int n = word.size();
    int start = 0, count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (i == n || abs(word[i] - word[i - 1]) > 2)
        {
            count += countSubstrings(start, i - 1, word, k);
            start = i;
        }
    }
    return count;
}