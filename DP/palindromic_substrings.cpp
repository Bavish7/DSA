#include<iostream>
using namespace std;

// PALINDROMIC SUNSTRINGS (LEETCODE 647)
// USING FOR LOOPS - TC=O(N^3), SC=O(1)

// Steps:
// 1. Create a function isPalindrome(i, j) to check if s[i...j] is a palindrome using two pointers.
// 2. Move i forward and j backward while s[i] == s[j].
// 3. If mismatch occurs → return false.
// 4. Else → return true after loop ends.
// 5. In main function, iterate over all substrings s[i...j] (i ≤ j).
// 6. For each substring, check palindrome using isPalindrome().
// 7. If palindrome → increment count.
// 8. Return total count of palindromic substrings.

bool isPalindrome(int i, int j, string &s)
{
    while (i < j)
    {
        if (s[i++] != s[j--])
            return false;
    }
    return true;
}
int countSubstrings(string s)
{
    int n = s.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s))
                count++;
        }
    }
    return count;
}

// TOP-DOWN APPROACH - RECURSION + MEMOIZATION - TC=O(N^2), SC=O(N^2)
// Steps:
// 1. Create a recursive function isPalindrome(i, j) to check if s[i...j] is a palindrome.
// 2. Use memoization (dp array) to avoid recomputation of overlapping subproblems.
// 3. Base Case: If i > j → Empty substring → Palindrome.
// 4. If already calculated → return dp[i][j].
// 5. If s[i] == s[j] → Check inner substring s[i+1...j-1] recursively.
// 6. Else → Not a palindrome.
// 7. In main function, iterate for all substrings s[i...j] (i ≤ j).
// 8. Count all palindromic substrings.
// 9. Return count.

bool isPalindrome(int i, int j, string &s, vector<vector<int>> &dp)
{
    if (i > j)
        return true;
    if (dp[i][j] != -1)
        return dp[i][j];
    if (s[i] == s[j])
        return dp[i][j] = isPalindrome(i + 1, j - 1, s, dp);
    return dp[i][j] = false;
}
int countSubstrings(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, -1));
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if (isPalindrome(i, j, s, dp))
                count++;
        }
    }
    return count;
}

// BOTTOM-UP APPROACH - ITERATIVE + TABULATION - TC=O(N^2), SC=O(N^2)
// Steps:
// 1. Initialize a 2D dp array where dp[i][j] = 1 means substring s[i...j] is a palindrome.
// 2. Iterate over all possible lengths of substrings (len = 1 to n).
// 3. For every substring of length 'len':
//    → If len == 1 → Single character is always palindrome.
//    → If len == 2 → Check if both characters are equal.
//    → Else → Check if s[i]==s[j] and s[i+1...j-1] is palindrome (dp[i+1][j-1]==1).
// 4. Increment count if dp[i][j]==1.
// 5. Return the final count of palindromic substrings.

int countSubstrings(string s)
{
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int count = 0;
    for (int len = 1; len <= n; len++)
    {
        for (int i = 0; i + len - 1 < n; i++)
        {
            int j = i + len - 1;
            if (len==1)
                dp[i][j] = 1;
            else if (len==2)
                dp[i][j] = (s[i] == s[j]);
            else
            {
                dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
            }
            if (dp[i][j] == 1)
                count++;
        }
    }
    return count;
}

// EXPAND AROUND CENTER - TC=O(N^2), SC=O(1)
// Steps:
// 1. Expand around every possible center in the string.
// 2. There are 2n-1 centers in total:
//    → Odd length palindromes: center at (i, i)
//    → Even length palindromes: center at (i, i+1)
// 3. Expand while characters on both sides are equal.
// 4. Increment count for each valid palindrome found.

void isPalindrome(string &s, int i, int j, int &count)
{
    while (i >= 0 && j < s.size() && s[i] == s[j])
    {
        count++;
        i--;
        j++;
    }
}
int countSubstrings(string s)
{
    int n = s.size();
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        isPalindrome(s, i, i, count);
        isPalindrome(s, i, i + 1, count);
    }
    return count;
}