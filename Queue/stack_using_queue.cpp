#include<iostream>
using namespace std;

// IMPLEMENT STACK USING QUEUE (LEETCODE 225)
// USING QUEUE - TC=O(N), SC=O(N)

// Steps:
// 1. `push(int x)`:
//    - Push element `x` into the queue.
//    - Rotate the queue so that the newly added element is at the front of the queue. This simulates stack behavior.
//
// 2. `pop()`:
//    - The front of the queue is the top of the stack, so pop and return the front element of the queue.
//
// 3. `top()`:
//    - Return the front element of the queue, which is the current top of the stack.
//
// 4. `empty()`:
//    - Return true if the queue is empty, meaning the stack is empty.

queue<int> q;
MyStack()
{
}
void push(int x)
{
    q.push(x);
    for (int i = 0; i < q.size() - 1; i++)
    {
        int front = q.front();
        q.pop();
        q.push(front);
    }
}
int pop()
{
    int top = q.front();
    q.pop();
    return top;
}
int top()
{
    return q.front();
}
bool empty()
{
    return q.empty();
}