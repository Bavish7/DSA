#include<iostream>
using namespace std;

// WILDCARD MATCHING (LEETCODE 44)
// USING RECURSION BUT GIVING TLE- TC=O(2^N), SC=O(N)

// Steps:
// 1. Define a helper function `isMatchHelper` that takes string `s`, index `i`, pattern `p`, and index `j` as arguments.
// 2. Base case 1: If both `i` and `j` reach the end of their respective strings, return true (match found).
// 3. Base case 2: If `i` reaches the end of `s` but `j` still has characters in `p`, check if the remaining characters in `p` are all `*`. If so, return true; otherwise, return false.
// 4. If characters at `s[i]` and `p[j]` match or `p[j]` is '?', move to the next characters in both `s` and `p` by calling `isMatchHelper(s, i+1, p, j+1)`.
// 5. If `p[j]` is '*', consider two cases:
//    a. Exclude the '*' and move to the next character in `p` (`isMatchHelper(s, i, p, j+1)`).
//    b. Include the '*' and move to the next character in `s` (`isMatchHelper(s, i+1, p, j)`).
//    Return true if either case returns true.
// 6. If no conditions are met, return false.
// 7. Initialize indices `i` and `j` to 0 and call `isMatchHelper`.

bool isMatchHelper(string &s, int i, string &p, int j)
{
    if (i == s.size() && j == p.size())
    {
        return true;
    }
    if (i == s.size() && j < p.size())
    {
        while (j < p.size())
        {
            if (p[j] != '*')
            {
                return false;
            }
            j++;
        }
        return true;
    }
    if (s[i] == p[j] || p[j] == '?')
    {
        return isMatchHelper(s, i + 1, p, j + 1);
    }
    if (p[j] == '*')
    {
        bool exclude = isMatchHelper(s, i, p, j + 1);
        bool include = isMatchHelper(s, i + 1, p, j);
        return include || exclude;
    }
    return false;
}
bool isMatch(string s, string p)
{
    int i = 0, j = 0;
    return isMatchHelper(s, i, p, j);
}