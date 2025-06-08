#include<iostream>
using namespace std;

// DECODE STRING (LEETCODE 394)
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize a stack to help decode the string.
// 2. Iterate through each character in the string `s`:
//    - Push characters onto the stack until a ']' is encountered.
//    - When ']' is found, pop characters from the stack to form the decoded substring until '[' is reached.
//    - Collect any digits preceding the '[' to determine the repeat count for the substring.
//    - Repeat the decoded substring the number of times specified by the digits and push it back onto the stack.
// 3. After processing the entire string, pop all elements from the stack to form the final decoded string.
// 4. Return the decoded string as the result.

string decodeString(string s)
{
    stack<string> st;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ']')
        {
            string temp = "";
            while (!st.empty() && st.top() != "[")
            {
                temp += st.top();
                st.pop();
            }
            st.pop();
            string numeric = "";
            while (!st.empty() && isdigit(st.top()[0]))
            {
                numeric += st.top();
                st.pop();
            }
            reverse(numeric.begin(), numeric.end());
            int n = stoi(numeric);
            string curr = "";
            for (int j = 0; j < n; j++)
            {
                curr += temp;
            }
            st.push(curr);
        }
        else
        {
            string temp(1, s[i]);
            st.push(temp);
        }
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    return ans;
}