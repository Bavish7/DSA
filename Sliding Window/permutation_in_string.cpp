#include<iostream>
using namespace std;

// PERMUTATION IN STRING (LEETCODE 567)
// USING FIXED SIZE SLIDING WINDOW AND CHARACTER COUNT - TC=O(M), SC=O(1)

// Steps:
// 1. Count frequency of each character in `s1` using count1[]
// 2. Initialize a sliding window of size `n` (length of s1) on `s2`
// 3. As window expands (right pointer moves), update count2[] for s2[right]
// 4. If window size exceeds `n`, shrink from the left (decrement count of s2[left])
// 5. At each step, check if count1 == count2 (i.e., all character counts match)
//    → If yes, a permutation of s1 exists in s2 → return true
// 6. If no match found till end, return false

bool checkInclusion(string s1, string s2)
{
    int n = s1.size(), m = s2.size();
    vector<int> count1(26, 0), count2(26, 0);
    for (int i = 0; i < n; i++)
    {
        int index = s1[i] - 'a';
        count1[index]++;
    }
    int left = 0, right = 0;
    while (right < m)
    {
        count2[s2[right] - 'a']++;
        if (right - left + 1 > n)
        {
            count2[s2[left] - 'a']--;
            left++;
        }
        if (count1 == count2)
            return true;
        right++;
    }
    return false;
}