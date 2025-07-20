#include<iostream>
using namespace std;

// TAKE K OF EACH CHARACTER FROM LEFT AND RIGHT (LEETCODE 2516)
// USING VARIABLE SIZE WINDOW - TC=O(N), SC=O(1)

// Steps:
// 1. Count total frequency of 'a', 'b', 'c' in string `s`.
// 2. If any character appears less than `k` times, return -1 (impossible to take `k` of each).
// 3. Try to maximize the length of a middle subarray you can leave untouched (i.e., not take from).
// 4. Slide window [left, right] and decrement frequency of s[right] from total.
// 5. If any character’s remaining count falls below `k`, shrink window from the left to fix the violation.
// 6. Track the max valid window length and return `n - maxLen` as the minimum characters to take.

int takeCharacters(string s, int k)
{
    int n = s.size();
    vector<int> freq(3, 0);
    for (char ch : s)
    {
        freq[ch - 'a']++;
    }
    for (int i = 0; i < 3; i++)
    {
        if (freq[i] < k)
            return -1;
    }
    int left = 0, right = 0;
    int maxLen = 0;
    while (right < n)
    {
        freq[s[right] - 'a']--;
        while (left <= right && (freq[0] < k || freq[1] < k || freq[2] < k))
        {
            freq[s[left] - 'a']++;
            left++;
        }
        maxLen = max(maxLen, right - left + 1);
        right++;
    }
    return n - maxLen;
}