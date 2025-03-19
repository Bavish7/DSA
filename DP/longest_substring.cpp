#include<iostream>
using namespace std;

// LONGEST PALINDROMIC SUBSTRING (LEETCODE 5)
// USING STRING - TC=O(N^3), SC=O(1)

// Steps:
// 1. Define a helper function isPalindrome to check if a substring is a palindrome.
// 2. Iterate over all possible substrings of the input string.
// 3. Check if each substring is a palindrome.
// 4. Keep track of the longest palindromic substring found.

bool isPalindrome(string &temp, int i, int j)
{
    while (i < j)
    {
        if (temp[i] != temp[j])
        {
            return false;
        }
        i++;
        j--;
    }
    return true;
}
string longestPalindrome(string s)
{
    string ans = "";
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            if (isPalindrome(s, i, j))
            {
                string t = s.substr(i, j - i + 1);
                ans = t.size() > ans.size() ? t : ans;
            }
        }
    }
    return ans;
}

// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(N^2)
// Steps:
// 1. Initialize `maxLen` and `start` to track the longest palindromic substring's length and starting index.
// 2. Define a helper function `solve(i, j)` that:
//    - Returns true if `i >= j`.
//    - Checks if `dp[i][j]` is computed. If yes, return it.
//    - If characters at `s[i]` and `s[j]` match, recursively call `solve(i + 1, j - 1)`.
//    - Update `maxLen` and `start` if a longer palindrome is found.
// 3. In the `longestPalindrome` function:
//    - Create a 2D vector `dp` for memoization.
//    - Loop through all possible substrings with start index `i` and end index `j`, calling `solve(i, j)`.
// 4. Return the longest palindromic substring using `s.substr(start, maxLen)`.

int maxLen = 1, start = 0;
bool solve(string &s, int i, int j, vector<vector<bool>> &dp)
{
    if (i >= j)
    {
        return true;
    }
    if (dp[i][j])
    {
        return dp[i][j];
    }
    bool flag = false;
    if (s[i] == s[j])
    {
        flag = solve(s, i + 1, j - 1, dp);
    }
    if (flag)
    {
        int curLen = j - i + 1;
        if (curLen > maxLen)
        {
            maxLen = curLen;
            start = i;
        }
    }
    return dp[i][j] = flag;
}
string longestPalindrome(string s)
{
    int n = s.size();
    vector<vector<bool>> dp(n, vector<bool>(n, 0));
    for (int i = 0; i < s.size(); i++)
    {
        for (int j = i; j < s.size(); j++)
        {
            bool ans = solve(s, i, j, dp);
        }
    }
    return s.substr(start, maxLen);
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^2), SC=O(N^2)
// Steps:
// 1. Initialize `n` to the size of the string `s`. If `n` is 0, return an empty string.
// 2. Create a 2D vector `dp` of size `n x n` initialized to `false` to store whether substrings are palindromic.
// 3. Initialize `maxLen` to 1 and `start` to 0 to track the longest palindromic substring found.
// 4. Set all substrings of length 1 (individual characters) as palindromic in `dp`.
// 5. Check for palindromic substrings of length 2 and update `dp` accordingly.
// 6. Use a nested loop to check for palindromic substrings of lengths 3 to `n`:
//    - For each starting index `i`, calculate the ending index `j`.
//    - If `s[i] == s[j]` and the substring `s[i+1:j-1]` is palindromic, update `dp[i][j]` to `true`.
//    - Update `maxLen` and `start` if a longer palindrome is found.
// 7. Return the longest palindromic substring using `s.substr(start, maxLen)`.

string longestPalindrome(string s)
{
    int n = s.size();
    if (n == 0)
        return "";
    vector<vector<bool>> dp(n, vector<bool>(n, false));
    int maxLen = 1;
    int start = 0;
    for (int i = 0; i < n; i++)
    {
        dp[i][i] = true;
    }
    for (int i = 0; i < n - 1; i++)
    {
        if (s[i] == s[i + 1])
        {
            dp[i][i + 1] = true;
            maxLen = 2;
            start = i;
        }
    }
    for (int length = 3; length <= n; length++)
    {
        for (int i = 0; i <= n - length; i++)
        {
            int j = i + length - 1;
            if (s[i] == s[j] && dp[i + 1][j - 1])
            {
                dp[i][j] = true;
                if (length > maxLen)
                {
                    maxLen = length;
                    start = i;
                }
            }
        }
    }
    return s.substr(start, maxLen);
}