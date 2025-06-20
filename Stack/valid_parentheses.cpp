#include <iostream>
#include <stack>
using namespace std;

// VALID PARENTHESES (LEETCODE 20)
// USING STACK -  TC=O(N), SC=O(N)

// Steps:
// 1. Initialize a stack to keep track of opening parentheses.
// 2. Iterate through each character of the string:
//    - If the character is an opening parenthesis ('(', '{', or '['), push it onto the stack.
//    - If the character is a closing parenthesis (')', '}', or ']'):
//      - Check if the stack is not empty.
//      - Check if the top element of the stack matches the corresponding opening parenthesis for the current closing parenthesis.
//      - If it matches, pop the top element from the stack.
//      - If it does not match or the stack is empty, return `false` as the parentheses are not valid.
// 3. After processing all characters, check if the stack is empty:
//    - If the stack is empty, return `true` as all parentheses were properly matched and closed.
//    - If the stack is not empty, return `false` as there are unmatched opening parentheses.

bool isValid(string s)
{
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '{' || ch == '[')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty())
            {
                char top = st.top();
                if ((ch == ')' && top == '(') || (ch == '}' && top == '{') || (ch == ']' && top == '['))
                {
                    st.pop();
                }
                else
                {
                    return false;
                }
            }
            else
            {
                return false;
            }
        }
    }
    if (st.empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}