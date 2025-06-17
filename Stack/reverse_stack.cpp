#include <iostream>
#include <stack>
using namespace std;

// REVERSE A STACK USING RECURSION
// USING RECURSION AND BACKTRACKING - TC=O(N^2), SC=O(N)

// Steps:
// 1. Define a helper function `insertAtBottom` that inserts an element at the bottom of the stack:
//    - If the stack is empty, push the element onto the stack and return.
//    - If the stack is not empty, pop the top element and recursively call `insertAtBottom` to insert the new element.
//    - Push the previously popped element back onto the stack to maintain the order of the remaining elements.
// 2. Define the main function `reverseStack` to reverse the stack:
//    - If the stack is empty, return as there is nothing to reverse.
//    - Pop the top element of the stack and store it in `num`.
//    - Recursively call `reverseStack` to reverse the remaining stack.
//    - Call `insertAtBottom` to insert the popped element `num` at the bottom of the stack.
// 3. This process will recursively remove elements and then insert them back in reverse order, effectively reversing the stack.

void insertAtBottom(stack<int> &stack, int num)
{
    if (stack.empty())
    {
        stack.push(num);
        return;
    }
    int s = stack.top();
    stack.pop();
    insertAtBottom(stack, num);
    stack.push(s);
}
void reverseStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }
    int num = stack.top();
    stack.pop();
    reverseStack(stack);
    insertAtBottom(stack, num);
}