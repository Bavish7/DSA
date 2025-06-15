#include<iostream>
using namespace std;

// PREFIX TO INFIX CONVERSION
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Iterate through the prefix expression in reverse order.
// 2. If the character is an operand (letters or digits), push it onto the stack.
// 3. If the character is an operator, pop two operands from the stack and append them to the result along with the operator in between.
// 4. Push the result back onto the stack.
// 5. After processing the entire expression, the final result will be present at the top of the stack.

string prefixToInfix(string exp)
{
    stack<string> st;
    for (int i = exp.size() - 1; i >= 0; i--)
    {
        if ((exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= '0' && exp[i] <= '9'))
        {
            string s(1, exp[i]);
            st.push(s);
        }
        else
        {
            string op1 = st.top();
            st.pop();
            string op2 = st.top();
            st.pop();
            st.push("(" + op1 + exp[i] + op2 + ")");
        }
    }
    return st.top();
}