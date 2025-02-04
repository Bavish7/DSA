#include<iostream>
using namespace std;

// REMOVE INVALID PARENTHESES (LEETCODE 301)
// USING RECURSION AND BACKTRACKING - TC=O(2^N), SC=O(N)

// Steps:
// 1. **Calculate Invalid Parentheses**:
//    - Traverse the string to count the number of invalid opening and closing parentheses.
//    - `invalidOpen` counts extra opening parentheses.
//    - `invalidClose` counts extra closing parentheses that don't have matching opening parentheses.
//
// 2. **Recursive Backtracking Function (`solve`)**:
//    - **Base Case**: If we've processed all characters:
//      - Check if all `open`, `close`, and `bal` (balance) counts are zero, indicating a valid string.
//      - If valid, add the current `output` string to the result set `ans`.
//    - **Recursive Case**:
//      - **If Character is Not Parenthesis**:
//        - Add it to the `output` and recurse to process the next character.
//        - Remove it from `output` after recursion to backtrack.
//      - **If Character is '('**:
//        - Optionally skip this parenthesis if we have extra opening parentheses (`open > 0`).
//        - Add this parenthesis to the `output`, update balance, and recurse.
//        - Remove it from `output` after recursion to backtrack.
//      - **If Character is ')'**:
//        - Optionally skip this parenthesis if we have extra closing parentheses (`close > 0`).
//        - Add this parenthesis to the `output`, update balance, and recurse if balance is positive.
//        - Remove it from `output` after recursion to backtrack.
//
// 3. **Invoke Recursive Function**:
//    - Start the recursive function with the calculated invalid parentheses and an empty `output` string.
//    - Convert the result set to a vector of strings for the final output.

void solve(string &s, unordered_set<string> &ans, int open, int close, int bal, int index, string &output)
{
    if (index >= s.length())
    {
        if (open == 0 && close == 0 && bal == 0)
        {
            ans.insert(output);
        }
        return;
    }
    if (s[index] != '(' && s[index] != ')')
    {
        output.push_back(s[index]);
        solve(s, ans, open, close, bal, index + 1, output);
        output.pop_back();
    }
    else
    {
        if (s[index] == '(')
        {
            if (open > 0)
            {
                solve(s, ans, open - 1, close, bal, index + 1, output);
            }
            output.push_back('(');
            solve(s, ans, open, close, bal + 1, index + 1, output);
            output.pop_back();
        }
        else if (s[index] == ')')
        {
            if (close > 0)
            {
                solve(s, ans, open, close - 1, bal, index + 1, output);
            }
            if (bal > 0)
            {
                output.push_back(')');
                solve(s, ans, open, close, bal - 1, index + 1, output);
                output.pop_back();
            }
        }
    }
}
vector<string> removeInvalidParentheses(string s)
{
    unordered_set<string> ans;
    int invalidOpen = 0;
    int invalidClose = 0;
    int balance = 0;
    for (auto ch : s)
    {
        if (ch == '(')
        {
            invalidOpen++;
        }
        else if (ch == ')')
        {
            if (invalidOpen > 0)
            {
                invalidOpen--;
            }
            else
            {
                invalidClose++;
            }
        }
    }
    string output = "";
    int index = 0;
    solve(s, ans, invalidOpen, invalidClose, balance, index, output);
    return vector<string>(ans.begin(), ans.end());
}