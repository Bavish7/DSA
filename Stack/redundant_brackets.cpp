#include <iostream>
#include <stack>
using namespace std;

// FIND REDUNDANT BRACKETS
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize an empty stack `st` to help keep track of characters in the expression.
// 2. If the length of the string `s` is 1, return `true` as a single character cannot form a valid expression and thus would be considered redundant.
// 3. Traverse through each character in the string `s`:
//    - If the character is an opening bracket '(', or an operator ('+', '-', '*', '/'), push it onto the stack.
//    - If the character is a closing bracket ')':
//      - Initialize a variable `count` to keep track of the number of operators between the matching opening and closing brackets.
//      - Pop elements from the stack until the opening bracket '(' is found. Count the number of operators popped. This step helps in checking if the bracket was redundant.
//      - After popping the opening bracket, if `count` is zero, it means there were no operators between the brackets, so the brackets are redundant. Return `true` in this case.
// 4. If the traversal completes and no redundant brackets are found, return `false`.

bool findRedundantBrackets(string &s)
{
    stack<char> st;
    if (s.length() == 1)
    {
        return true;
    }
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(' || ch == '+' || ch == '-' || ch == '*' || ch == '/')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            int count = 0;
            while (!st.empty() && st.top() != '(')
            {
                char temp = st.top();
                if (temp == '+' || temp == '-' || temp == '*' || temp == '/')
                {
                    count++;
                }
                st.pop();
            }
            st.pop();
            if (count == 0)
            {
                return true;
            }
        }
    }
    return false;
}