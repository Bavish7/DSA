#include<iostream>
using namespace std;

// CHECK IF WORD IS VALID AFTER SUBSTITUTIONS (LEETCODE 1003)
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Check if the string starts with 'a'; if not, return false.
// 2. Use a stack to validate the sequence of characters according to the rules:
//    - Push 'a' to the stack.
//    - For 'b', check if 'a' is on top of the stack and push 'b'.
//    - For 'c', ensure 'b' is on top and followed by 'a'. If so, pop both.
// 3. If any rule is violated, return false.
// 4. After processing the string, ensure the stack is empty to validate the sequence.

bool isValid(string s)
{
    if (s[0] != 'a')
        return false;
    stack<char> st;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'a')
        {
            st.push(s[i]);
        }
        else if (s[i] == 'b')
        {
            if (!st.empty() && st.top() == 'a')
            {
                st.push(s[i]);
            }
            else
            {
                return false;
            }
        }
        else
        {
            if (!st.empty() && st.top() == 'b')
            {
                st.pop();
                if (!st.empty() && st.top() == 'a')
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
    return st.empty();
}