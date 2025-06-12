#include <iostream>
#include <stack>
using namespace std;

// MINIMUM COST TO MAKE STRING VALID 
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Check if the length of the string `str` is odd. If true, return -1 because an odd-length string cannot be balanced by inserting characters.
// 2. Initialize a stack `st` to help track the balance of the string.
// 3. Iterate through each character `ch` in the string `str`.
//    - If `ch` is '{', push it onto the stack because it might need to be matched or balanced.
//    - If `ch` is '}', check if the stack is not empty and the top of the stack is '{'. If true, pop the top of the stack as this forms a balanced pair.
//    - If the stack is empty or the top of the stack is not '{', push '}' onto the stack because it needs to be matched or balanced.
// 4. After processing all characters, count the remaining unmatched '{' and '}' in the stack.
//    - Initialize two counters `a` and `b`. `a` will count unmatched '}', and `b` will count unmatched '{'.
// 5. Iterate through the stack and update `a` and `b` based on the type of character.
// 6. Calculate the minimum cost to balance the string:
    // - The cost to balance the unmatched '}' is `(a + 1) / 2`, which covers the case where an extra '}' might be present.
    // - The cost to balance the unmatched '{' is `(b + 1) / 2`, which covers the case where an extra '{' might be present.
//  7. Return the total cost calculated.


int findMinimumCost(string str)
{
    if (str.length() % 2 == 1)
    {
        return -1;
    }
    stack<char> st;
    for (int i = 0; i < str.length(); i++)
    {
        char ch = str[i];
        if (ch == '{')
        {
            st.push(ch);
        }
        else
        {
            if (!st.empty() && st.top() == '{')
            {
                st.pop();
            }
            else
            {
                st.push(ch);
            }
        }
    }
    int a = 0, b = 0;
    while (!st.empty())
    {
        if (st.top() == '{')
        {
            b++;
        }
        else
        {
            a++;
        }
        st.pop();
    }
    int ans = (a + 1) / 2 + (b + 1) / 2;
    return ans;
}