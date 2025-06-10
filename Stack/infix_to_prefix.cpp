#include<iostream>
using namespace std;

// INFIX TO PREFIX CONVERSION
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Reverse the infix expression.
// 2. Iterate through the reversed infix expression character by character.
// 3. If the character is an operand (letters or digits), append it directly to the result.
// 4. If the character is a closing parenthesis, push it onto the stack.
// 5. If the character is an opening parenthesis, pop elements from the stack and append them to the result until a closing parenthesis is encountered. Remove the closing parenthesis.
// 6. For operators, pop and append elements from the stack to the result as long as the precedence of the current operator is less than or equal to the precedence of the operator at the top of the stack. Then push the current operator onto the stack.
// 7. After processing the entire expression, pop and append any remaining elements from the stack to the result.

int checkPrec(char ch)
{
    if (ch == '^')
    {
        return 3;
    }
    else if (ch == '*' || ch == '/')
    {
        return 2;
    }
    else if (ch == '+' || ch == '-')
    {
        return 1;
    }
    else
        return -1;
}
string infixToPrefix(string exp)
{
    string ans = "";
    stack<char> st;
    reverse(exp.begin(), exp.end());
    for (int i = 0; i < exp.size(); i++)
    {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9'))
        {
            ans += exp[i];
        }
        else if (exp[i] == ')')
        {
            st.push(exp[i]);
        }
        else if (exp[i] == '(')
        {
            while (st.top() != ')' && !st.empty())
            {
                ans += st.top();
                st.pop();
            }
            st.pop();
        }
        else
        {
            while (!st.empty() && checkPrec(exp[i]) <= checkPrec(st.top()))
            {
                ans += st.top();
                st.pop();
            }
            st.push(exp[i]);
        }
    }
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}