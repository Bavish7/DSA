#include<iostream>
using namespace std;

// POSTFIX TO INFIX CONVERSION
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Iterate through the postfix expression character by character.
// 2. If the character is an operand (letters or digits), push it onto the stack.
// 3. If the character is an operator, pop two operands from the stack and append them to the result along with the operator in between.
// 4. Push the result back onto the stack.

string postfixToInfix(string exp)
{
    stack<string> st;
    for (int i = 0; i < exp.size(); i++)
    {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9'))
        {
            string s(1, exp[i]);
            st.push(s);
        }
        else
        {
            string op2 = st.top();
            st.pop();
            string op1 = st.top();
            st.pop();
            st.push("(" + op1 + exp[i] + op2 + ")");
        }
    }
    return st.top();
}