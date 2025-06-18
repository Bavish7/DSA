#include <iostream>
#include <stack>
using namespace std;

// SORT A STACK WITHOUT LOOPS
// RECURSION AND BACKTRACKING - TC=O(N^2), SC=O(N)

// Steps:
// 1. Define a helper function `sortedInsert` to insert an element into the stack in sorted order:
//    - If the stack is empty or the top element of the stack is less than the element to be inserted, push the element onto the stack and return.
//    - Otherwise, pop the top element of the stack, recursively call `sortedInsert` to insert the new element, and then push the previously popped element back onto the stack.
// 2. Define the main function `sortStack` to sort the stack:
//    - If the stack is empty, return as there is nothing to sort.
//    - Pop the top element of the stack and store it in `num`.
//    - Recursively call `sortStack` to sort the remaining stack.
//    - Call `sortedInsert` to insert the popped element `num` into the sorted stack.
// 3. This process will recursively remove elements and then insert them back in sorted order, effectively sorting the stack.

void sortedInsert(stack<int> &stack, int num)
{
    if (stack.empty() || stack.top() < num)
    {
        stack.push(num);
        return;
    }
    int n = stack.top();
    stack.pop();
    sortedInsert(stack, num);
    stack.push(n);
}
void sortStack(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }
    int num = stack.top();
    stack.pop();
    sortStack(stack);
    sortedInsert(stack, num);
}