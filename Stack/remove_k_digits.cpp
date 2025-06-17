#include<iostream>
using namespace std;

// REMOVE K DIGITS (LEETCODE 402)
// USING STACK - TC=O(N), SC=O(N)

// 1. Use a stack to store characters of the number while maintaining a non-decreasing sequence.
// 2. For each character in the number, if the current character is smaller than the top of the stack and k > 0, pop the stack to remove digits.
// 3. After processing all digits, if k is still greater than 0, continue popping from the stack to remove more digits.
// 4. Build the result by popping the remaining elements from the stack, reverse the string to get the correct order.
// 5. Remove leading zeros from the result.
// 6. If the result is empty after removing zeros, return "0".

string removeKdigits(string num, int k)
{
    if (k == num.size())
    {
        return "0";
    }
    stack<char> st;
    st.push(num[0]);
    for (int i = 1; i < num.size(); i++)
    {
        while (!st.empty() && st.top() > num[i] && k > 0)
        {
            st.pop();
            k--;
        }
        st.push(num[i]);
    }
    while (k > 0)
    {
        if (st.empty())
        {
            break;
        }
        st.pop();
        k--;
    }
    string ans = "";
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }
    reverse(ans.begin(), ans.end());
    int i = 0;
    while (ans[i] == '0')
    {
        i++;
    }
    if (i == ans.size())
        return "0";
    return ans.substr(i);
}