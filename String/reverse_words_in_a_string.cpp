#include<iostream>
using namespace std;

// REVERSE WORDS IN A STRING (LEETCODE 151)
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Traverse the input string `s` to extract words (separated by spaces) into a stack.
//    - Ignore extra spaces between words.
//    - Push non-empty words to the stack.
// 2. After traversal, handle the last word if it's not empty.
// 3. Build the reversed string by popping words from the stack and appending them to the result.
//    - Add a single space between words and remove the trailing space at the end.
// 4. Return the reversed word string.

string reverseWords(string s)
{
    stack<string> st;
    string temp = "";
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == ' ')
        {
            if (temp.size() == 0)
            {
                continue;
            }
            else
            {
                st.push(temp);
                temp = "";
            }
        }
        else
        {
            temp.push_back(s[i]);
        }
    }
    string ans = "";
    if (temp.size() != 0)
    {
        ans = temp + " ";
    }
    while (!st.empty())
    {
        ans += st.top();
        ans += " ";
        st.pop();
    }
    ans.pop_back();
    return ans;
}

// USING TWO POINTERS - TC=O(N), SC=O(1)
// Steps:
// 1. Trim leading and trailing spaces by adjusting indices `i` and `j`.
// 2. Traverse the trimmed string from `i` to `j` and build individual words:
//    - If a space is encountered, append the current word (`temp`) to the result (`ans`) in reverse order.
//    - Reset `temp` after adding it to `ans`.
// 3. After traversal, add the last word (`temp`) to `ans` if it's non-empty.
// 4. Remove the trailing space from the result if it exists and return the result.

string reverseWords(string s){
    int n = s.size();
    int i = 0;
    while(i < n && s[i] == ' '){
        i++;
    }
    int j = n - 1;
    while(j >= 0 && s[j] == ' '){
        j--;
    }
    string ans = "";
    string temp = "";
    while(i <= j){
        if(s[i] == ' '){
            if(temp.size() > 0){
                ans = temp + " " + ans;
                temp = "";
            }
        }
        else{
            temp.push_back(s[i]);
        }
        i++;
    }
    if(temp.size() > 0){
        ans = temp + " " + ans;
    }
    if(ans.size() > 0){
        ans.pop_back();
    }
    return ans;
}

