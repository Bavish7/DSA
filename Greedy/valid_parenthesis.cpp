#include<iostream>
using namespace std;

// VALID PARENTHESIS STRING (LEETCODE 678)
// USING RANGE COUNT - TC=O(N), SC=O(1)

// Steps:
// 1. Initialize `mini` (minimum possible open parentheses) and `maxi` (maximum possible open parentheses) to 0.
// 2. Traverse the string:
//    - If the character is '(', increment both `mini` and `maxi`.
//    - If the character is ')', decrement both `mini` and `maxi`.
//    - If the character is '*', decrement `mini` and increment `maxi` (it can act as '(', ')' or '').
// 3. If `mini` becomes negative during traversal, reset it to 0 (as '*' can neutralize unmatched ')').
// 4. If `maxi` becomes negative, return `false` (as there are more unmatched ')' than possible open parentheses).
// 5. After traversal, return `true` if `mini` equals 0 (all open parentheses are matched).

bool checkValidString(string s)
{
    int mini = 0, maxi = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            mini++;
            maxi++;
        }
        else if (s[i] == ')')
        {
            mini--;
            maxi--;
        }
        else
        {
            mini--;
            maxi++;
        }
        if (mini < 0)
            mini = 0;
        if (maxi < 0)
            return false;
    }
    return mini == 0;
}