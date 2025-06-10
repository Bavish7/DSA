#include <iostream>
#include <stack>
using namespace std;

// INSERT AT BOTTOM OF A STACK
// USING RECURSION AND BACKTRACKING - TC=O(N), SC=O(N)

// Steps:
// 1. Define a helper function `solve` that takes the stack and the element to be inserted.
// 2. If the stack is empty:
//    - Push the element `x` onto the stack and return. This is the base case for recursion.
// 3. If the stack is not empty:
//    - Store the top element of the stack in a variable `num`.
//    - Pop the top element from the stack.
//    - Recursively call `solve` with the modified stack and element `x`.
//    - After recursion completes, push the previously stored element `num` back onto the stack.
// 4. Define `pushAtBottom`, which simply calls the `solve` function with the given stack and element.
// 5. Return the modified stack after `solve` completes.

void solve(stack<int> &myStack, int x)
{
    if (myStack.empty())
    {
        myStack.push(x);
        return;
    }
    int num = myStack.top();
    myStack.pop();
    solve(myStack, x);
    myStack.push(num);
}
stack<int> pushAtBottom(stack<int> &myStack, int x)
{
    solve(myStack, x);
    return myStack;
}