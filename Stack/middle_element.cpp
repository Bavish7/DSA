#include<iostream>
#include<stack>
using namespace std;

// DELETE MIDDLE ELEMENT OF THE STACK
// USING RECURSION AND BACKTRACKING - TC=O(N), SC=O(N)

// Steps:
// 1. Define a recursive helper function `solve` to remove the middle element of the stack.
// 2. **Base Case**: If `count` equals `N / 2`, it means we have reached the middle element of the stack.
//    - Pop the middle element from the stack and return from the function.
// 3. **Recursive Case**:
//    - Store the top element of the stack in `num` and then pop it.
//    - Recursively call `solve` with the updated stack and increment `count` by 1.
//    - After the recursive call returns, push the stored element (`num`) back onto the stack.
// 4. **Main Function** `deleteMiddle`:
//    - Initialize `count` to 0 and call the `solve` function with the stack, its size `N`, and `count`.
//    - `solve` will handle the recursive process of removing the middle element.

void solve(stack<int> &inputStack, int N, int count)
{
    if (count == N / 2)
    {
        inputStack.pop();
        return;
    }
    int num = inputStack.top();
    inputStack.pop();
    solve(inputStack, N, count + 1);
    inputStack.push(num);
}
void deleteMiddle(stack<int> &inputStack, int N)
{

    int count = 0;
    solve(inputStack, N, count);
}
