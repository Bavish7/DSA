#include<iostream>
using namespace std;

// SIMPLIFY PATH (LEETCODE 71)
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Use a stack to store valid directory names from the path.
// 2. Iterate over the path:
//    - Skip '/' characters.
//    - Extract the directory or file name by processing characters between '/'.
//    - If the name is "." (current directory), continue.
//    - If the name is ".." (parent directory), pop the top of the stack if not empty.
//    - Otherwise, push the directory name onto the stack.
// 3. After processing, build the simplified path by popping elements from the stack and appending them to the result string.
// 4. If the result is empty, return "/", otherwise return the simplified path.

string simplifyPath(string path)
{
    stack<string> st;
    int n = path.size();
    string ans;
    for (int i = 0; i < n; i++)
    {
        if (path[i] == '/')
        {
            continue;
        }
        string temp;
        while (i < n && path[i] != '/')
        {
            temp += path[i];
            i++;
        }
        if (temp == ".")
        {
            continue;
        }
        else if (temp == "..")
        {
            if (!st.empty())
            {
                st.pop();
            }
        }
        else
        {
            st.push(temp);
        }
    }
    while (!st.empty())
    {
        ans = "/" + st.top() + ans;
        st.pop();
    }
    if (ans.size() == 0)
    {
        return "/";
    }
    return ans;
}