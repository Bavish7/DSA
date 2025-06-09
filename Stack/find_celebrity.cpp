#include <iostream>
#include <stack>
using namespace std;

// FIND CELEBRITY
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize a stack and push all indices (0 to n-1) onto the stack.
// 2. While there is more than one candidate in the stack:
//    a. Pop two candidates, `a` and `b`, from the stack.
//    b. Use the `knows(a, b)` function to determine if `a` knows `b`:
//       - If `a` knows `b`, `a` cannot be a celebrity, so push `b` back onto the stack.
//       - If `a` does not know `b`, `b` cannot be a celebrity, so push `a` back onto the stack.
// 3. After processing all candidates, the stack will contain one potential celebrity.
// 4. Store the candidate in `ans` and check if this candidate is a true celebrity:
//    a. Verify that the candidate does not know anyone else (i.e., `knows(ans, i)` should be false for all `i`).
//    b. Verify that everyone knows the candidate (i.e., `knows(i, ans)` should be true for all `i` except `ans` itself).
// 5. If both conditions are satisfied, return `ans` as the celebrity; otherwise, return -1 indicating no celebrity.

int findCelebrity(int n)
{
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        st.push(i);
    }
    while (st.size() > 1)
    {
        int a = st.top();
        st.pop();
        int b = st.top();
        st.pop();
        if (knows(a, b))
        {
            st.push(b);
        }
        else
        {
            st.push(a);
        }
    }
    int ans = st.top();
    st.pop();
    for (int i = 0; i < n; i++)
    {
        if (knows(ans, i))
        {
            return -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (knows(i, ans) != 1 && ans != i)
        {
            return -1;
        }
    }
    return ans;
}