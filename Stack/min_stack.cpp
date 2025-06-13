#include <iostream>
#include <stack>
using namespace std;

// MIN STACK (LEETCODE 155)
// TC=O(1), SC=O(1)

// Steps:
// 1. Initialize a stack `st` to store the elements of the stack and an integer `minVal` to track the current minimum value.
// 2. In the constructor `MinStack()`, set `minVal` to INT_MAX, which represents an initial state where no minimum value has been set yet.
// 3. For the `push(int val)` operation:
//    - If the new value `val` is less than or equal to `minVal`, push the current `minVal` onto the stack. This step ensures that the minimum value before pushing the new `val` is stored in the stack.
//    - Update `minVal` to the new value `val`.
//    - Push the new value `val` onto the stack.
// 4. For the `pop()` operation:
//    - If the top element of the stack is equal to `minVal`, pop the top element. This step also means that the minimum value needs to be updated.
//    - After popping the top element (which was the minimum), update `minVal` to the new top element of the stack, which is the previous minimum before the current `minVal`.
//    - Pop the new top element (which was the previous minimum).
// 5. For the `top()` operation, return the top element of the stack, which represents the most recently pushed element.
// 6. For the `getMin()` operation, return the `minVal`, which represents the current minimum value of the stack.

stack<int> st;
int minVal;
MinStack()
{
    minVal = INT_MAX;
}

void push(int val)
{
    if (val <= minVal)
    {
        st.push(minVal);
        minVal = val;
    }
    st.push(val);
}

void pop()
{
    if (st.top() == minVal)
    {
        st.pop();
        minVal = st.top();
    }
    st.pop();
}

int top()
{
    return st.top();
}

int getMin()
{
    return minVal;
}