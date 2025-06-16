#include <iostream>
#include <stack>
using namespace std;

// PREVIOUS SMALLER ELEMENT 
// USING STACK - TC=O(N), SC=O(N)

// Steps:
// 1. Initialize a stack `st` to keep track of elements while processing.
// 2. Initialize a vector `ans` of size `n` to store the previous smaller element for each element in the array.
// 3. Push a sentinel value (-1) onto the stack. This value helps in handling cases where no smaller element exists.
// 4. Traverse the array `arr` from left to right (i.e., starting from the first element to the last).
// 5. For each element `curr` in the array:
//    - While the top element of the stack is greater than or equal to `curr`, pop elements from the stack. This step ensures that the stack only contains elements smaller than the current element.
//    - The top element of the stack after the while loop is the previous smaller element for `curr`. Assign this value to `ans[i]`.
//    - Push the current element `curr` onto the stack.
// 6. After processing all elements, return the vector `ans` which contains the previous smaller element for each element in the array.

vector<int> prevSmallerElement(vector<int> &arr, int n)
{
    stack<int> st;
    vector<int> ans(n);
    st.push(-1);
    for (int i = 0; i <n; i++)
    {
        int curr = arr[i];
        while (st.top() >= curr)
        {
            st.pop();
        }
        ans[i] = st.top();
        st.push(curr);
    }
    return ans;
}