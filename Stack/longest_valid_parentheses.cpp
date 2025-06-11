#include<iostream>
using namespace std;

// LONGEST VALID PARENTHESES (LEETCODE 32)
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize a stack with -1, which helps in handling the base case when the first valid substring starts from index 0.
// 2. Iterate through the string:
//    - For each '(' character, push its index onto the stack.
//    - For each ')' character, pop the top of the stack. After popping:
//      - If the stack is empty, push the current index to the stack to act as the new base.
//      - If the stack is not empty, calculate the length of the valid parentheses substring by taking the difference between the current index and the index at the top of the stack.
// 3. Keep track of the maximum length of valid parentheses encountered during the iteration.
// 4. Return the maximum length found.

int longestValidParentheses(string s)
{
    if (s.size() == 0)
    {
        return 0;
    }
    stack<int> st;
    st.push(-1);
    int maxLen = 0;
    for (int i = 0; i < s.length(); i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            st.push(i);
        }
        else
        {
            st.pop();
            if (st.empty())
            {
                st.push(i);
            }
            else
            {
                int len = i - st.top();
                maxLen = max(len, maxLen);
            }
        }
    }
    return maxLen;
}

// USING 2 FOR LOOP - TC=O(N), SC=O(1)
// Steps:
// 1. First pass (left to right):
//    - Use two counters: `left` for '(' and `right` for ')'.
//    - Traverse through the string. For each '(' increment `left`, and for each ')' increment `right`.
//    - When `left` equals `right`, it means we have valid parentheses, so calculate the length and update the maximum length.
//    - If at any point `right` exceeds `left`, reset both counters (invalid substring).
// 2. Second pass (right to left):
//    - Similar process but traversing in reverse.
//    - This handles cases where extra '(' appears before a valid set of parentheses, making sure to catch valid parentheses that could be missed in the first pass.

int longestValidParentheses(string s)
{
    int maxLen = 0;
    int left = 0;
    int right = 0;
    for (int i = 0; i < s.size(); i++)
    {
        char ch = s[i];
        if (ch == '(')
        {
            left++;
        }
        else
        {
            right++;
        }
        if (left == right)
        {
            maxLen = max(maxLen, 2 * left);
        }
        else if (left < right)
        {
            left = right = 0;
        }
    }
    left = right = 0;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        char ch = s[i];
        if (ch == '(')
        {
            left++;
        }
        else
        {
            right++;
        }
        if (left == right)
        {
            maxLen = max(maxLen, 2 * left);
        }
        else if (left > right)
        {
            left = right = 0;
        }
    }
    return maxLen;
}