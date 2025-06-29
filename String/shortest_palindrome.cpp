#include<iostream>
using namespace std;

// SHORTEST PALINDROME (LEETCODE 214)
// USING KMP ALGORITHM - TC=O(N), SC=O(N)

// Steps:
// 1. Reverse the input string `s` and store it as `reversedStr`.  
// 2. Construct a new string `str` by concatenating `s`, a separator `*`, and `reversedStr`.  
// 3. Compute the LPS (Longest Prefix Suffix) array for `str` to determine the longest palindromic prefix.  
// 4. Calculate the difference `diff` between the string length and the last value of LPS.  
// 5. Prefix `s` with the necessary characters from `reversedStr` to form the shortest palindrome.  
// 6. Return the modified string.  

string shortestPalindrome(string s)
{
    int n = s.size();
    string reversedStr = s;
    reverse(reversedStr.begin(), reversedStr.end());
    string str = s;
    str += "*" + reversedStr;
    vector<int> lps(2 * n + 1);
    int i = 0, j = 1;
    while (j < str.size())
    {
        if (str[i] == str[j])
        {
            lps[j] = i + 1;
            i++, j++;
        }
        if (j == str.size())
            break;
        if (str[i] != str[j])
        {
            if (i > 0)
                i = lps[i - 1];
            else
            {
                i = lps[j] = 0;
                j++;
            }
        }
    }
    int diff = n - lps[2 * n];
    s = reversedStr.substr(0, diff) + s;
    return s;
}
